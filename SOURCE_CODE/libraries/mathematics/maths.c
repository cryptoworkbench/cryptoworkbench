// This library contains all of the mathematics for (modular) arithmetic.
#include <stdlib.h>
#include <stdarg.h>
#include "maths.h"

FILE *urandom = NULL;
const char *_standard_prime_table_filename = "shared_prime_table";

const char *additive_signs[] = {"0", "+", "addition", "additions", "additive", "add", 0};
const char *multiplicative_signs[] = {"1", "*", "multiplication", "multiplications", "multiplicative", "multiply", 0};

char *_REPORT_standard_prime_table_filename() { return (char *) _standard_prime_table_filename; }
char *_open_prime_table = NULL; char *_REPORT_open_prime_table() { return (char *) _open_prime_table; }
// Two global variables and two functions for access to these global variables in other files/libraries

struct ordered_pair _isomorphism() { struct ordered_pair ret_val = { ADDITIVE_IDENTITY, MULTIPLICATIVE_IDENTITY }; return ret_val; }
// a general function which a lot of functions in this library make use of ^^

/* FUNCTIONS THAT HAVE TO DO WITH mod_ FOLLOW: */
unsigned long _conditional_cap(unsigned long result, unsigned long mod_) { return (mod_) ? result % mod_ : result; }
unsigned long mod_conditional_cap(unsigned long result) { return (*mod_) ? _conditional_cap(result, *mod_) : result; }
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_cap(a + b, mod_); }
unsigned long mod_add(unsigned long a, unsigned long b) { return _add(a, b, *mod_); }
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_) { return _conditional_cap(mod_ - _conditional_cap(element_of_additive_group, mod_), mod_); }
unsigned long mod_inverse(unsigned long element_of_additive_group) { return _inverse(element_of_additive_group, *mod_); }
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_cap(a + _inverse(b, mod_), mod_); }
unsigned long mod_subtract(unsigned long a, unsigned long b) { return _subtract(a, b, *mod_); }
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_) { return _conditional_cap(a * b, mod_); }
unsigned long mod_multiply(unsigned long a, unsigned long b) { return mod_conditional_cap(a * b); } 
unsigned long _divide(unsigned long numerator, unsigned long denominator, unsigned long mod_)
{ if (mod_) while (numerator % denominator != 0) numerator += mod_; return _conditional_cap(numerator / denominator, mod_); }
unsigned long mod_divide(unsigned long numerator, unsigned long denominator) { return _divide(numerator, denominator, *mod_); }

/* FUNCTIONS THAT HAVE TO DO WITH mod_exponentiate FOLLOW: */
unsigned long exponentiate(unsigned long base, unsigned long exponent)
{ unsigned long exponentiation_RESULT = (0 < base); for (unsigned long iter = 0; iter < exponent; iter++) exponentiation_RESULT *= base; return exponentiation_RESULT; } 
unsigned long least_base_TWO_log(unsigned long power_of_TWO) {
    if (power_of_TWO == 0) return 0; unsigned long return_value = ADDITIVE_IDENTITY; unsigned long multiplicative_accumulator = MULTIPLICATIVE_IDENTITY;
    while (multiplicative_accumulator < power_of_TWO) { multiplicative_accumulator *= 2; return_value++; } if (multiplicative_accumulator > power_of_TWO) return_value--; return return_value;
} unsigned long _exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_) {
    if (base == 0 || exponent == 0) return 1; unsigned long minimum_log = least_base_TWO_log(exponent); unsigned long *backbone = (unsigned long *) malloc(sizeof(unsigned long) * (minimum_log + 1));
    unsigned long i = ADDITIVE_IDENTITY; backbone[i] = _conditional_cap(base, mod_); while (i < minimum_log) { backbone[i + 1] = _multiply(backbone[i], backbone[i], mod_); i++; }
    unsigned long ret_val = MULTIPLICATIVE_IDENTITY;
    while (exponent != 0) { ret_val = _multiply(ret_val, backbone[minimum_log], mod_); exponent -= exponentiate(2, minimum_log); minimum_log = least_base_TWO_log(exponent); } free(backbone); return ret_val;
} unsigned long mod_exponentiate(unsigned long base, unsigned long exponent) { return _exponentiate(base, exponent, *mod_); }

/* FUNCTIONS THAT HAVE TO DO WITH id_ FOLLOW: */
const char *_as_number(int id) { return (id) ? multiplicative_signs[0] : additive_signs[0]; } const char *id_as_number() { return _as_number(*id_); }
const char *_as_operation_symbol(int id) { return (id) ? multiplicative_signs[1] : additive_signs[1]; } const char *id_as_operation_symbol() { return _as_operation_symbol(*id_); }
const char *_as_noun(int id) { return (id) ? multiplicative_signs[2] : additive_signs[2]; } const char *id_as_noun() { return _as_noun(*id_); }
const char *_as_nouns(int id) { return (id) ? multiplicative_signs[3] : additive_signs[3]; } const char *id_as_nouns() { return _as_nouns(*id_); }
const char *_as_adjective(int id) { return (id) ? multiplicative_signs[4] : additive_signs[4]; } const char *id_as_adjective() { return _as_adjective(*id_); }
const char *_as_verb(int id) { return (id) ? multiplicative_signs[5] : additive_signs[5]; } const char *id_as_verb() { return _as_verb(*id_); }
// to get the identity represented as number, operation symbol, noun, noun in multiple, or as adjective ^^^^^

field_operation ___field_operation(unsigned long id) { return (id) ? mod_multiply : mod_add; }
field_operation id_field_operation() { return ___field_operation(*id_); }

int identity_parse_str(int *id_, char *str, int exit_status)
{
    if (str && _match(str, 6, multiplicative_signs)) *id_ = 1;
    else if (str && _match(str, 6, additive_signs)) *id_ = 0;
    else { unparsed_arg = str; return n(error_message(identity_error, exit_status)); }
    return 0;
}
// functions for setting the global int variable 'id_'

void identity_error()
{ fprintf(stderr, "parsing of '%s' failed: could not match '%s' with any imaginable group operation description.", unparsed_arg, unparsed_arg); }

void list_plausable_group_identity_descriptions(int argv_index)
{
    fflush(stderr);
    fprintf(stderr, "\n- \u2115%s+ could have been specified using '%s', '%s', '%s', '%s', '%s' or '%s'                        		instead of '%s'", (*argv_loc)[1], additive_signs[5], additive_signs[4], additive_signs[2], additive_signs[3], additive_signs[0], additive_signs[1], (*argv_loc)[argv_index]);
    fprintf(stderr, "\n- \u2115%s* could have been specified using '%s', '%s', '%s', '%s', '%s' or '%s'		instead of '%s'", (*argv_loc)[1], multiplicative_signs[5], multiplicative_signs[4], multiplicative_signs[2], multiplicative_signs[3], multiplicative_signs[0], multiplicative_signs[1], (*argv_loc)[argv_index]);
}

unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, unsigned long DH_private_key) { return _exponentiate(DH_parameters->b, DH_private_key, DH_parameters->a); }
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs) { fprintf(fs, "(\u2115/%lu\u2115*, %lu)", DH_parameters->a, DH_parameters->b); }

unsigned long *UL_array_of_SIZE(int SIZE) { unsigned long *ret_val = (unsigned long *) malloc(sizeof(unsigned long) * SIZE); return ret_val; }
unsigned long INDEX_within_UL_array(unsigned long *UL_array, unsigned long array_size, unsigned long number) { for (unsigned long INDEX = 0; INDEX < array_size; INDEX++) if (UL_array[INDEX] == number) return INDEX;}

unsigned long _polynomial(unsigned long x, unsigned long *coefficient, int number_of_coefficients, unsigned long mod_) { struct ordered_pair iso = _isomorphism();
    int i = number_of_coefficients; do { i--; iso.a = _add(iso.a, _multiply(iso.b, coefficient[i], mod_), mod_); iso.b = _multiply(iso.b, x, mod_); } while (i != 0); return iso.a; }
unsigned long mod_polynomial(unsigned long x, unsigned long *coefficient, int number_of_coefficients) { return _polynomial(x, coefficient, number_of_coefficients, *mod_); }

unsigned long GCD(unsigned long a, unsigned long b) {
    unsigned long remainder = a % b;
    while (remainder != 0) {
	a = b;
	b = remainder;
	remainder = a % b;
    }

    return b;
} /* ^ Calculates the GCD using a procedural implementation of the euclidean algorithm ^^^ */

unsigned long UNRESTRICTED_GCD(unsigned long *array, unsigned long array_size) { unsigned long ret_val = array[0]; for (unsigned long i = 1; i < array_size; i++) ret_val = GCD(ret_val, array[i]); return ret_val; }

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
    // return mod_conditional_cap(x); // doesn't work
    return mod_conditional_cap(*mod_ + x); // works // return (*mod_ + x) % *mod_; // also works
    // return x % *mod_; // doesn't work
}

unsigned long LCM(unsigned long a, unsigned long b) { unsigned long ret_val = a; if (a < b) ret_val = b; while (ret_val % a != 0 || ret_val % b != 0) ret_val++; return ret_val; }
unsigned long UNRESTRICTED_LCM(unsigned long *array, unsigned long array_size) { unsigned long ret_val = array[0]; for (unsigned long i = 1; i < array_size; i++) ret_val = LCM(ret_val, array[i]); return ret_val; }

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

void _prime_table_unavailable() { fprintf(stderr, "failed to access prime table '%s' !\n", _standard_prime_table_filename); }

void spec() { fprintf(stderr, "# you can create it using 'prime_table_exporter'.\n"); }

FILE *prime_table_open() {
    FILE *prime_table; if (prime_table = fopen(_standard_prime_table_filename, "r")) _open_prime_table = (char *) _standard_prime_table_filename;
    else conditional_goodbye(h(h(error_specification(spec, h(error_message(_prime_table_unavailable, -10))))));
    return prime_table;
} void prime_table_close(FILE *prime_table) { fclose(prime_table); _open_prime_table = NULL; }

int _eulers_criterion(unsigned long odd_prime_p, unsigned long odd_prime_q) { return (odd_prime_q - 1 - _exponentiate(odd_prime_p, (odd_prime_q - 1) / 2, odd_prime_q)) ? 1 : -1; }
int mod_eulers_criterion(unsigned long odd_prime_p) { return _eulers_criterion(odd_prime_p, *mod_); }

void open_urandom() { urandom = fopen("/dev/urandom", "r"); }
void close_urandom() { if (urandom) fclose(urandom); }

unsigned long urandom_number(unsigned long upper_bound) { if (!(urandom)) open_urandom();
    unsigned long ret_val; fread(&ret_val, sizeof(unsigned long), 1, urandom);
    ret_val = _conditional_cap(ret_val, upper_bound); return ret_val;
}

unsigned long chinese_remainder_theorem(unsigned long remainder, unsigned long *moduli, unsigned long modulis) { struct ordered_pair isomorphism = _isomorphism();
    for (unsigned long i = 0; i < modulis; i++, isomorphism.a += isomorphism.b, isomorphism.b = remainder) { for (unsigned long j = 0; j < modulis; j++) if (moduli[i] != moduli[j]) isomorphism.b *= moduli[j];
	    unsigned long reduced_term = isomorphism.b % moduli[i]; if (reduced_term != remainder) if (reduced_term != 1) isomorphism.b *= _divide(1, reduced_term, moduli[i]); isomorphism.b *= remainder;
    } return isomorphism.a;
}

int pair_of_strs_represents_pair_of_coprime_ULs(_error_function _first_instruction, _error_function second_instruction, unsigned long *ptr_one, unsigned long *ptr_two, int _first_index, int second_index, int exit_status) {
    // requires 'argv_loc' to be set ^

    if (error_specification(_first_instruction, n(ul_parse_str(ptr_one, (*argv_loc)[_first_index], 1)))) return - _first_index;
    if (error_specification(second_instruction, n(ul_parse_str(ptr_two, (*argv_loc)[second_index], 1)))) return - second_index;
    // interpret the numbers ^^

    if (coprime(*ptr_one, *ptr_two)) return 0;
    // perform the coprimality check ^

    fprintf(stderr, " GCD(%s, %s) != 1 -->  ", (*argv_loc)[_first_index], (*argv_loc)[second_index]);
    fprintf(stderr, "%s is not coprime to %s -->  ", (*argv_loc)[second_index], (*argv_loc)[_first_index]);
    fprintf(stderr, "%s is neither from \u2115%s* nor from \u2115/%s\u2115* !", (*argv_loc)[_first_index], (*argv_loc)[second_index], (*argv_loc)[second_index]);
    return exit_status;
}
