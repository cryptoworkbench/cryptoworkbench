typedef unsigned long (*_factorization_method) (unsigned long);
_factorization_method _preferred_factorization_ENGINE;

char *_a; char *_b; char *_c; char *_d; char *_e; char *_f; char *_g; char *_h;

void initialize_factorization_library();
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

char *STDIN_factorization_engine();
void write_to_preferences_file(char *str, FILE *file);
char *query_preferences_file();
// new ^

_factorization_method factorization_method(int SELECTOR); // 'SET_preferred_factorization_ENGINE()'
void SET_preferred_factorization_ENGINE(int SELECTOR);
void FACTORIZATION_METHOD_UNCHOSEN(char *arg);
int SELECTOR_from_str_representing_factorization_method(char *arg);
const char *_preferred_factorization_ENGINE_description();



// PRIME FACTORIZATION:
struct LL_ { struct LL_ *next; unsigned long e; };
struct _PRIME_FACTORIZATION { unsigned long *prime_factor; int *log; int number_of_distinct_prime_factors; };
// Variable type declarations ^

struct LL_ *insert(struct LL_ *last, unsigned long new_divisor); // NON-recursive <--
struct LL_ *stretched_divisor(struct LL_ *in, struct ordered_pair divisor_pair); // NON-recursive <--
struct LL_ *divisor_list_stretch(struct LL_ *i); // recursive function yielding the list containing the prime factorization <--
void divisor_list_WIPE(struct LL_ *i); // also recursive
unsigned long number_of_distinct_prime_factors(unsigned long previous_prime_factor, struct LL_ *i, unsigned long ret_val); // recursive function which counts the number of distinct prime factors said list <--
void PRIME_FACTORIZATION_setup(struct _PRIME_FACTORIZATION *crux, unsigned long last_factor, struct LL_ *i, unsigned long index); // recursive function which set's up the program's crux (which holds the associative array)
struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION_allocate(int number_of_distinct_prime_factors); // allocation of a struct '_PRIME_FACTORIZATION'
void PRIME_FACTORIZATION_free(struct _PRIME_FACTORIZATION *crux); // destruction of a struct '_PRIME_FACTORIZATION'
struct _PRIME_FACTORIZATION *_PRIME_FACTORIZATION(unsigned long number_of_distinct_prime_factors, struct LL_ *divisors); // NON-recursive wrapper function for 'PRIME_FACTORIZATION_allocate' <--
struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION(unsigned long number); // NON-recursive wrapper function for 'PRIME_FACTORIZATION_allocate' <--
unsigned long PRIME_FACTORIZATION_calculate(unsigned long multiplicative_accumulator, struct _PRIME_FACTORIZATION *crux, int index); // recursive function for converting from prime factorization back to number ^
struct _PRIME_FACTORIZATION *_PRIME_FACTORIZATION_print(struct _PRIME_FACTORIZATION *crux, int index); // recursive function which prints struct '_PRIME_FACTORIZATION'
struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION_print(struct _PRIME_FACTORIZATION *crux); // wrapper for the above recursive function
