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
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h" // 'ignored_arguments()'
#include "../../libraries/mathematics/maths.h" // 'inverse()'
ul MOD; // < handle library inclusions ^^

#define EXTERNAL_PROGRAM "polynomial_function_map_over_GF"

unsigned long a, _secret_B;

struct cartesian_coordinates {
    unsigned long x;
    unsigned long y;
};

void secret_reduce() { if (_secret_B >= MOD) { _secret_B %= MOD; printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", MOD, _secret_B); } }

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], MOD_LOCATION_REPORT())) { printf("%s is not MOD!\n", argv[1]); exit(-1); }
    if (6 < argc) { ignored_arguments(argc, argv, 5); argc = 6; } // < complain about unneccesary arguments and forget about them once and for all
    struct cartesian_coordinates first_sample_mapping, second_sample_mapping;
    switch (argc) {
	case 6: if (!str_represents_ul(argv[5], &second_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of second point.\n", argv[5]); }
	case 5: if (!str_represents_ul(argv[4], &second_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of second point.\n", argv[4]); }
	case 4: if (!str_represents_ul(argv[3], &first_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of first point.\n", argv[3]); }
	case 3: if (!str_represents_ul(argv[2], &first_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of first point.\n", argv[2]); }
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

    unsigned long Y_difference = add(first_sample_mapping.y, inverse(second_sample_mapping.y));
    unsigned long X_difference = add(first_sample_mapping.x, inverse(second_sample_mapping.x));
    ul a = modular_division(Y_difference, X_difference);
    ul b = add(first_sample_mapping.y, inverse(multiply(first_sample_mapping.x, a)));
    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", MOD);
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", a, b, MOD);
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", polynomial_over_GF(0, 2, a, b));
    return 0;
}
