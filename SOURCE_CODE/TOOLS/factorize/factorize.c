// I WANT THIS TO BECOME A GENERAL FACTORIZATION APP WHICH CHOOSES IT'S FACTORIZATION METHOD BASED ON TERMINAL ARGUMENTS
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'factorization_method_WRAPPER()'
ul MOD; // < This time we will use 'MOD' for the odd composite


char *fermats_factorization_APPROACH = "fermats_factorization_approach";
char *naive_factorization_APPROACH = "naive_factorization_approach";
char *least_naive_factorization_APPROACH = "least_naive_factorization_approach";

void unrecognized_APPROACH(char *argv_two) {
    fprintf(stderr, "Failed to interpret '%s' as one of the three factorization engines available:\n", argv_two);
    fprintf(stderr, "1). %s\n", fermats_factorization_APPROACH);
    fprintf(stderr, "2). %s\n", naive_factorization_APPROACH);
    fprintf(stderr, "3). %s\n\nTerminating with exit status '-1'.\n", least_naive_factorization_APPROACH);
    exit(-1);
}

int main(int argc, char **argv) {
    if (2 > argc || !match_variadic(argv[1], 3, fermats_factorization_APPROACH, naive_factorization_APPROACH, least_naive_factorization_APPROACH)) unrecognized_APPROACH(argv[1]);
    if (3 > argc || !str_represents_ul(argv[2], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[2]); exit(-2); }
    fprintf(stdout, "Using \"%s\" as the factorization method.\n\n", argv[1]);
    // ^ Deal with user input

    _factorization_method factorization_method_chosen;
    if (strcmp(argv[1], fermats_factorization_APPROACH) == 0) factorization_method_chosen = fermats_factorization_approach;
    else if (strcmp(argv[1], naive_factorization_APPROACH) == 0) factorization_method_chosen = naive_factorization_approach;
    else factorization_method_chosen = least_naive_factorization_approach; // we do not have to check the last possibility

    struct ordered_pair factorization_of_MOD = factorization_method_WRAPPER(factorization_method_chosen, MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
