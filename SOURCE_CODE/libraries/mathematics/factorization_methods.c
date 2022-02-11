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
	case 0: return efficient_trial_division; case 1: return LESS_efficient_trial_division; case 2: return LEAST_efficient_trial_division;
	case 3: return efficient_trial_division_TABLE_AIDED; case 4: return LESS_efficient_trial_division_TABLE_AIDED; case 5: return LEAST_efficient_trial_division_TABLE_AIDED;
	case 6: return shor_factorization; case 7: return fermat_factorization; default: return NULL; };
} void SET_preferred_factorization_ENGINE(int SELECTOR) { _preferred_factorization_ENGINE = factorization_method(SELECTOR); }

struct ordered_pair _factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use)
{ struct ordered_pair factor = divisor_pair(number, factorization_ENGINE_to_use(number)); if (factor.b < factor.a) { ul temp = factor.b; factor.b = factor.a; factor.a = temp; } return factor; }
// ^ passing as second argument '_preferred_factorization_ENGINE' or 'NULL' yields the same result

struct ordered_pair factorize(unsigned long number, _factorization_method alternate_choice)
{ return (alternate_choice) ? divisor_pair(number, alternate_choice(number)) : divisor_pair(number, _preferred_factorization_ENGINE(number)); }

char *read_preferences_file() {
    FILE *file; if (!(file = fopen(_preferred_factorization_engine_file, "r")))
    { fprintf(stderr, "Couldn't open preferences file '%s'. " EXIT_STATUS_GOODBYE, _preferred_factorization_engine_file, -1); exit(-1); }
    char *ret_val = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ret_val); fclose(file); return ret_val;
}

/* new version (in development)
void read_preferences_file(char *ptr) {
	FILE *file; if (!(file = fopen(_preferred_factorization_engine_file, "r"))) {
	    fprintf(stderr, "Failed to open preferences file '%s'.\n\n", _preferred_factorization_engine_file);
	    fprintf(stdout, "Please select from the list below which factorization should be preferred:\n");
	    fprintf(stdout, "%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n%s. %s\n", _A, __a, _B, __b, _C, __c, _D, __d, _E, __e, _F, __f, _G, __g, _H, __h);
	    fprintf(stdout, "\nPreferred factorization engine: ");
	    char *preferred_factorization_engine = BUFFER_OF_SIZE(200); fscanf(stdin, " %s", preferred_factorization_engine);
	    // Works ^

	    fscanf(file, "%s[^\n]", BUFFER); fclose(file); int SELECTOR = translate_SUBTRACT_ONE(BUFFER); free(BUFFER); return SELECTOR;
	}
}
*/

void FACTORIZATION_METHOD_UNCHOSEN(char *arg) {
    fprintf(stderr, "Couldn't understand engine specification '%s', please specify one of the following:\n", arg);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _A, __a, _B, __b, _C, __c);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _D, __d, _E, __e, _F, __f);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", _G, __g, _H, __h);
    fprintf(stderr, "\n'%s' is not one of these.\n\n", arg);
    fprintf(stderr, EXIT_STATUS_GOODBYE, -2); exit(-2);
}

int translate_SUBTRACT_ONE(char *arg) {
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

int interpret_ENGINE_from_external_file() {
    FILE *file;
    if (file = fopen(_preferred_factorization_engine_file, "r")) {
	char *BUFFER = BUFFER_OF_SIZE(200);
	fscanf(file, "%s[^\n]", BUFFER); fclose(file); int SELECTOR = translate_SUBTRACT_ONE(BUFFER); free(BUFFER); return SELECTOR;
    } fprintf(stderr, "Couldn't open preferences file '%s'. " EXIT_STATUS_GOODBYE, -1, _preferred_factorization_engine_file); exit(-1);
}
