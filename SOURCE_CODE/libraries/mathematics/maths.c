/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include "maths.h"
// #include "stdio.h"

unsigned long conditional_field_cap(unsigned long result) { return (MOD) ? result % MOD : result; } // < Return result if there is no N_quotient, otherwise apply modular arithmetic
unsigned long add(unsigned long a, unsigned long b) { return conditional_field_cap(a + b); }
unsigned long multiply(unsigned long a, unsigned long b) { return conditional_field_cap(a * b); }
_group_operation operation_from_ID(unsigned long ID) { return (ID) ? multiply : add; }
// .^^^ All of the functions needed for "operation_from_ID"

unsigned long inverse(unsigned long element_of_additive_group) { return MOD - element_of_additive_group; } // < root of the definition of subtract
unsigned long subtract(unsigned long a, unsigned long b) { return conditional_field_cap(a + inverse(b)); }
unsigned long modular_division(unsigned long numerator, unsigned long denominator) { while (numerator % denominator != 0) numerator += MOD; return numerator / denominator; }
// ^^^ Useful functions for (infinite) field arithmetic

unsigned long exponentiate_UNRESTRICTEDLY(unsigned long base, unsigned long exponent) {
    unsigned long exponentiation_RESULT = (0 < base);
    for (unsigned long iter = 0; iter < exponent; iter++)
	exponentiation_RESULT *= base;

    return exponentiation_RESULT;
} // ^ Used by "exponentiate_using_backbone()", "exponentiation()"

unsigned long *square_and_multiply_backbone(unsigned long base, unsigned long required_base_two_log) {
    ul *backbone = (unsigned long *) malloc(sizeof(unsigned long) * (required_base_two_log + 1));
    ul iterator = ADDITIVE_IDENTITY; 

    backbone[iterator] = base % MOD;
    while (iterator < required_base_two_log) { backbone[iterator + 1] = (backbone[iterator] * backbone[iterator]) % MOD; iterator++; }
    // ^^ Regarding this second line:
    // In the case where the variable "exponent" was 0, this function would not be called
    // In the case where the variable "exponent" is 1, the while loop will not run
    // In the other cases (where 1 < "exponent"), it will run just the appriopiate amount of times

    return backbone;
} // ^ Used by "exponentiation()", "SINGULAR_polynomial_over_GF()"

unsigned long least_base_TWO_log(unsigned long power_of_TWO) {
    if (power_of_TWO == 0) return 0;
    unsigned long return_value = ADDITIVE_IDENTITY; // Initialize the logarithm of the base 2 exponentiation (the additive correspondence in the isomorphish)
    unsigned long multiplicative_accumulator = MULTIPLICATIVE_IDENTITY; // Initialize the variable on which we will perform base 2 exponentiation (the multiplicative corrspondence in the isomorphish)

    // Find the first power of 2 which is not smaller than power_of_TWO
    while (multiplicative_accumulator < power_of_TWO) {
	multiplicative_accumulator *= 2;
	return_value++;
    }

    // If the first power of 2 which is not smaller than "power_of_TWO", is equal to the power_of_TWO, then the power_of_TWO is a power of two, and all is set and done.
    //
    // If however, as will be in most cases, the first power of two which is not smaller than 'power_of_TWO' is actually greater than 'power_of_TWO', we over-estimated.
    //
    // In this case 'multiplicative_accumulator' over 2 ('multiplicative_accumulator / 2' in code) will be less than power_of_TWO, but also the greatest power of two which still fits power_of_TWO.
    if (multiplicative_accumulator > power_of_TWO)
	return_value--;

    return return_value;
} // ^ Used by "exponentiation_using_backbone()", "exponentiation()"

unsigned long exponentiation_using_backbone(unsigned long *residue_list, unsigned long index, unsigned long exponent) {
    ul return_value = MULTIPLICATIVE_IDENTITY;
    while (exponent != 0) {
	return_value *= residue_list[index]; return_value %= MOD;
	exponent -= exponentiate_UNRESTRICTEDLY(2, index);
	index = least_base_TWO_log(exponent);
    } return return_value;
} // ^ Used by "exponentiation()"

unsigned long exponentiation(unsigned long base, unsigned long exponent) { if (MOD == 0) return exponentiate_UNRESTRICTEDLY(base, exponent);
    if (base == 0 || exponent == 0) return 1;
    unsigned long mininum_log = least_base_TWO_log(exponent);
    unsigned long *backbone = square_and_multiply_backbone(base, mininum_log);
    ul exponentiation_RESULT = exponentiation_using_backbone(backbone, mininum_log, exponent);
    free(backbone); return exponentiation_RESULT;
} // ^ Used by N_operation

unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID) { switch (ID) { case 0: return add(a, b); case 1: return multiply(a, b); default: return exponentiation(a, b); }; }

unsigned long SINGULAR_polynomial_over_GF(unsigned long **coefficient, unsigned long _x) { ul additions, Res; additions = Res = ADDITIVE_IDENTITY; ul term_factor = MULTIPLICATIVE_IDENTITY;
    while (coefficient[additions]) { Res += (term_factor * *coefficient[additions]); Res %= MOD; term_factor *= _x; term_factor %= MOD; additions++; }
    return Res;
}

unsigned long polynomial_over_GF(unsigned long x, int number_of_coefficients, ...) {
    ul additions, Res; additions = Res = ADDITIVE_IDENTITY; ul term_factor = MULTIPLICATIVE_IDENTITY;
    va_list ap;
    va_start (ap, number_of_coefficients);
    for (ul i = 0; i < number_of_coefficients; i++) {
	Res += (va_arg(ap, unsigned long)); Res %= MOD; term_factor *= x; term_factor %= MOD; additions++;
    } va_end(ap);

    return Res;
}

unsigned long GCD(unsigned long a, unsigned long b) {
    unsigned long remainder = a % b;
    while (remainder != 0) {
	a = b;
	b = remainder;
	remainder = a % b;
    }

    return b;
} /* ^ Calculates the GCD using a procedural implementation of the euclidean algorithm ^^^ */

unsigned long totient(unsigned long a) {
    unsigned long totient = 0;

    for (unsigned long i = 1; i < a; i++)
	if (GCD(i, a) == 1) totient++;

    return totient;
}

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y) {
    if (a == 0) {
	*x = 0;
	*y = 1;
	return b;
    }

    unsigned long _x, _y;
    unsigned long gcd = extended_gcd(b % a, a, &_x, &_y);

    *x = _y - (b/a) * _x;
    *y = _x;

    return gcd;
}

unsigned long multiplicative_inverse(unsigned long a) { // Yield a^-1 mod b
    unsigned long x, y;
    extended_gcd(a, MOD, &x, &y);

    return MOD + x;
}

unsigned long least_common_multiple(unsigned long a, unsigned long b) {
    unsigned long least_common_multiple = a; if (a < b) least_common_multiple = b;
    while (least_common_multiple % a != 0 || least_common_multiple % b != 0) least_common_multiple++;
    return least_common_multiple;
}

unsigned long DOWN_ROUNDED_second_root(unsigned long number) {
    struct ordered_pair pair = {0, 0}; update(&pair, number);
    if (pair.b == number) return pair.a;
    else return pair.a - 1;
}

unsigned long HALT_VAL(unsigned long composite, int stupidity_level) {
    switch (stupidity_level) {
	case 3: return composite;
	case 2: return (composite - (composite % 2)) / 2;
	case 1: return DOWN_ROUNDED_second_root(composite);
    };
}

struct ordered_pair most_naive_factorization_approach(unsigned long composite) {
    for (ul i = 2; i < HALT_VAL(composite, 3); i++) if (composite % i == 0) return (struct ordered_pair) { composite / i, i };
    return (struct ordered_pair) { composite, 1 };
}

struct ordered_pair less_naive_factorization_approach(unsigned long composite) {
    for (ul i = 2; i <= HALT_VAL(composite, 2); i++) if (composite % i == 0) return (struct ordered_pair) { composite / i, i };
    return (struct ordered_pair) { composite, 1 };
}

struct ordered_pair least_naive_factorization_approach(unsigned long composite) { struct ordered_pair ret_val;
    for (ul i = 2; i <= HALT_VAL(composite, 1); i++) if (composite % i == 0) { ret_val.a = composite / i; ret_val.b = i; return pair_reorder(&ret_val); }
    return (struct ordered_pair) { composite, 1 };
}

// Now some functions to achieve Fermat factorization
// We will use "struct ordered_pair"
// We will use unsigned long member 'a' for the roots
// We will use unsigned member 'b' for the squares
void update(struct ordered_pair *to_be_updated, unsigned long least) { while (to_be_updated->b < least) { to_be_updated->b += to_be_updated->a; to_be_updated->a++; to_be_updated->b += to_be_updated->a; } }
// ^ dependency of 'fermats_factorization_approach_ENGINE()'

struct ordered_pair fermats_factorization_approach_ENGINE(unsigned long odd_composite) {
    struct ordered_pair square_BIG = {0, 0}; // Declare the struct we will use for the 'BIG' square
    struct ordered_pair square_SMALL = {0, 0}; // Declare the struct we will use for the 'SMALL' square
    while (square_BIG.b != odd_composite + square_SMALL.b) {
	update(&square_BIG, odd_composite + square_SMALL.b);
	update(&square_SMALL, square_BIG.b - odd_composite);
    } return (struct ordered_pair) { square_BIG.a + square_SMALL.a, square_BIG.a - square_SMALL.a};
} struct ordered_pair fermats_factorization_approach(unsigned long composite) { return factorization_method_WRAPPER(fermats_factorization_approach_ENGINE, composite); }

struct ordered_pair pair_reorder(struct ordered_pair *pair) { if (pair->a < pair->b) { unsigned long temp = pair->b; pair->b = pair->a; pair->a = temp; } return *pair; }
// ^ Switched the values of member 'a' and member 'b' with a 'struct ordered_pair' pair of numbers IFF 'b' > 'a'

struct ordered_pair factorization_method_WRAPPER(_factorization_method factorization_method_that_cannot_handle_even_numbers, unsigned long COMPOSITE) { struct ordered_pair ret_val;
    ul exponent_of_two_within_COMPOSITE = MULTIPLICATIVE_IDENTITY; // start off assuming 'COMPOSITE' is divisible by 2 ZERO times
    while (COMPOSITE % 2 == 0) { COMPOSITE /= 2; exponent_of_two_within_COMPOSITE *= 2; }
    if (exponent_of_two_within_COMPOSITE != 1) { ret_val.a = exponent_of_two_within_COMPOSITE; ret_val.b = COMPOSITE; }
    else { ret_val = factorization_method_that_cannot_handle_even_numbers(COMPOSITE); }
    return pair_reorder(&ret_val);
}
