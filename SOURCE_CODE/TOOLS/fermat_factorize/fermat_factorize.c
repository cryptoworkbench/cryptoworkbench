#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'factorization_method_WRAPPER()'
ul MOD; // < This time we will use 'MOD' for the odd composite

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "Failed to interpret composite '%s'!\n\nTerminating with exit status '-1'.\n", argv[1]); exit(-1); }
    if (MOD % 2 == 0) { fprintf(stderr, "%lu \u2261 1	(modulus 2)\n\n\nFermat's factorization method does not work for even numbers.\n\nTerminating with exit status '-2'.\n", MOD); exit(-2); }

    struct ordered_pair factorization_of_MOD = fermat_factorize(MOD);
    fprintf(stdout, "%lu = %lu * %lu\n", MOD, factorization_of_MOD.a, factorization_of_MOD.b);
    return 0;
}
