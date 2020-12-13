// unsigned int prime(unsigned long potential_prime); // Returns 1 if potential_prime is prime, returns 0 if potential_prime is composite
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
unsigned long down_rounded_base_2_logarithm(unsigned long exponent);
unsigned long mod_exponentiate(unsigned long base, unsigned long exponent, unsigned long modulus);
