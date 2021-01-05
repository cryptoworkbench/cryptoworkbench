/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include <stdlib.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

/* unsigned int prime(unsigned long potential_prime) {
    for (unsigned long i = 2; i <= (potential_prime - (potential_prime % 2)) / 2; i++)
	if (potential_prime % i == 0)
	    return 0;
    return 1;
} */

unsigned long euclidean_algorithm(unsigned long big, unsigned long small) {
    if (big % small == 0)
	return small;

    return euclidean_algorithm(small, big % small);
}

long extended_gcd(long a, long b, long *x, long *y) {
    if (a == 0) {
	*x = 0;
	*y = 1;
	return b;
    }

    long _x, _y;
    long gcd = extended_gcd(b % a, a, &_x, &_y);

    *x = _y - (b/a) * _x;
    *y = _x;

    return gcd;
}

long multiplicative_inverse(long a, long b) { // Yield a^-1 mod b
    long x, y; extended_gcd(a, b, &x, &y);
    return b + x;
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
    residue_array[index] = base % modulus;
    do {
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
