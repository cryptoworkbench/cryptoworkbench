#include <stdio.h>
#include <stdlib.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
typedef unsigned long UL;
typedef unsigned long * UL_ptr;

unsigned long N_addition(unsigned long a, unsigned long b);
unsigned long FINITE_N_addition(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the addition operation for finite and non-finite arithmetic, with other words: --===>
// ^>> Define the addition operation for "modular" and "regular" arithmetic

unsigned long N_multiplication(unsigned long a, unsigned long b);
unsigned long FINITE_N_multiplication(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the multiplication operation for finite and non-finite arithmetic, with other words: --===>
// ^>> Define the multiplication operation for "modular" and "regular" arithmetic

unsigned long N_exponentiation(unsigned long BASE, unsigned long Exponent);
unsigned long FINITE_N_exponentiation(unsigned long BASE, unsigned long Exponent, unsigned long CAP);
// ^^^ Define the exponentiation operation for finite and non-finite arithmetic, with other words: --===>
// ^>> Define the exponentiation operation for "modular" and "regular" arithmetic


unsigned long N_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID);
// ^^^ Combine them all

/* ### OLD FUNCTIONS: */
unsigned long GCD(unsigned long a, unsigned long b);
// ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^ Order of inputs does not matter.

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a, unsigned long mod);

/* A simple exponentiation function which raises base to exponent.
 * 
 * Date type inputs are both unsigned, so we only need to watch these two potential exceptions:
 * Base is equal to the additive identity (0), in this case the resulting number from the exponentiation is always 0, because 0 multiplied by itself any amount of times will equal 0.
 * Base is equal to the multiplicative identity (1), in this case the resulting number from the exponentiation is always 1, because 1 multiplied by itself any amount of times will equal 1.
 *
 * Both I have been cognizant of in the design of this exponentiation function.
 *
 * Ps.
 * Returns the multiplicative identity when the exponent is 0.*/

/* Two functions for modular exponentiation */
unsigned long down_rounded_BASE_2_logarithm(unsigned long base_exponent);
