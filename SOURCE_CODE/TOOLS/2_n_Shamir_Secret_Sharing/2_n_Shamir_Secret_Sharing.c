/* DEVELOPER NOTICE #1:
 * I want to switch this TOOL over from 'mod_polynomial' to 'mod_Polynomial'
 *
 * DEVELOPER NOTICE #2:
 * executing 'clear && polynomial_plot 13 9 7 && 2_n_Shamir_Secret_Sharing 13 1 3 4 4'
 *
 * Gives a curious result:
 * a is calculated incorrectly but b is calculated correctly (a will be 4 instead of 9).
 */

/* DEVELOPER NOTICE #0:
 * Supplying a point with coordinate x = 0, the general formula still seems to work for 2-n SSSS.
 * I wrote '3_n_Shamir_Secret_Sharing.c' in a similar manner but for 3-n SSSS it seems to be the case that this is not always the case. (and it is if I wrote it properly).
 */

/* A first degree polynomial function is obviously of the form:
 * "f(x) = A * X^1 + B * X^0"
 *
 * A.k.a.
 * "f(x) = A * X^1 + B * 1"
 *
 * A.k.a.
 * "f(x) = A * X^1 + B"
 *
 * A.k.a. "A LINEAR EQUATION!"
 *
 * THIS PROGRAM takes the mod value and the value for A from the command line arguments.
 * Then it determines what linear equation to use based on which number you wished to split/encode.
 * Then it prints out the coordinates of this linear curve over the finite field defined by the mod value.
 *
 * The user then will choose what two points (which are obviously never "f(0)" (!) ) this proof of concept program should proceed to work with.
 *
 * The program then:
 * #1). Determines 'A' again (verifies* 'A') from these two specified points [* verification by program termination: if 'A' calculated again is not the same, the program terminates; THIS PROOF CONCEPT]
 * #2). Determines "f(0)" using the Mod value and this set of coordinates. This equates to the calculation of the linear equation (first degree polynomial) parameter 'B'
 */
#include <stdio.h>
#include <unistd.h> // 'execvp()'
#include "../../libraries/functional/string.h" // 'ignored_arguments()'
#include "../../libraries/mathematics/maths.h" // 'mod_inverse()'
#include "../../libraries/mathematics/shamir_secret_sharing.h"
#define K 2 // degree of polynomial that is resolved in other to retrieve secret encoded as contant term

void second_second() { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of second point."); }
void second_first() { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of second point."); }
void first_second() { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of first point."); }
void first_first() { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of first point."); }

void mod_error() { fprintf(stderr, "%s is not mod!", unparsed_arg); }

int main(int argc, char **argv) {
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(argv[1], &mod, -1)))))); mod_ = &mod;
    if (6 < argc) { ignored_arguments(argc, argv, 5); argc = 6; } // < complain about unneccesary arguments and forget about them once and for all
    unsigned long ***equation = equations_ALLOCATE(K); switch (argc) {
	case 6: conditional_goodbye(n(n(error_specification(second_second, n(str_represents_ul_(argv[5], equation[1][0], 0))))));
	case 5: conditional_goodbye(n(n(error_specification(second_first, n(str_represents_ul_(argv[4], equation[1][1], 0))))));
	case 4: conditional_goodbye(n(n(error_specification(first_second, n(str_represents_ul_(argv[3], equation[0][0], 0))))));
	case 3: conditional_goodbye(n(n(error_specification(first_first, n(str_represents_ul_(argv[2], equation[0][1], 0))))));
    }; // ^ interpret interpretable information
    fprintf(stdout, "x_1 \u2261 "); if (2 < argc) fprintf(stdout, "%lu\n", *equation[0][1]); else fscanf(stdin, " %lu", equation[0][1]);
    fprintf(stdout, "y_1 \u2261 "); if (3 < argc) fprintf(stdout, "%lu\n", *equation[0][0]); else fscanf(stdin, " %lu", equation[0][0]); fprintf(stdout, "\n");
    fprintf(stdout, "x_2 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", *equation[1][1]); else fscanf(stdin, " %lu", equation[1][1]);
    fprintf(stdout, "y_2 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", *equation[1][0]); else fscanf(stdin, " %lu", equation[1][0]); fprintf(stdout, "\n");
    *equation[0][K] = *equation[1][K] = 1; unsigned long **equation_ONE_WITH_TWO = coefficient_cancel(equation[0], equation[1], 2);
    // ^ Prepare equations

    unsigned long **coefficient = UL_array_of_SIZE(K);
    *coefficient[0] = mod_divide(*equation_ONE_WITH_TWO[0], *equation_ONE_WITH_TWO[1]); // coefficient a
    *coefficient[1] = mod_subtract(*equation[0][0], mod_multiply(*equation[0][1], *coefficient[0])); // coefficient b

    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", mod);
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", *coefficient[0], *coefficient[1], mod);
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", mod_polynomial(coefficient, 0)); // 0 = x
    equation_DISCARD(coefficient);
    equations_DELETE(equation); return 0;
}
