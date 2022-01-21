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

const char *a = "a"; const char *_a = "most_inefficient_trial_division";
const char *b ="b"; const char *_b = "most_inefficient_aided_trial_division";

const char *c = "c"; const char *_c = "less_inefficient_trial_division";
const char *d = "d"; const char *_d = "less_inefficient_aided_trial_division";

const char *e = "e"; const char *_e = "least_inefficient_trial_division";
const char *f ="f"; const char *_f = "least_inefficient_aided_trial_division";

const char *g = "g"; const char *_g = "difference_of_squares_factorization_method";
const char *h = "h"; const char *_h = "fermats_factorization_method";

const char *supported_engines[16]; // 6 factorization engines are supported, and each takes 2 signifiers (identifiers in 'argv[1]'). That means we need 12 slots plus one for the "NULL" pointer at the end. That's 11 sloths
// ^^ Prepare const char * array for 'match()'. set_list() completes the preparation immediately when 'main()' starts (which is to say immediately upon program execution).

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Please specify one of the factorization methods available:\n");
    fprintf(stderr, "a). %s\n", _a);
    fprintf(stderr, "b). %s\n", _b);

    fprintf(stderr, "c). %s\n", _c);
    fprintf(stderr, "d). %s\n", _d);

    fprintf(stderr, "e). %s\n", _e);
    fprintf(stderr, "f). %s\n", _f);

    fprintf(stderr, "g). %s\n", _g);
    fprintf(stderr, "h). %s\n\n", _h);
    fprintf(stderr, "\"%s\" is not one of them. Terminating with exit status '-1'.\n", argv_two);
    exit(-1);
}

void set_list() {
    supported_engines[0] = a; supported_engines[1] = _a;
    supported_engines[2] = b; supported_engines[3] = _b;
    supported_engines[4] = c; supported_engines[5] = _c;
    supported_engines[6] = d; supported_engines[7] = _d;
    supported_engines[8] = e; supported_engines[9] = _e;
    supported_engines[10] = f; supported_engines[11] = _f;
    supported_engines[12] = g; supported_engines[13] = _g;
    supported_engines[14] = h; supported_engines[15] = _h;
    supported_engines[16] = 0;
}

int main(int argc, char **argv) { set_list(); // < initialize the const char * array 'supported_engines' that we call 'match()' with in the line immediately below
    if (2 > argc || !match(argv[1], supported_engines)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }

    _factorization_method factorization_method_chosen = fermat_factorization;
    if (match_variadic(argv[1], 2, a, _a)) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if x divides %lu.", MOD, MOD);
	factorization_method_chosen = most_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, b, _b)) {
	fprintf(stdout, "Using prime table aided trail division (with '%s') and checking for all 'x <= %lu' if f x divides %lu.", _REPORT_standard_prime_table_filename(), MOD, MOD);
	factorization_method_chosen = most_inefficient_trial_division_aided_by_table;
    } else if (match_variadic(argv[1], 2, c, _c)) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if f x divides %lu.", (MOD - (MOD % 2)) / 2, MOD);
	factorization_method_chosen = less_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, d, _d)) {
	fprintf(stdout, "Using prime table aided trail division (with '%s') and checking for all 'x <= %lu' if f x divides %lu.", _REPORT_standard_prime_table_filename(), (MOD - (MOD % 2)) / 2, MOD);
	factorization_method_chosen = less_inefficient_trial_division_aided_by_table;
    } else if (match_variadic(argv[1], 2, e, _e)) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if f x divides %lu.", DOWN_ROUNDED_second_root(MOD), MOD);
	factorization_method_chosen = least_inefficient_trial_division;
    } else if (match_variadic(argv[1], 2, f, _f)) {
	factorization_method_chosen = least_inefficient_trial_division_aided_by_table;
	fprintf(stdout, "Using prime table aided trail division (with '%s') and checking for all 'x <= %lu' if f x divides %lu.", _REPORT_standard_prime_table_filename(), DOWN_ROUNDED_second_root(MOD), MOD);
    } else if (match_variadic(argv[1], 2, g, _g)) { if (MOD % 2 == 0)
	{ fprintf(stderr, "%lu \u2261 0	(modulus 2)\n\nThe difference of squares method can only handle odd numbers, but %lu is even. Terminating with exit status '-3'.\n", MOD, MOD); return -3; }
	fprintf(stdout, "Using the difference of squares method.");
	factorization_method_chosen = difference_of_squares_factorization_method;
    } else fprintf(stdout, "Using Fermat's factorization method."); fprintf(stdout, "\n\n");

    struct ordered_pair factorization_of_MOD = factorization_method_chosen(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
