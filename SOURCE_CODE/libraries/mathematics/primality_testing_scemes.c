// Next up:
// Make a general primality testing application
// This application has it's own configuration file.
// This configuration file can be set to make the primality testing application use a primality testing procedure based on a factorization method, but
// This configuration file can also be set to make the primality testing application use 'fermats_DETERMINISTIC_primality_test'
#include "primality_testing_scemes.h"
#include "maths.h" // needed for 'ADDITIVE_IDENTITY', 'MULTIPLICATIVE_IDENTITY'
#include "factorization_methods.h" // needed for the definition of function pointer type _factorization_method
_factorization_method preferred_factorization_ENGINE; // needed because of 'factization_methods.h'
_primality_test preferred_PRIMALITY_TEST; // new to this library

int efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LESS_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LESS_efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LEAST_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LEAST_efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LESS_efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LEAST_efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int shor_factorization_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - shor_factorization(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int fermat_factorization_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - fermat_factorization(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
// ^ 8 primality tests based on factorization methods

_primality_test primality_test(int SELECTOR) {
    switch (SELECTOR) { case 0: return LEAST_efficient_trial_division_PRIMALITY_TEST; case 1: return LESS_efficient_trial_division_PRIMALITY_TEST; case 2: return efficient_trial_division_PRIMALITY_TEST;
	case 3: return LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST; case 4: return LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST;
	case 5: return efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST; case 6: return shor_factorization_PRIMALITY_TEST; case 7: return fermat_factorization_PRIMALITY_TEST; default: return NULL; };
} // ^ A similar function for returning pointers to primality test functions in 'primality_testing_scemes.c' as there was a function for returning pointers to factorization functions in 'factorization.h'

void SET_preferred_PRIMALITY_TEST(int SELECTOR) { preferred_PRIMALITY_TEST = primality_test(SELECTOR); }

int composite_test_based_on_preferred_factorization_engine(unsigned long potential_composite) { return (potential_composite - preferred_factorization_ENGINE(potential_composite)) ? MULTIPLICATIVE_IDENTITY : ADDITIVE_IDENTITY; }
int primality_test_based_on_preferred_factorization_engine(unsigned long potential_prime) { return (potential_prime - preferred_factorization_ENGINE(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }

int fermats_DETERMINISTIC_primality_test(unsigned long potential_prime) { for (ul i = 2; i < potential_prime; i++) if (GCD(i, potential_prime) != 1 || 1 != exponentiate(i, potential_prime - 1, potential_prime)) return 0; return 1; }
