// DEVELOPERS NOTES:
// Abstract out 'legendre_symbol' into maths.c or factorization.c
//
// DEVELOPERS NOTE:
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

// Legendre symbol for composite numerator and odd prime denominator
int _legendre_symbol(unsigned long N, unsigned long q, int multiplicative_accumulator, int index, struct _PRIME_FACTORIZATION *prime_factorization) {
    if (index == prime_factorization->number_of_distinct_prime_factors) { PRIME_FACTORIZATION_free(prime_factorization); return multiplicative_accumulator; }
    int i = eulers_criterion(prime_factorization->prime_factor[index], q); if (!(i + 1 || prime_factorization->log[index] % 2)) i = 1;
    return _legendre_symbol(N, q, multiplicative_accumulator * i, index + 1, prime_factorization);
}

// Same as above but adds support for even prime and multiplicative identity 
int legendre_symbol(unsigned long N, unsigned long q) {
    if (N == 1) return 1; // 1 is always a quadratic residue in groups with mod > 1
    else if (N == 2) { int i = q % 8; if (i == 1 || i == 7) return 1; else if (i == 3 || i == 5) return -1; }
    return _legendre_symbol(N, q, 1, 0, PRIME_FACTORIZATION(N));
}

// Attempts to generalize the above using factorization for the denominator
int jacobi_symbol(unsigned long p, unsigned long C) {
    struct _PRIME_FACTORIZATION *prime_factorization = PRIME_FACTORIZATION(C);
    int m = 1;
    for (int i = 0; i < prime_factorization->number_of_distinct_prime_factors; i++) {
	int leg = legendre_symbol(p % prime_factorization->prime_factor[i], prime_factorization->prime_factor[i]);
	if (leg == -1 && prime_factorization->log[i] % 2 == 0) leg = 1; // if (!(leg + 1 || prime_factorization->log[i] % 2)) leg = 1;
	// printf("legende_symbol of ( %lu / %lu )^%i = %i\n", p % prime_factorization->prime_factor[i], prime_factorization->prime_factor[i], prime_factorization->log[i], leg);
	m *= leg;
    }
    return m;
}

unsigned long N, q;

// void coprime_error() { fprintf(stderr, "gcd(%s, %s) != 1: %s is not an element from \u2115%s*.", (*argv_location)[i], (*argv_location)[1], (*argv_location)[i], (*argv_location)[1]); }
void coprime_fail() { fprintf(stderr, "%s is not an element from \u2115%s*.", (*argv_location)[1], (*argv_location)[2]); }
void denominator_fail() { fprintf(stderr, "Please provide as second argument the denominator to the Jacobi symbol."); }
void numerator_fail() { fprintf(stderr, "Please provide as first argument the numerator to the Jacobi symbol."); }

int main(int argc, char **argv) {
    conditional_goodbye(n(n(error_specification(numerator_fail, n(ul_parse_str(argv[1], &N, -1))))));
    conditional_goodbye(n(n(error_specification(denominator_fail, n(ul_parse_str(argv[2], &q, -1)))))); argv_location = &argv;
    conditional_goodbye(n(n(error_message(coprime_fail, -2 * ( !coprime(N, q) )))));
    if (N > q) { N %= q; fprintf(stdout, "Reduced N modulus q.\n"); }
    // verify arguments validity ^^^

    _preferred_factorization_engine = factorization_method_retrieve(argv[2]);

    fprintf(stdout, "Legendre's symbol for N over q ( N / q ) = %s over %s = ( %s / %s ) = %i\n", argv[1], argv[2], argv[1], argv[2], legendre_symbol(N, q)); // PROGRAM APPROACH <--
    /*
    unsigned long ans;
    if (!primality_test_based_on_preferred_factorization_engine(q)) ans = jacobi_symbol(N, q);
    else ans = legendre_symbol(N, q);
    if (ans == 1) fprintf(stdout, "%lu is a quadratic residue mod %lu\n", N, q); // BASH SCRIPT APPROACH <--
    else if (ans == - 1) fprintf(stdout, "%lu is not a quadratic residue mod %lu\n", N, q); // BASH SCRIPT APPROACH <--
    */
    return 0;
}
