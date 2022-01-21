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
#include "../../libraries/mathematics/factorization_methods.h" // needed for function pointers 'trial_division_LEAST_EFFICIENT', 'trial_division_LESS_EFFICIENT', 'trial_division_MOST_EFFICIENT', etc
ul MOD; // < This time we will use 'MOD' for the composite

const char *A = "a"; const char *B ="b"; const char *C = "c"; const char *D = "d"; const char *E = "e"; const char *F ="f"; const char *G = "g"; const char *H = "h";
// ^ All of the codes in use to signify the various engines.

const char *choice_A = "trial division (in it's least efficient form)";
const char *choice_B = "trial division (in it's less efficient form)";
const char *choice_C = "trial division (in it's most efficient form)";

const char *choice_D = "prime table aided trial division (in it's least efficient form)";
const char *choice_E = "prime table aided trial division (in it's less efficient form)";
const char *choice_F = "prime table aided trial division (in it's most efficient form)";

const char *choice_G = "difference of squares factorization method";
const char *choice_H = "fermats factorization method";

const char *supported_engines[9]; // 6 factorization engines are supported, and each takes 2 signifiers (identifiers in 'argv[1]'). That means we need 12 slots plus one for the "NULL" pointer at the end. That's 11 sloths
// ^^ Prepare const char * array for 'match()'. set_list() completes the preparation immediately when 'main()' starts (which is to say immediately upon program execution).

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Please specify one of the factorization methods available:\n");
    fprintf(stderr, "%s). %s\n", A, choice_A);
    fprintf(stderr, "%s). %s\n", B, choice_B);
    fprintf(stderr, "%s). %s\n", C, choice_C); // < ^ trial division algorithms

    fprintf(stderr, "%s). %s\n", D, choice_D);
    fprintf(stderr, "%s). %s\n", E, choice_E);
    fprintf(stderr, "%s). %s\n", F, choice_F); // < ^ trial division algorithms aided by a prime table

    fprintf(stderr, "%s). %s\n", G, choice_G);
    fprintf(stderr, "%s). %s\n\n", H, choice_H);
    fprintf(stderr, "\"%s\" is not one of them. Terminating with exit status '-1'.\n", argv_two);
    exit(-1);
}

void set_list() {
    supported_engines[0] = A; supported_engines[1] = B; supported_engines[2] = C; supported_engines[3] = D; supported_engines[4] = E;
    supported_engines[5] = F; supported_engines[6] = G; supported_engines[7] = H; supported_engines[8] = 0;
}

int main(int argc, char **argv) { set_list(); // < initialize the const char * array 'supported_engines' that we call 'match()' with in the line immediately below
    if (2 > argc || !match(argv[1], supported_engines)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }

    _factorization_method factorization_method_chosen = fermat_factorization;
    if (strcmp(argv[1], A) == 0) { factorization_method_chosen = trial_division_LEAST_EFFICIENT;
	fprintf(stdout, "Using trial division and checking for all 'x <= %lu' if x divides %lu.", MOD, MOD);
    } else if (strcmp(argv[1], B) == 0) { factorization_method_chosen = trial_division_LESS_EFFICIENT;
	fprintf(stdout, "Using trial division and checking for all 'x <= %lu' if x divides %lu.", (MOD - (MOD % 2)) / 2, MOD);
    } else if (strcmp(argv[1], C) == 0) { factorization_method_chosen = trial_division_MOST_EFFICIENT;
	fprintf(stdout, "Using trial division and checking for all 'x <= %lu' if x divides %lu.", DOWN_ROUNDED_second_root(MOD), MOD);
    } else if (strcmp(argv[1], D) == 0) { factorization_method_chosen = table_aided_trial_division_LEAST_EFFICIENT;
	fprintf(stdout, "Using prime table aided trial division (with '%s') and checking for all 'x <= %lu' if x divides %lu.", _REPORT_standard_prime_table_filename(), MOD, MOD);
    } else if (strcmp(argv[1], E) == 0) { factorization_method_chosen = table_aided_trial_division_LESS_EFFICIENT;
	fprintf(stdout, "Using prime table aided trial division (with '%s') and checking for all 'x <= %lu' if x divides %lu.", _REPORT_standard_prime_table_filename(), (MOD - (MOD % 2)) / 2, MOD);
    } else if (strcmp(argv[1], F) == 0) { factorization_method_chosen = table_aided_trial_division_MOST_EFFICIENT;
	fprintf(stdout, "Using prime table aided trial division (with '%s') and checking for all 'x <= %lu' if x divides %lu.", _REPORT_standard_prime_table_filename(), DOWN_ROUNDED_second_root(MOD), MOD);
    } else if (strcmp(argv[1], G) == 0) { factorization_method_chosen = difference_of_squares_factorization_method;
	if (MOD % 2 == 0)
	{ fprintf(stderr, "%lu \u2261 0	(modulus 2)\n\nThe difference of squares method can only handle odd numbers, but %lu is even. Terminating with exit status '-3'.\n", MOD, MOD); return -3; }
	fprintf(stdout, "Using the difference of squares method.");
    } else fprintf(stdout, "Using Fermat's factorization method."); fprintf(stdout, "\n\n");

    struct ordered_pair factorization_of_MOD = factorization_method_chosen(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
