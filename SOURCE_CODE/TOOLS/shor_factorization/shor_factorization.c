#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // needed for 'DOWN_ROUNDED_second_root()' and some of the factorization methods in 'factorization_methods.c' need functions headers from 'maths.h'
#include "../../libraries/mathematics/factorization_methods.h" // needed for function pointers 'trial_division_LEAST_EFFICIENT', 'trial_division_LESS_EFFICIENT', 'trial_division_MOST_EFFICIENT', etc
ul MOD; // < This time we will use 'MOD' for the composite
_factorization_method preferred_factorization_ENGINE;

int main(int argc, char **argv) { SET_preferred_factorization_ENGINE(9);
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "Str didn represent ul.\n"); exit(-1); }
    struct ordered_pair factor = factorize(MOD, preferred_factorization_ENGINE);
    printf("%lu = %lu * %lu\n", MOD, factor.a, factor.b);
    return 0;
}
