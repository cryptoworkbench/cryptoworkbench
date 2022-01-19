// I WANT THIS TO BECOME A GENERAL FACTORIZATION APP WHICH CHOOSES IT'S FACTORIZATION METHOD BASED ON TERMINAL ARGUMENTS
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'factorization_method_WRAPPER()'
ul MOD; // < This time we will use 'MOD' for the odd composite

char *fermat = "fermat_factorization";
char *naive = "naive_factorization";
char *least_naive = "least_naive_factorization_approach";

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[1]); exit(-1); }
    if (3 > argc || !match_variadic(argv[2], 3, fermat, naive, least_naive)) { fprintf(stderr, "Failed to interpret '%s' as one of the factorization methods available.\n"); exit(-2); }
    fprintf(stdout, "Using \"%s\" as the factorization method.\n\n", argv[2]);
    // ^ Deal with user input

    _factorization_method chosen_factorization_method;
    if (strcmp(argv[2], fermat) == 0) chosen_factorization_method = fermat_factorize;
    else if (strcmp(argv[2], naive) == 0) chosen_factorization_method = naive_factorize;
    else chosen_factorization_method = least_naive_factorization_approach; // we do not have to check the last possibility

    struct ordered_pair factorization_of_MOD = factorization_method_WRAPPER(chosen_factorization_method, MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
