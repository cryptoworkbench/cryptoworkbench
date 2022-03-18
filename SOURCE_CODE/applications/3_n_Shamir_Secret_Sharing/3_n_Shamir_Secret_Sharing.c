/* This is my attemp at implementing 3-n Shamir Secret Sharing.
 *
 * This little project has been inspired by:
 * 1). https://www.youtube.com/watch?v=iFY5SyY3IMQ	"Secret Sharing Explained Visually" (yt channel "Art of the Problem")
 * 2). https://www.youtube.com/watch?v=K54ildEW9-Q	"How to keep an open secret with mathematics." (yt channel "Stand-up Maths")
 * 3). https://www.youtube.com/watch?v=ohc1futhFYM	"Equation of Parabola Given 3 Points (System of Equations)" (yt channel "Mario's Math Tutoring")
 *
 * For example try:
 * ./plot_polynomial 31 1 2 3
 *
 * Then select points one, two and three:
 * ./3_n_Shamir_Secret_Sharing 31 1 6 2 17 3 3
 *
 * 3_n_Shamir_Secret_Sharing will recover that a was 3, b was 2, and the secret encoded on the y axis (c) was 1.
 *
 * Another example:
 * ./plot_polynomial 101 3 2 12
 *
 * ./3_n_Shamir_Secret_Sharing 101 95 7 96 77 97 52
 *
 * This will tell that c was 12.
 *
 * DEVELOPER NOTICE #1:
 * I want to switch this TOOL over from 'mod_polynomial' to 'mod_polynomial'
 *
 * DEVELOPER NOTICE #2:
 * Didn't work with:
 * 17 7 2 6 2 15 11
 *
 * But should have yielded:
 * a = 15, b = 9, c = 3
 *
 * Yields a floating point exception instead.
 */
#include <stdio.h>
#include <stdlib.h> // 'exit()'
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.extended.h"
#include "../../libraries/mathematics/shamir_secret_sharing.h"
#define K 3

void __last_y_failed_to_parse() { fprintf(stderr, "Please provide as seventh argument the y coordinate of last point!"); }
void __last_x_failed_to_parse() { fprintf(stderr, "Please provide as sixth argument the x coordinate of last point!"); }
void second_y_failed_to_parse() { fprintf(stderr, "Please provide as fifth argument the y coordinate of second point!"); }
void second_x_failed_to_parse() { fprintf(stderr, "Please provide as fourth argument the x coordinate of second point!"); }
void _first_y_failed_to_parse() { fprintf(stderr, "Please provide as third argument the y coordinate of first point!"); }
void _first_x_failed_to_parse() { fprintf(stderr, "Please provide as second argument the x coordinate of first point!"); }
void _____mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument a finite field specification!"); }

int main(int argc, char **argv) { SET_k(K);
    unsigned long mod; conditional_goodbye(n(n(error_specification(_____mod_failed_to_parse, n(ul_parse_str(           &mod, argv[1], -1)))))); mod_ = &mod; unsigned long **equation = equations_ALLOCATE(K);
                       conditional_goodbye(n(n(error_specification(_first_x_failed_to_parse, n(ul_parse_str(1 + equation[0], argv[2], -2))))));
                       conditional_goodbye(n(n(error_specification(_first_y_failed_to_parse, n(ul_parse_str(0 + equation[0], argv[3], -3))))));
                       conditional_goodbye(n(n(error_specification(second_x_failed_to_parse, n(ul_parse_str(1 + equation[1], argv[4], -4))))));
                       conditional_goodbye(n(n(error_specification(second_y_failed_to_parse, n(ul_parse_str(0 + equation[1], argv[5], -5))))));
                       conditional_goodbye(n(n(error_specification(__last_x_failed_to_parse, n(ul_parse_str(1 + equation[2], argv[6], -6))))));
                       conditional_goodbye(n(n(error_specification(__last_y_failed_to_parse, n(ul_parse_str(0 + equation[2], argv[7], -7))))));
    if (8 < argc) ignored_arguments(argc, argv, 7); // complain and about unneccesary command line arguments <--
    // interpret command line arguments ^

    fprintf(stdout, "Supplied mappings:\n%lu -> %lu\n%lu -> %lu\n%lu -> %lu\n\n", equation[0][1], equation[0][0], equation[1][1], equation[1][0], equation[2][1], equation[2][0]);
    // display coordinate points ('mapping behaviour samples') ^

    equation[0][2] = mod_exponentiate(equation[0][1], 2);
    equation[1][2] = mod_exponentiate(equation[1][1], 2);
    equation[2][2] = mod_exponentiate(equation[2][1], 2);

    equation[0][3] = equation[1][3] = equation[2][3] = 1;
    // ^ Prepare initial equations

    unsigned long *equation_ONE_and_TWO = coefficient_cancel(equation[0], equation[1], 3); 
    unsigned long *equation_TWO_and_THREE = coefficient_cancel(equation[1], equation[2], 3);
    unsigned long *final_linear_equation = coefficient_cancel(equation_ONE_and_TWO, equation_TWO_and_THREE, 1);
    // ^ Prepare other equations

    unsigned long *coefficient = UL_array_of_SIZE(K);
    coefficient[0] = mod_divide(final_linear_equation[0], final_linear_equation[2]);
    coefficient[1] = mod_divide(mod_subtract(equation_ONE_and_TWO[0], mod_multiply(equation_ONE_and_TWO[2], coefficient[0])), equation_ONE_and_TWO[1]);
    coefficient[2] = mod_subtract(equation[0][0], mod_add(mod_multiply(coefficient[1], equation[0][1]), (mod_multiply(coefficient[0], _exponentiate(equation[0][1], 2, mod)))));
    // ^ Put the coefficients into an unsigned long array

    fprintf(stdout, "Second-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", mod);
    fprintf(stdout, "f(x) \u2261 %lu * x^2 + %lu * x + %lu	(modulus %lu)\n", coefficient[0], coefficient[1], coefficient[2], mod);
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", mod_polynomial(0, coefficient, K));
    free(coefficient); equations_DELETE(equation); return 0;
}
