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
#define COMPOSITE_NOT_INTERPRETABLE "Failed to interpret composite '%s'!\n\n"
ul MOD; // < This time we will use 'MOD' for the composite
_factorization_method preferred_factorization_ENGINE;

void domain_display(unsigned long a, unsigned long b) { fprintf(stdout, " and checking for all 'x <= %lu' if x divides %lu.", a, b); }

void initialize() {
    if (preferred_factorization_ENGINE == LEAST_efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(MOD, 3), MOD); }
    else if (preferred_factorization_ENGINE == LESS_efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(MOD, 2), MOD); }
    else if (preferred_factorization_ENGINE == efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(MOD, 1), MOD); }
    else if (preferred_factorization_ENGINE == LEAST_efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename()); domain_display(trial_limit(MOD, 3), MOD); }
    else if (preferred_factorization_ENGINE == LESS_efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename()); domain_display(trial_limit(MOD, 2), MOD); }
    else if (preferred_factorization_ENGINE == efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename()); domain_display(trial_limit(MOD, 1), MOD); }
    else if (preferred_factorization_ENGINE == shor_factorization) { fprintf(stdout, "Applying Shor's factorization algorithm for quantum computers."); }
    else fprintf(stdout, "Using Fermat's factorization method.");
}

int main(int argc, char **argv) { preferred_factorization_ENGINE = NULL;
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, COMPOSITE_NOT_INTERPRETABLE EXIT_STATUS_GOODBYE, argv[1], -1); exit(-1); } char *ptr = argv[2];
    if (argc < 3) { FILE *file; if (file = fopen(preferred_factorization_engine_file_REPORT(), "r")) { ptr = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ptr); fclose(file); }
	else { fprintf(stderr, "Couldn't open preferences file '%s'. " EXIT_STATUS_GOODBYE, -1, preferred_factorization_engine_file_REPORT()); exit(-1); } }
    int SELECTOR = translate_SUBTRACT_ONE(ptr);
    if (SELECTOR) SET_preferred_factorization_ENGINE(SELECTOR - 1); // < a.k.a. interpretation from 'ptr' successful
    else ERR(ptr); initialize(); if (!(argc < 3)) fprintf(stdout, "	(engine specified by terminal argument)"); fprintf(stdout, "\n\n");

    struct ordered_pair factor_a_and_b = factorize(MOD, NULL); // <- NULL means 'preferred_factorization_ENGINE' will be deployed
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factor_a_and_b.a, factor_a_and_b.b);
    return 0;
} // make use use of '
