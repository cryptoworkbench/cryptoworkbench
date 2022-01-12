#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

unsigned long MODULUS;
// ^^ Variables included as "extern" in "../../libraries/mathematics/maths.h"

int main(int argc, char **argv) { unsigned long inv_of_inv;
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MODULUS)) { fprintf(stderr, "%s is not mod.\n", argv[1]); exit(-1); }
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &inv_of_inv)) { fprintf(stderr, "%s is not interpretable.\n", argv[2]); exit(-2); }
    printf("Multiplicative inverse of %lu (a.k.a. %lu) %% %lu: %lu\n", inv_of_inv, inv_of_inv % MODULUS, MODULUS, modular_division(1, inv_of_inv));
    return 0;
}
