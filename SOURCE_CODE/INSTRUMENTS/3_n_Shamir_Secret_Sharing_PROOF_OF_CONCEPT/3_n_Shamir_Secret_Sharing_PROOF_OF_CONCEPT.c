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

unsigned long m, a, b, c;

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
    return_value.coefficient_a = (INP.coefficient_a * multiplier) % m;
    return_value.coefficient_b = (INP.coefficient_b * multiplier) % m;
    return_value.result = (INP.result * multiplier) % m;
    return return_value;
}

struct linear_equation linear_equation_add(struct linear_equation equation_one, struct linear_equation equation_two) {
    struct linear_equation ret;
    ret.coefficient_a = (equation_one.coefficient_a + (m - equation_two.coefficient_a)) % m;
    ret.coefficient_b = (equation_one.coefficient_b + (m - equation_two.coefficient_b)) % m;
    ret.result = (equation_one.result + (m - equation_two.result)) % m;
    return ret;
}

void C_reduce() { if (c >= m) { c%=m; printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", m, c); } }

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &m)) { printf("%s is not m!\n", argv[1]); exit(-1); }
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &a)) { printf("%s is not a!\n", argv[2]); exit(-2); } a%=m;
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &b)) { printf("%s is not b!\n", argv[3]); exit(-3); } b%=m;
    if (4 < argc) {
	if (STR_could_be_parsed_into_UL(argv[4], &c)) C_reduce();
	else { printf("The secret '%s' has not yet been transformed into numerical form!\n", argv[4]); exit(-4); }
    } else { printf("Please put in the secret number such that 'secret number' < %lu: ", m); fscanf(stdin, "%lu", &c); C_reduce(); }
    // ^^ Gather starting information

    fprintf(stdout, "[x,y] points on 'y \u2261 %lux^2 + %lux + %lu (mod %lu)': (complete)\n", a, b, c, m);
    for (unsigned long x = 0; x < m; x++) {
	struct cartesian_coordinates point_on_graph = {x, 0};
	unsigned long y = (((((((x * x) % m) * a) % m) + ((x * b) % m)) % m) + c) % m;
	printf("[%lu,%lu]\n", x, y);
    } fprintf(stdout, "\n"); // << ^ Calculate all coordinates for this parabola over this finite field

    struct cartesian_coordinates point_one, point_two, point_three;
    fprintf(stdout, "Point one, format [x,y]: ["); fscanf(stdin, "%lu,%lu]", &point_one.x, &point_one.y);
    fprintf(stdout, "Point two: ["); fscanf(stdin, " %lu,%lu]", &point_two.x, &point_two.y);
    fprintf(stdout, "Point three: ["); fscanf(stdin, " %lu,%lu]", &point_three.x, &point_three.y);

    struct linear_equation equation_one = {(point_one.x*point_one.x)%m, point_one.x, point_one.y};
    struct linear_equation equation_two = {(point_two.x*point_two.x)%m, point_two.x, point_two.y};
    struct linear_equation equation_three = {(point_three.x*point_three.x)%m, point_three.x, point_three.y};
    struct linear_equation equation_two_and_one = linear_equation_add(equation_two, equation_one);
    struct linear_equation equation_two_and_three = linear_equation_add(equation_two, equation_three);
    unsigned long coefficient_b_lcm = least_common_multiple(equation_two_and_one.coefficient_b, equation_two_and_three.coefficient_b); // printf("\nCalculated lcm as: %lu\n", coefficient_b_lcm);
    struct linear_equation modified_two_and_one = multiply_values_by(equation_two_and_one, coefficient_b_lcm / equation_two_and_one.coefficient_b);
    struct linear_equation modified_two_and_three = multiply_values_by(equation_two_and_three, coefficient_b_lcm / equation_two_and_three.coefficient_b);
    struct linear_equation final_linear_equation = linear_equation_add(modified_two_and_one, modified_two_and_three);
    // ^^ Prepare all the required linear equations

    // ... continuation of program :
    unsigned division_intermediary;

    division_intermediary = final_linear_equation.result; while (division_intermediary % final_linear_equation.coefficient_a != 0) division_intermediary += m;
    unsigned long retrieved_a = division_intermediary / final_linear_equation.coefficient_a; retrieved_a %= m; // << Check if may be ommited
    if (retrieved_a != a) // return -5 if the quadratic formula parameter 'a' had been incorrectly inferred from the 3 coordinate points (the 3-N in this k = 3 3-N Shamir Secret Sharing Sceme)
    { fprintf(stderr, "\nThe value that I inferred from coordinate points for variable 'a' did not correspond to the variable 'a' that was used to plot the points. %lu != %lu. Exiting.\n", retrieved_a, a); return -5; }
    // ^^ Prove that a can be successfully derived from these linear equations by not returning here

    division_intermediary = (equation_two_and_one.result+(m-((equation_two_and_one.coefficient_a*retrieved_a)%m)))%m; while (division_intermediary % equation_two_and_one.coefficient_b != 0) division_intermediary += m;
    unsigned long retrieved_b = division_intermediary / equation_two_and_one.coefficient_b; retrieved_b %= m;
    if (retrieved_b != b) // return -6 is the quadratic formula parameter 'b' had been incorrectly inferred from the 3 coordinate points
    { fprintf(stderr, "The value that I inferred from coordinate points for variable 'b' did not correspond to the variable 'b' that was used to plot the points. %lu != %lu. Exiting.\n", retrieved_b, b); return -6; }
    // ^^ Prove that b can be successfully derived from these linear equations by not returning here either

    unsigned long retrieved_C = (equation_one.result + (m - (((retrieved_b * point_one.x) % m ) + ((((point_one.x * point_one.x) % m ) * a) % m )) % m )) % m;
    if (c != retrieved_C) { fprintf(stderr, "%lu != %lu\n", retrieved_C, c); return -7; }
    else fprintf(stdout, "\nSecret curve parameter value: %lu.\n", retrieved_C); return 0;
}
