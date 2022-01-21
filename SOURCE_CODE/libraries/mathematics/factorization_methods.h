#define STANDARD_PRIME_TABLE_FILENAME "UNIVERSAL PRIME TABLE"

typedef struct ordered_pair (*_factorization_method) (unsigned long);
// ^ One function pointer type

struct ordered_pair trail_division(unsigned long composite, unsigned long trial_limit);
struct ordered_pair trial_division_aided_by_table(unsigned long composite, unsigned long trial_limit, char *prime_table_filename);
struct ordered_pair _trial_division_aided_by_table(unsigned long composite, unsigned long trial_limit);
// ^ Trial division factorization engines

unsigned long trial_limit(unsigned long composite, int supidity_level);
struct ordered_pair most_inefficient_trial_division(unsigned long composite);
struct ordered_pair less_inefficient_trial_division(unsigned long composite);
struct ordered_pair least_inefficient_trial_division(unsigned long composite);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
struct ordered_pair difference_of_squares_factorization_method(unsigned long odd_composite);
struct ordered_pair odd_composite_decomposer_WRAPPER(unsigned long composite, _factorization_method odds_decomposer);
struct ordered_pair pair_reorder(struct ordered_pair *pair);
struct ordered_pair twos_factor_filter(unsigned long even_composite);
struct ordered_pair fermat_factorization(unsigned long composite);
// ^ And a lot of functions

struct ordered_pair most_inefficient_trial_division_aided_by_table(unsigned long composite);
struct ordered_pair less_inefficient_trial_division_aided_by_table(unsigned long composite);
struct ordered_pair least_inefficient_trial_division_aided_by_table(unsigned long composite);
