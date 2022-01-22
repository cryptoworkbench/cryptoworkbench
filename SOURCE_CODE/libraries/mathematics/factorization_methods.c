#include <stdio.h> // needed for 'fprintf()'
#include "../functional/string.h" // needed for definition EXIT_STATUS_GOODBYE
#include "factorization_methods.h" // need for function headers
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number) {
    struct ordered_pair pair_of_divisors; pair_of_divisors.a = DIVISOR_OF_number; pair_of_divisors.b = number / pair_of_divisors.a; return pair_of_divisors; }

struct ordered_pair trial_division(unsigned long presumed_composite, unsigned long trial_limit) {
    ul divisor = MULTIPLICATIVE_IDENTITY; do { divisor++; if (trial_limit < divisor) divisor == presumed_composite; } while (presumed_composite % divisor != 0);

    struct ordered_pair ret_val = divisor_pair(presumed_composite, divisor);
    return pair_reorder(&ret_val);
} // 'LEAST_efficient_trial_division()', 'LESS_efficient_trial_division()', 'efficient_trial_division()'

struct ordered_pair _trial_division_TABLE_AIDED(unsigned long presumed_composite, unsigned long trial_limit, FILE *prime_table) {
    ul prime_divisor; do {
	if (fscanf(prime_table, "%lu\n", &prime_divisor) != 1)
	{ fprintf(stderr, "The prime table '%s' not complete enough to find the first prime divisor of %lu. The last prime tested was %lu.\n", REPORT_open_prime_table(), presumed_composite, prime_divisor); exit(-1); }
	if (prime_divisor > trial_limit) prime_divisor = presumed_composite;
    } while (presumed_composite % prime_divisor != 0); prime_table_close(prime_table);

    struct ordered_pair ret_val = divisor_pair(presumed_composite, prime_divisor);
    return pair_reorder(&ret_val);
}

struct ordered_pair trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit) { return _trial_division_TABLE_AIDED(composite, trial_limit, prime_table_open(REPORT_standard_prime_table_filename()));}
// ^ 'trial_division_TABLE_AIDED()' simply calls '_trial_division_TABLE_AIDED()' without 'char *prime_table_filename_specification' specification field.

unsigned long trial_limit(unsigned long composite, int supidity_level)
{ switch (supidity_level) { case 3: return composite; case 2: return (composite - (composite % 2)) / 2; case 1: return DOWN_ROUNDED_second_root(composite); }; }

struct ordered_pair LEAST_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 3)); }
struct ordered_pair LESS_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 2)); }
struct ordered_pair efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 1)); }
// ^ trial division methods

struct ordered_pair LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 3)); }
struct ordered_pair LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 2)); }
struct ordered_pair efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 1)); }
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
    } return (struct ordered_pair) { square_BIG.a - square_SMALL.a, square_BIG.a + square_SMALL.a};
}

struct ordered_pair pair_reorder(struct ordered_pair *pair) { if (pair->a > pair->b) { unsigned long temp = pair->a; pair->a = pair->b; pair->b = temp; } return *pair; }
// ^ Switched the values of member 'a' and member 'b' within a 'struct ordered_pair' pair of numbers IFF 'b' > 'a'

struct ordered_pair twos_factor_filter(unsigned long even_composite) { struct ordered_pair ret_val;
    ret_val.a = MULTIPLICATIVE_IDENTITY; do { even_composite /= 2; ret_val.a *= 2; } while (even_composite % 2 == 0); // REMEMBER: this function is only supposed to be called for an even composite!
    ret_val.b = even_composite;
    return pair_reorder(&ret_val);
}

struct ordered_pair odd_composite_decomposer_WRAPPER(unsigned long composite, _factorization_method odds_decomposer) { return (composite % 2 == 0) ? twos_factor_filter(composite) : odds_decomposer(composite); }
struct ordered_pair fermat_factorization(unsigned long composite) { return odd_composite_decomposer_WRAPPER(composite, difference_of_squares_factorization_method); }

_factorization_method factorization_method(int SELECTOR) {
    switch (SELECTOR) { case 0: return LEAST_efficient_trial_division; case 1: return LESS_efficient_trial_division; case 2: return efficient_trial_division; case 3: return LEAST_efficient_trial_division_TABLE_AIDED;
	case 4: return LESS_efficient_trial_division_TABLE_AIDED; case 5: return efficient_trial_division_TABLE_AIDED; case 6: return difference_of_squares_factorization_method; case 7: return fermat_factorization; };
} // ^ the central point of function unity
