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
unsigned long down_rounded_base_2_logarithm(unsigned long exponent) {
    unsigned long return_value = ADDITIVE_IDENTITY; // Initialize the logarithm of the base 2 exponentiation
    unsigned long power_of_two = MULTIPLICATIVE_IDENTITY; // Initialize the variable on which we will perform base 2 exponentiation

    /* Find the first power of 2 which is not smaller than the exponent */
    while (!(power_of_two >= exponent)) {
	power_of_two *= 2;
	return_value++;
    }

    /* If the first power of 2 which is not smaller than the exponent, is equal to the exponent, then the exponent is a power of two, and all is set and done.
     *
     * If however, as will be in most cases, the first power of two which is not smaller than 'exponent' is actually greater than 'exponent', we over-estimated.
     *
     * In this case 'power_of_two' over 2 ('power_of_two / 2' in code) will be less than exponent, but also the greatest power of two which still fits exponent. */
    if (power_of_two > exponent)
	return_value--;

    return return_value;
}

unsigned long mod_exponentiate(unsigned long base, unsigned long exponent, unsigned long modulus) {
    /* Prepare variables */
    unsigned long greatest_power_of_two = down_rounded_base_2_logarithm(exponent);
    unsigned long *residue_array = (unsigned long *) malloc(sizeof(unsigned long) * greatest_power_of_two);
    unsigned long log = ADDITIVE_IDENTITY;
    unsigned long ret_val = MULTIPLICATIVE_IDENTITY;

    /* Initialize array */
    residue_array[log] = base % modulus;
    do {
	residue_array[log + 1] = (residue_array[log] * residue_array[log]) % modulus;
	log++;
    } while (log < greatest_power_of_two);

    /* Process array, arrive at result, and free array */
    while (exponent != 0) {
	ret_val %= (ret_val * residue_array[greatest_power_of_two]);
	exponent -= exponentiate(2, greatest_power_of_two);
	greatest_power_of_two = down_rounded_base_2_logarithm(exponent);
    } free(residue_array);

    /* Return ret_val */
    return ret_val;
}
