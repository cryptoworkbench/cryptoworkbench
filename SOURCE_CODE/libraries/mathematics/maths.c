/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include "maths.h"

unsigned long N_addition(unsigned long a, unsigned long b) { return a + b; }
unsigned long N_multiplication(unsigned long a, unsigned long b) { return a * b; }
// ^^^ Define respectively, the following first-degree (in)finite field combinations:
// ^^^ ~ Addition in infinite fields (regular addition without MODding the result)
// ^^^ ~ Addition in finite fields (addition with MODding the result)

unsigned long FINITE_N_addition(unsigned long a, unsigned long b, unsigned long CAP) { return N_addition(a, b) % CAP; }
unsigned long FINITE_N_multiplication(unsigned long a, unsigned long b, unsigned long CAP) { return N_multiplication(a, b) % CAP; }
// ^^^ Define respectively, the following second-degree (in)finite field combinations:
// ^^^ ~ Multiplication in infinite fields (regular multiplication without MODding the result)
// ^^^ ~ Multiplication in finite fields (multiplication with MODding the result)

INFINITE_field_combination get_INFINITE_field_combination_from_inflection_point_(unsigned long inflection_point) {
    if (inflection_point == ADDITIVE_IDENTITY) return &N_addition;
    else return &N_multiplication;
}

FINITE_field_combination get_FINITE_field_combination_from_inflection_point_(unsigned long inflection_point) {
    if (inflection_point == ADDITIVE_IDENTITY) return &FINITE_N_addition;
    else return &FINITE_N_multiplication;
}

unsigned long N_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID) {
    if (ID) return (N_quotient == ADDITIVE_IDENTITY) ? N_multiplication(A, B) : FINITE_N_multiplication(A, B, N_quotient);
    return (N_quotient == ADDITIVE_IDENTITY) ? N_addition(A, B) : FINITE_N_addition(A, B, N_quotient);
}













unsigned long GCD(unsigned long a, unsigned long b) {
    unsigned long remainder = a % b;
    while (remainder != 0) { a = b; b = remainder; remainder = a % b; } return b; }
/* ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm ^^^ */

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

unsigned long multiplicative_inverse(unsigned long a, unsigned long mod) { // Yield a^-1 mod b
    unsigned long x, y; extended_gcd(a, mod, &x, &y);
    return mod + x;
}

unsigned long exponentiate(unsigned long base, unsigned long exponent) {
    if (base == 0)
	return 0;
    else if (base == 1)
	return 1;
    else {
	unsigned long ret = MULTIPLICATIVE_IDENTITY;
	for (unsigned long iterator = 0; iterator < exponent; iterator++)
	    ret *= base;
	return ret;
    }
}

/* Two functions for modular exponentiation */
unsigned long down_rounded_base_2_logarithm(unsigned long base_exponent) {
    unsigned long return_value = ADDITIVE_IDENTITY; // Initialize the logarithm of the base 2 exponentiation
    unsigned long power_of_two = MULTIPLICATIVE_IDENTITY; // Initialize the variable on which we will perform base 2 exponentiation

    /* Find the first power of 2 which is not smaller than the base_exponent */
    while (!(power_of_two >= base_exponent)) {
	power_of_two *= 2;
	return_value++;
    }

    /* If the first power of 2 which is not smaller than the base_exponent, is equal to the base_exponent, then the base_exponent is a power of two, and all is set and done.
     *
     * If however, as will be in most cases, the first power of two which is not smaller than 'base_exponent' is actually greater than 'base_exponent', we over-estimated.
     *
     * In this case 'power_of_two' over 2 ('power_of_two / 2' in code) will be less than base_exponent, but also the greatest power of two which still fits base_exponent. */
    if (power_of_two > base_exponent)
	return_value--;

    return return_value;
}

unsigned long mod_exponentiate(unsigned long base, unsigned long base_exponent, unsigned long modulus) {
    /* Prepare variables */
    unsigned long least_base_two_logarithm = down_rounded_base_2_logarithm(base_exponent);
    unsigned long *residue_array = (unsigned long *) malloc(sizeof(unsigned long) * least_base_two_logarithm);
    unsigned long index = ADDITIVE_IDENTITY;
    unsigned long return_value = MULTIPLICATIVE_IDENTITY;

    /* Initialize array */
    residue_array[index] = base % modulus; do {
	residue_array[index + 1] = (residue_array[index] * residue_array[index]) % modulus;
	index++;
    } while (index < least_base_two_logarithm);

    /* Process array, arrive at result, and free array */
    while (base_exponent != 0) {
	return_value = (return_value * residue_array[least_base_two_logarithm]) % modulus;
	base_exponent -= exponentiate(2, least_base_two_logarithm);
	least_base_two_logarithm = down_rounded_base_2_logarithm(base_exponent);
    } free(residue_array);

    /* Return return_value */
    return return_value;
}
