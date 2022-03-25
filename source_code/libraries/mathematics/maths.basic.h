#include <stdio.h>
#include "../functional/string.basic.h"
// library inclusions ^^

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define PRIME_TABLE_UNAVAILABLE_ERROR "Failed to open the prime table '%s'.\n\n"
// definitions ^^^

struct ordered_pair { ul a; ul b; };
typedef unsigned long (*operation_) (ul, ul, ul);
struct group { operation_ oper; ul mod; const char **sign; };
// type declarations ^^

struct group *_group;

struct group **__group;
// this will point to an array of 'struct group' PTRs ^

struct ordered_pair _isomorphism();
// general function ^

char *_REPORT_standard_prime_table_filename(); char *_REPORT_open_prime_table();
// two function for handling prime tables ^^

unsigned long exponentiate(ul base, ul exponent);
// basic infinite field exponentiation ^

/* ===================== corresponds to 'maths.extended.h' (!) ================== */
unsigned long _exponentiate(ul base, ul exponent, ul _mod);
unsigned long _conditional_cap(ul result, ul _mod);
unsigned long _inverse(ul element_of_additive_group, ul _mod);
unsigned long _add(ul a, ul b, ul _mod);
unsigned long _subtract(ul a, ul b, ul _mod);
unsigned long _multiply(ul a, ul b, ul _mod);
unsigned long _divide(ul numerator, ul denominator, ul _mod);
unsigned long _polynomial(ul x, ul *coefficient, int coefficients, ul _mod);
// basic (in)finite field operations ^

int _eulers_criterion(ul odd_prime_p, ul odd_prime_q);
/* ===================== corresponds to 'maths.extended.h' (!) ================== */ // '_mod' needs to be initialized

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
int pair_of_strs_represents_pair_of_coprime_ULs(error_function_ _first_instruction, error_function_ second_instruction, ul_ptr ptr_one, ul_ptr ptr_two, int _first_index, int second_index, int exit_status);

// NEW:
int _operation_parse_str(operation_ *_operation, char *str, int exit_status);
void _operation_parse_str_ul_parse_str(char *operation_str, operation_ *operation_ptr, error_function_ operation_failed_to_parse, int operation_failed_to_parse_EXIT_CODE, char *modulus_str, ul_ptr modulus_ptr, error_function_ modulus_failed_to_parse, int modulus_failed_to_parse_EXIT_CODE);
struct group *group_parse_strs(struct group *pass_through, char *operation_str, int operation_failed_to_parse_EXIT_CODE, error_function_ operation_failed_to_parse, char *modulus_str, int modulus_failed_to_parse_EXIT_CODE, error_function_ modulus_failed_to_parse);
char ***argv_operation_parse_str_ul_parse_str(char ***pass_through, operation_ *operation_ptr, error_function_ operation_failed_to_parse, ul_ptr modulus_ptr, error_function_ modulus_failed_to_parse, int argv_index);
