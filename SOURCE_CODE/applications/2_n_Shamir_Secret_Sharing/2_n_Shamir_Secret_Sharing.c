/* DEVELOPER NOTICE #1:
 * I want to switch this TOOL over from 'mod_polynomial' to 'mod_polynomial'
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
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/math.extended.h"
#include "../../libraries/mathematics/shamir_secret_sharing.h"
#define K 2 // degree of polynomial that is resolved in other to retrieve secret encoded as contant term

unsigned long **equation; unsigned long mod;

void _last_y_failed_to_parse() { fprintf(stderr, "Please provide as fifth argument the y coordinate of second point!"); equations_DELETE(equation); }
void _last_x_failed_to_parse() { fprintf(stderr, "Please provide as fourth argument the x coordinate of second point!"); equations_DELETE(equation); }
void first_y_failed_to_parse() { fprintf(stderr, "Please provide as third argument the y coordinate of first point!"); equations_DELETE(equation); }
void first_x_failed_to_parse() { fprintf(stderr, "Please provide as second argument the x coordinate of first point!"); equations_DELETE(equation); }
void ______________mod_error() { fprintf(stderr, "Please provide as first argument a finite field specification!", (*argv_ptr)[1]); }

// index[0]: y coordinate
// index[1]: x coordinate
// index[2]: c variable

int main(int argc, char **argv) { mod = ADDITIVE_IDENTITY; argv_ptr = &argv; SET_k(K);
    conditional_goodbye(n(n(error_specification(______________mod_error, n(ul_parse_str(&mod,            argv[1], -1)))))); mod_ = &mod; equation = equations_ALLOCATE(K);
    conditional_goodbye(n(n(error_specification(first_x_failed_to_parse, n(ul_parse_str(1 + equation[0], argv[2], -2))))));
    conditional_goodbye(n(n(error_specification(first_y_failed_to_parse, n(ul_parse_str(0 + equation[0], argv[3], -3))))));
    conditional_goodbye(n(n(error_specification(_last_x_failed_to_parse, n(ul_parse_str(1 + equation[1], argv[4], -4))))));
    conditional_goodbye(n(n(error_specification(_last_y_failed_to_parse, n(ul_parse_str(0 + equation[1], argv[5], -5))))));
    if (6 < argc) ignored_arguments(argc, argv, 5); fprintf(stdout, "Supplied sample mappings:\n%lu -> %lu\n%lu -> %lu\n\n", equation[0][1], equation[0][0], equation[1][1], equation[1][0]);
    // handle terminal inputs ^ 

    equation[0][K] = equation[1][K] = 1; unsigned long *equation_ONE_WITH_TWO = coefficient_cancel(equation[0], equation[1], 2);
    // prepare equations ^

    unsigned long *coefficient = UL_array_of_SIZE(K); // make an alternate version which DOES yield a zero terminated ul string <--
    coefficient[0] = mod_divide(equation_ONE_WITH_TWO[0], equation_ONE_WITH_TWO[1]); // the difference in y <-
    coefficient[1] = mod_subtract(equation[0][0], mod_multiply(equation[0][1], coefficient[0]));

    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", mod);
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", coefficient[0], coefficient[1], mod);
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", mod_polynomial(0, coefficient, K));
    // fprintf(stdout, "\nThe shared secret was '%lu'.\n", mod_polynomial(0, coefficient, K)); for some reason does not work with 
    free(coefficient); equations_DELETE(equation); return 0;
}
