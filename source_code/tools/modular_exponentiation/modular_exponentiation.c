#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // mod_exponentiate();

int main(int argc, char **argv) {
    unsigned long modulus, exponent, base;
    // ^^^ Declare needed variables
    
    fprintf(stdout, "Modulus: ");
    if (4 > argc || (! ul_ptr_from_str(&modulus, argv[3]))) fscanf(stdin, "%lu", &modulus);
    else fprintf(stdout, "%lu\n", modulus);

    fprintf(stdout, "Exponent: ");
    if (3 > argc || (! ul_ptr_from_str(&exponent, argv[2]))) fscanf(stdin, "%lu", &exponent);
    else fprintf(stdout, "%lu\n", exponent);

    fprintf(stdout, "Base: ");
    if (2 > argc || (! ul_ptr_from_str(&base, argv[1]))) fscanf(stdin, "%lu", &base);
    else fprintf(stdout, "%lu\n", base);

    fprintf(stdout, "\n%lu^%lu %% %lu = %lu\n", base, exponent, modulus, mod_exponentiate(base, exponent, modulus));
    exit(0);
}
