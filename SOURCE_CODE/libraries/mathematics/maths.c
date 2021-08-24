/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include "maths.h"

/* Two functions for modular exponentiation */
unsigned long down_rounded_BASE_2_logarithm(unsigned long base_exponent) {
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

unsigned long N_addition(unsigned long A, unsigned long B) { return A + B; }

unsigned long N_multiplication(unsigned long A, unsigned long B) {
    unsigned long multiplication_RESULT = ADDITIVE_IDENTITY;
    // ^^ Start with an empty set

    UL iterator = ADDITIVE_IDENTITY;
    do { multiplication_RESULT = N_addition(multiplication_RESULT, A);
	iterator++; } while (iterator < B);
    // ^^ And prove multiplicication is repeated addition

    return multiplication_RESULT;
}

unsigned long FINITE_N_addition(unsigned long A, unsigned long B, unsigned long Limit) { return N_addition(A, B) % Limit; }
unsigned long FINITE_N_multiplication(unsigned long A, unsigned long B, unsigned long Limit) { return N_multiplication(A, B) % Limit; }
// ^^^ The finite (modular) ones

unsigned long N_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID) {
    if (ID) return (N_quotient == ADDITIVE_IDENTITY) ? N_multiplication(A, B) : FINITE_N_multiplication(A, B, N_quotient);
    return (N_quotient == ADDITIVE_IDENTITY) ? N_addition(A, B) : FINITE_N_addition(A, B, N_quotient);
}

unsigned long N_exponentiation(unsigned long BASE, unsigned long Exponent) {
    unsigned long ans = (0 < BASE); for (unsigned long iter = 0; iter < Exponent; iter++) ans = N_multiplication(ans, BASE);
    return ans;
}

unsigned long FINITE_N_exponentiation(unsigned long BASE, unsigned long Exponent, unsigned long CAP) {
    unsigned long least_BASE_two_logarihm = down_rounded_BASE_2_logarithm(Exponent);
    unsigned long *residue_array = (unsigned long *) malloc(sizeof(unsigned long) * least_BASE_two_logarihm);
    unsigned long NDX = ADDITIVE_IDENTITY; unsigned long ans = MULTIPLICATIVE_IDENTITY;
    // ^^^ Prepare variables

    residue_array[NDX] = FINITE_N_addition(BASE, ADDITIVE_IDENTITY, CAP); do {
	residue_array[NDX + 1] = FINITE_N_multiplication(residue_array[NDX], residue_array[NDX], CAP);
	NDX++;
    } while (NDX < least_BASE_two_logarihm);
    // ^^^ Initialize array

    while (Exponent != 0) {
	ans = (ans * residue_array[least_BASE_two_logarihm]) % CAP;
	Exponent -= N_exponentiation(2, least_BASE_two_logarihm);
	least_BASE_two_logarihm = down_rounded_BASE_2_logarithm(Exponent);
    } free(residue_array);
    // ^^^ Process array, arrive at result, and free array

    return ans;
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
