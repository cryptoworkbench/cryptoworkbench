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
#include "../../libraries/mathematics/maths.h"
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

struct linear_equation MULTIPLY(struct linear_equation INP, unsigned long multiplier) {
    struct linear_equation return_value;
    return_value.coefficient_a = (multiplier * INP.coefficient_a) % MOD;
    return_value.coefficient_b = (multiplier * INP.coefficient_b) % MOD;
    return_value.result = (multiplier * INP.result) % MOD;
    return return_value;
}

struct linear_equation INV(struct linear_equation EQUATION) {
    struct linear_equation ret;
    ret.coefficient_a = inverse(EQUATION.coefficient_a);
    ret.coefficient_b = inverse(EQUATION.coefficient_b);
    ret.result = inverse(EQUATION.result);
    return ret;
}

struct linear_equation ADD(struct linear_equation equation_one, struct linear_equation equation_two) {
    struct linear_equation ret;
    ret.coefficient_a = equation_one.coefficient_a + equation_two.coefficient_a;
    ret.coefficient_b = equation_one.coefficient_b + equation_two.coefficient_b;
    ret.result = equation_one.result + equation_two.result;
    // ^^ Add equations

    ret.coefficient_a %= MOD; ret.coefficient_b %= MOD; ret.result %= MOD;
    // ^^ But do not forget we are supposed to be doing this algebra in a finite field

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

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) argv_ERROR(1, argv);
    if (8 < argc) { ignored_arguments(argc, argv, 7); argc = 8; } // < complain about unneccesary arguments and forget about them once and for all
    struct cartesian_coordinates first_sample_mapping, second_sample_mapping, third_sample_mapping;
    switch (argc) {
	case 8:
	    if (!str_represents_ul(argv[7], &third_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as a y variable.\n", argv[7]); }
	case 7:
	    if (!str_represents_ul(argv[6], &third_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as a x variable.\n", argv[6]); }
	case 6:
	    if (!str_represents_ul(argv[5], &second_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as a y coordinate.\n", argv[5]); }
	case 5:
	    if (!str_represents_ul(argv[4], &second_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as a x coordinate.\n", argv[4]); }
	case 4:
	    if (!str_represents_ul(argv[3], &first_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as a y coordinate.\n", argv[3]); }
	case 3:
	    if (!str_represents_ul(argv[2], &first_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as a x coordinate.\n", argv[2]); }
	    break;
    }; // ^ Interpret interpretable information
    fprintf(stdout, "x_1 \u2261 ");
    if (2 < argc) fprintf(stdout, "%lu\n", first_sample_mapping.x);
    else fscanf(stdin, " %lu", &first_sample_mapping.x);

    fprintf(stdout, "y_1 \u2261 ");
    if (3 < argc) fprintf(stdout, "%lu\n", first_sample_mapping.y);
    else fscanf(stdin, " %lu", &first_sample_mapping.y); fprintf(stdout, "\n");

    fprintf(stdout, "x_2 \u2261 ");
    if (4 < argc) fprintf(stdout, "%lu\n", second_sample_mapping.x);
    else fscanf(stdin, " %lu", &second_sample_mapping.x);

    fprintf(stdout, "y_2 \u2261 ");
    if (5 < argc) fprintf(stdout, "%lu\n", second_sample_mapping.y);
    else fscanf(stdin, " %lu", &second_sample_mapping.y); fprintf(stdout, "\n");

    fprintf(stdout, "x_3 \u2261 ");
    if (4 < argc) fprintf(stdout, "%lu\n", third_sample_mapping.x);
    else fscanf(stdin, " %lu", &third_sample_mapping.x);

    fprintf(stdout, "y_3 \u2261 ");
    if (5 < argc) fprintf(stdout, "%lu\n", third_sample_mapping.y);
    else fscanf(stdin, " %lu", &third_sample_mapping.y); fprintf(stdout, "\n");
    // ^ Take in information

    fprintf(stdout, "Sample mappings of second-degree polynomial function over \U0001D53D%lu:\n", MOD);
    fprintf(stdout, "%lu -> %lu\n", first_sample_mapping.x, first_sample_mapping.y);
    fprintf(stdout, "%lu -> %lu\n", second_sample_mapping.x, second_sample_mapping.y);
    fprintf(stdout, "%lu -> %lu\n\n", third_sample_mapping.x, third_sample_mapping.y);
    // ^ Display information abstractly

    struct linear_equation equation_a = { exponentiation(first_sample_mapping.x, 2), exponentiation(first_sample_mapping.x, 1), first_sample_mapping.y};
    struct linear_equation equation_b = { exponentiation(second_sample_mapping.x, 2), exponentiation(second_sample_mapping.x, 1), second_sample_mapping.y};
    struct linear_equation equation_c = { exponentiation(third_sample_mapping.x, 2), exponentiation(third_sample_mapping.x, 1), third_sample_mapping.y};
    struct linear_equation equation_a_and_b = ADD(equation_a, INV(equation_b));
    struct linear_equation equation_b_and_c = ADD(equation_b, INV(equation_c));
    struct linear_equation final_linear_equation = ADD(equation_b_and_c, MULTIPLY(equation_a_and_b, modular_division(equation_a_and_b.coefficient_b, inverse(equation_b_and_c.coefficient_b))));

    ul a = modular_division(final_linear_equation.result, final_linear_equation.coefficient_a) % MOD;
    ul b = modular_division(add(equation_a_and_b.result, inverse(multiply(equation_a_and_b.coefficient_a, a))), equation_a_and_b.coefficient_b) % MOD;
    ul c = add(equation_a.result, inverse((add(multiply(b, first_sample_mapping.x), (multiply(a, exponentiation(first_sample_mapping.x, 2)))))));

    fprintf(stdout, "Derived from sample mappings under \U0001D53D%lu that the second-degree polynomial function responsible must have been:\n", MOD);
    fprintf(stdout, "f(x) \u2261 %lu * x^2 + %lu * x + %lu	(%% %lu)\n", a, b, c, MOD);

    fprintf(stdout, "\nSolution to 3_n Shamir Secret Sharing Sceme:\n");
    fprintf(stdout, "f(0) \u2261 %lu * 0^2 + %lu * 0^1 + %lu \u2261 %lu * 0 + %lu * 0 + %lu \u2261 0 + 0 + %lu \u2261 %lu	(mod %lu)\n\n", a, b, c, a, b, c, c, c, MOD);
    fprintf(stdout, "The secret  split / shared \\ encoded  is always the constant term in the polynomial, 'c' in this case; so the secret is (represented by) the numeric value '%lu'.\n", c);

    return 0;
}
