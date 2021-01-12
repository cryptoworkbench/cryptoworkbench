#include <stdio.h>
#include <stdlib.h>

int _read_prime(unsigned long *prime_space_ptr, FILE *prime_table_fs, int binary_mode);
unsigned long lookup_factorize(unsigned long presumed_composite, int binary_mode, FILE *prime_table_fs);
/* ^^ Returns the least natural divisor of "presumed_composite" greater than 1, WITH OTHER WORDS: ==>
 * When "presumed_composite" is prime, this function returns "presumed_composite"
 * When "presumed_composite" is composite, this function returns the least (prime) divisor of "presumed_composite"
 *
 * This function at it's basis is just a simple primality checker.
 * When the supplied prime table is not extensive enough such that this primality check can be done, 0 is returned.
 */

int prime(unsigned long presumed_composite, int binary_mode, FILE *prime_table_fs);
// ^^ Ternary function to make the above factorization engine into a primality test

unsigned long GCD(unsigned long a, unsigned long b);
/* ^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^
 * Order of inputs does not matter.
 */

long extended_gcd(long a, long b, long *x, long *y);
long multiplicative_inverse(long a, long b);

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
