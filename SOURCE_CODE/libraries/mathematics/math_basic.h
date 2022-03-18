#include <stdio.h>
#include "../functional/string.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"

struct ordered_pair { unsigned long a; unsigned long b; }; typedef unsigned long (*field_operation) (unsigned long, unsigned long); typedef unsigned long ul;
// type declarations ^^^

struct ordered_pair _isomorphism();
// general function ^

char *_REPORT_standard_prime_table_filename(); char *_REPORT_open_prime_table();
// two function for handling prime tables ^^

unsigned long exponentiate(unsigned long base, unsigned long exponent);
// basic infinite field exponentiation ^

unsigned long _exponentiate(unsigned long base, unsigned long exponent, unsigned long mod_);
unsigned long _conditional_cap(unsigned long result, unsigned long mod_);
unsigned long _inverse(unsigned long element_of_additive_group, unsigned long mod_);
unsigned long _add(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _subtract(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _multiply(unsigned long a, unsigned long b, unsigned long mod_);
unsigned long _divide(unsigned long numerator, unsigned long denominator, unsigned long mod_);
unsigned long _polynomial(unsigned long x, unsigned long *coefficient, int coefficients, unsigned long mod_);
// basic (in)finite field operations ^

const char *_as_number(unsigned int id_);
const char *_as_operation_symbol(unsigned int id_);
const char *_as_noun(unsigned int id_);
const char *_as_nouns(unsigned int id_);
const char *_as_adjective(unsigned int id_);
const char *_as_verb(unsigned int id_);
// functions that have to do with the identity element ^

int _eulers_criterion(unsigned long odd_prime_p, unsigned long odd_prime_q); // one function in between  <-

int identity_parse_str(int *id_, char *str, int exit_status); void identity_error();
void list_plausable_group_identity_descriptions(int argv_index);
// more functions regarding the identity element

/* REMAINING FUNCTIONS FOLLOW: */
unsigned long LCM(unsigned long a, unsigned long b); unsigned long UNRESTRICTED_LCM(unsigned long *array, unsigned long array_size);
unsigned long GCD(unsigned long a, unsigned long b); unsigned long UNRESTRICTED_GCD(unsigned long *array, unsigned long array_size);
// functions for calculating the LCM and the GCD ^^

typedef struct ordered_pair STRUCT_DH_parameters;
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs);
unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, unsigned long private_key);
// functions for DH and DH based scemes (i.e. Elgamal) ^

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a);
int coprime(unsigned long a, unsigned long b);
unsigned long totient(unsigned long a);

unsigned long least_base_TWO_log(unsigned long power_of_TWO); // required by '_exponentiate'
unsigned long *UL_array_of_SIZE(int SIZE);
unsigned long INDEX_within_UL_array(unsigned long *UL_array, unsigned long UL_array_SIZE, unsigned long number);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, unsigned long minimum);
unsigned long DOWN_ROUNDED_second_root(unsigned long number);

char *sieve_of_eratosthenes(unsigned long limit);
unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, unsigned long limit, FILE *FS);
FILE *prime_table_open(); // < I want this to eventually try to cooperate with the logbook instead of stderr
void prime_table_close(FILE *prime_table); // < closes FS and resets char * variable '_open_prime_table' to NULL


void open_urandom();
void close_urandom();
unsigned long urandom_number(unsigned long upper_bound);

unsigned long chinese_remainder_theorem(unsigned long remainder, unsigned long *moduli, unsigned long modulis);
int pair_of_strs_represents_pair_of_coprime_ULs(_error_function _first_instruction, _error_function second_instruction, unsigned long *ptr_one, unsigned long *ptr_two, int _first_index, int second_index, int exit_status);
