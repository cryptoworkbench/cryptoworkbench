#include <stdio.h> // < Needed for "fprintf()"
#include <stdlib.h> // < Needed for "malloc()"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h" // <<< Needed for "ul_ptr_from_str()"
UL MODULUS;

void QUIT_ON_ARGV_THREE_ERROR(char *argv_three) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp exponent '%s'. Returning '-3'.\n", argv_three); exit(-2);
}

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp base '%s'. Returning '-2'.\n", argv_two); exit(-2);
}

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp modulus '%s'. Returning '-1'.\n", argv_one); exit(-1);
}

int main(int argc, char **argv) { UL base, exponent;
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MODULUS)) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    else if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &base)) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    else if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &exponent)) QUIT_ON_ARGV_THREE_ERROR(argv[3]);
    // ^^^ Parse terminal arguments

    fprintf(stdout, "%lu^%lu %% %lu = %lu\n", base, exponent, MODULUS, N_combine(base, exponent, EXPONENTIAL));
    // ^^^ Perform modular exponentiation using the "FINITE_N_exponentiation()" function
    return 0;
}
