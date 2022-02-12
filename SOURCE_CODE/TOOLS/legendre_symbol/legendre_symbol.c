// Here I will calculate the Legende symbol using Euler's criterion.:q
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/primality_testing.h"

int main(int argc, char **argv) { const char *specific_file = _REPORT_preferred_factorization_engine_file();
    FILE *file; if (!(file = fopen(specific_file, "r"))) { fprintf(stderr, "Couldn't open preferences file '%s'." EXIT_STATUS_GOODBYE, specific_file, -1); exit(-1); }
    // ^ open file required for reading

    char *BUFFER = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", BUFFER); fclose(file);
    // ^ copy first 200 bytes from file into BUFFER

    int SELECTOR = SELECTOR_from_str_representing_factorization_method(BUFFER); if (SELECTOR) SET_preferred_factorization_ENGINE(SELECTOR - 1); else FACTORIZATION_METHOD_UNCHOSEN(BUFFER); free(BUFFER);
    // ^ Now engine should be set

    unsigned long p; if (2 > argc || !str_represents_ul(argv[1], &p)) { fprintf(stderr, "Failed to interpret %s as 'p'.\n", argv[1]); exit(-2); }
    unsigned long q; if (3 > argc || !str_represents_ul(argv[2], &q)) { fprintf(stderr, "Failed to interpret %s as 'q'.\n", argv[2]); exit(-3); }
    // ^ interpret required primes

    if (!primality_test_based_on_preferred_factorization_engine(p)) { fprintf(stderr, "p (%lu) is not prime.\n", p); exit(-4); }
    if (!primality_test_based_on_preferred_factorization_engine(q)) { fprintf(stderr, "q (%lu) is not prime.\n", q); exit(-5); }
    if (p > q) { p %= q; fprintf(stdout, "Reduced p modulus q.\n"); }
    fprintf(stdout, "p = %lu\n", p); fprintf(stdout, "q = %lu\n\n", q); fprintf(stdout, "The Legendre symbol of p over q ( p / q ) = %lu over %lu = ( %lu / %lu ) = %i\n", p, q, p, q, legendre_symbol(p, q));
    return 0;
}
