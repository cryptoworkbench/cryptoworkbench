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
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // needed for 'DOWN_ROUNDED_second_root()' and some of the factorization methods in 'factorization_methods.c' need functions headers from 'maths.h'
#include "../../libraries/mathematics/factorization_methods.h" // needed for function pointers 'most_inefficient_trial_division', 'less_inefficient_trial_division', 'least_inefficient_trial_division', etc
ul MOD; // < This time we will use 'MOD' for the composite

const char *most_inefficient_TRIAL_DIVISION = "most_inefficient_trial_division"; const char *_a = "a";
const char *less_inefficient_TRIAL_DIVISION = "less_inefficient_trial_division"; const char *_b = "b";
const char *least_inefficient_TRIAL_DIVISION = "least_inefficient_trial_division"; const char *_c = "c";
const char *difference_of_squares_FACTORIZATION_METHOD = "difference_of_squares_factorization_method"; const char *_d = "d";
const char *fermats_FACTORIZATION_METHOD = "fermats_factorization_method"; const char *_e = "e";
const char *prime_table_FACTORIZATION_METHOD = "prime_table_factorization_method"; const char *_f = "f";
const char *supported_engines[13]; // 6 factorization engines are supported, and each takes 2 signifiers (identifiers in 'argv[1]'). That means we need 12 slots plus one for the "NULL" pointer at the end. That's 11 sloths
// ^^ Prepare const char * array for 'match()'. set_list() completes the preparation immediately when 'main()' starts (which is to say immediately upon program execution).

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Please specify one of the factorization methods available:\n");
    fprintf(stderr, "a). %s\n", most_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "b). %s\n", less_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "c). %s\n", least_inefficient_TRIAL_DIVISION);
    fprintf(stderr, "d). %s\n", difference_of_squares_FACTORIZATION_METHOD);
    fprintf(stderr, "e). %s\n", fermats_FACTORIZATION_METHOD);
    fprintf(stderr, "f). %s\n\n", prime_table_FACTORIZATION_METHOD);
    fprintf(stderr, "\"%s\" is not one of them. Terminating with exit status '-1'.\n", argv_two);
    exit(-1);
}

void set_list() {
    supported_engines[0] = _a; supported_engines[1] = most_inefficient_TRIAL_DIVISION;
    supported_engines[2] = _b; supported_engines[3] = less_inefficient_TRIAL_DIVISION;
    supported_engines[4] = _c; supported_engines[5] = least_inefficient_TRIAL_DIVISION;
    supported_engines[6] = _d; supported_engines[7] = difference_of_squares_FACTORIZATION_METHOD;
    supported_engines[8] = _e; supported_engines[9] = fermats_FACTORIZATION_METHOD;
    supported_engines[10] = _f; supported_engines[11] = prime_table_FACTORIZATION_METHOD;
    supported_engines[12] = 0;
}

int main(int argc, char **argv) { set_list(); // < initialize the const char * array 'supported_engines' that we call 'match()' with in the line immediately below
    if (2 > argc || !match(argv[1], supported_engines)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }

    _factorization_method factorization_method_chosen = fermat_factorization;
    if (match_variadic(argv[1], 2, most_inefficient_TRIAL_DIVISION, _a)) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if x divides %lu.", MOD - 1, MOD);
	factorization_method_chosen = most_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, less_inefficient_TRIAL_DIVISION, _b)) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if f x divides %lu.", (MOD - (MOD % 2)) / 2, MOD);
	factorization_method_chosen = less_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, least_inefficient_TRIAL_DIVISION, _c)) {
	fprintf(stdout, "Using trail division and checking for all x <= %lu if x divides %lu.", DOWN_ROUNDED_second_root(MOD), MOD);
	factorization_method_chosen = least_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, difference_of_squares_FACTORIZATION_METHOD, _d)) { if (MOD % 2 == 0)
	{ fprintf(stderr, "%lu \u2261 0	(modulus 2)\n\nThe difference of squares method can only handle odd numbers, but %lu is even. Terminating with exit status '-3'.\n", MOD, MOD); return -3; }
	fprintf(stdout, "Using the difference of squares method.");
	factorization_method_chosen = difference_of_squares_factorization_method;
    } else if (match_variadic(argv[1], 2, prime_table_FACTORIZATION_METHOD, _f)) {
	fprintf(stdout, "Using a lookup by prime table trial division approach (using lookup table '%s').", _REPORT_standard_prime_table_filename());
	factorization_method_chosen = _trial_division_aided_by_table;
    } else fprintf(stdout, "Using Fermat's factorization method."); fprintf(stdout, "\n\n");

    struct ordered_pair factorization_of_MOD = factorization_method_chosen(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
