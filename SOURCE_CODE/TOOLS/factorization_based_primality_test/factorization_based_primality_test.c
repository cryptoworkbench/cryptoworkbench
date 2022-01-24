// doesn't get 'h'
#include <stdio.h> // needed for 'fprintf()', 'fopen()'
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()', 'BUFFER_OF_SIZE()', EXIT_STATUS_GOODBYE
#include "../../libraries/mathematics/factorization_methods.h" // needed for 'translate_SUBTRACT_ONE()'
#include "../../libraries/mathematics/primality_testing_scemes.h" // needed for 'SET_preferred_PRIMALITY_TEST()', 'ERR()'
unsigned long MOD;
_primality_test preferred_PRIMALITY_TEST;

char *chosen_PRIMALITY_TEST(_primality_test PRIMALITY_TEST) {
    if (PRIMALITY_TEST == LEAST_efficient_trial_division_PRIMALITY_TEST) return REPORT_A();
    else if (PRIMALITY_TEST == LESS_efficient_trial_division_PRIMALITY_TEST) return REPORT_B();
    else if (PRIMALITY_TEST == efficient_trial_division_PRIMALITY_TEST) return REPORT_C();
    else if (PRIMALITY_TEST == LEAST_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return REPORT_D();
    else if (PRIMALITY_TEST == LESS_efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return REPORT_E();
    else if (PRIMALITY_TEST == efficient_trial_division_TABLE_AIDED_PRIMALITY_TEST) return REPORT_F();
    else if (PRIMALITY_TEST == shor_factorize_PRIMALITY_TEST) return REPORT_G();
    else if (PRIMALITY_TEST == fermat_factorization_PRIMALITY_TEST) return REPORT_H();
    else return NULL;
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) exit(-1);
    char *ptr = argv[2]; // may be NULL
    if (argc < 3) { FILE *file; if (file = fopen(FILE_SPECIFYING_PREFERRED_ENGINE, "r")) { ptr = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ptr); fclose(file); }
	else { fprintf(stderr, "Couldn't open preferences file '" FILE_SPECIFYING_PREFERRED_ENGINE "'. "EXIT_STATUS_GOODBYE, -1); exit(-1); } }
    int SELECTOR = translate_SUBTRACT_ONE(ptr);
    if (SELECTOR) SET_preferred_PRIMALITY_TEST(SELECTOR - 1); // < a.k.a. interpretation from 'ptr' successful
    else ERR(ptr);
    
    fprintf(stdout, "Using the factorization engine \"%s\" as the basis for my primality test on %lu.", chosen_PRIMALITY_TEST(preferred_PRIMALITY_TEST), MOD); if (!(argc < 3)) fprintf(stdout, "	(as specified by terminal argument)");
    fprintf(stdout, "\n\n");

    if (preferred_PRIMALITY_TEST(MOD)) fprintf(stdout, "%lu is prime.\n", MOD);
    else fprintf(stdout, "%lu is not prime.\n", MOD);
    return 0;
}
