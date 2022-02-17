// eulers_criterion() seems to calculate Legendre's symbol using Euler's criterion. Good.
// I need to make a wrapper function which factorizes 'p' in order to be able to use eulers_criterion() as a backhand
// and calculate any:
// ( __composite__ / P )
//
// LEGENDRE SYMBOL.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/primality_testing.h"

int legendre_symbol(unsigned long potential_composite) {

}

int main(int argc, char **argv) {
    unsigned long p; if (2 > argc || !str_represents_ul(argv[1], &p)) { fprintf(stderr, "Failed to interpret %s as 'p'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    // ^ interpret required primes

    char *ptr = argv[3]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_primality_test = primality_test(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (argv[3]) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_primality_test = primality_test(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[3]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then force take factorization method from STDIN

    // if (!prime(p, NULL)) { fprintf(stderr, "p (%lu) is not prime.\n", p); exit(-4); }
    // RESTRICTION REMOVAL IN PROGRESS

    if (!prime(q, NULL)) { fprintf(stderr, "q (%lu) is not prime.\n", q); exit(-5); }
    if (p > q) { p %= q; fprintf(stdout, "Reduced p modulus q.\n"); } // fprintf(stdout, "p = %lu\n", p); fprintf(stdout, "q = %lu\n\n", q);
    fprintf(stdout, "The Legendre symbol of p over q ( p / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", p, q, p, q, eulers_criterion(p, q));
    return 0;
}
