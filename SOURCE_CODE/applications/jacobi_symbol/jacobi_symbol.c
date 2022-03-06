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
int _legendre_symbol(unsigned long N, unsigned long D, int multiplicative_accumulator, int index, struct _PRIME_FACTORIZATION *N_factorization) {
    // recursive function ^

    if (index == N_factorization->number_of_distinct_prime_factors) { PRIME_FACTORIZATION_free(N_factorization); return multiplicative_accumulator; }
    // return conditional ^

    int i = mod_eulers_criterion(N_factorization->prime_factor[index]); if (!(i + 1 || N_factorization->log[index] % 2)) i = 1;
    return _legendre_symbol(N, D, multiplicative_accumulator * i, index + 1, N_factorization);
}

// Same as above but adds support for even prime and 1
int legendre_symbol(unsigned long N, unsigned long D) {
    if (N == 1) return 1; // 1 will always be a quadratic residue
    else if (N == 2) { int i = D % 8; if (i == 1 || i == 7) return 1; else if (i == 3 || i == 5) return -1; }
    return _legendre_symbol(N, D, 1, 0, PRIME_FACTORIZATION(N));
}

// Attempts to generalize the above using factorization for the denominator
int jacobi_symbol(unsigned long p, unsigned long C) {
    struct _PRIME_FACTORIZATION *prime_factorization = PRIME_FACTORIZATION(C);
    int m = 1;
    for (int i = 0; i < prime_factorization->number_of_distinct_prime_factors; i++) {
	int leg = legendre_symbol(p % prime_factorization->prime_factor[i], prime_factorization->prime_factor[i]);
	if (leg == -1 && prime_factorization->log[i] % 2 == 0) leg = 1; // if (!(leg + 1 || prime_factorization->log[i] % 2)) leg = 1;
	m *= leg;
    }
    return m;
}

unsigned long D; // Denominator <--
unsigned long N; // Numerator <--

void coprime_fail() { fprintf(stderr, "Jaman", (*argv_location)[2], (*argv_location)[1], (*argv_location)[1]); }
void denominator_fail() { fprintf(stderr, "Please specify in the first argument a multiplicative group specification (goes as denominator into the Jacobi symbol)."); }
void numerator_fail() { fprintf(stderr, "Please specify in the second argument an element from \u2115%s*", (*argv_location)[1]); }

int main(int argc, char **argv) { argv_location = &argv;
    conditional_goodbye(n(n(pair_of_strs_represents_pair_of_coprime_ULs(denominator_fail, numerator_fail, &D, &N, 1, 2, -3)))); _preferred_factorization_engine = factorization_method_retrieve(argv[3]);
    // take in denominator, numerator, check if they are coprime, and overrule external file '/applications/.global_preference.factorization_engine' if requested ^^^

    mod_ = &D;
    unsigned long ans;
    if (!primality_test_based_on_preferred_factorization_engine(D)) ans = jacobi_symbol(N, D);
    else ans = legendre_symbol(N, D);
    if (ans == 1) fprintf(stdout, "%lu is a quadratic residue mod %lu\n", N, D); // BASH SCRIPT APPROACH <--
    else if (ans == - 1) fprintf(stdout, "%lu is not a quadratic residue mod %lu\n", N, D); // BASH SCRIPT APPROACH <--
    // fprintf(stdout, "Legendre's symbol for N over D ( N / D ) = %s over %s = ( %s / %s ) = %i\n", argv[1], argv[2], argv[1], argv[2], legendre_symbol(N, D)); // PROGRAM APPROACH <--
    return 0;
}
