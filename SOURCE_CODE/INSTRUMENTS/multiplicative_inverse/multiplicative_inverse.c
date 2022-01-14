#include <stdio.h>
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'GCD()'
UL MOD; // < Handle library inclusions ^^

const char *argv_ONE[] = {"first", "modulus"};
const char *argv_TWO[] = {"second", "number coprime with the modulus whose multiplicative inverse you want to know"};

void argv_ERROR(char **argv, int index) {
    const char **error_specific_message = argv_ONE;
    if (index == 2) error_specific_message = argv_TWO;
    fprintf(stderr, "%s is not something I am able to understand as a number; please provide as %s argument the %s.\n\nTerminating with exit status '-%i'.\n", argv[index], error_specific_message[0], error_specific_message[1], index);
    exit(-index);
} // ^ used by 'main()'

int main(int argc, char **argv) { // 'UL MOD' is at line 4
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) argv_ERROR(argv, 1); UL number_coprime_to_MOD;
    if (3 > argc || !str_represents_ul(argv[2], &number_coprime_to_MOD)) argv_ERROR(argv, 2); UL GCD_of_arguments = GCD(number_coprime_to_MOD, MOD);
    // ^ take in supplied (MANDATORY) arguments

    if (GCD_of_arguments != 1) { fprintf(stderr, "%lu shares a factor of %lu with %lu.\n\nTerminating with exit status '-3'.\n", number_coprime_to_MOD, GCD_of_arguments, MOD); exit(-3); }
    // ^ exit if the number to calculate the multiplicative inverse of is not coprime to the modulus

    fprintf(stdout, "%lu^(-1) \u2261 ", number_coprime_to_MOD);
    if (number_coprime_to_MOD != number_coprime_to_MOD % MOD) fprintf(stdout, "%lu^(-1) \u2261 ", number_coprime_to_MOD % MOD);
    fprintf(stdout, "%lu (mod %lu)\n", modular_division(1, number_coprime_to_MOD), MOD);
    // ^ display result

    return 0;
}
