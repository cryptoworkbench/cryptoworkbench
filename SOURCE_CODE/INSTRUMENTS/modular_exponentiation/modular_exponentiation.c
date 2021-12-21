#include <stdio.h> // <<< Needed for "fprintf()"
#include <stdlib.h> // <<< Needed for "malloc()"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h" // <<< Needed for "ul_ptr_from_str()"

void QUIT_ON_ARGV_THREE_ERROR(char *argv_three) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp CAP '%s'. Returning '-3'.\n", argv_three); exit(-2);
}

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp base '%s'. Returning '-2'.\n", argv_two); exit(-2);
}

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP '%s'. Returning '-1'.\n", argv_one); exit(-1);
}

int main(int argc, char **argv) { UL BASE, Exponent, CAP;
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &BASE)) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    else if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &Exponent)) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    else if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &CAP)) QUIT_ON_ARGV_THREE_ERROR(argv[3]);
    // ^^^ Parse terminal arguments

    fprintf(stdout, "%lu^%lu %% %lu = %lu\n", BASE, Exponent, CAP, N_combine(CAP, BASE, Exponent, EXPONENTIAL));
    // ^^^ Perform modular exponentiation using the "FINITE_N_exponentiation()" function
    return 0;
}
