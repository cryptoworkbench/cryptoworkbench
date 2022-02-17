#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/primality_testing.h"

int _legendre_symbol(unsigned long N, unsigned long q, int multiplicative_accumulator, int index, struct _PRIME_FACTORIZATION *prime_factorization) {
    if (index == prime_factorization->number_of_distinct_prime_factors) { PRIME_FACTORIZATION_free(prime_factorization); return multiplicative_accumulator; }
    int i = eulers_criterion(prime_factorization->prime_factor[index], q); if (i == -1 && prime_factorization->log[index] % 2 == 0) i = 1;
    return _legendre_symbol(N, q, multiplicative_accumulator * i, index + 1, prime_factorization);
} int legendre_symbol(unsigned long N, unsigned long q) {struct _PRIME_FACTORIZATION *prime_factorization = PRIME_FACTORIZATION_initialize(N); return _legendre_symbol(N, q, 1, 0, prime_factorization);}

int main(int argc, char **argv) {
    unsigned long N; if (2 > argc || !str_represents_ul(argv[1], &N)) { fprintf(stderr, "Failed to interpret %s as 'N'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    char *ptr = argv[3]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (argv[3]) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[3]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then force take factorization method from STDIN

    // if (!primality_test_based_on_preferred_factorization_engine(N)) { fprintf(stderr, "p (%lu) is not prime.\n", N); exit(-4); }
    if (!primality_test_based_on_preferred_factorization_engine(q)) { fprintf(stderr, "q (%lu) is not prime.\n", q); exit(-5); }
    if (N > q) { N %= q; fprintf(stdout, "Reduced N modulus q.\n"); }

    // fprintf(stdout, "Legendre's symbol for N over q ( N / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", N, q, N, q, legendre_symbol(N, q)); // PROGRAM APPROACH <--
    if (legendre_symbol(N, q) == 1) fprintf(stdout, "%lu is a quadratic residue mod %lu\n", N, q); // SHELL SCRIPT APPROACH <--
    return 0;
}
