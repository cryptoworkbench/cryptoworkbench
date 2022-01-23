typedef int (*_primality_test) (unsigned long);

int efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int LESS_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int LEAST_efficient_trial_division_PRIMALITY_TEST(unsigned long potential_prime);
int efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST(unsigned long potential_prime);
int fermat_factorization_PRIMALITY_TEST(unsigned long potential_prime);
// ^ These 7 we know

_primality_test primality_test(int SELECTOR);
void SET_prefered_PRIMALITY_TEST(int SELECTOR);
int composite_test_based_on_prefered_factorization_engine(unsigned long potential_composite);
int primality_test_based_on_prefered_factorization_engine(unsigned long potential_prime);
// ^ Two functions which just use the engine that is currently registered as the prefered one
