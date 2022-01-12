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

unsigned long N_addition(unsigned long A, unsigned long B) { return (A + B) % MOD; }
unsigned long N_multiplication(unsigned long A, unsigned long B) {
    unsigned long multiplication_RESULT = ADDITIVE_IDENTITY;
    // ^^ Start with an empty set

    UL iterator = ADDITIVE_IDENTITY;
    do { multiplication_RESULT = N_addition(multiplication_RESULT, A);
	iterator++; } while (iterator < B);
    // ^^ And prove multiplicication is repeated addition

    return multiplication_RESULT % MOD;
}

_group_operation operation_from_ID(unsigned long ID) { return (ID) ? N_multiplication : N_addition; }
// ^^^ The finite (modular) ones

unsigned long N_exponentiation(unsigned long BASE, unsigned long Exponent) {
    if (MOD) {
	unsigned long least_BASE_two_logarihm = down_rounded_BASE_2_logarithm(Exponent);
	unsigned long *residue_list = (unsigned long *) malloc(sizeof(unsigned long) * least_BASE_two_logarihm);
	// ^^ Prepare obvious variables (variables you'd think about)

	UL iter = ADDITIVE_IDENTITY; UL exponentiation_RESULT = MULTIPLICATIVE_IDENTITY;
	// ^^ Prepare less obvious variables (variables you come to realize you need once you start writting this function)

	residue_list[iter] = N_addition(ADDITIVE_IDENTITY, BASE);
	// ^^ Start with a first mod calculation of "BASE^1 % Limit"

	do {residue_list[iter + 1] = N_multiplication(residue_list[iter], residue_list[iter]); iter++; }
	while (iter < least_BASE_two_logarihm);
	// ^^ Continue the square and multiply method

	while (Exponent != 0) {
	    exponentiation_RESULT = (exponentiation_RESULT * residue_list[least_BASE_two_logarihm]) % MOD;
	    Exponent -= N_exponentiation(2, least_BASE_two_logarihm);
	    least_BASE_two_logarihm = down_rounded_BASE_2_logarithm(Exponent); }
	// ^^ Collect the pieces
	
	free(residue_list);
	// ^^ Free residue_list

	return exponentiation_RESULT;
    } else {
	unsigned long ans = (0 < BASE);
	for (unsigned long iter = 0; iter < Exponent; iter++)
	    ans = N_multiplication(ans, BASE);

	return ans;
    }
}

unsigned long N_combine(unsigned long A, unsigned long B, unsigned long ID) {
    switch (ID) {
	case 0: return N_addition(A, B);
	case 1: return N_multiplication(A, B);
	case 2: return N_exponentiation(A, B);
    };
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

unsigned long modular_division(unsigned long member_from_equivalence_class_representing_the_numerator, unsigned long denominator) {
    while (member_from_equivalence_class_representing_the_numerator % denominator != 0)
	member_from_equivalence_class_representing_the_numerator += MOD;

    return member_from_equivalence_class_representing_the_numerator / denominator;
}
