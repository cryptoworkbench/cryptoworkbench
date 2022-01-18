#include <stdio.h>
#include "../../libraries/functional/string.h"
// #include "../../libraries/mathematics/maths.h" // 'fermat_factorization()'
ul MOD; // < This time we will use 'MOD' for the odd composite

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "Failed to interpret limit '%s'!\n", argv[1]); exit(-1); }

    struct N_pair factorization_of_MOD = fermat_factorization(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.one, factorization_of_MOD.two);
    return 0;
}
