#include <stdio.h>
#include "../functional/string.basic.h"
// library inclusions ^^

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"
// definitions ^^^

struct ordered_pair { ul a; ul b; };
typedef unsigned long (*group_operation) (ul, ul, ul);
// type declarations ^^

group_operation *_group_operation;

struct ordered_pair _isomorphism();
// general function ^

char *_REPORT_standard_prime_table_filename(); char *_REPORT_open_prime_table();
// two function for handling prime tables ^^

unsigned long exponentiate(ul base, ul exponent);
// basic infinite field exponentiation ^

/* ===================== corresponds to 'maths.extended.h' (!) ================== */
int _identity_parse_str(ui_ptr id_, char *str, int exit_status);
int _identity_parse_str_(ui_ptr id_, char *str, int exit_status); // <-- this variant also sets '_group_operation' which may be used in conjunction with 'mod_group_operation'

unsigned long _exponentiate(ul base, ul exponent, ul mod_);
unsigned long _conditional_cap(ul result, ul mod_);
unsigned long _inverse(ul element_of_additive_group, ul mod_);
unsigned long _add(ul a, ul b, ul mod_);
unsigned long _subtract(ul a, ul b, ul mod_);
unsigned long _multiply(ul a, ul b, ul mod_);
unsigned long _divide(ul numerator, ul denominator, ul mod_);
unsigned long _polynomial(ul x, ul *coefficient, int coefficients, ul mod_);
// basic (in)finite field operations ^

const char *_as_number(ui id_);
const char *_as_operation_symbol(ui id_);
const char *_as_noun(ui id_);
const char *_as_nouns(ui id_);
const char *_as_adjective(ui id_);
const char *_as_verb(ui id_);
// functions that have to do with the identity element ^

int _eulers_criterion(ul odd_prime_p, ul odd_prime_q);
/* ===================== corresponds to 'maths.extended.h' (!) ================== */

void list_plausable_group_identity_descriptions(int argv_index);
// more functions regarding the identity element

unsigned long LCM(ul a, ul b);
unsigned long GCD(ul a, ul b);

unsigned long UNRESTRICTED_LCM(ul_ptr array, ul array_size);
unsigned long UNRESTRICTED_GCD(ul_ptr array, ul array_size);
// functions for calculating the LCM and the GCD ^^

typedef struct ordered_pair STRUCT_DH_parameters;
void print_DH_parameters(STRUCT_DH_parameters *DH_parameters, FILE *fs);
unsigned long DH_public_key(STRUCT_DH_parameters *DH_parameters, ul private_key);
// functions for DH and DH based scemes (i.e. Elgamal) ^

unsigned long extended_gcd(ul a, ul b, ul *x, ul *y);
int coprime(ul a, ul b);
unsigned long totient(ul a);

unsigned long least_base_TWO_log(ul power_of_TWO); // required by '_exponentiate'
unsigned long INDEX_within_UL_array(ul_ptr UL_array, ul UL_array_SIZE, ul number);
struct ordered_pair least_perfect_square_equal_to_or_greater_than(struct ordered_pair *to_be_updated, ul minimum);
unsigned long DOWN_ROUNDED_second_root(ul number);

char *sieve_of_eratosthenes(ul limit);
unsigned long primes_printed_from_sieve_array_to_FS(char *sieve, ul limit, FILE *FS);
FILE *prime_table_open(); // < I want this to eventually try to cooperate with the logbook instead of stderr
void prime_table_close(FILE *prime_table); // < closes FS and resets char * variable '_open_prime_table' to NULL


void open_urandom();
void close_urandom();
unsigned long urandom_number(ul upper_bound);

unsigned long chinese_remainder_theorem(ul remainder, ul_ptr moduli, ul modulis);
int pair_of_strs_represents_pair_of_coprime_ULs(_error_function _first_instruction, _error_function second_instruction, ul_ptr ptr_one, ul_ptr ptr_two, int _first_index, int second_index, int exit_status);
