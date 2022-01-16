#include <stdio.h> // 'printf()'
#include <stdlib.h> // 'malloc()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'N_operation()'
ul MOD = 0; // <^^ Handle library inclusions

void QUIT_ON_ARGV_THREE_ERROR(char *argv_three) {
    fprintf(stderr, "FATAL ERROR: cannot grasp exponent '%s'. Returning '-3'.\n", argv_three); exit(-2);
}

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stderr, "FATAL ERROR: cannot grasp base '%s'. Returning '-2'.\n", argv_two); exit(-2);
}

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stderr, "FATAL ERROR: cannot grasp modulus '%s'. Returning '-1'.\n", argv_one); exit(-1);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) QUIT_ON_ARGV_ONE_ERROR(argv[1]); ul base;
    if (3 > argc || !str_represents_ul(argv[2], &base)) QUIT_ON_ARGV_TWO_ERROR(argv[2]); ul exponent;
    if (4 > argc || !str_represents_ul(argv[3], &exponent)) QUIT_ON_ARGV_THREE_ERROR(argv[3]);
    // ^^^ Parse terminal arguments

    fprintf(stdout, "%lu^%lu %% %lu = %lu\n", base, exponent, MOD, N_operation(base, exponent, 2));
    // ^^^ Perform modular exponentiation using the "FINITE_N_exponentiation()" function
    return 0;
}
