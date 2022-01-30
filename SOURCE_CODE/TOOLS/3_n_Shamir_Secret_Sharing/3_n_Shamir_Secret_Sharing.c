/* This is my attemp at implementing 3-n Shamir Secret Sharing.
 *
 * This little project has been inspired by:
 * 1). https://www.youtube.com/watch?v=iFY5SyY3IMQ	"Secret Sharing Explained Visually" (yt channel "Art of the Problem")
 * 2). https://www.youtube.com/watch?v=K54ildEW9-Q	"How to keep an open secret with mathematics." (yt channel "Stand-up Maths")
 * 3). https://www.youtube.com/watch?v=ohc1futhFYM	"Equation of Parabola Given 3 Points (System of Equations)" (yt channel "Mario's Math Tutoring")
 *
 * HOWEVER, this code does not always work properly. Consider the following two arguments:
 * 1). polynomial_over_GF 13 9 7 5  && 3_n_Shamir_Secret_Sharing 13 1 8 2 3 3 3	
 * 2). polynomial_over_GF 13 9 7 5  && 3_n_Shamir_Secret_Sharing 13 1 8 2 3 4 8
 *
 * The first runs properly and correctly gives you the three variables needed.
 * The second does not.
 */
#include <stdio.h>
#include <stdlib.h> // 'exit()'
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/SSSS.h"
#define K 3

char *one = "%s is not a suitable value for the field modulus!\n\nExiting '-%lu'.\n";

void argv_ERROR(unsigned long index, char **argv) {
    char *error; switch (index) {
	case 1: error = one;
    }; fprintf(stderr, error, argv[index], index);
    exit(-index);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_LOCATION_OF_mod())) argv_ERROR(1, argv);
    if (8 < argc) { ignored_arguments(argc, argv, 7); argc = 8; } // < complain about unneccesary arguments and forget about them once and for all
    unsigned long ***equation = equations_ALLOCATE(K); switch (argc) {
	case 8: if (!str_represents_ul(argv[7], equation[2][0])) fprintf(stderr, "Failed to interpret argument '%s' as a y variable.\n", argv[7]);
	case 7: if (!str_represents_ul(argv[6], equation[2][1])) fprintf(stderr, "Failed to interpret argument '%s' as a x variable.\n", argv[6]);
	case 6: if (!str_represents_ul(argv[5], equation[1][0])) fprintf(stderr, "Failed to interpret argument '%s' as a y coordinate.\n", argv[5]);
	case 5: if (!str_represents_ul(argv[4], equation[1][1])) fprintf(stderr, "Failed to interpret argument '%s' as a x coordinate.\n", argv[4]);
	case 4: if (!str_represents_ul(argv[3], equation[0][0])) fprintf(stderr, "Failed to interpret argument '%s' as a y coordinate.\n", argv[3]);
	case 3: if (!str_represents_ul(argv[2], equation[0][1])) fprintf(stderr, "Failed to interpret argument '%s' as a x coordinate.\n", argv[2]);
    }; // ^ Interpreted interpretable information
    fprintf(stdout, "x_1 \u2261 "); if (2 < argc) fprintf(stdout, "%lu\n", *equation[0][1]); else fscanf(stdin, " %lu", equation[0][1]);
    fprintf(stdout, "y_1 \u2261 "); if (3 < argc) fprintf(stdout, "%lu\n", *equation[0][0]); else fscanf(stdin, " %lu", equation[0][0]); fprintf(stdout, "\n");
    fprintf(stdout, "x_2 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", *equation[1][1]); else fscanf(stdin, " %lu", equation[1][1]);
    fprintf(stdout, "y_2 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", *equation[1][0]); else fscanf(stdin, " %lu", equation[1][0]); fprintf(stdout, "\n");
    fprintf(stdout, "x_3 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", *equation[2][1]); else fscanf(stdin, " %lu", equation[2][1]);
    fprintf(stdout, "y_3 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", *equation[2][0]); else fscanf(stdin, " %lu", equation[2][0]); fprintf(stdout, "\n");
    *equation[0][2] = exponentiate(*equation[0][1], 2, _REPORT_mod()); *equation[1][2] = exponentiate(*equation[1][1], 2, _REPORT_mod()); *equation[2][2] = exponentiate(*equation[2][1], 2, _REPORT_mod());
    *equation[0][3] = *equation[1][3] = *equation[2][3] = 1;
    // ^ Prepared initial equations

    unsigned long **equation_ONE_and_TWO = coefficient_cancel(equation[0], equation[1], 3); 
    unsigned long **equation_TWO_and_THREE = coefficient_cancel(equation[1], equation[2], 3);
    unsigned long **final_linear_equation = coefficient_cancel(equation_ONE_and_TWO, equation_TWO_and_THREE, 1);
    // ^ Prepared other equations

    unsigned long **coefficient = UL_array_of_SIZE(K); *coefficient[0] = division(*final_linear_equation[0], *final_linear_equation[2]);
    *coefficient[1] = division(subtract(*equation_ONE_and_TWO[0], mod_multiply(*equation_ONE_and_TWO[2], *coefficient[0])), *equation_ONE_and_TWO[1]);
    *coefficient[2] = subtract(*equation[0][0], mod_add(mod_multiply(*coefficient[1], *equation[0][1]), (mod_multiply(*coefficient[0], exponentiate(*equation[0][1], 2, _REPORT_mod())))));
    // ^ Put the coefficients into an unsigned long array

    fprintf(stdout, "Second-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", _REPORT_mod());
    fprintf(stdout, "f(x) \u2261 %lu * x^2 + %lu * x + %lu	(modulus %lu)\n", *coefficient[0], *coefficient[1], *coefficient[2], _REPORT_mod());
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", polynomial_over_GF(coefficient, 0));
    equations_DELETE(equation); return 0;
    // ^ Finalize program
}
