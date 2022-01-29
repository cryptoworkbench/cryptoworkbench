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

/* Complimentary developers notes:
 * Supplying a point with coordinate x = 0, the general formula still seems to work for 2-n SSSS.
 * I wrote '3_n_Shamir_Secret_Sharing.c' in a similar manner but for 3-n SSSS it seems to be the case that this is not always the case. (and it is if I wrote it properly).
 */
#include <stdio.h>
#include <unistd.h> // 'execvp()'
#include "../../libraries/functional/string.h" // 'ignored_arguments()'
#include "../../libraries/mathematics/maths.h" // 'inverse()'
#include "../../libraries/mathematics/SSSS.h"
#define K 2 // degree of polynomial that is resolved in other to retrieve secret encoded as contant term
#define EXTERNAL_PROGRAM "polynomial_function_map_over_GF"

void equation_print(unsigned long **equation) { printf("%lu = ", *equation[0]); int i = 1; while (equation[i]) { printf("%lu + ", *equation[i]); i++; } printf("c"); }

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_LOCATION_OF_mod())) { printf("%s is not mod!\n", argv[1]); exit(-1); }
    if (6 < argc) { ignored_arguments(argc, argv, 5); argc = 6; } // < complain about unneccesary arguments and forget about them once and for all
    unsigned long ***equations = equations_ALLOCATE(K); switch (argc) {
	case 6: if (!str_represents_ul(argv[5], equations[1][0])) fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of second point.\n", argv[5]);
	case 5: if (!str_represents_ul(argv[4], equations[1][1])) fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of second point.\n", argv[4]);
	case 4: if (!str_represents_ul(argv[3], equations[0][0])) fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of first point.\n", argv[3]);
	case 3: if (!str_represents_ul(argv[2], equations[0][1])) fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of first point.\n", argv[2]);
    };
    fprintf(stdout, "x_1 \u2261 "); if (2 < argc) fprintf(stdout, "%lu\n", *equations[0][1]); else fscanf(stdin, " %lu", equations[0][1]);
    fprintf(stdout, "y_1 \u2261 "); if (3 < argc) fprintf(stdout, "%lu\n", *equations[0][0]); else fscanf(stdin, " %lu", equations[0][0]); fprintf(stdout, "\n");
    fprintf(stdout, "x_2 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", *equations[1][1]); else fscanf(stdin, " %lu", equations[1][1]);
    fprintf(stdout, "y_2 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", *equations[1][0]); else fscanf(stdin, " %lu", equations[1][0]); fprintf(stdout, "\n");
    // unsigned long **equation_ONE_WITH_TWO = coefficient_cancel(equations[0], equations[1], 1);
    unsigned long **equation_ONE_WITH_TWO = equation_SUBTRACT(equations[0], equations[1]);
    // ^ Prepare equations

    unsigned long **coefficient = UL_array_with_INDEX(K);
    *coefficient[0] = modular_division(*equation_ONE_WITH_TWO[0], *equation_ONE_WITH_TWO[1]); // coefficient a
    *coefficient[1] = subtract(*equations[0][0], multiply(*equations[0][1], *coefficient[0])); // coefficient b

    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", _REPORT_mod());
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", *coefficient[0], *coefficient[1], _REPORT_mod());
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", polynomial_over_GF(coefficient, 0)); // 0 = x
    equation_DISCARD(coefficient);
    equations_DELETE(equations); return 0;
}
