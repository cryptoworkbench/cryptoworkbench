/* This is a proof of concept for 3-n Shamir Secret Sharing (which is based on 2-nd degree polynomials over finite fields).
 *
 * This little project has been inspired by:
 * 1). https://www.youtube.com/watch?v=iFY5SyY3IMQ	"Secret Sharing Explained Visually" (yt channel "Art of the Problem")
 * 2). https://www.youtube.com/watch?v=K54ildEW9-Q	"How to keep an open secret with mathematics." (yt channel "Stand-up Maths")
 * 3). https://www.youtube.com/watch?v=ohc1futhFYM	"Equation of Parabola Given 3 Points (System of Equations)" (yt channel "Mario's Math Tutoring")
 */
#include <stdio.h>
#include <stdlib.h> // 'exit()'
#include <unistd.h> // 'execvp()'
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h"
ul MOD = 0;

unsigned long a, b, c;

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
    return_value.coefficient_a = (multiplier * INP.coefficient_a) % MOD;
    return_value.coefficient_b = (multiplier * INP.coefficient_b) % MOD;
    return_value.result = (multiplier * INP.result) % MOD;
    return return_value;
}

struct linear_equation linear_equation_add(struct linear_equation equation_one, struct linear_equation equation_two) {
    struct linear_equation ret;
    ret.coefficient_a = (equation_one.coefficient_a + (MOD - equation_two.coefficient_a)) % MOD;
    ret.coefficient_b = (equation_one.coefficient_b + (MOD - equation_two.coefficient_b)) % MOD;
    ret.result = (equation_one.result + (MOD - equation_two.result)) % MOD;
    return ret;
}

void C_reduce() { if (c >= MOD) { c%=MOD; fprintf(stdout, "The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", MOD, c); } }

char *one = "%s is not a suitable value for the field modulus!\n\nExiting '-%lu'.\n";
char *two = "%s is not a suitable value for the second-degree polynomial parameter 'a'!\n\nExiting '-%lu'.\n";
char *three = "%s is not a suitable value for the second-degree polynomial parameter 'b'!\n\nExiting '-%lu'.\n";
char *intermediate_error = "The value that I inferred from coordinate points for variable '%c' did not correspond to the variable '%c' that was used to plot the points. %lu != %lu. Exiting '-%lu'.\n";

void argv_ERROR(unsigned long index, char **argv) {
    char *error; switch (index) {
	case 1: error = one; break;
	case 2: error = two; break;
	case 3: error = three;
    }; fprintf(stderr, error, argv[index], index);
    exit(-index);
}

void algebra_check_for_supposed_variable_against(char variable_symbol, unsigned long new, unsigned long original) {
    if (new != original) {
	switch (variable_symbol) {
	    case 'a': fprintf(stderr, intermediate_error, variable_symbol, variable_symbol, new, original, 5); exit(-5);
	    case 'b': fprintf(stderr, intermediate_error, variable_symbol, variable_symbol, new, original, 6); exit(-6);
	    case 'c': fprintf(stderr, intermediate_error, variable_symbol, variable_symbol, new, original, 7); exit(-7);
	};
    }
}

const char *prog_name = "polynomial_function_map_over_GF";

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) argv_ERROR(1, argv);
    // ^^ Gather starting information

    fprintf(stdout, "Give me three function inputs and outputs:\n"); struct cartesian_coordinates point_one, point_two, point_three;
    fprintf(stdout, "f(a): "); fscanf(stdin, "%lu", &point_one.y); fprintf(stdout, "a   : "); fscanf(stdin, "%lu", &point_one.x);
    fprintf(stdout, "\nf(b): "); fscanf(stdin, "%lu", &point_two.y); fprintf(stdout, "b   : "); fscanf(stdin, "%lu", &point_two.x);
    fprintf(stdout, "\nf(c): "); fscanf(stdin, "%lu", &point_three.y); fprintf(stdout, "c   : "); fscanf(stdin, "%lu", &point_three.x);

    // fprintf(stdout, "Parabola plot of second-degree polynomial over \U0001D53D %lu:\n", MOD);
    struct linear_equation equation_one = {(point_one.x*point_one.x)%MOD, point_one.x, point_one.y};
    struct linear_equation equation_two = {(point_two.x*point_two.x)%MOD, point_two.x, point_two.y};
    struct linear_equation equation_three = {(point_three.x*point_three.x)%MOD, point_three.x, point_three.y};
    struct linear_equation equation_two_and_one = linear_equation_add(equation_two, equation_one);
    struct linear_equation equation_two_and_three = linear_equation_add(equation_two, equation_three);
    unsigned long coefficient_b_lcm = least_common_multiple(equation_two_and_one.coefficient_b, equation_two_and_three.coefficient_b);
    struct linear_equation final_linear_equation = linear_equation_add(multiply_values_by(equation_two_and_one, coefficient_b_lcm / equation_two_and_one.coefficient_b), multiply_values_by(equation_two_and_three, coefficient_b_lcm / equation_two_and_three.coefficient_b));
    // ^^ Prepare all the required linear equations

    ul a = modular_division(final_linear_equation.result, final_linear_equation.coefficient_a) % MOD;
    ul b = modular_division((equation_two_and_one.result + (MOD - ((equation_two_and_one.coefficient_a * a) % MOD))) % MOD, equation_two_and_one.coefficient_b) % MOD;
    ul c = (equation_one.result + (MOD - (((b * point_one.x) % MOD ) + ((((point_one.x * point_one.x) % MOD ) * a) % MOD )) % MOD )) % MOD;

    fprintf(stdout, "\nf(x) \u2261 %lu * x^2 + %lu * x + %lu	(%% %lu)		\u21D2 THE SHARED SECRET WAS %lu.\n", a, b, c, MOD, c);
    return 0;
}
