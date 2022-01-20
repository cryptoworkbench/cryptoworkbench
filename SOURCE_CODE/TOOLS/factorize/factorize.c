// CURRENT program operation (boring, but a good prototype / starting point):
// Factorizes 'argv[2]' based on the factorization method specified by 'argv[1]'.
//
// There are 5 factorization methods which 'argv[1]' can signify:
// ~ the least efficient form of trial division
// ~ the second to least efficient form of trial division
// ~ efficient trial division
// ~ factorization of odd composites using the difference of squares factorization method / approach
// ~ fermat factorization, which basically means:
//   		CASE #1). Applying the difference of squares approach when supplied with an odd number, or
//   		CASE #2). Factoring out the factors of two from the composite (dividing the composite by the greatest exponent of 2 not greater than the composite)
//
// INTENDED program operation:
// It interprets the intended factorization method from an external preferences file instead of from 'argv[1]'.
// Instead 'argv[1]' will be used for the composite, which makes more sense.
//
// The external file's specification of what factorization engine to use can be overruled by 'argv[2]' though.
// If 'argv[2]' is not a valid signification of what factorization engine to use, the default (externally specified!) factorization engine is used.
//
// When the program is ran for the first time it asks what factorization engine should be preferred and this is automatically saved to the external preferences file.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'factorization_method_WRAPPER()'
#include "../../libraries/mathematics/factorization_methods.h" // 'factorization_method_WRAPPER()'
ul MOD; // < This time we will use 'MOD' for the odd composite


char *most_inefficient_TRIAL_DIVISION = "most_inefficient_trial_division";
char *less_inefficient_TRIAL_DIVISION = "less_inefficient_trial_division";
char *least_inefficient_TRIAL_DIVISION = "least_inefficient_trial_division";
char *difference_of_squares_factorization_METHOD = "difference_of_squares_factorization_method";
char *fermats_factorization_METHOD = "fermats_factorization_method";

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Failed to interpret '%s' as one of these five factorization method at my disposal:\n", argv_two);
    fprintf(stderr, "1). %s\n", most_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "2). %s\n", less_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "3). %s\n", least_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "4). %s\n", difference_of_squares_factorization_METHOD);
    fprintf(stderr, "5). %s\n\n", fermats_factorization_METHOD);
    fprintf(stderr, "Terminating with exit status '-1'.\n");
    exit(-1);
}

int main(int argc, char **argv) {
    if (2 > argc || !match_variadic(argv[1], 5, most_inefficient_TRIAL_DIVISION, less_inefficient_TRIAL_DIVISION, least_inefficient_TRIAL_DIVISION, difference_of_squares_factorization_METHOD, fermats_factorization_METHOD)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }

    _factorization_method factorization_method_chosen = fermat_factorization;
    if (strcmp(argv[1], most_inefficient_TRIAL_DIVISION) == 0) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if x divides %lu.", MOD - 1, MOD);
	factorization_method_chosen = most_inefficient_trial_division;
    } else if (strcmp(argv[1], less_inefficient_TRIAL_DIVISION) == 0) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if f x divides %lu.", (MOD - (MOD % 2)) / 2, MOD);
	factorization_method_chosen = less_inefficient_trial_division;
    } else if (strcmp(argv[1], least_inefficient_TRIAL_DIVISION) == 0) {
	fprintf(stdout, "Using trail division and checking for all x <= %lu if x divides %lu.", DOWN_ROUNDED_second_root(MOD), MOD);
	factorization_method_chosen = least_inefficient_trial_division;
    } else if (strcmp(argv[1], difference_of_squares_factorization_METHOD) == 0) { if (MOD % 2 == 0)
	{ fprintf(stderr, "%lu \u2261 0	(modulus 2)\n\nThe difference of squares method can only handle odd numbers, but %lu is even. Terminating with exit status '-3'.\n", MOD, MOD); return -3; }
	fprintf(stderr, "Using the difference of squares method.");
	factorization_method_chosen = difference_of_squares_factorization_method;
    } else fprintf(stdout, "Using fermat's factorization method."); fprintf(stdout, "\n\n");

    struct ordered_pair factorization_of_MOD = factorization_method_chosen(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
