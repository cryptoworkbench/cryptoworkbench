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
 * THIS PROGRAM takes the MOD value and the value for A from the command line arguments.
 * Then it determines what linear equation to use based on which number you wished to split/encode.
 * Then it prints out the coordinates of this linear curve over the finite field defined by the MOD value.
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
#include "../../libraries/mathematics/maths.h" // 'inverse()'
#define K 2 // degree of polynomial that is resolved in other to retrieve secret encoded as contant term
#define EXTERNAL_PROGRAM "polynomial_function_map_over_GF"

void equation_print(unsigned long **equation) { printf("%lu = ", *equation[0]); int i = 1; while (equation[i]) { printf("%lu + ", *equation[i]); i++; } printf("c"); }

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], MOD_LOCATION_REPORT())) { printf("%s is not MOD!\n", argv[1]); exit(-1); }
    if (6 < argc) { ignored_arguments(argc, argv, 5); argc = 6; } // < complain about unneccesary arguments and forget about them once and for all
    unsigned long **equation_ONE, **equation_TWO; equation_ONE = equation_initialize(K); equation_TWO = equation_initialize(K);
    switch (argc) {
	case 6: if (!str_represents_ul(argv[5], equation_TWO[0])) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of second point.\n", argv[5]); }
	case 5: if (!str_represents_ul(argv[4], equation_TWO[1])) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of second point.\n", argv[4]); }
	case 4: if (!str_represents_ul(argv[3], equation_ONE[0])) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of first point.\n", argv[3]); }
	case 3: if (!str_represents_ul(argv[2], equation_ONE[1])) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of first point.\n", argv[2]); }
    };
    fprintf(stdout, "x_1 \u2261 "); if (2 < argc) fprintf(stdout, "%lu\n", *equation_ONE[1]); else fscanf(stdin, " %lu", equation_ONE[1]);
    fprintf(stdout, "y_1 \u2261 "); if (3 < argc) fprintf(stdout, "%lu\n", *equation_ONE[0]); else fscanf(stdin, " %lu", equation_ONE[0]); fprintf(stdout, "\n");
    fprintf(stdout, "x_2 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", *equation_TWO[1]); else fscanf(stdin, " %lu", equation_TWO[1]);
    fprintf(stdout, "y_2 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", *equation_TWO[0]); else fscanf(stdin, " %lu", equation_TWO[0]); fprintf(stdout, "\n");
    // ^ Got all information at this point

    unsigned long **equation_ONE_WITH_TWO = equation_SUBTRACT(equation_ONE, equation_TWO);
    unsigned long a = modular_division(*equation_ONE_WITH_TWO[0], *equation_ONE_WITH_TWO[1]);
    unsigned long b = subtract(*equation_ONE[0], multiply(*equation_ONE[1], a));

    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", MOD_REPORT());
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", a, b, MOD_REPORT());
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", polynomial_over_GF(0, K, b, a));
    return 0;
}
