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

void domain_display(unsigned long a, unsigned long b) { fprintf(stdout, " and checking for all 'x <= %lu' if x divides %lu.", a, b); }

_factorization_method initialize(unsigned long composite) {
    if (_preferred_factorization_ENGINE == LEAST_efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(composite, 3), composite); }
    else if (_preferred_factorization_ENGINE == LESS_efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(composite, 2), composite); }
    else if (_preferred_factorization_ENGINE == efficient_trial_division) { fprintf(stdout, "Using trial division"); domain_display(trial_limit(composite, 1), composite); }
    else if (_preferred_factorization_ENGINE == LEAST_efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", _REPORT_standard_prime_table_filename()); domain_display(trial_limit(composite, 3), composite); }
    else if (_preferred_factorization_ENGINE == LESS_efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", _REPORT_standard_prime_table_filename()); domain_display(trial_limit(composite, 2), composite); }
    else if (_preferred_factorization_ENGINE == efficient_trial_division_TABLE_AIDED)
    { fprintf(stdout, "Using prime table aided trial division (with '%s')", _REPORT_standard_prime_table_filename()); domain_display(trial_limit(composite, 1), composite); }
    else if (_preferred_factorization_ENGINE == shor_factorization) { fprintf(stdout, "Applying Shor's factorization algorithm for quantum computers."); }
    else fprintf(stdout, "Using Fermat's factorization method.");
    return _preferred_factorization_ENGINE;
}

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the composite to factorize.\n\n"); return str_not_parsable_as_number; }; }
// 'error_selector' function itself contains the only error message along with library function str_not_parsable_as_number() ^

int main(int argc, char **argv) { unsigned long composite; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &composite)) error_message(error_selector(1), -1);
    // take in composite ^
    
    char *ptr = argv[2]; if (!ptr) ptr = query_preferences_file();
    int SELECTOR = ONE_MORE_THAN_translation(ptr);
    if (SELECTOR) {
	SET_preferred_factorization_ENGINE(SELECTOR - 1); // < a.k.a. interpretation from 'ptr' successful
	// printf("ello\n");
    }
    else FACTORIZATION_METHOD_UNCHOSEN(ptr); _factorization_method preferred_factorization_method = initialize(composite);
    if (!(argc < 3)) fprintf(stdout, "	(engine specified by terminal argument)"); fprintf(stdout, "\n\n");

    struct ordered_pair factor_a_and_b = factorize(composite, NULL);
    fprintf(stdout, "%lu = %lu * %lu\n", composite, factor_a_and_b.a, factor_a_and_b.b);
    return 0;
} // make use use of '
