#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"

typedef unsigned long ul;
unsigned long _REPORT_mod(); unsigned long *_REPORT_LOCATION_OF_mod();
char *REPORT_standard_prime_table_filename(); // < for access in other files to 'const char pointer standard_prime_table_filename'.
char *REPORT_open_prime_table(); // < for access in other files to 'char * _opened_prime_table' (which gets initialied to NULL).

struct ordered_pair { unsigned long a; unsigned long b; };

unsigned long conditional_field_cap(unsigned long result); unsigned long _conditional_field_cap(unsigned long result, unsigned long mod);
unsigned long add(unsigned long a, unsigned long b);
unsigned long multiply(unsigned long a, unsigned long b);
unsigned long inverse(unsigned long element_of_additive_group); // yields the additive inverse of ul 'element_of_additive_group'
unsigned long subtract(unsigned long a, unsigned long b);
unsigned long modular_division(unsigned long member_from_equivalence_class_representing_the_numerator, unsigned long denominator);

unsigned long _conditional_field_cap(unsigned long result, unsigned long mod_OVERRIDE);
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE);
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE);
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_OVERRIDE);
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE);
unsigned long _modular_division(unsigned long numerator, unsigned long denominator, unsigned long mod_OVERRIDE);

typedef unsigned long (*_group_operation) (unsigned long, unsigned long);
_group_operation operation_from_ID(unsigned long ID);

unsigned long exponentiate(unsigned long base, unsigned long exponent, unsigned long mod);
unsigned long exponentiate_UNRESTRICTEDLY(unsigned long base, unsigned long exponent); // << normal finite field exponentiation depends upon this ):
unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID);
// ^^^ Combine them all

/* ### OLD FUNCTIONS: */
unsigned long GCD(unsigned long a, unsigned long b);
unsigned long totient(unsigned long a);
// ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^ Order of inputs does not matter.

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a);

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
unsigned long least_base_TWO_log(unsigned long power_of_TWO);
unsigned long **UL_array_of_SIZE(int INDEX);
int UL_array_LENGTH(unsigned long **UL_array);
unsigned long polynomial_over_GF(unsigned long **coefficient, unsigned long _x); // < array of coefficient pointers needs to be in reversed order to how polynomials are usually written in standard form
unsigned long least_common_multiple(unsigned long a, unsigned long b);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long DOWN_ROUNDED_second_root(unsigned long number);

char *sieve_of_eratosthenes(unsigned long limit);
unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, unsigned long limit, FILE *FS);
FILE *prime_table_open(char *prime_table_filename); // < I want this to eventually try to cooperate with the logbook instead of stderr
void prime_table_close(FILE *prime_table); // < closes FS and resets char * variable '_open_prime_table' to NULL
int legendre_symbol(unsigned long odd_prime_p, unsigned long odd_prime_q);
