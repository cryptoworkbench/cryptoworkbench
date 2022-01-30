/* This library contains all the math functions which are not verbose.
 *
 * See the header file for function descriptions. */
#include "maths.h" // needed for function headers and for the definition PRIME_TABLE_UNAVAILABLE_ERROR
#include "../functional/string.h" // needed for the definition EXIT_STATUS_GOODBYE

const char *_standard_prime_table_filename = "shared_prime_table";
char *_REPORT_standard_prime_table_filename() { return (char *) _standard_prime_table_filename; }
char *_open_prime_table = NULL; char *_REPORT_open_prime_table() { return (char *) _open_prime_table; }
// Two global variables and two functions for access to these global variables in other files/libraries

unsigned long _conditional_field_cap(unsigned long result, unsigned long mod_OVERRIDE) { return (mod_OVERRIDE) ? result % mod_OVERRIDE : result; }
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE) { return (mod_OVERRIDE) ? _conditional_field_cap(a + b, mod_OVERRIDE) : mod_add(a, b); }
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE) { return (mod_OVERRIDE) ? _conditional_field_cap(a * b, mod_OVERRIDE) : mod_multiply(a, b); }
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_OVERRIDE) { return _conditional_field_cap(mod_OVERRIDE - element_of_additive_group, mod_OVERRIDE); }
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_OVERRIDE) { return (mod_OVERRIDE) ? _conditional_field_cap(a + _inverse(b, mod_OVERRIDE), mod_OVERRIDE) : mod_subtract(a, b); }
unsigned long _division(unsigned long numerator, unsigned long denominator, unsigned long mod_OVERRIDE) {
    if (mod_OVERRIDE) while (numerator % denominator != 0) numerator += mod_OVERRIDE;
    return _conditional_field_cap(numerator / denominator, mod_OVERRIDE);
};
// ^ Basic arithemtic functions for (in)finite field operations

unsigned long conditional_field_cap(unsigned long result) { return (mod_) ? _conditional_field_cap(result, mod_) : result; }
unsigned long mod_add(unsigned long a, unsigned long b) { return conditional_field_cap(a + b); }
unsigned long mod_multiply(unsigned long a, unsigned long b) { return conditional_field_cap(a * b); }
unsigned long mod_inverse(unsigned long element_of_additive_group) { return conditional_field_cap(mod_ - element_of_additive_group); } // < root of the definition of mod_subtract
unsigned long mod_subtract(unsigned long a, unsigned long b) { return conditional_field_cap(a + mod_inverse(b)); }
unsigned long mod_division(unsigned long numerator, unsigned long denominator) { return (mod_) ? _division(numerator, denominator, mod_) : _division(numerator, denominator, 0); }
// ^ Wrappers for the previous block of functions which always use the global variable 'mod_'

_group_operation operation_from_ID(unsigned long ID) { return (ID) ? mod_multiply : mod_add; }
// .^^^ All of the functions needed for "operation_from_ID"

// ^^^ Useful functions for (infinite) field arithmetic

unsigned long exponentiate_UNRESTRICTEDLY(unsigned long base, unsigned long exponent) {
    unsigned long exponentiation_RESULT = (0 < base);
    for (unsigned long iter = 0; iter < exponent; iter++)
	exponentiation_RESULT *= base;

    return exponentiation_RESULT;
} // ^ Used by "exponentiate_using_backbone()", "exponentiate()"

unsigned long *square_and_multiply_backbone(unsigned long base, unsigned long required_base_two_log, unsigned long mod_) {
    unsigned long *backbone = (unsigned long *) malloc(sizeof(unsigned long) * (required_base_two_log + 1));
    unsigned long iterator = ADDITIVE_IDENTITY; 

    backbone[iterator] = _conditional_field_cap(base, mod_);
    while (iterator < required_base_two_log) { backbone[iterator + 1] = _multiply(backbone[iterator], backbone[iterator], mod_); iterator++; }
    // ^^ Regarding this second line:
    // In the case where the variable "exponent" was 0, this function would not be called
    // In the case where the variable "exponent" is 1, the while loop will not run
    // In the other cases (where 1 < "exponent"), it will run just the appriopiate amount of times

    return backbone;
} // ^ Used by "exponentiate()", "polynomial_over_GF()"

unsigned long least_base_TWO_log(unsigned long power_of_TWO) {
    if (power_of_TWO == 0) return 0;
    unsigned long return_value = ADDITIVE_IDENTITY; // Initialize the logarithm of the base 2 exponentiation (the additive correspondence in the isomorphish)
    unsigned long multiplicative_accumulator = MULTIPLICATIVE_IDENTITY; // Initialize the variable on which we will perform base 2 exponentiation (the multiplicative corrspondence in the isomorphish)

    // Find the first power of 2 which is not smaller than power_of_TWO
    while (multiplicative_accumulator < power_of_TWO) {
	multiplicative_accumulator *= 2;
	return_value++;
    }

    // If the first power of 2 which is not smaller than "power_of_TWO", is equal to the power_of_TWO, then the power_of_TWO is a power of two, and all is set and done.
    //
    // If however, as will be in most cases, the first power of two which is not smaller than 'power_of_TWO' is actually greater than 'power_of_TWO', we over-estimated.
    //
    // In this case 'multiplicative_accumulator' over 2 ('multiplicative_accumulator / 2' in code) will be less than power_of_TWO, but also the greatest power of two which still fits power_of_TWO.
    if (multiplicative_accumulator > power_of_TWO)
	return_value--;

    return return_value;
} // ^ Used by "exponentiation_using_backbone()", "exponentiate()"

unsigned long exponentiation_using_backbone(unsigned long *residue_list, unsigned long index, unsigned long exponent, unsigned long mod_) {
    unsigned long ret_val = MULTIPLICATIVE_IDENTITY;
    while (exponent != 0) {
	ret_val = _multiply(ret_val, residue_list[index], mod_);
	exponent -= exponentiate_UNRESTRICTEDLY(2, index);
	index = least_base_TWO_log(exponent);
    } return ret_val;
} // ^ Used by "exponentiate()"

unsigned long exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_) {
    if (base == 0 || exponent == 0) return 1; unsigned long mininum_log = least_base_TWO_log(exponent); unsigned long *backbone = square_and_multiply_backbone(base, mininum_log, mod_);
    unsigned long ret_val = exponentiation_using_backbone(backbone, mininum_log, exponent, mod_); free(backbone); return ret_val;
} // ^ 'N_operation()'

unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID) { switch (ID) { case 0: return mod_add(a, b); case 1: return mod_multiply(a, b); default: return exponentiate(a, b, mod_); }; }

unsigned long **UL_array_of_SIZE(int SIZE) {
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * (SIZE + 1)); ret_val[SIZE] = NULL;
    for (int i = 0; i < SIZE; i++) ret_val[i] = (unsigned long *) malloc(sizeof(unsigned long)); return ret_val;
}

int UL_array_SIZE(unsigned long **UL_array) { int ret_val = 0; while (UL_array[ret_val]) ret_val++; return ret_val; }

unsigned long polynomial_over_GF(unsigned long **COEFFICIENT_array, unsigned long _x) {
    unsigned long ret_val = ADDITIVE_IDENTITY; unsigned long term_factor = MULTIPLICATIVE_IDENTITY;
    int ONE_LESS_THAN_degree_of_polynomial = UL_array_SIZE(COEFFICIENT_array);
    unsigned long i = ONE_LESS_THAN_degree_of_polynomial; do { i--;
	ret_val = mod_add(ret_val, mod_multiply(term_factor, *COEFFICIENT_array[i])); term_factor = mod_multiply(term_factor, _x);
    } while (i != 0);
    return ret_val;
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
    extended_gcd(a, mod_, &x, &y);

    return mod_ + x;
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

int legendre_symbol(unsigned long odd_prime_p, unsigned long odd_prime_q) { return (odd_prime_q - 1 - exponentiate(odd_prime_p, (odd_prime_q - 1) / 2, odd_prime_q)) ? 1 : -1; }
