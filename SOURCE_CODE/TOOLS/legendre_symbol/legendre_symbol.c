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

// PROCEDURAL IMPLEMENTATION:
int legendre_symbol(unsigned long p, unsigned long q) {
    struct _PRIME_FACTORIZATION *prime_factorization_of_number = PRIME_FACTORIZATION_initialize(p); int m = MULTIPLICATIVE_IDENTITY;
    for (int i = 0; i < prime_factorization_of_number->number_of_distinct_prime_factors; i++)
    { int j = eulers_criterion(prime_factorization_of_number->prime_factor[i], q); if (j == -1 && prime_factorization_of_number->log[i] % 2 == 1) j = 1; m *= j; } return m;
}

int main(int argc, char **argv) {
    unsigned long p; if (2 > argc || !str_represents_ul(argv[1], &p)) { fprintf(stderr, "Failed to interpret %s as 'N'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    char *ptr = argv[3]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (argv[3]) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[3]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then force take factorization method from STDIN

    if (!primality_test_based_on_preferred_factorization_engine(q)) { fprintf(stderr, "q (%lu) is not prime.\n", q); exit(-5); }
    if (p > q) { p %= q; fprintf(stdout, "Reduced p modulus q.\n"); } // fprintf(stdout, "p = %lu\n", p); fprintf(stdout, "q = %lu\n\n", q);
    fprintf(stdout, "The Legendre symbol of p over q ( p / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", p, q, p, q, legendre_symbol(p, q));
    return 0;
}
/* RECURSIVE IMPLEMENTATION:
int _legendre_symbol(unsigned long N, unsigned long q, int multiplicative_accumulator, int index, struct _PRIME_FACTORIZATION *prime_factorization_of_number) {
    if (index + 1 == prime_factorization_of_number->number_of_distinct_prime_factors) return multiplicative_accumulator;
    int i = eulers_criterion(prime_factorization_of_number->prime_factor[index], q); if (i == -1 && prime_factorization_of_number->log[index] % 2 == 1) i = 1;
    return _legendre_symbol(N, q, multiplicative_accumulator * i, index + 1, prime_factorization_of_number);
} int legendre_symbol(unsigned long N, unsigned long q) {struct _PRIME_FACTORIZATION *prime_factorization_of_number = PRIME_FACTORIZATION_initialize(N); return _legendre_symbol(N, q, 1, 0, prime_factorization_of_number);}
*/
