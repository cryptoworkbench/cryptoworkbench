#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
#include "../../libraries/mathematics/universal_group_library.h"
ul MOD;

void initialize() {
    if (ENGINE == LEAST_efficient_trial_division) fprintf(stdout, "Using \"LEAST_efficient_trial_division\" as factorization engine.\n"); 
    else if (ENGINE == LESS_efficient_trial_division) fprintf(stdout, "Using \"LESS_efficient_trial_division\" as factorization engine.\n"); 
    else if (ENGINE == efficient_trial_division) fprintf(stdout, "Using \"efficient_trial_division\" as factorization engine.\n"); 
    else if (ENGINE == LEAST_efficient_trial_division_TABLE_AIDED)
	fprintf(stdout, "Using \"LEAST_efficient_trial_division_TABLE_AIDED\" as factorization engine.\n"); 
    else if (ENGINE == LESS_efficient_trial_division_TABLE_AIDED)
	fprintf(stdout, "Using \"LESS_efficient_trial_division_TABLE_AIDED\" as factorization engine.\n"); 
    else if (ENGINE == efficient_trial_division_TABLE_AIDED)
	fprintf(stdout, "Using \"efficient_trial_division_TABLE_AIDED\" as factorization engine.\n"); 
    else fprintf(stdout, "Using Fermat's factorization method.");
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) exit(-1);
    interpret_ENGINE_from_external_file(); char *ptr = argv[2]; // may be NULL
    if (argc < 3) { FILE *file; if (file = fopen(FILE_SPECIFYING_PREFERRED_ENGINE, "r")) { ptr = BUFFER_OF_SIZE(200); fscanf(file, "%s[^\n]", ptr); fclose(file); }
	else { fprintf(stderr, "Couldn't open preferences file '" FILE_SPECIFYING_PREFERRED_ENGINE "'." EXIT_STATUS_GOODBYE, -1); exit(-1); } }
    int SELECTOR = translate_SUBTRACT_ONE(ptr);
    if (SELECTOR) ENGINE_SET(SELECTOR - 1); // < a.k.a. interpretation from 'ptr' successful
    else ERR(ptr); initialize(); if (!(argc < 3)) fprintf(stdout, "	(engine specified by terminal argument)"); fprintf(stdout, "\n\n");

    if (prime(MOD)) fprintf(stdout, "%lu is prime.\n", MOD);
    else fprintf(stdout, "%lu is not prime.\n", MOD);
    return 0;
}
