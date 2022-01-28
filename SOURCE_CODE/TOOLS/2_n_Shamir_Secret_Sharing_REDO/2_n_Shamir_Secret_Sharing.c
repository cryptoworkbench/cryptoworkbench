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

#define EXTERNAL_PROGRAM "polynomial_function_map_over_GF"

struct cartesian_coordinates {
    unsigned long x;
    unsigned long y;
};

void equation_DISCARD(unsigned long **equation) { int i; while (equation[i]) { free(equation[i]); i++; }; free(equation); }

int equation_length(unsigned long **equation) { int equation_length = 0; while (equation[equation_length]) equation_length++; return equation_length; }

unsigned long **equation_initialize(int required_size) {
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * (required_size + 1)); ret_val[required_size] = NULL;
    for (int i = 0; i < required_size; i++) ret_val[i] = (unsigned long *) malloc(sizeof(unsigned long)); return ret_val;
}

unsigned long **equation_ADD(unsigned long **equation_ONE, unsigned long **equation_TWO) { int LENGTH_OF_equation_ONE = equation_length(equation_ONE); int LENGTH_OF_equation_TWO = equation_length(equation_TWO);
    if (LENGTH_OF_equation_ONE != LENGTH_OF_equation_TWO) { fprintf(stderr, "equations had different length: %i vs %i", LENGTH_OF_equation_ONE, LENGTH_OF_equation_TWO); exit(-2); }
    unsigned long **resulting_equation = equation_initialize(LENGTH_OF_equation_ONE); for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = add(*equation_ONE[i], *equation_TWO[i]);return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_NEGATIVE(unsigned long **equation) {
    unsigned long **resulting_equation = equation_initialize(equation_length(equation));
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = inverse(*equation[i]);
    return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_SUBTRACT(unsigned long **equation_ONE, unsigned long **equation_TWO) {
    unsigned long **NEGATIVE_OF_equation_ONE = equation_NEGATIVE(equation_ONE);
    unsigned long **resulting_equation = equation_ADD(NEGATIVE_OF_equation_ONE, equation_TWO); equation_DISCARD(NEGATIVE_OF_equation_ONE);
    return resulting_equation;
}

void equation_print(unsigned long **equation) { printf("%lu = ", *equation[0]); int i = 1; while (equation[i]) { printf("%lu + ", *equation[i]); i++; } printf("c"); }

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], MOD_LOCATION_REPORT())) { printf("%s is not MOD!\n", argv[1]); exit(-1); }
    if (6 < argc) { ignored_arguments(argc, argv, 5); argc = 6; } // < complain about unneccesary arguments and forget about them once and for all
    struct cartesian_coordinates first_sample_mapping, second_sample_mapping;
    switch (argc) {
	case 6: if (!str_represents_ul(argv[5], &second_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of second point.\n", argv[5]); }
	case 5: if (!str_represents_ul(argv[4], &second_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of second point.\n", argv[4]); }
	case 4: if (!str_represents_ul(argv[3], &first_sample_mapping.y)) { fprintf(stderr, "Failed to interpret argument '%s' as y coordinate of first point.\n", argv[3]); }
	case 3: if (!str_represents_ul(argv[2], &first_sample_mapping.x)) { fprintf(stderr, "Failed to interpret argument '%s' as x coordinate of first point.\n", argv[2]); }
    };
    fprintf(stdout, "x_1 \u2261 "); if (2 < argc) fprintf(stdout, "%lu\n", first_sample_mapping.x); else fscanf(stdin, " %lu", &first_sample_mapping.x);
    fprintf(stdout, "y_1 \u2261 "); if (3 < argc) fprintf(stdout, "%lu\n", first_sample_mapping.y); else fscanf(stdin, " %lu", &first_sample_mapping.y); fprintf(stdout, "\n");
    fprintf(stdout, "x_2 \u2261 "); if (4 < argc) fprintf(stdout, "%lu\n", second_sample_mapping.x); else fscanf(stdin, " %lu", &second_sample_mapping.x);
    fprintf(stdout, "y_2 \u2261 "); if (5 < argc) fprintf(stdout, "%lu\n", second_sample_mapping.y); else fscanf(stdin, " %lu", &second_sample_mapping.y); fprintf(stdout, "\n");
    // ^ Got all information

    // unsigned long **equation_ONE = (unsigned long **) malloc(sizeof(unsigned long *) * 3); *(equation_ONE[0] = (unsigned long *) malloc(sizeof(unsigned long))) = first_sample_mapping.y;
    // *(equation_ONE[1] = (unsigned long *) malloc(sizeof(unsigned long))) = first_sample_mapping.x; equation_ONE[2] = 0;
    // ^ Prepare equation one

    unsigned long **equation_ONE = equation_initialize(2); *equation_ONE[0] = first_sample_mapping.y; *equation_ONE[1] = first_sample_mapping.x;
    unsigned long **equation_TWO = equation_initialize(2); *equation_TWO[0] = second_sample_mapping.y; *equation_TWO[1] = second_sample_mapping.x;
    // ^ Prepare equations based on supplied points

    unsigned long **equation_ONE_WITH_TWO = equation_SUBTRACT(equation_ONE, equation_TWO);
    unsigned long a = modular_division(*equation_ONE_WITH_TWO[0], *equation_ONE_WITH_TWO[1]);
    unsigned long b = subtract(first_sample_mapping.y, multiply(first_sample_mapping.x, a));

    fprintf(stdout, "First-degree polynomial function that follows the behaviour of supplied mappings over \U0001D53D%lu:\n", MOD_REPORT());
    fprintf(stdout, "f(x) \u2261 %lu * x + %lu	(modulus %lu)\n", a, b, MOD_REPORT());
    fprintf(stdout, "\nThe shared secret was '%lu'.\n", polynomial_over_GF(0, 2, b, a));
    return 0;
}
