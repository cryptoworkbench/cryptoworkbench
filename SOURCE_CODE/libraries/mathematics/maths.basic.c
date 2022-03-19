// This library contains all of the mathematics for (modular) arithmetic.
#include <stdlib.h>
#include <stdarg.h>
#include "maths.basic.h"

FILE *urandom = NULL;
const char *_standard_prime_table_filename = "shared_prime_table";

const char *additive_signs[] = {"0", "+", "addition", "additions", "additive", "add", 0};
const char *multiplicative_signs[] = {"1", "*", "multiplication", "multiplications", "multiplicative", "multiply", 0};

char *_REPORT_standard_prime_table_filename() { return (char *) _standard_prime_table_filename; }
char *_open_prime_table = NULL; char *_REPORT_open_prime_table() { return (char *) _open_prime_table; }
// Two global variables and two functions for access to these global variables in other files/libraries

struct ordered_pair _isomorphism() { struct ordered_pair ret_val = { ADDITIVE_IDENTITY, MULTIPLICATIVE_IDENTITY }; return ret_val; }
// a general function which a lot of functions in this library make use of ^^

// FUNCTIONS THAT HAVE TO DO WITH mod_ FOLLOW:
unsigned long _conditional_cap(ul result, ul mod_) { return (mod_) ? result % mod_ : result; }
unsigned long _add(ul a, ul b, ul mod_) { return _conditional_cap(a + b, mod_); }
unsigned long _inverse(ul element_of_additive_group, ul mod_) { return _conditional_cap(mod_ - _conditional_cap(element_of_additive_group, mod_), mod_); }
unsigned long _subtract(ul a, ul b, ul mod_) { return _conditional_cap(a + _inverse(b, mod_), mod_); }
unsigned long _multiply(ul a, ul b, ul mod_) { return _conditional_cap(a * b, mod_); }
unsigned long _divide(ul numerator, ul denominator, ul mod_)
{ if (mod_) while (numerator % denominator != 0) numerator += mod_; return _conditional_cap(numerator / denominator, mod_); }

unsigned long exponentiate(ul base, ul exponent)
{ unsigned long exponentiation_RESULT = (0 < base); for (ul iter = 0; iter < exponent; iter++) exponentiation_RESULT *= base; return exponentiation_RESULT; } 
unsigned long least_base_TWO_log(ul power_of_TWO) {
    if (power_of_TWO == 0) return 0; unsigned long return_value = ADDITIVE_IDENTITY; unsigned long multiplicative_accumulator = MULTIPLICATIVE_IDENTITY;
    while (multiplicative_accumulator < power_of_TWO) { multiplicative_accumulator *= 2; return_value++; } if (multiplicative_accumulator > power_of_TWO) return_value--; return return_value;
} unsigned long _exponentiate(ul base, ul exponent, ul mod_) {
    if (base == 0 || exponent == 0) return 1; unsigned long minimum_log = least_base_TWO_log(exponent); unsigned long *backbone = (unsigned long *) malloc(sizeof(unsigned long) * (minimum_log + 1));
    unsigned long i = ADDITIVE_IDENTITY; backbone[i] = _conditional_cap(base, mod_); while (i < minimum_log) { backbone[i + 1] = _multiply(backbone[i], backbone[i], mod_); i++; }
    unsigned long ret_val = MULTIPLICATIVE_IDENTITY;
    while (exponent != 0) { ret_val = _multiply(ret_val, backbone[minimum_log], mod_); exponent -= exponentiate(2, minimum_log); minimum_log = least_base_TWO_log(exponent); } free(backbone); return ret_val;
}
// functions that have to do with mod_exponentiate ^^^^

const char *_as_number(unsigned int id_) { return (id_) ? multiplicative_signs[0] : additive_signs[0]; }
const char *_as_operation_symbol(unsigned int id_) { return (id_) ? multiplicative_signs[1] : additive_signs[1]; }
const char *_as_noun(unsigned int id_) { return (id_) ? multiplicative_signs[2] : additive_signs[2]; }
const char *_as_nouns(unsigned int id_) { return (id_) ? multiplicative_signs[3] : additive_signs[3]; }
const char *_as_adjective(unsigned int id_) { return (id_) ? multiplicative_signs[4] : additive_signs[4]; }
const char *_as_verb(unsigned int id_) { return (id_) ? multiplicative_signs[5] : additive_signs[5]; }
// get the identity represented by corresponding number, operation symbol, singular noun, plural noun, adjective, or verb

void identity_error() { fprintf(stderr, "parsing of '%s' failed: could not match '%s' with any imaginable group operation description.", unparsed_str, unparsed_str); }

int _identity_parse_str(ui_ptr id_, char *str, int exit_status)
{ if (!str || (str && !((*id_ = _match(str, 6, multiplicative_signs)) || _match(str, 6, additive_signs)))) return n(error_message(not_parsable(identity_error, str), exit_status)); return 0; }
// to get the appriopiate group operation ^

void list_plausable_group_identity_descriptions(int argv_index)
{
    fflush(stderr);
    fprintf(stderr, "\n- \u2115%s+ could have been specified using '%s', '%s', '%s', '%s', '%s' or '%s'                        		instead of '%s'", (*argv_ptr)[1], additive_signs[5], additive_signs[4], additive_signs[2], additive_signs[3], additive_signs[0], additive_signs[1], (*argv_ptr)[argv_index]);
    fprintf(stderr, "\n- \u2115%s* could have been specified using '%s', '%s', '%s', '%s', '%s' or '%s'		instead of '%s'", (*argv_ptr)[1], multiplicative_signs[5], multiplicative_signs[4], multiplicative_signs[2], multiplicative_signs[3], multiplicative_signs[0], multiplicative_signs[1], (*argv_ptr)[argv_index]);
}

unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, ul DH_private_key) { return _exponentiate(DH_parameters->b, DH_private_key, DH_parameters->a); }
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs) { fprintf(fs, "(\u2115/%lu\u2115*, %lu)", DH_parameters->a, DH_parameters->b); }

unsigned long *UL_array_of_SIZE(int SIZE) { unsigned long *ret_val = (unsigned long *) malloc(sizeof(unsigned long) * SIZE); return ret_val; }
unsigned long INDEX_within_UL_array(ul_ptr UL_array, ul array_size, ul number) { for (unsigned long INDEX = 0; INDEX < array_size; INDEX++) if (UL_array[INDEX] == number) return INDEX;}

unsigned long _polynomial(ul x, ul_ptr coefficient, int number_of_coefficients, ul mod_) { struct ordered_pair iso = _isomorphism();
    int i = number_of_coefficients; do { i--; iso.a = _add(iso.a, _multiply(iso.b, coefficient[i], mod_), mod_); iso.b = _multiply(iso.b, x, mod_); } while (i != 0); return iso.a; }

unsigned long GCD(ul a, ul b) {
    unsigned long remainder = a % b;
    while (remainder != 0) {
	a = b;
	b = remainder;
	remainder = a % b;
    }

    return b;
} /* ^ Calculates the GCD using a procedural implementation of the euclidean algorithm ^^^ */

unsigned long UNRESTRICTED_GCD(ul_ptr array, ul array_size) { unsigned long ret_val = array[0]; for (unsigned long i = 1; i < array_size; i++) ret_val = GCD(ret_val, array[i]); return ret_val; }

int coprime(ul a, ul b) { return (GCD(a, b) == 1) ? 1 : 0; }

unsigned long totient(ul a) {
    unsigned long totient = 0;

    for (unsigned long i = 1; i < a; i++)
	if (GCD(i, a) == 1) totient++;

    return totient;
}

unsigned long extended_gcd(ul a, ul b, ul_ptr x, ul_ptr y) {
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


unsigned long LCM(ul a, ul b) { unsigned long ret_val = a; if (a < b) ret_val = b; while (ret_val % a != 0 || ret_val % b != 0) ret_val++; return ret_val; }
unsigned long UNRESTRICTED_LCM(ul_ptr array, ul array_size) { unsigned long ret_val = array[0]; for (unsigned long i = 1; i < array_size; i++) ret_val = LCM(ret_val, array[i]); return ret_val; }

struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, ul minimum)
{ while (to_be_updated->b < minimum) { to_be_updated->b += to_be_updated->a; to_be_updated->a++; to_be_updated->b += to_be_updated->a; } }
// ^ dependency of 'difference_of_squares_factorization()'

unsigned long DOWN_ROUNDED_second_root(ul number) { struct ordered_pair pair = {0, 0}; least_perfect_square_equal_to_or_greater_than(&pair, number); if (pair.b == number) return pair.a; else return pair.a - 1;}
// ^ dependency of 'most_efficient_trail_division()' function in the library 'factorization_methods.c'

char *sieve_of_eratosthenes(ul limit) {
    char *ret_val = (char *) malloc(sizeof(char) * (limit - 1)); // we allocate a spot less because I do not see the number one as a prime, or perhaps because it isn't ... ... ...
    unsigned long i; for (i = 2; i <= limit; i++) ret_val[i - 2] = 1; for (i = 2; i * i <= limit; i++) for (unsigned long j = i; j * i <= limit; j++) ret_val[(j * i) - 2] = 0;
    return ret_val;
} // ^ supposed to be used in conjunction with 'primes_printed_from_sieve_array_to_FS()'

unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, ul limit, FILE *FS) { unsigned long ret_val = ADDITIVE_IDENTITY;
    for (unsigned long i = 2; i < limit; i++) if (sieve[i - 2]) { fprintf(FS, "%lu\n", i); ret_val++; } free(sieve); // it is quintisentially a difficult problem to predict the last prime in the sieve unfortunately
    return ret_val;
}

void _prime_table_unavailable() { fprintf(stderr, "failed to access prime table '%s' !", _standard_prime_table_filename); }

void spec() { fprintf(stderr, " you can create it using 'prime_table_exporter'."); }

FILE *prime_table_open() {
    FILE *prime_table; if (prime_table = fopen(_standard_prime_table_filename, "r")) _open_prime_table = (char *) _standard_prime_table_filename;
    else conditional_goodbye(h(h(error_specification(spec, h(h(error_message(_prime_table_unavailable, -10)))))));
    return prime_table;
} void prime_table_close(FILE *prime_table) { fclose(prime_table); _open_prime_table = NULL; }

int _eulers_criterion(ul odd_prime_p, ul odd_prime_q) { return (odd_prime_q - 1 - _exponentiate(odd_prime_p, (odd_prime_q - 1) / 2, odd_prime_q)) ? 1 : -1; }

void open_urandom() { urandom = fopen("/dev/urandom", "r"); }
void close_urandom() { if (urandom) fclose(urandom); }

unsigned long urandom_number(ul upper_bound) { if (!(urandom)) open_urandom();
    unsigned long ret_val; fread(&ret_val, sizeof(unsigned long), 1, urandom);
    ret_val = _conditional_cap(ret_val, upper_bound); return ret_val;
}

unsigned long chinese_remainder_theorem(ul remainder, ul_ptr moduli, ul modulis) { struct ordered_pair isomorphism = _isomorphism();
    for (unsigned long i = 0; i < modulis; i++, isomorphism.a += isomorphism.b, isomorphism.b = remainder) { for (unsigned long j = 0; j < modulis; j++) if (moduli[i] != moduli[j]) isomorphism.b *= moduli[j];
	    unsigned long reduced_term = isomorphism.b % moduli[i]; if (reduced_term != remainder) if (reduced_term != 1) isomorphism.b *= _divide(1, reduced_term, moduli[i]); isomorphism.b *= remainder;
    } return isomorphism.a;
}

int pair_of_strs_represents_pair_of_coprime_ULs(_error_function _first_instruction, _error_function second_instruction, ul_ptr ptr_one, ul_ptr ptr_two, int _first_index, int second_index, int exit_status) {
    // requires 'argv_ptr' to be set ^

    if (error_specification(_first_instruction, n(_ul_parse_str(ptr_one, (*argv_ptr)[_first_index], 1)))) return - _first_index;
    if (error_specification(second_instruction, n(_ul_parse_str(ptr_two, (*argv_ptr)[second_index], 1)))) return - second_index;
    // interpret the numbers ^^

    if (coprime(*ptr_one, *ptr_two)) return 0;
    // perform the coprimality check ^

    fprintf(stderr, " GCD(%s, %s) != 1 -->  ", (*argv_ptr)[_first_index], (*argv_ptr)[second_index]);
    fprintf(stderr, "%s is not coprime to %s -->  ", (*argv_ptr)[second_index], (*argv_ptr)[_first_index]);
    fprintf(stderr, "%s is neither from \u2115%s* nor from \u2115/%s\u2115* !", (*argv_ptr)[_first_index], (*argv_ptr)[second_index], (*argv_ptr)[second_index]);
    return exit_status;
}
