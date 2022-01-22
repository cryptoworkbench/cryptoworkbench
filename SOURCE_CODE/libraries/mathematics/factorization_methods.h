struct ordered_pair pair_reorder(struct ordered_pair *pair); // < switches the values of member 'a' and member 'b' within a 'struct ordered_pair' pair of numbers IFF 'b' > 'a'
// ^ FUNCTIONS NOT IN USE

typedef unsigned long (*_factorization_method) (unsigned long);
_factorization_method ENGINE; // 'ENGINE_SET()'
void ENGINE_SET(int SELECTOR);
// ^ apparently this does not need 'extern' before the declaration

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number);
unsigned long trial_limit(unsigned long composite, int supidity_level);
unsigned long trial_division(unsigned long composite, unsigned long trial_limit);
unsigned long trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit);
unsigned long _trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit, FILE *prime_table);
// ^ Trial division factorization engines

unsigned long efficient_trial_division(unsigned long composite);
unsigned long LESS_efficient_trial_division(unsigned long composite);
unsigned long LEAST_efficient_trial_division(unsigned long composite);
// ^ Different implementations of ordinary trial division

unsigned long efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite);
unsigned long LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite);
// ^ Different implementations of table aided trial division

struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long difference_of_squares_factorization_method(unsigned long odd_composite);
unsigned long odds_factorizer_WRAPPER(unsigned long composite, _factorization_method odds_factorizer);
unsigned long evens_factorizer(unsigned long even_composite); // the most efficient factorization algorithm known for powers of two
unsigned long fermat_factorization(unsigned long composite);
// ^ And a lot of functions

_factorization_method factorization_method(int SELECTOR);
// ^ This function returns a function pointer
