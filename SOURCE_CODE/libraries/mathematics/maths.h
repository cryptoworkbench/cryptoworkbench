#include <stdio.h>
#include <stdlib.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

unsigned long N_addition(unsigned long a, unsigned long b);
unsigned long FINITE_N_addition(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the ordinating addition operations for 'regular' (not FINITE) and 'modular' (FINITE) arithmetic respectively

unsigned long N_multiplication(unsigned long a, unsigned long b);
unsigned long FINITE_N_multiplication(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the N_multiplication N_multiplication operations for 'regular' (not FINITE) and 'modular' (FINITE) arithmetic, also respectively

typedef unsigned long (*INFINITE_field_combination) (unsigned long, unsigned long);
typedef unsigned long (*FINITE_field_combination) (unsigned long, unsigned long, unsigned long);
// ^^^ Define the neccessary function pointer types in order to define the following two functions

INFINITE_field_combination get_INFINITE_field_combination_from_inflection_point_(unsigned long inflection_point);
FINITE_field_combination get_FINITE_field_combination_from_inflection_point_(unsigned long inflection_point);
// ^^^ Define two functions to get the right (in)finite field operation (addition or N_multiplication {right == regarding finite or infinite fields})

unsigned long N_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID);




























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
unsigned long exponentiate(unsigned long base, unsigned long exponent); // READ BELOW

/* Two functions for modular exponentiation */
unsigned long down_rounded_base_2_logarithm(unsigned long base_exponent);
unsigned long mod_exponentiate(unsigned long base, unsigned long exponent, unsigned long modulus);
