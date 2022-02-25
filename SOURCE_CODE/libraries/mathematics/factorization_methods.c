#include <stdio.h> // needed for 'fprintf()'
#include "../functional/string.h" // needed for definition EXIT_STATUS_GOODBYE
#include "factorization_methods.h" // need for function headers
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'
#include "universal_group_library.h" // needed for 'BUFFER_OF_SIZE()'

const char *_preferred_factorization_engine_file = "global_preference.factorization_engine";
const char *_REPORT_preferred_factorization_engine_file() { return _preferred_factorization_engine_file; }
const char *_a = "efficient_trial_division"; const char *_b = "less_efficient_trial_division"; const char *_c = "trial_division"; const char *_d = "TABLE_AIDED_efficient_trial_division";
const char *_e = "TABLE_AIDED_less_efficient_trial_division"; const char *_f = "TABLE_AIDED_trial_division"; const char *_g = "fermats_factorization_method"; const char *_h = "shor_factorization";

const char *_REPORT_a() { return _a; } const char *_REPORT_b() { return _b; } const char *_REPORT_c() { return _c; } const char *_REPORT_d() { return _d; } const char *_REPORT_e() { return _e; }
const char *_REPORT_f() { return _f; } const char *_REPORT_g() { return _g; } const char *_REPORT_h() { return _h; } const char *_A = "a"; const char *_B = "b"; const char *_C = "c"; const char *_D = "d";
const char *_E = "e"; const char *_F = "f"; const char *_G = "g"; const char *_H = "h";
// ^ string literals we will be comparing against

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number)
{ struct ordered_pair pair_of_divisors; pair_of_divisors.b = DIVISOR_OF_number; pair_of_divisors.a = number / pair_of_divisors.b; return pair_of_divisors; }
unsigned long bigger_half(unsigned long number, ul half) { return (number / half < half) ? half : number / half; } // not in .h counterpart: not needed there!

unsigned long trial_division(unsigned long presumed_composite, unsigned long _trial_limit)
{ ul divisor = MULTIPLICATIVE_IDENTITY; do { divisor++; if (_trial_limit < divisor) divisor == presumed_composite; } while (presumed_composite % divisor != 0); return bigger_half(presumed_composite, divisor); }

unsigned long _trial_division_TABLE_AIDED(unsigned long presumed_composite, unsigned long _trial_limit, FILE *prime_table) {
    ul prime_divisor; do {
	if (fscanf(prime_table, "%lu\n", &prime_divisor) != 1)
	{ fprintf(stderr, "The prime table '%s' not complete enough to find the first prime divisor of %lu. The last prime tested was %lu.\n", _REPORT_open_prime_table(), presumed_composite, prime_divisor); exit(-1); }
	if (prime_divisor > _trial_limit) prime_divisor = presumed_composite;
    } while (presumed_composite % prime_divisor != 0); prime_table_close(prime_table); return bigger_half(presumed_composite, prime_divisor);
} unsigned long trial_division_TABLE_AIDED(unsigned long composite, unsigned long _trial_limit) { return _trial_division_TABLE_AIDED(composite, _trial_limit, prime_table_open(_REPORT_standard_prime_table_filename()));}

unsigned long trial_limit(unsigned long composite, int supidity_level)
{ switch (supidity_level) { case 3: return composite; case 2: return (composite - (composite % 2)) / 2; case 1: return DOWN_ROUNDED_second_root(composite); }; }

unsigned long efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 1)); }
unsigned long LESS_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 2)); }
unsigned long LEAST_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 3)); }
unsigned long efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 1)); }
unsigned long LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 2)); }
unsigned long LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 3)); }
// ^ trial division methods (all dependencies of 'factorization_method()'

unsigned long shor_factorization(unsigned long presumed_composite) {
    for (unsigned long a_ = 2; a_ <= presumed_composite; a_++) {
	unsigned long _GCD = GCD(presumed_composite, a_); if (_GCD != 1) return _GCD;
	// ^ return when we find a number less than 'presumed_composite' which proves that 'presumed_composite' has a divisor greater than one (namely, the divisor it shared in common with this number)
	unsigned long period_of_a_ = 1; for (unsigned long a_power = a_; a_power != MULTIPLICATIVE_IDENTITY; a_power *= a_, a_power %= presumed_composite) period_of_a_++; if (period_of_a_ % 2 == 1) continue;
	unsigned long a_power = _exponentiate(a_, period_of_a_ / 2, 0); if (presumed_composite == a_power + 1) continue; return GCD(presumed_composite, a_power + 1);
    }
} // dependency of 'factorization_method()'

// NOW SOME FUNCTIONS TO ACHIEVE FERMAT FACTORIZATION
// We will use "struct ordered_pair"
// We will use unsigned long member 'a' for the roots
// We will use unsigned member 'b' for the squares
unsigned long difference_of_squares_factorization_method(unsigned long odd_composite) { struct ordered_pair square_BIG = {0, 0}; struct ordered_pair square_SMALL = {0, 0};
    while (square_BIG.b != odd_composite + square_SMALL.b)
    { least_perfect_square_equal_to_or_greater_than(&square_BIG, odd_composite + square_SMALL.b); least_perfect_square_equal_to_or_greater_than(&square_SMALL, square_BIG.b - odd_composite); }
    return square_BIG.a + square_SMALL.a; }
unsigned long evens_factorizer(unsigned long even_composite) { ul a = MULTIPLICATIVE_IDENTITY; do { even_composite /= 2; a *= 2; } while (even_composite % 2 == 0); return a; } // only call with even composite
unsigned long odds_factorizer_WRAPPER(unsigned long composite, _factorization_method odds_factorizer) { return (composite % 2 == 0) ? evens_factorizer(composite) : odds_factorizer(composite); }
unsigned long fermat_factorization(unsigned long composite) { return odds_factorizer_WRAPPER(composite, difference_of_squares_factorization_method); }
// ^ FOUR FUCNCTIONS TO ACHIEVE FERMAT FACTORIZATION

_factorization_method factorization_method(int SELECTOR) {
    switch (SELECTOR) {
	case 0: return NULL;
	case 1: return efficient_trial_division;
	case 2: return LESS_efficient_trial_division;
	case 3: return LEAST_efficient_trial_division;
	case 4: return efficient_trial_division_TABLE_AIDED;
	case 5: return LESS_efficient_trial_division_TABLE_AIDED;
	case 6: return LEAST_efficient_trial_division_TABLE_AIDED;
	case 7: return fermat_factorization;
	case 8: return shor_factorization;
    };
}

struct ordered_pair _factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use)
{ struct ordered_pair factor = divisor_pair(number, factorization_ENGINE_to_use(number)); if (factor.b < factor.a) { ul temp = factor.b; factor.b = factor.a; factor.a = temp; } return factor; }
// ^ passing as second argument '_preferred_factorization_engine' or 'NULL' yields the same result

struct ordered_pair factorize(unsigned long number, _factorization_method alternate_choice)
{ return (alternate_choice) ? divisor_pair(number, alternate_choice(number)) : divisor_pair(number, _preferred_factorization_engine(number)); }

const char *permission_failure = "permission failure within 'factorization_methods.c':";
void factorization_engine_preference_file_ERROR() { fprintf(stderr, "\n%s do not have sufficient rights to access '%s'.\n\n", permission_failure, _preferred_factorization_engine_file); }
void factorization_engine_preference_specification_ERROR() { fprintf(stderr, "\nTried too many times to parse the unparsable.\nUser can run program again for more chances.\n\n"); }

char *STDIN_factorization_preference() {
    fprintf(stdout, "Please select from the list below:\n");
    fprintf(stdout, "%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s (not guarenteed to work for the TOOL prime_factorization and mostly useless anyway)\n\n", _A, _a, _B, _b, _C, _c, _D, _d, _E, _e, _F, _f, _G, _g, _H, _h);
    // list available choices ^ 

    char *preferred_factorization_engine = BUFFER_OF_SIZE(200); int extra_chances;
    for (extra_chances = 0; extra_chances != 4; extra_chances++) { fprintf(stdout, "Choice of factorization engine");
    if (extra_chances != 0) fprintf(stdout, " (didn't understand previous choice)"); fprintf(stdout, ": ");
    if (fscanf(stdin, " %s", preferred_factorization_engine) == 1 && SELECTOR_from_str_representing_factorization_method(preferred_factorization_engine)) break; }
    if (extra_chances == 4) error_message(factorization_engine_preference_specification_ERROR, -2);
    // Ask 5 times what factorization method should be preferred ^

    return preferred_factorization_engine;
}

void write_to_preferences_file(char *str, FILE *file) { fprintf(file, "%s\n", str); fclose(file); }

char *query_preferences_file() { FILE *file;
    if (!(file = fopen(_preferred_factorization_engine_file, "r"))) { fprintf(stderr, "Failed to open global preferences file '%s'.\n\n", _preferred_factorization_engine_file);
	if (!(file = fopen(_preferred_factorization_engine_file, "w"))) error_message(factorization_engine_preference_file_ERROR, -1);
	char *str = STDIN_factorization_preference(); write_to_preferences_file(str, file); free(str);
	fprintf(stdout, "Saved preference.\n\n"); return query_preferences_file();
    } char *BUFFER = BUFFER_OF_SIZE(200); BUFFER[0] = 0; fscanf(file, " %s[^\n]", BUFFER); fclose(file);
    return BUFFER;
} // recursive function which works fine and runs at most twice ^

int SELECTOR_from_str_representing_factorization_method(char *arg) {
    if (match_variadic(arg, 2, _a, _A)) return 1;
    else if (match_variadic(arg, 2, _b, _B)) return 2;
    else if (match_variadic(arg, 2, _c, _C)) return 3;
    else if (match_variadic(arg, 2, _d, _D)) return 4;
    else if (match_variadic(arg, 2, _e, _E)) return 5;
    else if (match_variadic(arg, 2, _f, _F)) return 6;
    else if (match_variadic(arg, 2, _g, _G)) return 7;
    else if (match_variadic(arg, 2, _h, _H)) return 8;
    return 0;
}

const char *_factorization_engine_description(_factorization_method factorization_engine) {
    if (factorization_engine == efficient_trial_division) return _a;
    else if (factorization_engine == LESS_efficient_trial_division) return _b;
    else if (factorization_engine == LEAST_efficient_trial_division) return _c;
    else if (factorization_engine == efficient_trial_division) return _d;
    else if (factorization_engine == LESS_efficient_trial_division) return _e;
    else if (factorization_engine == LEAST_efficient_trial_division) return _f;
    else if (factorization_engine == fermat_factorization) return _g;
    else if (factorization_engine == shor_factorization) return _h;
    return NULL;
} // done

int primality_test_based_on_preferred_factorization_engine(unsigned long potential_prime)
{ return (potential_prime - _preferred_factorization_engine(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY;}

_factorization_method factorization_method_retrieve(char *potentially_factorization_method_specifying_argument) { _factorization_method ret_val;
    char *ptr = potentially_factorization_method_specifying_argument; if (!ptr) ptr = query_preferences_file();
    if (!(ret_val = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (potentially_factorization_method_specifying_argument) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; ret_val = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_preference(ptr)));
	if (!potentially_factorization_method_specifying_argument) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then try to take the factorization method from STDIN by force
    return ret_val;
}

// PRIME FACTORIZATION:
struct LL_ *insert(struct LL_ *last, unsigned long new_divisor) // NON-recursive <--
{ struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = new_divisor; struct LL_ *next = last->next; last->next = ret_val; ret_val->next = next; return ret_val; }

struct LL_ *stretched_divisor(struct LL_ *in, struct ordered_pair divisor_pair) // NON-recursive <--
{ in->e = divisor_pair.a; return insert(in, divisor_pair.b); }

struct LL_ *divisor_list_stretch(struct LL_ *i)
{ struct ordered_pair divisor_pair = factorize(i->e, NULL); if (!(divisor_pair.a - 1)) return i; return divisor_list_stretch(stretched_divisor(i, divisor_pair)); }
// recursive function yielding the list containing the prime factorization ^

void divisor_list_WIPE(struct LL_ *i) { if (!(i)) return; struct LL_ *next = i->next; free(i); divisor_list_WIPE(next); }

unsigned long number_of_distinct_prime_factors(unsigned long previous_prime_factor, struct LL_ *i, unsigned long ret_val)
{ if (!(i)) return ret_val; if (i->e != previous_prime_factor) ret_val++; number_of_distinct_prime_factors(i->e, i->next, ret_val); }
// recursive function which counts the number of distinct prime factors said (^^) list ^

void PRIME_FACTORIZATION_setup(struct _PRIME_FACTORIZATION *crux, unsigned long last_factor, struct LL_ *i, unsigned long index)
{ if (!(i)) return; if (i->e == last_factor) crux->log[index]++; else { index++; crux->prime_factor[index] = i->e; } PRIME_FACTORIZATION_setup(crux, i->e, i->next, index); }
// recursive function which set's up the program's crux (which holds the associative array)

struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION_allocate(int number_of_distinct_prime_factors) {
    struct _PRIME_FACTORIZATION *ret_val = (struct _PRIME_FACTORIZATION *) malloc(sizeof(struct _PRIME_FACTORIZATION));
    ret_val->prime_factor = (unsigned long *) malloc(sizeof(unsigned long) * number_of_distinct_prime_factors);
    ret_val->log = (int *) malloc(sizeof(int) * number_of_distinct_prime_factors);
    for (int i = 0; i < number_of_distinct_prime_factors; i++) ret_val->log[i] = 1; ret_val->number_of_distinct_prime_factors = number_of_distinct_prime_factors; return ret_val;
} void PRIME_FACTORIZATION_free(struct _PRIME_FACTORIZATION *crux) { free(crux->log); free(crux->prime_factor); free(crux); }
// funct^ons for allocation and destruction of a program's crux ^

struct _PRIME_FACTORIZATION *_PRIME_FACTORIZATION(unsigned long number_of_distinct_prime_factors, struct LL_ *divisors) { // NON-recursive wrapper function for 'PRIME_FACTORIZATION_allocate' <--
    struct _PRIME_FACTORIZATION *ret_val = PRIME_FACTORIZATION_allocate(number_of_distinct_prime_factors); ret_val->prime_factor[0] = divisors->e;
    PRIME_FACTORIZATION_setup(ret_val, ret_val->prime_factor[0], divisors->next, 0); divisor_list_WIPE(divisors); return ret_val;
}

struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION(unsigned long number) { // NON-recursive wrapper function for 'PRIME_FACTORIZATION_allocate' <--
    struct LL_ *divisors = (struct LL_ *) malloc(sizeof(struct LL_)); divisors->e = number; divisors->next = NULL; // struct LL_ *tail =
    divisor_list_stretch(divisors); return _PRIME_FACTORIZATION(number_of_distinct_prime_factors(divisors->e, divisors->next, 1), divisors);
}

unsigned long PRIME_FACTORIZATION_calculate(unsigned long multiplicative_accumulator, struct _PRIME_FACTORIZATION *crux, int index) {
    if (index == crux->number_of_distinct_prime_factors) return multiplicative_accumulator;
    return PRIME_FACTORIZATION_calculate(multiplicative_accumulator * exponentiate(crux->prime_factor[index], crux->log[index]), crux, 1 + index);
} // recursive function for converting from prime factorization back to number ^

struct _PRIME_FACTORIZATION *_PRIME_FACTORIZATION_print(struct _PRIME_FACTORIZATION *crux, int index) {
    fprintf(stdout, "%lu^%lu", crux->prime_factor[index], crux->log[index]); index++; if (index == crux->number_of_distinct_prime_factors) return crux;
    fprintf(stdout, " * "); return _PRIME_FACTORIZATION_print(crux, index);
} // recursive function to print crux ^

struct _PRIME_FACTORIZATION *PRIME_FACTORIZATION_print(struct _PRIME_FACTORIZATION *crux)
{ fprintf(stdout, "%lu = ", PRIME_FACTORIZATION_calculate(MULTIPLICATIVE_IDENTITY, crux, 0)); _PRIME_FACTORIZATION_print(crux, 0); fprintf(stdout, "\n"); return crux; }
// wrapper function for calling the recursive function '_PRIME_FACTORIZATION_print' ^
