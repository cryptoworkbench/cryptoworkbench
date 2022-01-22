#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"
ul MOD;

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) exit(-1);
    ENGINE_SET(0);
    if (prime(MOD)) fprintf(stdout, "%lu is prime.\n", MOD);
    else fprintf(stdout, "%lu is not prime.\n", MOD);
    return 0;
}
