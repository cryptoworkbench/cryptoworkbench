#include "factorization_methods.h" // needed for all of the function headers
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'

struct ordered_pair trail_division(unsigned long composite, unsigned long trail_limit) { struct ordered_pair ret_val;
    for (ul i = 2; i <= trail_limit; i++) if (composite % i == 0) { ret_val.a = composite / i; ret_val.b = i; return pair_reorder(&ret_val); }
    return (struct ordered_pair) { composite, 1 };
}

struct ordered_pair most_inefficient_trial_division(unsigned long composite) { return trail_division(composite, composite - 1); }
struct ordered_pair less_inefficient_trial_division(unsigned long composite) { return trail_division(composite, (composite - (composite % 2)) / 2); }
struct ordered_pair least_inefficient_trial_division(unsigned long composite) { return trail_division(composite, DOWN_ROUNDED_second_root(composite)); }

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

struct ordered_pair odd_composite_decomposer_WRAPPER(unsigned long composite, _factorization_method odds_decomposer)
{ return (composite % 2 == 0) ? twos_factor_filter(composite) : odds_decomposer(composite); }

struct ordered_pair pair_reorder(struct ordered_pair *pair) { if (pair->a < pair->b) { unsigned long temp = pair->b; pair->b = pair->a; pair->a = temp; } return *pair; }
// ^ Switched the values of member 'a' and member 'b' with a 'struct ordered_pair' pair of numbers IFF 'b' > 'a'

struct ordered_pair twos_factor_filter(unsigned long even_composite) { struct ordered_pair ret_val;
    ret_val.a = MULTIPLICATIVE_IDENTITY; do { even_composite /= 2; ret_val.a *= 2; } while (even_composite % 2 == 0); // REMEMBER: this function is only supposed to be called for an even composite!
    ret_val.b = even_composite;
    return pair_reorder(&ret_val);
}

struct ordered_pair fermat_factorization(unsigned long composite) { return odd_composite_decomposer_WRAPPER(composite, difference_of_squares_factorization_method); }
