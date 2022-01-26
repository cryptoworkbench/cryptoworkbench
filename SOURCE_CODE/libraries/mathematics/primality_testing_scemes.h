typedef int (*_primality_test) (unsigned long); _primality_test preferred_PRIMALITY_TEST_REPORT();

int efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int LESS_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int LEAST_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int shor_factorization_PRIMALITY_TEST(unsigned long potential_prime);
int fermat_factorization_PRIMALITY_TEST(unsigned long potential_prime);
int fermats_DETERMINISTIC_primality_test(unsigned long potential_prime);
// ^ 8 primality test at our disposal (7 of which derived from functions which take a number and return it's smallest divisor greater than 1, i.e. factorization algorithms)

_primality_test primality_test(int SELECTOR);
int primality_test_based_on_preferred_factorization_engine(unsigned long potential_prime);
void SET_preferred_PRIMALITY_TEST(int SELECTOR);
// ^ Two functions which just use the engine that is currently registered as the preferred one

int prime(unsigned long potential_prime, _primality_test preferred_primality_test);
