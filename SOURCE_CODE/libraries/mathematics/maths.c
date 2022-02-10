/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include <stdlib.h>
#include <stdarg.h>
#include "maths.h"
#include "../functional/string.h"

FILE *entropy_source = NULL;
const char *_standard_prime_table_filename = "shared_prime_table";
char *_REPORT_standard_prime_table_filename() { return (char *) _standard_prime_table_filename; }
char *_open_prime_table = NULL; char *_REPORT_open_prime_table() { return (char *) _open_prime_table; }
// Two global variables and two functions for access to these global variables in other files/libraries

struct ordered_pair _isomorphism() { struct ordered_pair ret_val = { ADDITIVE_IDENTITY, MULTIPLICATIVE_IDENTITY }; return ret_val; }

unsigned long _conditional_field_cap(unsigned long result, unsigned long mod_) { return (mod_) ? result % mod_ : result; }
unsigned long mod_conditional_field_cap(unsigned long result) { return (*mod_) ? _conditional_field_cap(result, *mod_) : result; }
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_field_cap(a + b, mod_); }
unsigned long mod_add(unsigned long a, unsigned long b) { return _add(a, b, *mod_); }
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_) { return _conditional_field_cap(mod_ - element_of_additive_group, mod_); }
unsigned long mod_inverse(unsigned long element_of_additive_group) { return _inverse(element_of_additive_group, *mod_); }
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_field_cap(a + _inverse(b, mod_), mod_); }
unsigned long mod_subtract(unsigned long a, unsigned long b) { return _subtract(a, b, *mod_); }
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_field_cap(a * b, mod_); }
unsigned long mod_multiply(unsigned long a, unsigned long b) { return mod_conditional_field_cap(a * b); } 
unsigned long _divide(unsigned long numerator, unsigned long denominator, unsigned long mod_)
{ if (mod_) while (numerator % denominator != 0) numerator += mod_; return _conditional_field_cap(numerator / denominator, mod_); }
unsigned long mod_divide(unsigned long numerator, unsigned long denominator) { return _divide(numerator, denominator, *mod_); }
// ^ some functions and their wrappers

unsigned long exponentiate(unsigned long base, unsigned long exponent)
{ unsigned long exponentiation_RESULT = (0 < base); for (unsigned long iter = 0; iter < exponent; iter++) exponentiation_RESULT *= base; return exponentiation_RESULT; } 

unsigned long least_base_TWO_log(unsigned long power_of_TWO) {
    if (power_of_TWO == 0) return 0; unsigned long return_value = ADDITIVE_IDENTITY; unsigned long multiplicative_accumulator = MULTIPLICATIVE_IDENTITY;
    while (multiplicative_accumulator < power_of_TWO) { multiplicative_accumulator *= 2; return_value++; } if (multiplicative_accumulator > power_of_TWO) return_value--; return return_value;
}

unsigned long _exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_) {
    if (base == 0 || exponent == 0) return 1; unsigned long minimum_log = least_base_TWO_log(exponent); unsigned long *backbone = (unsigned long *) malloc(sizeof(unsigned long) * (minimum_log + 1));
    unsigned long i = ADDITIVE_IDENTITY; backbone[i] = _conditional_field_cap(base, mod_); while (i < minimum_log) { backbone[i + 1] = _multiply(backbone[i], backbone[i], mod_); i++; }
    unsigned long ret_val = MULTIPLICATIVE_IDENTITY;
    while (exponent != 0) { ret_val = _multiply(ret_val, backbone[minimum_log], mod_); exponent -= exponentiate(2, minimum_log); minimum_log = least_base_TWO_log(exponent); } free(backbone); return ret_val;
} unsigned long mod_exponentiate(unsigned long base, unsigned long exponent) { return _exponentiate(base, exponent, *mod_); }

unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, unsigned long DH_private_key) { return _exponentiate(DH_parameters->b, DH_private_key, DH_parameters->a); }
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs) { fprintf(fs, "(\u2115/%lu\u2115*, %lu)", DH_parameters->a, DH_parameters->b); }

unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID) { switch (ID) { case 0: return mod_add(a, b); case 1: return mod_multiply(a, b); default: return mod_exponentiate(a, b); }; }

_group_operation _operation_from_ID(unsigned long ID) { return (ID) ? _multiply : _add; }
mod_group_operation operation_from_ID(unsigned long ID) { return (ID) ? mod_multiply : mod_add; }

mod_group_operation _finite_group_operation(unsigned long ID) { return (ID) ? mod_multiply : mod_add; }
mod_group_operation id_finite_group_operation() { return _finite_group_operation(*id_); }

int part_of_group(unsigned long number) {
    if (*mod_ == 0 && *id_ != 0) return 1;
    // ^ every unsigned long is a part of the infinite field of natural numbers

    if (*id_ == 0 && number < *mod_) return 1; // additive group
    else if (GCD(number, *mod_) == 1) return 1; // multiplicative group
    return 0; // not part of one of the four above covered groups
}

unsigned long F_combi(unsigned long a, unsigned long b) {
    if (*mod_) { switch (*id_) { case 0: return mod_add(a, b); case 1: return mod_multiply(a, b); }; }
    else if (*id_) return _multiply(a, b, 0); return _add(a, b, 0);
}

unsigned long GF_combi(unsigned long a, unsigned long b) { return (*id_) ? mod_multiply(a, b) : mod_add(a, b); }

unsigned long **UL_array_of_SIZE(int SIZE) {
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * (SIZE + 1)); ret_val[SIZE] = NULL;
    for (int i = 0; i < SIZE; i++) ret_val[i] = (unsigned long *) malloc(sizeof(unsigned long)); return ret_val;
}

int UL_array_SIZE(unsigned long **UL_array) { int ret_val = 0; while (UL_array[ret_val]) ret_val++; return ret_val; }

unsigned long INDEX_within_UL_array(unsigned long *UL_array, unsigned long UL_array_SIZE, unsigned long number) {
    for (unsigned long INDEX = 0; INDEX < UL_array_SIZE; INDEX++) {
	if (UL_array[INDEX] == number) return INDEX;
    }
}

unsigned long _polynomial(unsigned long **COEFFICIENT_array, unsigned long _x, unsigned long mod_) {
    unsigned long ret_val = ADDITIVE_IDENTITY; unsigned long term_factor = MULTIPLICATIVE_IDENTITY; unsigned long i = UL_array_SIZE(COEFFICIENT_array);
    do { i--; ret_val = _add(ret_val, _multiply(term_factor, *COEFFICIENT_array[i], mod_), mod_); term_factor = _multiply(term_factor, _x, mod_); } while (i != 0); return ret_val;
} unsigned long mod_polynomial(unsigned long **COEFFICIENT_array, unsigned long _x) { return _polynomial(COEFFICIENT_array, _x, *mod_); }

unsigned long GCD(unsigned long a, unsigned long b) {
    unsigned long remainder = a % b;
    while (remainder != 0) {
	a = b;
	b = remainder;
	remainder = a % b;
    }

    return b;
} /* ^ Calculates the GCD using a procedural implementation of the euclidean algorithm ^^^ */

unsigned long UNRESTRICTED_GCD(unsigned long **array, unsigned long array_size) { unsigned long ret_val = *array[0]; for (unsigned long i = 1; i < array_size; i++) ret_val = GCD(ret_val, *array[i]); return ret_val; }

int coprime(unsigned long a, unsigned long b) { return (GCD(a, b) == 1) ? 1 : 0; }

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
    extended_gcd(a, *mod_, &x, &y);

    // return x; // doesn't work
    // return mod_conditional_field_cap(x); // doesn't work
    return mod_conditional_field_cap(*mod_ + x); // works // return (*mod_ + x) % *mod_; // also works
    // return x % *mod_; // doesn't work
}

unsigned long least_common_multiple(unsigned long a, unsigned long b) {
    unsigned long least_common_multiple = a; if (a < b) least_common_multiple = b;
    while (least_common_multiple % a != 0 || least_common_multiple % b != 0) least_common_multiple++;
    return least_common_multiple;
}

struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum)
{ while (to_be_updated->b < minimum) { to_be_updated->b += to_be_updated->a; to_be_updated->a++; to_be_updated->b += to_be_updated->a; } }
// ^ dependency of 'difference_of_squares_factorization()'

unsigned long DOWN_ROUNDED_second_root(unsigned long number) { struct ordered_pair pair = {0, 0}; least_perfect_square_equal_to_or_greater_than(&pair, number); if (pair.b == number) return pair.a; else return pair.a - 1;}
// ^ dependency of 'most_efficient_trail_division()' function in the library 'factorization_methods.c'

char *sieve_of_eratosthenes(unsigned long limit) {
    char *ret_val = (char *) malloc(sizeof(char) * (limit - 1)); // we allocate a spot less because I do not see the number one as a prime, or perhaps because it isn't ... ... ...
    unsigned long i; for (i = 2; i <= limit; i++) ret_val[i - 2] = 1; for (i = 2; i * i <= limit; i++) for (unsigned long j = i; j * i <= limit; j++) ret_val[(j * i) - 2] = 0;
    return ret_val;
} // ^ supposed to be used in conjunction with 'primes_printed_from_sieve_array_to_FS()'

unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, unsigned long limit, FILE *FS) { unsigned long ret_val = ADDITIVE_IDENTITY;
    for (unsigned long i = 2; i < limit; i++) if (sieve[i - 2]) { fprintf(FS, "%lu\n", i); ret_val++; } free(sieve); // it is quintisentially a difficult problem to predict the last prime in the sieve unfortunately
    return ret_val;
}

FILE *prime_table_open(char *prime_table_filename) {
    FILE *prime_table; if (prime_table = fopen(prime_table_filename, "r")) _open_prime_table = prime_table_filename;
    else { fprintf(stderr, PRIME_TABLE_UNAVAILABLE_ERROR EXIT_STATUS_GOODBYE, prime_table_filename, -1); exit(-1); }
    return prime_table;
} void prime_table_close(FILE *prime_table) { fclose(prime_table); _open_prime_table = NULL; }

int legendre_symbol(unsigned long odd_prime_p, unsigned long odd_prime_q) { return (odd_prime_q - 1 - _exponentiate(odd_prime_p, (odd_prime_q - 1) / 2, odd_prime_q)) ? 1 : -1; }

void open_urandom() { entropy_source = fopen("/dev/urandom", "r"); }
void close_urandom() { if (entropy_source) fclose(entropy_source); }

unsigned long urandom_number(unsigned long upper_bound) { if (!(entropy_source)) open_urandom();
    unsigned long ret_val; fread(&ret_val, sizeof(unsigned long), 1, entropy_source);
    ret_val = _conditional_field_cap(ret_val, upper_bound); return ret_val;
}

unsigned long chinese_remainder_theorem(unsigned long remainder, unsigned long **moduli, unsigned long modulis) { struct ordered_pair isomorphism = _isomorphism();
    for (unsigned long i = 0; i < modulis; i++, isomorphism.a += isomorphism.b, isomorphism.b = remainder) { for (unsigned long j = 0; j < modulis; j++) if (*moduli[i] != *moduli[j]) isomorphism.b *= *moduli[j];
	    unsigned long reduced_term = isomorphism.b % *moduli[i]; if (reduced_term != remainder) if (reduced_term != 1) isomorphism.b *= _divide(1, reduced_term, *moduli[i]); isomorphism.b *= remainder;
    } return isomorphism.a;
}
