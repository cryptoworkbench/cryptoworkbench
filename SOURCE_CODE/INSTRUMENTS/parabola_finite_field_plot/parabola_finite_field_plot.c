/* Works with:
 *./parabola_finite_field_plot 11 2 3 9
 *
 * Also works with:
 * 17 2 3 4
 *
 * Lacks exit() test like the linear one does. But maybe that is good.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"

unsigned long Mod, A, B, C;

struct linear_equation {
    unsigned long coefficient_a;
    unsigned long coefficient_b;
    unsigned long result;
};

struct cartesian_coordinates {
    unsigned long x;
    unsigned long y;
};

unsigned long least_common_multiple(unsigned long a, unsigned long b) {
    unsigned long least_common_multiple = a; if (a < b) least_common_multiple = b;
    while (least_common_multiple % a != 0 || least_common_multiple % b != 0) least_common_multiple++;
    return least_common_multiple;
}

struct linear_equation multiply_values_by(struct linear_equation INP, unsigned long multiplier) {
    struct linear_equation return_value;
    return_value.coefficient_a = (INP.coefficient_a * multiplier) % Mod;
    return_value.coefficient_b = (INP.coefficient_b * multiplier) % Mod;
    return_value.result = (INP.result * multiplier) % Mod;
    return return_value;
}

struct linear_equation linear_equation_add(struct linear_equation equation_one, struct linear_equation equation_two) {
    struct linear_equation ret;
    ret.coefficient_a = (equation_one.coefficient_a + (Mod - equation_two.coefficient_a)) % Mod;
    ret.coefficient_b = (equation_one.coefficient_b + (Mod - equation_two.coefficient_b)) % Mod;
    ret.result = (equation_one.result + (Mod - equation_two.result)) % Mod;
    return ret;
}

unsigned long md(unsigned long IN) { return IN % Mod; }
void C_reduce() { if (C >= Mod) { md(C); printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", Mod, C); } }

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &Mod)) { printf("%s is not Mod!\n", argv[1]); exit(-1); }
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &A)) { printf("%s is not A!\n", argv[2]); exit(-2); } md(A);
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &B)) { printf("%s is not B!\n", argv[3]); exit(-3); } md(B);
    if (4 < argc) {
	if (STR_could_be_parsed_into_UL(argv[4], &C)) C_reduce();
	else { printf("The secret '%s' has not yet been transformed into numerical form!\n", argv[4]); exit(-4); }
    } else { printf("Please put in the secret number such that 'secret number' < %lu: ", Mod); fscanf(stdin, "%lu", &C); C_reduce(); }
    // ^^ Gather starting information

    fprintf(stdout, "[x,y] points on 'y \u2261 %lux^2 + %lux + %lu (mod %lu)': (complete)\n", A, B, C, Mod);
    for (unsigned long x = 0; x < Mod; x++) {
	struct cartesian_coordinates point_on_graph = {x, 0};
	unsigned long y = (md(md((md(A * (md(x * x)))) + (md(x * B)))) + C);
	printf("[%lu,%lu]\n", x, y);
    } fprintf(stdout, "\n"); // << ^ Calculate all coordinates for this parabola over this finite field

    struct cartesian_coordinates point_one, point_two, point_three;
    fprintf(stdout, "Point one, format [x,y]: ["); fscanf(stdin, "%lu,%lu]", &point_one.x, &point_one.y);
    fprintf(stdout, "Point two: ["); fscanf(stdin, " %lu,%lu]", &point_two.x, &point_two.y);
    fprintf(stdout, "Point three: ["); fscanf(stdin, " %lu,%lu]", &point_three.x, &point_three.y);

    struct linear_equation equation_one = { md(point_one.x * point_one.x), point_one.x, point_one.y };
    struct linear_equation equation_two = { md(point_two.x * point_two.x), point_two.x, point_two.y };
    struct linear_equation equation_three = { md(point_three.x * point_three.x), point_three.x, point_three.y };
    struct linear_equation equation_two_and_one = linear_equation_add(equation_two, equation_one);
    struct linear_equation equation_two_and_three = linear_equation_add(equation_two, equation_three);
    unsigned long coefficient_b_lcm = least_common_multiple(equation_two_and_one.coefficient_b, equation_two_and_three.coefficient_b); // printf("\nCalculated lcm as: %lu\n", coefficient_b_lcm);
    struct linear_equation modified_two_and_one = multiply_values_by(equation_two_and_one, coefficient_b_lcm / equation_two_and_one.coefficient_b);
    struct linear_equation modified_two_and_three = multiply_values_by(equation_two_and_three, coefficient_b_lcm / equation_two_and_three.coefficient_b);
    struct linear_equation final_linear_equation = linear_equation_add(modified_two_and_one, modified_two_and_three);
    // ^^ Prepare all the required linear equations

    unsigned pre_A = final_linear_equation.result; while (pre_A % final_linear_equation.coefficient_a != 0) pre_A += Mod;
    unsigned long retrieved_A = pre_A / final_linear_equation.coefficient_a; md(retrieved_A); // << Check if may be ommited
    if (retrieved_A != A) // return -5 if the quadratic formula parameter 'a' had been incorrectly inferred from the 3 coordinate points (the 3-N in this k = 3 3-N Shamir Secret Sharing Sceme)
    { fprintf(stderr, "\nThe value that I inferred from coordinate points for variable 'a' did not correspond to the variable 'a' that was used to plot the points. %lu != %lu. Exiting.\n", retrieved_A, A); return -5; }
    // ^^ Prove that A can be successfully derived from these linear equations by not returning here

    unsigned long pre_B = md(equation_two_and_one.result + (Mod - md(equation_two_and_one.coefficient_a * retrieved_A)));
    while (pre_B % equation_two_and_one.coefficient_b != 0) pre_B += Mod;
    unsigned long retrieved_B = pre_B / equation_two_and_one.coefficient_b; md(retrieved_B);
    if (retrieved_B != B) // return -6 is the quadratic formula parameter 'b' had been incorrectly inferred from the 3 coordinate points
    { fprintf(stderr, "The value that I inferred from coordinate points for variable 'b' did not correspond to the variable 'b' that was used to plot the points. %lu != %lu. Exiting.\n", retrieved_B, B); return -6; }
    // ^^ Prove that B can be successfully derived from these linear equations by not returning here either

    unsigned long retrieved_C = md(equation_one.result + (Mod - md(md(md(A * (md(point_one.x * point_one.x)))) + (md(retrieved_B * point_one.x)))));
    if (C != retrieved_C) { fprintf(stderr, "%lu != %lu\n", retrieved_C, C); return -7; }
    else fprintf(stdout, "\nSecret curve parameter value: %lu.\n", retrieved_C); return 0;
}
