/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include "maths.h"

unsigned long conditional_field_cap(unsigned long result) { return (MOD) ? result % MOD : result; } // < Return result if there is no N_quotient, otherwise apply modular arithmetic
unsigned long addition(unsigned long a, unsigned long b) { return conditional_field_cap(a + b); }
unsigned long multiplication(unsigned long a, unsigned long b) { return conditional_field_cap(a * b); }
_group_operation operation_from_ID(unsigned long ID) { return (ID) ? multiplication : addition; }
// .^^^ All of the functions needed for "operation_from_ID"

unsigned long subtraction(unsigned long a, unsigned long b) { return conditional_field_cap(a + (MOD - b)); }
unsigned long additive_inverse(unsigned long element_of_additive_group) { return subtraction(0, element_of_additive_group); }
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
} // ^ Used by "exponentiation()", "polynomial_over_finite_field()"

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

unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID) { switch (ID) { case 0: return addition(a, b); case 1: return multiplication(a, b); case 2: return exponentiation(a, b); }; }

unsigned long polynomial_over_finite_field(unsigned long **coefficient, unsigned long _x) { ul terms_added, Res; terms_added = Res = ADDITIVE_IDENTITY; ul term_factor = MULTIPLICATIVE_IDENTITY;
    while (coefficient[terms_added]) { Res += (term_factor * *coefficient[terms_added]); Res %= MOD; term_factor *= _x; term_factor %= MOD; terms_added++; }
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
