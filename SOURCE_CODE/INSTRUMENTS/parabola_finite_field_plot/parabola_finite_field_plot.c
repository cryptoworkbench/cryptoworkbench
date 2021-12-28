/* Working.
 *
 * Lacks exit() test like the linear one does. But maybe that is good.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"

unsigned long Mod, A, B, _secret_C;

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

void secret_reduce() { if (_secret_C >= Mod) { _secret_C %= Mod; printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", Mod, _secret_C); } }

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &Mod)) { printf("%s is not Mod!\n", argv[1]); exit(-1); }
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &A)) { printf("%s is not A!\n", argv[2]); exit(-2); } A %= Mod;
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &B)) { printf("%s is not B!\n", argv[3]); exit(-3); } B %= Mod;
    if (4 < argc) {
	if (STR_could_be_parsed_into_UL(argv[4], &_secret_C)) secret_reduce();
	else { printf("The secret '%s' has not yet been transformed into numerical form!\n", argv[4]); exit(-4); }
    } else { printf("Now please put in your secret less than %lu: ", Mod); fscanf(stdin, "%lu", &_secret_C); secret_reduce(); }
    // ^^ Gather starting information

    fprintf(stdout, "Solutions for 'f(x) \u2261 %lux^2 + %lux + %lu (mod %lu)', in format [x, f(x)]:\n", A, B, _secret_C, Mod);
    for (unsigned long x = 0; x < Mod; x++) {
	struct cartesian_coordinates point_on_graph = {x, 0};
	unsigned long y = ((((((A * ((x * x) % Mod)) % Mod) + ((x * B) % Mod)) % Mod) + _secret_C) % Mod);
	printf("[%lu, %lu]\n", x, y);
    } fprintf(stdout, "\n"); // << ^ Calculate all coordinates for this parabola over this finite field

    struct cartesian_coordinates point_one, point_two, point_three;
    fprintf(stdout, "Point one, format [x, y]: ["); fscanf(stdin, "%lu, %lu]", &point_one.x, &point_one.y);
    fprintf(stdout, "Point two: ["); fscanf(stdin, " %lu, %lu]", &point_two.x, &point_two.y);
    fprintf(stdout, "Point three: ["); fscanf(stdin, " %lu, %lu]", &point_three.x, &point_three.y);

    fprintf(stdout, "\nPoints that I'm working with:\n");
    fprintf(stdout, "Point one   : [%lu, %lu]\n", point_one.x, point_one.y);
    fprintf(stdout, "Point two   : [%lu, %lu]\n", point_two.x, point_two.y);
    fprintf(stdout, "Point three : [%lu, %lu]\n", point_three.x, point_three.y);

    struct linear_equation equation_one = { (point_one.x * point_one.x) % Mod, point_one.x, point_one.y };
    struct linear_equation equation_two = { (point_two.x * point_two.x) % Mod, point_two.x, point_two.y };
    struct linear_equation equation_three = { (point_three.x * point_three.x) % Mod, point_three.x, point_three.y }; printf("\n");
    printf("Linear equation one           : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", equation_one.result, equation_one.coefficient_a, equation_one.coefficient_b, Mod);
    printf("Linear equation two           : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", equation_two.result, equation_two.coefficient_a, equation_two.coefficient_b, Mod);
    printf("Linear equation three         : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", equation_three.result, equation_three.coefficient_a, equation_three.coefficient_b, Mod);

    struct linear_equation equation_two_and_one = linear_equation_add(equation_two, equation_one);
    struct linear_equation equation_two_and_three = linear_equation_add(equation_two, equation_three); printf("\n");
    printf("Linear equation two and one   : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", equation_two_and_one.result, equation_two_and_one.coefficient_a, equation_two_and_one.coefficient_b, Mod);
    printf("Linear equation two and three : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n\n", equation_two_and_three.result, equation_two_and_three.coefficient_a, equation_two_and_three.coefficient_b, Mod);

    unsigned long coefficient_b_lcm = least_common_multiple(equation_two_and_one.coefficient_b, equation_two_and_three.coefficient_b);
    printf("\nCalculated lcm as: %lu\n", coefficient_b_lcm);

    struct linear_equation modified_two_and_one = multiply_values_by(equation_two_and_one, coefficient_b_lcm / equation_two_and_one.coefficient_b);
    struct linear_equation modified_two_and_three = multiply_values_by(equation_two_and_three, coefficient_b_lcm / equation_two_and_three.coefficient_b);
    printf("Linear equation two and one   : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", modified_two_and_one.result, modified_two_and_one.coefficient_a, modified_two_and_one.coefficient_b, Mod);
    printf("Linear equation two and three : %lu - c \u2261 %lu (x^2) + %lu (x) (mod %lu)\n", modified_two_and_three.result, modified_two_and_three.coefficient_a, modified_two_and_three.coefficient_b, Mod);

    struct linear_equation final_linear_equation = linear_equation_add(modified_two_and_one, modified_two_and_three);
    printf("Final linear equation         : %lu - c \u2261 %lu (x^2) (mod %lu)\n", final_linear_equation.result, final_linear_equation.coefficient_a, Mod);

    unsigned pre_A = final_linear_equation.result;
    while (pre_A % final_linear_equation.coefficient_a != 0) pre_A += Mod;
    unsigned long retrieved_A = pre_A / final_linear_equation.coefficient_a; printf("\nA: %lu\n", retrieved_A);
    // ^^ Okay so we can successfully figure out A!, now we must move on to figuring out B based on A

    unsigned long pre_B = equation_two_and_one.result + (Mod - ((equation_two_and_one.coefficient_a * retrieved_A)) % Mod);
    while (pre_B % equation_two_and_one.coefficient_b != 0) pre_B += Mod;
    unsigned long retrieved_B = pre_B / equation_two_and_one.coefficient_b;
    printf("B: %lu\n", retrieved_B);
    // ^^ Okay so we can successfully figure out B!, now we must move on to figuring out C based on B
    return 0;
}
