// I WANT THIS TO BECOME A GENERAL FACTORIZATION APP WHICH CHOOSES IT'S FACTORIZATION METHOD BASED ON TERMINAL ARGUMENTS
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'factorization_method_WRAPPER()'
#include "../../libraries/mathematics/factorization_methods.h" // 'factorization_method_WRAPPER()'
ul MOD; // < This time we will use 'MOD' for the odd composite


char *INEFFICIENT_trail_division = "inefficient_trail_division";
char *MORE_EFFICIENT_trail_division = "more_efficient_trail_division";
char *MOST_EFFICIENT_trail_division = "most_efficient_trail_division";
char *difference_of_squares_factorization_METHOD = "difference_of_squares_factorization_method";
char *fermats_factorization_METHOD = "fermats_factorization_method";

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Failed to interpret '%s' as one of the three factorization engines available:\n", argv_two);
    fprintf(stderr, "1). %s\n", INEFFICIENT_trail_division);
    fprintf(stderr, "2). %s\n", MORE_EFFICIENT_trail_division);
    fprintf(stderr, "3). %s\n", MOST_EFFICIENT_trail_division);
    fprintf(stderr, "4). %s\n", difference_of_squares_factorization_METHOD);
    fprintf(stderr, "4). %s\n\n", fermats_factorization_METHOD);
    fprintf(stderr, "Terminating with exit status '-1'.\n");
    exit(-1);
}

int main(int argc, char **argv) {
    if (2 > argc || !match_variadic(argv[1], 5, INEFFICIENT_trail_division, MORE_EFFICIENT_trail_division, MOST_EFFICIENT_trail_division, difference_of_squares_factorization_METHOD, fermats_factorization_METHOD)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }

    _factorization_method factorization_method_chosen = fermat_factorization;
    if (strcmp(argv[1], INEFFICIENT_trail_division) == 0) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if x divides %lu.", MOD - 1, MOD);
	factorization_method_chosen = inefficient_trail_division;
    } else if (strcmp(argv[1], MORE_EFFICIENT_trail_division) == 0) {
	fprintf(stdout, "Using trail division and checking for all 'x <= %lu' if f x divides %lu.", (MOD - (MOD % 2)) / 2, MOD);
	factorization_method_chosen = more_efficient_trail_division;
    } else if (strcmp(argv[1], MOST_EFFICIENT_trail_division) == 0) {
	fprintf(stdout, "Using trail division and checking for all x <= %lu if x divides %lu.", DOWN_ROUNDED_second_root(MOD), MOD);
	factorization_method_chosen = most_efficient_trail_division;
    } else if (strcmp(argv[1], difference_of_squares_factorization_METHOD) == 0) { if (MOD % 2 == 0)
	{ fprintf(stderr, "%lu \u2261 0	(modulus 2)\n\nThe difference of squares method can only handle odd numbers, but %lu is even. Terminating with exit status '-3'.\n", MOD, MOD); return -3; }
	fprintf(stderr, "Using the difference of squares method.");
	factorization_method_chosen = difference_of_squares_factorization_method;
    } else fprintf(stdout, "Using fermat's factorization method."); fprintf(stdout, "\n\n");

    struct ordered_pair factorization_of_MOD = factorization_method_chosen(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
