// doesn't get 'h'
#include <stdio.h> // needed for 'fprintf()', 'fopen()'
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()', 'BUFFER_OF_SIZE()', EXIT_STATUS_GOODBYE
#include "../../libraries/mathematics/factorization_methods.h" // needed for 'translate_SUBTRACT_ONE()'
#include "../../libraries/mathematics/primality_testing_scemes.h" // needed for 'SET_preferred_PRIMALITY_TEST()', 'FACTORIZATION_METHOD_UNCHOSEN()'

_primality_test chosen_PRIMALITY_TEST() { _primality_test preferred_PRIMALITY_TEST = preferred_PRIMALITY_TEST_REPORT();
    if (preferred_PRIMALITY_TEST == efficient_trial_division_PRIMALITY_TEST) fprintf(stdout, "%s", A_REPORT());
    else if (preferred_PRIMALITY_TEST == LESS_efficient_trial_division_PRIMALITY_TEST) fprintf(stdout, "%s", B_REPORT());
    else if (preferred_PRIMALITY_TEST == LEAST_efficient_trial_division_PRIMALITY_TEST) fprintf(stdout, "%s", C_REPORT());
    else if (preferred_PRIMALITY_TEST == efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) fprintf(stdout, "%s", D_REPORT());
    else if (preferred_PRIMALITY_TEST == LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) fprintf(stdout, "%s", E_REPORT());
    else if (preferred_PRIMALITY_TEST == LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) fprintf(stdout, "%s", F_REPORT());
    else if (preferred_PRIMALITY_TEST == shor_factorization_PRIMALITY_TEST) fprintf(stdout, "%s", G_REPORT());
    else if (preferred_PRIMALITY_TEST == fermat_factorization_PRIMALITY_TEST) fprintf(stdout, "%s", H_REPORT());
    return preferred_PRIMALITY_TEST;
}

int main(int argc, char **argv) { unsigned long potential_prime;
    if (2 > argc || !str_represents_ul(argv[1], &potential_prime)) exit(-1); char *ptr = argv[2];
    if (!ptr) {
	FILE *file;
	if (!(file = fopen(preferred_factorization_engine_file_REPORT(), "r"))) { fprintf(stderr, "Couldn't open preferences file '%s'. "EXIT_STATUS_GOODBYE, preferred_factorization_engine_file_REPORT(), -1); exit(-1); }
	ptr = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ptr); fclose(file);
    }
    int SELECTOR = translate_SUBTRACT_ONE(ptr);
    if (SELECTOR) SET_preferred_PRIMALITY_TEST(SELECTOR - 1);
    else FACTORIZATION_METHOD_UNCHOSEN(ptr);

    fprintf(stdout, "Using the factorization engine \""); _primality_test preferred_PRIMALITY_TEST =  chosen_PRIMALITY_TEST();
    fprintf(stdout, "\" as the basis for my primality test on %lu.", potential_prime);
    if (!(argc < 3)) fprintf(stdout, "	(as specified by terminal argument)"); fprintf(stdout, "\n\n");

    fprintf(stdout, "%lu is ", potential_prime);
    if (prime(potential_prime, preferred_PRIMALITY_TEST)) fprintf(stdout, "prime.\n", potential_prime);
    else fprintf(stdout, "not prime.\n", potential_prime);
    return 0;
}
