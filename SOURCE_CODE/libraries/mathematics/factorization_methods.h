typedef unsigned long (*_factorization_method) (unsigned long); _factorization_method _preferred_factorization_ENGINE;
const char *_REPORT_preferred_factorization_engine_file();
const char *_REPORT_a(); const char *_REPORT_b(); const char *_REPORT_c(); const char *_REPORT_d(); const char *_REPORT_e(); const char *_REPORT_f(); const char *_REPORT_g(); const char *_REPORT_h();
// a global function pointer for functions that take an UL and return an UL, that is going to be used for factorization ENGINEs returning the smallest divisor (from N, obviously) of any number greater than 1

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number);
unsigned long return_greatest(struct ordered_pair divisor_pair);
unsigned long trial_limit(unsigned long composite, int supidity_level);
unsigned long trial_division(unsigned long composite, unsigned long _trial_limit);
unsigned long trial_division_TABLE_AIDED(unsigned long composite, unsigned long _trial_limit);
unsigned long _trial_division_TABLE_AIDED(unsigned long composite, unsigned long _trial_limit, FILE *prime_table);
// ^ Trial division factorization engines

unsigned long efficient_trial_division(unsigned long composite);
unsigned long LESS_efficient_trial_division(unsigned long composite);
unsigned long LEAST_efficient_trial_division(unsigned long composite);
unsigned long efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long shor_factorization(unsigned long presumed_composite);

struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long difference_of_squares_factorization_method(unsigned long odd_composite);
unsigned long odds_factorizer_WRAPPER(unsigned long composite, _factorization_method odds_factorizer);
unsigned long evens_factorizer(unsigned long even_composite); // the most efficient factorization algorithm known for powers of two
unsigned long fermat_factorization(unsigned long composite);
struct ordered_pair factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use); struct ordered_pair _factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use);
// ^ And a lot of functions

_factorization_method factorization_method(int SELECTOR); // 'SET_preferred_factorization_ENGINE()'
void SET_preferred_factorization_ENGINE(int SELECTOR);
void FACTORIZATION_METHOD_UNCHOSEN(char *arg);
int translate_SUBTRACT_ONE(char *arg);
int interpret_ENGINE_from_external_file();
