// doesn't get 'h'
#include <stdio.h> // needed for 'fprintf()', 'fopen()'
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()', 'BUFFER_OF_SIZE()', EXIT_STATUS_GOODBYE
#include "../../libraries/mathematics/factorization_methods.h" // needed for 'SELECTOR_from_str_representing_factorization_method()'
#include "../../libraries/mathematics/primality_testing.h" // needed for 'SET_preferred_PRIMALITY_TEST()', 'FACTORIZATION_METHOD_UNCHOSEN()'

int main(int argc, char **argv) { unsigned long potential_prime;
    if (!str_represents_ul(argv[1], &potential_prime)) exit(-1);
    
    char *ptr = argv[2]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_primality_test = primality_test(SELECTOR_from_str_representing_factorization_method(ptr)))) {
	fprintf(stderr, "Failed to interpret '%s' from ", ptr); if (argv[2]) fprintf(stderr, "terminal argument");
	else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_primality_test = primality_test(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[2]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); }
    } // if both the terminal argument and the preferences file were unintelligeble, then force take factorization method from STDIN

    fprintf(stdout, "Using the factorization engine \"%s\" as the basis for my primality test on %lu.", chosen_PRIMALITY_TEST(), potential_prime);
    if (!(argc < 3)) fprintf(stdout, "	(as specified by terminal argument)"); fprintf(stdout, "\n\n");

    fprintf(stdout, "%lu is ", potential_prime);
    if (prime(potential_prime, NULL)) fprintf(stdout, "prime.\n", potential_prime);
    else fprintf(stdout, "not prime.\n", potential_prime);

    // for (unsigned long i = 2; i < 100; i++) if (prime(i, NULL)) printf("%lu\n", i);
    // ^ for a little prime batch
    return 0;
}
