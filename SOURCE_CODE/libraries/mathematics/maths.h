/* When a commented-out line only contains one function header, this function is within the maths.c file but should not be used by functions outside of maths.c
 */
#include <stdio.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"

typedef unsigned long ul; unsigned long *mod_; 
char *_REPORT_standard_prime_table_filename(); // < for access in other files to 'const char pointer standard_prime_table_filename'.
char *_REPORT_open_prime_table(); // < for access in other files to 'char * _opened_prime_table' (which gets initialied to NULL).

struct ordered_pair { unsigned long a; unsigned long b; };

unsigned long mod_conditional_field_cap(unsigned long result); unsigned long _conditional_field_cap(unsigned long result, unsigned long mod);
unsigned long mod_add(unsigned long a, unsigned long b);
unsigned long mod_inverse(unsigned long element_of_additive_group); // 1).
unsigned long mod_subtract(unsigned long a, unsigned long b);
unsigned long mod_multiply(unsigned long a, unsigned long b);
unsigned long mod_divide(unsigned long member_from_equivalence_class_representing_the_numerator, unsigned long denominator);
unsigned long mod_polynomial(unsigned long **coefficient, unsigned long _x); // < array of coefficient pointers needs to be in reversed order to how polynomials are usually written in standard form
unsigned long mod_exponentiate(unsigned long base, unsigned long exponent); // 2).

unsigned long _conditional_field_cap(unsigned long result, unsigned long mod_);
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_);
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _divide(unsigned long numerator, unsigned long denominator, unsigned long mod_);
unsigned long _polynomial(unsigned long **COEFFICIENT_array, unsigned long _x, unsigned long mod);

typedef unsigned long (*_group_operation) (unsigned long, unsigned long);
_group_operation operation_from_ID(unsigned long ID);

unsigned long _exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_);
// unsigned long __HIDDEN__regular_exponentiation_function(unsigned long base, unsigned long exponent); // < a regular procedural exponentiation function which is at the base of all exponentiation done through the project

unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID);
// ^^^ Combine them all

/* ### OLD FUNCTIONS: */
unsigned long GCD(unsigned long a, unsigned long b);
unsigned long totient(unsigned long a);
// ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^ Order of inputs does not matter.

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a);
unsigned long least_base_TWO_log(unsigned long power_of_TWO);
unsigned long **UL_array_of_SIZE(int SIZE);
int UL_array_SIZE(unsigned long **UL_array);
unsigned long least_common_multiple(unsigned long a, unsigned long b);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long DOWN_ROUNDED_second_root(unsigned long number);

char *sieve_of_eratosthenes(unsigned long limit);
unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, unsigned long limit, FILE *FS);
FILE *prime_table_open(char *prime_table_filename); // < I want this to eventually try to cooperate with the logbook instead of stderr
void prime_table_close(FILE *prime_table); // < closes FS and resets char * variable '_open_prime_table' to NULL
int legendre_symbol(unsigned long odd_prime_p, unsigned long odd_prime_q);

/* Supplemantary notes:
 * 1). The multiplicative inverse is very different from the additive inverse, check the function 'multiplicative_inverse' for this problem.
 * 2). _exponentiate() always uses the square and multiply method
 */
