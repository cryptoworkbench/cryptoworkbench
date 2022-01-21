#include <stdio.h> // needed for 'fprintf()'
#include "../functional/string.h" // needed for definition EXIT_STATUS_GOODBYE
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'
#include "factorization_methods.h" // need for function headers
#define STANDARD_PRIME_TABLE_FILENAME "UNIVERSAL PRIME TABLE"
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"

struct ordered_pair trail_division(unsigned long composite, unsigned long trial_limit) { struct ordered_pair ret_val;
    // ul i = 1; do { i++; if (trial_limit < i) break; } while (composite % i != 0); // ul i = 1; do { i++; if (composite % i == 0) break; } while (trial_limit < i);
    ul i = 2; while (composite % i != 0) i++;
    ret_val.a = i; ret_val.b = composite / i; return ret_val;
} // 'trial_division_LEAST_EFFICIENT()', 'trial_division_LESS_EFFICIENT()', 'trial_division_MOST_EFFICIENT()'

struct ordered_pair _TABLE_AIDED_trial_division(unsigned long composite, unsigned long trial_limit, char *prime_table_filename) {
    struct ordered_pair ret_val; // ret_val.a = MULTIPLICATIVE_IDENTITY; ret_val.b = composite; // < prepare ret_val
    if (!prime_table_filename) prime_table_filename = _REPORT_standard_prime_table_filename(); FILE *prime_table;
    if (!(prime_table = fopen(prime_table_filename, "r"))) { fprintf(stderr, PRIME_TABLE_UNAVAILABLE_ERROR EXIT_STATUS_GOODBYE, prime_table_filename, -1); exit(-1); }

    ul prime; do {
	if (fscanf(prime_table, "%lu\n", &prime) != 1) { fprintf(stderr, "The prime table '%s' is not complete enough to find the first prime divisors of %lu.\n", prime_table_filename, composite); exit(-1); }
	if (trial_limit < prime) break;
    } while (composite % prime != 0); fclose(prime_table); // we perform the same while loop here as in 'trail_division()'
    if (composite % prime == 0) { ret_val.a = prime; ret_val.b = composite / ret_val.a; }
    else { ret_val.a = MULTIPLICATIVE_IDENTITY; ret_val.b = composite / ret_val.a; }
    return ret_val;
}

struct ordered_pair table_aided_trial_division(unsigned long composite, unsigned long trial_limit) { return _TABLE_AIDED_trial_division(composite, trial_limit, NULL); }
// ^ Dependency of 'trial_division_aided_by_table_STANDARDIZED()'

unsigned long trial_limit(unsigned long composite, int supidity_level)
{ switch (supidity_level) { case 3: return composite; case 2: return (composite - (composite % 2)) / 2; case 1: return DOWN_ROUNDED_second_root(composite); }; }

struct ordered_pair trial_division_LEAST_EFFICIENT(unsigned long composite) { return trail_division(composite, trial_limit(composite, 3)); }
struct ordered_pair trial_division_LESS_EFFICIENT(unsigned long composite) { return trail_division(composite, trial_limit(composite, 2)); }
struct ordered_pair trial_division_MOST_EFFICIENT(unsigned long composite) { return trail_division(composite, trial_limit(composite, 1)); }
// ^ trial division methods

struct ordered_pair TABLE_AIDED_trial_division_LEAST_EFFICIENT(unsigned long composite) { return table_aided_trial_division(composite, trial_limit(composite, 3)); }
struct ordered_pair TABLE_AIDED_trial_division_LESS_EFFICIENT(unsigned long composite) { return table_aided_trial_division(composite, trial_limit(composite, 2)); }
struct ordered_pair TABLE_AIDED_trial_division_MOST_EFFICIENT(unsigned long composite) { return table_aided_trial_division(composite, trial_limit(composite, 1)); }
// ^ same trial division methods aided by a table

// NOW SOME FUNCTIONS TO ACHIEVE FERMAT FACTORIZATION
// We will use "struct ordered_pair"
// We will use unsigned long member 'a' for the roots
// We will use unsigned member 'b' for the squares
struct ordered_pair difference_of_squares_factorization_method(unsigned long odd_composite) {
    struct ordered_pair square_BIG = {0, 0}; // Declare the struct we will use for the 'BIG' square
    struct ordered_pair square_SMALL = {0, 0}; // Declare the struct we will use for the 'SMALL' square
    while (square_BIG.b != odd_composite + square_SMALL.b) {
	least_perfect_square_equal_to_or_greater_than(&square_BIG, odd_composite + square_SMALL.b);
	least_perfect_square_equal_to_or_greater_than(&square_SMALL, square_BIG.b - odd_composite);
    } return (struct ordered_pair) { square_BIG.a + square_SMALL.a, square_BIG.a - square_SMALL.a};
}

struct ordered_pair pair_reorder(struct ordered_pair *pair) { if (pair->a < pair->b) { unsigned long temp = pair->b; pair->b = pair->a; pair->a = temp; } return *pair; }
// ^ Switched the values of member 'a' and member 'b' with a 'struct ordered_pair' pair of numbers IFF 'b' > 'a'

struct ordered_pair twos_factor_filter(unsigned long even_composite) { struct ordered_pair ret_val;
    ret_val.a = MULTIPLICATIVE_IDENTITY; do { even_composite /= 2; ret_val.a *= 2; } while (even_composite % 2 == 0); // REMEMBER: this function is only supposed to be called for an even composite!
    ret_val.b = even_composite;
    return pair_reorder(&ret_val);
}

struct ordered_pair odd_composite_decomposer_WRAPPER(unsigned long composite, _factorization_method odds_decomposer)
{ return (composite % 2 == 0) ? twos_factor_filter(composite) : odds_decomposer(composite); }

struct ordered_pair fermat_factorization(unsigned long composite) { return odd_composite_decomposer_WRAPPER(composite, difference_of_squares_factorization_method); }
