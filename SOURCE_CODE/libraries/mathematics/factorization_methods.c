#include <stdio.h> // needed for 'fprintf()'
#include "../functional/string.h" // needed for definition EXIT_STATUS_GOODBYE
#include "factorization_methods.h" // need for function headers
#include "maths.h" // needed for 'DOWN_ROUNDED_second_root()'
#include "universal_group_library.h" // needed for 'BUFFER_OF_SIZE()'

struct ordered_pair divisor_pair(unsigned long number, unsigned long DIVISOR_OF_number)
{ struct ordered_pair pair_of_divisors; pair_of_divisors.a = DIVISOR_OF_number; pair_of_divisors.b = number / pair_of_divisors.a; return pair_of_divisors; }

unsigned long trial_division(unsigned long presumed_composite, unsigned long trial_limit) {
    ul divisor = MULTIPLICATIVE_IDENTITY; do { divisor++; if (trial_limit < divisor) divisor == presumed_composite; } while (presumed_composite % divisor != 0);
    return divisor;
}

unsigned long _trial_division_TABLE_AIDED(unsigned long presumed_composite, unsigned long trial_limit, FILE *prime_table) {
    ul prime_divisor; do {
	if (fscanf(prime_table, "%lu\n", &prime_divisor) != 1)
	{ fprintf(stderr, "The prime table '%s' not complete enough to find the first prime divisor of %lu. The last prime tested was %lu.\n", REPORT_open_prime_table(), presumed_composite, prime_divisor); exit(-1); }
	if (prime_divisor > trial_limit) prime_divisor = presumed_composite;
    } while (presumed_composite % prime_divisor != 0); prime_table_close(prime_table);
    return prime_divisor;
}

unsigned long trial_division_TABLE_AIDED(unsigned long composite, unsigned long trial_limit) { return _trial_division_TABLE_AIDED(composite, trial_limit, prime_table_open(REPORT_standard_prime_table_filename()));}

unsigned long trial_limit(unsigned long composite, int supidity_level)
{ switch (supidity_level) { case 3: return composite; case 2: return (composite - (composite % 2)) / 2; case 1: return DOWN_ROUNDED_second_root(composite); }; }

unsigned long efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 1)); }
unsigned long LESS_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 2)); }
unsigned long LEAST_efficient_trial_division(unsigned long composite) { return trial_division(composite, trial_limit(composite, 3)); }
// ^ trial division methods

unsigned long efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 1)); }
unsigned long LESS_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 2)); }
unsigned long LEAST_efficient_trial_division_TABLE_AIDED(unsigned long composite) { return trial_division_TABLE_AIDED(composite, trial_limit(composite, 3)); }
// ^ same trial division methods aided by a table

// NOW SOME FUNCTIONS TO ACHIEVE FERMAT FACTORIZATION
// We will use "struct ordered_pair"
// We will use unsigned long member 'a' for the roots
// We will use unsigned member 'b' for the squares
unsigned long difference_of_squares_factorization_method(unsigned long odd_composite) { struct ordered_pair square_BIG = {0, 0}; struct ordered_pair square_SMALL = {0, 0};
    while (square_BIG.b != odd_composite + square_SMALL.b)
    { least_perfect_square_equal_to_or_greater_than(&square_BIG, odd_composite + square_SMALL.b); least_perfect_square_equal_to_or_greater_than(&square_SMALL, square_BIG.b - odd_composite); }
    return square_BIG.a - square_SMALL.a; }
unsigned long evens_factorizer(unsigned long even_composite) { ul a = MULTIPLICATIVE_IDENTITY; do { even_composite /= 2; a *= 2; } while (even_composite % 2 == 0); return a; } // only call with even composite
unsigned long odds_factorizer_WRAPPER(unsigned long composite, _factorization_method odds_factorizer) { return (composite % 2 == 0) ? evens_factorizer(composite) : odds_factorizer(composite); }
unsigned long fermat_factorization(unsigned long composite) { return odds_factorizer_WRAPPER(composite, difference_of_squares_factorization_method); }
// ^ FOUR FUCNCTIONS TO ACHIEVE FERMAT FACTORIZATION

_factorization_method factorization_method(int SELECTOR) {
    switch (SELECTOR) { case 0: return LEAST_efficient_trial_division; case 1: return LESS_efficient_trial_division; case 2: return efficient_trial_division; case 3: return LEAST_efficient_trial_division_TABLE_AIDED;
	case 4: return LESS_efficient_trial_division_TABLE_AIDED; case 5: return efficient_trial_division_TABLE_AIDED; case 6: return fermat_factorization; };
} void SET_preferred_factorization_ENGINE(int SELECTOR) { preferred_factorization_ENGINE = factorization_method(SELECTOR); }

struct ordered_pair factorize(unsigned long number, _factorization_method factorization_ENGINE_to_use) {
    if (!factorization_ENGINE_to_use) factorization_ENGINE_to_use = preferred_factorization_ENGINE; // < unless there was an engine specified, use the engine all of the functions use
    return divisor_pair(number, factorization_ENGINE_to_use(number));
}

const char *a = "a"; const char *b = "b"; const char *c = "c"; const char *d = "d"; const char *e = "e"; const char *f = "f"; const char *g = "g";
const char *A = "trial_division_in_its_least_efficient_form"; char *REPORT_A() { return (char *) A; }
const char *B = "trial_division_in_its_less_efficient_form"; char *REPORT_B() { return (char *) B; }
const char *C = "trial_division_in_its_most_efficient_form"; char *REPORT_C() { return (char *) C; }
const char *D = "prime_table_aided_trial_division_in_its_least_efficient_form"; char *REPORT_D() { return (char *) D; }
const char *E = "prime_table_aided_trial_division_in_its_less_efficient_form"; char *REPORT_E() { return (char *) E; }
const char *F = "prime_table_aided_trial_division_in_its_most_efficient_form"; char *REPORT_F() { return (char *) F; }
const char *G = "fermats_factorization_method"; char *REPORT_G() { return (char *) G; }
// ^ string literals we will be comparing against

void ERR(char *arg) {
    fprintf(stderr, "Couldn't understand engine specification '%s', please specify one of the following:\n", arg);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", a, A, b, B, c, C);
    fprintf(stderr, "\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n\"%s\" for \"%s\"\n", d, D, e, E, f, F);
    fprintf(stderr, "\"%s\" for \"%s\"\n", g, G);
    fprintf(stderr, "\n'%s' is not one of these.\n\n", arg);
    fprintf(stderr, EXIT_STATUS_GOODBYE, -2); exit(-2);
}

int translate_SUBTRACT_ONE(char *arg) {
    if (match_variadic(arg, 2, A, a)) return 1;
    else if (match_variadic(arg, 2, B, b)) return 2;
    else if (match_variadic(arg, 2, C, c)) return 3;
    else if (match_variadic(arg, 2, D, d)) return 4;
    else if (match_variadic(arg, 2, E, e)) return 5;
    else if (match_variadic(arg, 2, F, f)) return 6;
    else if (match_variadic(arg, 2, G, g)) return 7;
    return 0;
}

int interpret_ENGINE_from_external_file() { FILE *file;
    if (file = fopen(FILE_SPECIFYING_PREFERRED_ENGINE, "r")) {
	char *BUFFER = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", BUFFER); fclose(file);
	int SELECTOR = translate_SUBTRACT_ONE(BUFFER) - 1;
	free(BUFFER);
	return SELECTOR; // <-- return situated here
    } fprintf(stderr, "Couldn't open preferences file '" FILE_SPECIFYING_PREFERRED_ENGINE "'. " EXIT_STATUS_GOODBYE, -1); exit(-1);
}

unsigned long _period(unsigned long exponent) { // only suppoed to be called when i^MOD
    printf("arrived in _period():\n");
    printf("GCD(%lu, %lu) = %lu\n", exponent, MOD, GCD(exponent, MOD));
    ul logarithm = 1;
    /*
    while (exponent != MULTIPLICATIVE_IDENTITY)
    { exponent *= exponent; exponent %= MOD; logarithm++; printf("%lu, ", exponent); } */
    return logarithm;
}

unsigned long shor_factorize(unsigned long presumed_composite) {
    ul a = MULTIPLICATIVE_IDENTITY; do {a++;
	fprintf(stdout, "\ntest for value a = %lu  ", a);
	unsigned long _GCD = GCD(presumed_composite, a); if (_GCD != 1) return _GCD;
	ul period = modular_division(MULTIPLICATIVE_IDENTITY, a);
	printf(" (peroid of a mod N: %lu)", period);
	// if (period % 2 == 1 || MOD == exponentiation(a, period / 2) + 1) continue;
	if (period % 2 == 1) continue; printf(" period of %lu is even, subjecting %lu to next test.", a, a);
	if (exponentiation(a, period / 2) + 1 == MOD) continue; printf(" %lu^%lu + 1 is not k * %lu", a, period / 2, MOD);
	printf("\n");
	ul a_to_half_p = exponentiate_UNRESTRICTEDLY(a, period / 2);
	ul p = GCD(a_to_half_p - 1, MOD);
	ul q = GCD(a_to_half_p + 1, MOD);

	printf("Factor a = GCD(%lu, %lu - 1) = GCD(%lu, %lu) = %lu\n", MOD, a_to_half_p, MOD, a_to_half_p - 1, p);
	printf("Factor q = GCD(%lu, %lu + 1) = GCD(%lu, %lu) = %lu\n", MOD, a_to_half_p, MOD, a_to_half_p + 1, q);
	printf("%lu = %lu * %lu\n", MOD, p, q);
	if (p < q) return p;
	else return q;
    } while (a <= presumed_composite);
}
