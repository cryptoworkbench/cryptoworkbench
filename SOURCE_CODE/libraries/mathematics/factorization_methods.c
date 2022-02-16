#include <stdio.h> // needed for 'fprintf()'
#include "../functional/string.h" // needed for definition EXIT_STATUS_GOODBYE
#include "factorization_methods.h" // need for function headers
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'
#include "universal_group_library.h" // needed for 'BUFFER_OF_SIZE()'

const char *_preferred_factorization_engine_file = "global_preference.factorization_engine";
const char *_REPORT_preferred_factorization_engine_file() { return _preferred_factorization_engine_file; }
const char *__a = "efficient_trial_division"; const char *__b = "less_efficient_trial_division"; const char *__c = "trial_division"; const char *__d = "TABLE_AIDED_efficient_trial_division";
const char *__e = "TABLE_AIDED_less_efficient_trial_division"; const char *__f = "TABLE_AIDED_trial_division"; const char *__g = "shor_factorization"; const char *__h = "fermats_factorization_method";

const char *_REPORT_a() { return __a; } const char *_REPORT_b() { return __b; } const char *_REPORT_c() { return __c; } const char *_REPORT_d() { return __d; } const char *_REPORT_e() { return __e; }
const char *_REPORT_f() { return __f; } const char *_REPORT_g() { return __g; } const char *_REPORT_h() { return __h; } const char *_A = "a"; const char *_B = "b"; const char *_C = "c"; const char *_D = "d";
const char *_E = "e"; const char *_F = "f"; const char *_G = "g"; const char *_H = "h";
// ^ string literals we will be comparing against

void initialize_factorization_library() {
    _a = (char *) __a; _b = (char *) __b; _c = (char *) __c; _d = (char *) __d;
    _e = (char *) __e; _f = (char *) __f; _g = (char *) __g; _h = (char *) __h;
}

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
	case 7: return shor_factorization;
	case 8: return fermat_factorization;
    };
}

struct ordered_pair _factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use)
{ struct ordered_pair factor = divisor_pair(number, factorization_ENGINE_to_use(number)); if (factor.b < factor.a) { ul temp = factor.b; factor.b = factor.a; factor.a = temp; } return factor; }
// ^ passing as second argument '_preferred_factorization_ENGINE' or 'NULL' yields the same result

struct ordered_pair factorize(unsigned long number, _factorization_method alternate_choice)
{ return (alternate_choice) ? divisor_pair(number, alternate_choice(number)) : divisor_pair(number, _preferred_factorization_ENGINE(number)); }

const char *permission_failure = "permission failure within 'factorization_methods.c':";
void factorization_engine_preference_file_ERROR() { fprintf(stderr, "\n%s do not have sufficient rights to access '%s'.\n\n", permission_failure, _preferred_factorization_engine_file); }
void factorization_engine_preference_specification_ERROR() { fprintf(stderr, "\nTried too many times to parse the unparsable.\nUser can run program again for more chances.\n\n"); }

char *STDIN_factorization_engine() {
    fprintf(stdout, "Please select from the list below:\n");
    fprintf(stdout, "%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n\n", _A, __a, _B, __b, _C, __c, _D, __d, _E, __e, _F, __f, _G, __g, _H, __h);
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
	char *str = STDIN_factorization_engine(); write_to_preferences_file(str, file); free(str);
	fprintf(stdout, "Saved preference.\n\n"); return query_preferences_file();
    } char *BUFFER = BUFFER_OF_SIZE(200); BUFFER[0] = 0; fscanf(file, " %s[^\n]", BUFFER); fclose(file);
    return BUFFER;
} // recursive function which works fine and runs at most twice ^

void FACTORIZATION_METHOD_UNCHOSEN(char *arg) {
    fprintf(stderr, "Couldn't understand engine specification '%s', please specify one of the following:\n", arg);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _A, __a, _B, __b, _C, __c);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _D, __d, _E, __e, _F, __f);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _G, __g, _H, __h);
    fprintf(stderr, "\n'%s' is not one of these.\n\n", arg);
    fprintf(stderr, EXIT_STATUS_GOODBYE, -2); exit(-2);
}

int SELECTOR_from_str_representing_factorization_method(char *arg) {
    if (match_variadic(arg, 2, __a, _A)) return 1;
    else if (match_variadic(arg, 2, __b, _B)) return 2;
    else if (match_variadic(arg, 2, __c, _C)) return 3;
    else if (match_variadic(arg, 2, __d, _D)) return 4;
    else if (match_variadic(arg, 2, __e, _E)) return 5;
    else if (match_variadic(arg, 2, __f, _F)) return 6;
    else if (match_variadic(arg, 2, __g, _G)) return 7;
    else if (match_variadic(arg, 2, __h, _H)) return 8;
    return 0;
}

const char *_preferred_factorization_ENGINE_description() { initialize_factorization_library(); // < makes available in calling file the below pointers
    if (_preferred_factorization_ENGINE == efficient_trial_division) return _a;
    else if (_preferred_factorization_ENGINE == LESS_efficient_trial_division) return _b;
    else if (_preferred_factorization_ENGINE == LEAST_efficient_trial_division) return _c;
    else if (_preferred_factorization_ENGINE == efficient_trial_division) return _d;
    else if (_preferred_factorization_ENGINE == LESS_efficient_trial_division) return _e;
    else if (_preferred_factorization_ENGINE == LEAST_efficient_trial_division) return _f;
    else if (_preferred_factorization_ENGINE == shor_factorization) return _g;
    else if (_preferred_factorization_ENGINE == fermat_factorization) return _h;
    return NULL;
}

// FUNCTIONS FOR PRIME FACTORIZATION:
/*
struct LL_ *insert(struct LL_ *last, unsigned long new_divisor) {
    struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = new_divisor;
    // create the new unit ^

    struct LL_ *next = last->next; last->next = ret_val; ret_val->next = next; return ret_val;
    // insert said unit and return at this unit ^
} // divisor_list_stretch()

struct LL_ *stretched_divisor(struct LL_ *in, struct ordered_pair divisor_pair) { in->e = divisor_pair.a;
    // update factorized sloth with smaller divisor ^

    return insert(in, divisor_pair.b);
    // insert the greater divisor and return the as-of-yet unfactorized divisor in the LL
} // divisor_list_stretch()

struct LL_ *divisor_list_stretch(struct LL_ *cursor)
{ struct ordered_pair divisor_pair = factorize(cursor->e, NULL); if (!(divisor_pair.a - 1)) return cursor; divisor_count++; return divisor_list_stretch(stretched_divisor(cursor, divisor_pair)); }
// recursive function which stretches a LL of divisors ^

unsigned long number_of_distinct_prime_factors(struct LL_ *divisors) {
    unsigned long ret_val = 0;
    struct LL_ *i = divisors; do {
	unsigned long prime_factor = i->e; ret_val++;
	while (i && i->e == prime_factor) i = i->next;
    } while (i);
    // count number of distinct prime factors ^^

    crux = (struct _crux *) malloc(sizeof(struct _crux));
    crux->prime_factor = (unsigned long *) malloc(sizeof(unsigned long) * ret_val);
    crux->log = (int *) malloc(sizeof(int) * ret_val);
    // allocate the crux and it's arrays

    i = divisors; int index = 0;
    do {crux->prime_factor[index] = i->e;
	for (crux->log[index] = 0; i && i->e == crux->prime_factor[index]; crux->log[index]++, i = i->next) {}
	index++;
    } while (index < ret_val);

    return ret_val;
}
*/
