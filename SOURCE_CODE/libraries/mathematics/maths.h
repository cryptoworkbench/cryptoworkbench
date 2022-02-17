#include <stdio.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"

struct ordered_pair { unsigned long a; unsigned long b; };
typedef unsigned long (*mod_group_operation) (unsigned long, unsigned long);
typedef unsigned long (*_group_operation) (unsigned long, unsigned long, unsigned long);
typedef unsigned long ul;

unsigned long *mod_, *id_; // < a function that starts with one of these works with one of these

char *_REPORT_standard_prime_table_filename(); // < for access in other files to 'const char pointer standard_prime_table_filename'.
char *_REPORT_open_prime_table(); // < for access in other files to 'char * _opened_prime_table' (which gets initialied to NULL).

struct ordered_pair _isomorphism();

unsigned long exponentiate(unsigned long base, unsigned long exponent); unsigned long _exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_);
unsigned long mod_exponentiate(unsigned long base, unsigned long exponent);
// required exponentiation functions ^^^

unsigned long _conditional_field_cap(unsigned long result, unsigned long mod_);
unsigned long mod_conditional_field_cap(unsigned long result);
// takes a modulus value if set ^^

unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long mod_add(unsigned long a, unsigned long b);
// add under (modular) arithmetic ^^

unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_);
unsigned long mod_inverse(unsigned long element_of_additive_group);
// take the additive inverse ^^

unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long mod_subtract(unsigned long a, unsigned long b);
// subtract under (modular) arithmetic ^^

unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long mod_multiply(unsigned long a, unsigned long b);
// multiply under (modular) arithmetic ^^

unsigned long _divide(unsigned long numerator, unsigned long denominator, unsigned long mod_);
unsigned long mod_divide(unsigned long member_from_equivalence_class_representing_the_numerator, unsigned long denominator);
// divide under (modular) arithmetic ^^

unsigned long _polynomial(unsigned long **COEFFICIENT_array, unsigned long _x, unsigned long mod);
unsigned long mod_polynomial(unsigned long **coefficient, unsigned long _x);
// calculate a polynomial (under mod arithmetic) ^^

typedef struct ordered_pair STRUCT_DH_parameters;
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs);
unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, unsigned long private_key);
// functions for DH and DH based scemes (i.e. Elgamal) ^

_group_operation _operation_from_ID(unsigned long ID); mod_group_operation operation_from_ID(unsigned long ID);
mod_group_operation _finite_group_operation(unsigned long ID); mod_group_operation id_finite_group_operation();

unsigned long F_combi(unsigned long a, unsigned long b);
unsigned long GF_combi(unsigned long a, unsigned long b);
/* ### OLD FUNCTIONS: */
unsigned long GCD(unsigned long a, unsigned long b);
int coprime(unsigned long a, unsigned long b);
unsigned long UNRESTRICTED_GCD(unsigned long **array, unsigned long array_size);
unsigned long totient(unsigned long a);
// ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^ Order of inputs does not matter.

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a);
unsigned long least_base_TWO_log(unsigned long power_of_TWO);
unsigned long **UL_array_of_SIZE(int SIZE);
int UL_array_SIZE(unsigned long **UL_array);
unsigned long INDEX_within_UL_array(unsigned long *UL_array, unsigned long UL_array_SIZE, unsigned long number);
unsigned long least_common_multiple(unsigned long a, unsigned long b);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long DOWN_ROUNDED_second_root(unsigned long number);

char *sieve_of_eratosthenes(unsigned long limit);
unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, unsigned long limit, FILE *FS);
FILE *prime_table_open(char *prime_table_filename); // < I want this to eventually try to cooperate with the logbook instead of stderr
void prime_table_close(FILE *prime_table); // < closes FS and resets char * variable '_open_prime_table' to NULL
int eulers_criterion(unsigned long odd_prime_p, unsigned long odd_prime_q);
void open_urandom();
void close_urandom();
unsigned long urandom_number(unsigned long upper_bound);

/*
void chinese_remainder_theorem_COPRIME_ERROR();
_error_selector chinese_remainder_theorem_ERROR_SELECTOR(int i);
*/
unsigned long chinese_remainder_theorem(unsigned long remainder, unsigned long **moduli, unsigned long modulis);

/* Supplemantary notes:
 * 1). The multiplicative inverse is very different from the additive inverse, check the function 'multiplicative_inverse' for this problem.
 * 2). _exponentiate() always uses the square and multiply method
 */
