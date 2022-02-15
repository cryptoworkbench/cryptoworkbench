// Next up:
// Make a general primality testing application
// This application has it's own configuration file.
// This configuration file can be set to make the primality testing application use a primality testing procedure based on a factorization method, but
// This configuration file can also be set to make the primality testing application use 'fermats_DETERMINISTIC_primality_test'
#include "primality_testing.h"
#include "maths.h" // needed for 'ADDITIVE_IDENTITY', 'MULTIPLICATIVE_IDENTITY'
#include "factorization_methods.h" // needed for the definition of function pointer type _factorization_method

int efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LESS_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LESS_efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LEAST_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LEAST_efficient_trial_division(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LESS_efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - LEAST_efficient_trial_division_TABLE_AIDED(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int shor_factorization_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - shor_factorization(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int fermat_factorization_PRIMALITY_TEST(unsigned long potential_prime) { return (potential_prime - fermat_factorization(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
int fermats_DETERMINISTIC_primality_test(unsigned long potential_prime) { for (unsigned long i = 2; i < potential_prime; i++) if (GCD(i, potential_prime) != 1 || 1 != _exponentiate(i, potential_prime - 1, potential_prime)) return 0; return 1; }
// Fermat's primality test and 8 more tests based on factorization methods ^^

_primality_test primality_test(int SELECTOR) {
    switch (SELECTOR) {
	case 0: return NULL;
	case 1: return efficient_trial_division_PRIMALITY_TEST;
	case 2: return LESS_efficient_trial_division_PRIMALITY_TEST;
	case 3: return LEAST_efficient_trial_division_PRIMALITY_TEST;
	case 4: return efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST;
	case 5: return LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST;
	case 6: return LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST;
	case 7: return shor_factorization_PRIMALITY_TEST;
	case 8: return fermat_factorization_PRIMALITY_TEST;
    };
} // ^ A similar function for returning pointers to primality test functions in 'primality_testing.c' as there was a function for returning pointers to factorization functions in 'factorization.h':
/// Only difference now is that there are 9 primality tests, while there were 8 factorization algorithms; this discrapency is not accounted for

int primality_test_based_on_preferred_factorization_engine(unsigned long potential_prime)
{ return (potential_prime - _preferred_factorization_ENGINE(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY;}
int prime(unsigned long potential_prime, _primality_test alternate_test) { return (alternate_test) ? alternate_test(potential_prime) : _preferred_primality_test(potential_prime); }

const char *chosen_PRIMALITY_TEST() { initialize_factorization_library(); // < makes available in calling file the below pointers
    if (_preferred_primality_test == efficient_trial_division_PRIMALITY_TEST) return _a;
    else if (_preferred_primality_test == LESS_efficient_trial_division_PRIMALITY_TEST) return _b;
    else if (_preferred_primality_test == LEAST_efficient_trial_division_PRIMALITY_TEST) return _c;
    else if (_preferred_primality_test == efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return _d;
    else if (_preferred_primality_test == LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return _e;
    else if (_preferred_primality_test == LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return _f;
    else if (_preferred_primality_test == shor_factorization_PRIMALITY_TEST) return _g;
    else if (_preferred_primality_test == fermat_factorization_PRIMALITY_TEST) return _h;
    return NULL;
}
