// Here I will calculate the Legende symbol using Euler's criterion.:q
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/primality_testing_scemes.h"
unsigned long MOD;

void initialize() {
    if (preferred_factorization_ENGINE == LEAST_efficient_trial_division) fprintf(stdout, "Using trial division");
    else if (preferred_factorization_ENGINE == LESS_efficient_trial_division) fprintf(stdout, "Using trial division");
    else if (preferred_factorization_ENGINE == efficient_trial_division) fprintf(stdout, "Using trial division");
    else if (preferred_factorization_ENGINE == LEAST_efficient_trial_division_TABLE_AIDED) fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename());
    else if (preferred_factorization_ENGINE == LESS_efficient_trial_division_TABLE_AIDED) fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename());
    else if (preferred_factorization_ENGINE == efficient_trial_division_TABLE_AIDED) fprintf(stdout, "Using prime table aided trial division (with '%s')", REPORT_standard_prime_table_filename()); 
    else if (preferred_factorization_ENGINE == shor_factorization) { fprintf(stdout, "Applying Shor's factorization algorithm for quantum computers."); }
    else fprintf(stdout, "Using Fermat's factorization method.");
}

int main(int argc, char **argv) {
    FILE *file; if (!(file = fopen(FILE_SPECIFYING_PREFERRED_ENGINE, "r"))) { fprintf(stderr, "Couldn't open preferences file '" FILE_SPECIFYING_PREFERRED_ENGINE "'. " EXIT_STATUS_GOODBYE, -1); exit(-1); }
    // ^ open file required for reading

    char *BUFFER = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", BUFFER); fclose(file);
    // ^ copy first 200 bytes from file into BUFFER

    int SELECTOR = translate_SUBTRACT_ONE(BUFFER); if (SELECTOR) SET_preferred_factorization_ENGINE(SELECTOR - 1); else ERR(BUFFER); free(BUFFER); // initialize();
    // ^ Now engine should be set

    unsigned long p; if (2 > argc || !str_represents_ul(argv[1], &p)) { fprintf(stderr, "Failed to interpret %s as 'p'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    // ^ interpret required primes

    if (composite_test_based_on_preferred_factorization_engine(p)) { fprintf(stderr, "p (%lu) is not prime.\n", p); exit(-4); }
    if (composite_test_based_on_preferred_factorization_engine(q)) { fprintf(stderr, "q (%lu) is not prime.\n", q); exit(-5); }
    if (p > q) { p %= q; fprintf(stdout, "Reduced p modulus q.\n"); }
    fprintf(stdout, "p = %lu\n", p); fprintf(stdout, "q = %lu\n\n", q); fprintf(stdout, "The Legendre symbol of p over q ( p / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", p, q, p, q, legendre_symbol(p, q));
    return 0;
}
