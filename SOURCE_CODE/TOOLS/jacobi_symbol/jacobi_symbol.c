// DEVELOPERS NOTES:
// The Jacobi symbol is actually only defined when the numerator is odd: this is not reflected in the code.
//
// does not necessarily calculate all quadratic roots (try):
// cl && subgroup_examplifier 15 1 1 1 && quadratic_residue_with_root 15
//
// Found a fail in jacobi_symbol():
// '~/WORKBENCH/<argv[0]> 20 21' yields "20 is a quadratic residue mod 21", which is not true
//
// However all the online calculators that I found also give this false answer:
// - https://www.mymathtables.com/numbers/legendre-symbol-generator.html
// - https://www.easycalculation.com/legendre-symbol.php
// - http://math.fau.edu/richman/jacobi.htm
//
// But M - 1 is never a quadratic residue, so I should probably just hard-code that (have the code reflect this (assumedly) inherent property).
//
// Haven't yet found a fail in legendre_symbol()
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/primality_testing.h"

// Legendre symbol for composite numerator and odd prime denominator
int _legendre_symbol(unsigned long N, unsigned long q, int multiplicative_accumulator, int index, struct _PRIME_FACTORIZATION *prime_factorization) {
    if (index == prime_factorization->number_of_distinct_prime_factors) { PRIME_FACTORIZATION_free(prime_factorization); return multiplicative_accumulator; }
    int i = eulers_criterion(prime_factorization->prime_factor[index], q); if (!(i + 1 || prime_factorization->log[index] % 2)) i = 1;
    return _legendre_symbol(N, q, multiplicative_accumulator * i, index + 1, prime_factorization);
}

// Same as above but adds support for even prime and multiplicative identity 
int legendre_symbol(unsigned long N, unsigned long q) {
    if (N == 1) return 1;
    else if (N == 2) { int i = q % 8; if (i == 1 || i == 7) return 1; else if (i == 3 || i == 5) return -1; }
    return _legendre_symbol(N, q, 1, 0, PRIME_FACTORIZATION(N));
}

// Attempts the generalize the above using factorization for the denominator
int jacobi_symbol(unsigned long p, unsigned long C) {
    struct _PRIME_FACTORIZATION *prime_factorization = PRIME_FACTORIZATION(C);
    int m = 1;
    for (int i = 0; i < prime_factorization->number_of_distinct_prime_factors; i++) {
	int leg = legendre_symbol(p % prime_factorization->prime_factor[i], prime_factorization->prime_factor[i]);
	if (leg == -1 && prime_factorization->log[i] % 2 == 0) leg = 1; // if (!(leg + 1 || prime_factorization->log[i] % 2)) leg = 1;
	printf("legende_symbol of ( %lu / %lu )^%i = %i\n", p % prime_factorization->prime_factor[i], prime_factorization->prime_factor[i], prime_factorization->log[i], leg);
	m *= leg;
    }
    return m;
}

int main(int argc, char **argv) {
    unsigned long N; if (2 > argc || !str_represents_ul(argv[1], &N)) { fprintf(stderr, "Failed to interpret %s as 'N'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    if (GCD(N, q) != 1) exit(-4);
    char *ptr = argv[3]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_engine = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (argv[3]) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_engine = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[3]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then force take factorization method from STDIN

    if (N > q) { N %= q; fprintf(stdout, "Reduced N modulus q.\n"); }

    // fprintf(stdout, "Legendre's symbol for N over q ( N / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", N, q, N, q, legendre_symbol(N, q)); // PROGRAM APPROACH <--
    //
    unsigned long ans;
    if (!primality_test_based_on_preferred_factorization_engine(q)) ans = jacobi_symbol(N, q);
    else ans = legendre_symbol(N, q);
    if (ans == 1) fprintf(stdout, "%lu is a quadratic residue mod %lu\n", N, q); // BASH SCRIPT APPROACH <--
    // else if (ans == - 1) fprintf(stdout, "%lu is not a quadratic residue mod %lu\n", N, q); // BASH SCRIPT APPROACH <--
    return 0;
}
