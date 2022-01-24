#define FILE_SPECIFYING_PREFERRED_ENGINE "universally_preferred_factorization_engine"

char *REPORT_A(); char *REPORT_B(); char *REPORT_C(); char *REPORT_D(); char *REPORT_E(); char *REPORT_F(); char *REPORT_G(); char *REPORT_H();
typedef unsigned long (*_factorization_method) (unsigned long); _factorization_method preferred_factorization_ENGINE; // 'SET_preferred_factorization_ENGINE()'
// a global function pointer for functions that take an UL and return an UL, that is going to be used for factorization ENGINEs returning the smallest divisor (from N, obviously) of any number greater than 1

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number);
unsigned long return_greatest(struct ordered_pair divisor_pair);
unsigned long trial_limit(unsigned long composite, int supidity_level);
unsigned long trial_division(unsigned long composite, unsigned long trial_limit);
unsigned long trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit);
unsigned long _trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit, FILE *prime_table);
// ^ Trial division factorization engines

unsigned long efficient_trial_division(unsigned long composite);
unsigned long LESS_efficient_trial_division(unsigned long composite);
unsigned long LEAST_efficient_trial_division(unsigned long composite); // < ^ Different implementations of ordinary trial division
unsigned long efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite); // < ^ Different implementations of table aided trial division
unsigned long shor_factorization(unsigned long presumed_composite);

struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long difference_of_squares_factorization_method(unsigned long odd_composite);
unsigned long odds_factorizer_WRAPPER(unsigned long composite, _factorization_method odds_factorizer);
unsigned long evens_factorizer(unsigned long even_composite); // the most efficient factorization algorithm known for powers of two
unsigned long fermat_factorization(unsigned long composite);
struct ordered_pair factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use);
// ^ And a lot of functions

_factorization_method factorization_method(int SELECTOR); // 'SET_preferred_factorization_ENGINE()'
void SET_preferred_factorization_ENGINE(int SELECTOR);
void ERR(char *arg);
int translate_SUBTRACT_ONE(char *arg);
int interpret_ENGINE_from_external_file();
