#include <stdio.h> // needed for 'fprintf()', 'fopen()'
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()', 'BUFFER_OF_SIZE()', EXIT_STATUS_GOODBYE
#include "../../libraries/mathematics/factorization_methods.h" // needed for 'SET_preferred_factorization_ENGINE()', 'translate_SUBTRACT_ONE()'
#include "../../libraries/mathematics/primality_testing_scemes.h" // needed for 'prime()'
unsigned long MOD;

char *chosen_factorization_engine(_factorization_method engine) {
    if (engine == LEAST_efficient_trial_division) return REPORT_A();
    else if (engine == LESS_efficient_trial_division) return REPORT_B();
    else if (engine == efficient_trial_division) return REPORT_C();
    else if (engine == LEAST_efficient_trial_division_TABLE_AIDED) return REPORT_D();
    else if (engine == LESS_efficient_trial_division_TABLE_AIDED) return REPORT_E();
    else if (engine == efficient_trial_division_TABLE_AIDED) return REPORT_F();
    else if (engine == fermat_factorization) return REPORT_G();
    else return NULL;
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) exit(-1);
    interpret_ENGINE_from_external_file(); char *ptr = argv[2]; // may be NULL
    if (argc < 3) { FILE *file; if (file = fopen(FILE_SPECIFYING_PREFERRED_ENGINE, "r")) { ptr = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ptr); fclose(file); }
	else { fprintf(stderr, "Couldn't open preferences file '" FILE_SPECIFYING_PREFERRED_ENGINE "'. kkkk"EXIT_STATUS_GOODBYE, -1); exit(-1); } }
    int SELECTOR = translate_SUBTRACT_ONE(ptr);
    if (SELECTOR) SET_preferred_factorization_ENGINE(SELECTOR - 1); // < a.k.a. interpretation from 'ptr' successful
    else ERR(ptr);
    
    fprintf(stdout, "Using the factorization engine \"%s\" as the basis for my primality test on %lu.", chosen_factorization_engine(prefered_factorization_ENGINE), MOD); if (!(argc < 3)) fprintf(stdout, "	(engine specified by terminal argument)");
    fprintf(stdout, "\n\n");

    if (prime(MOD)) fprintf(stdout, "%lu is prime.\n", MOD);
    else fprintf(stdout, "%lu is not prime.\n", MOD);
    return 0;
}
