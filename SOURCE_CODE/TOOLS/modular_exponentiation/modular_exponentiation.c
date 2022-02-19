#include <stdio.h> // 'printf()'
#include <stdlib.h> // 'malloc()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'N_operation()'

void exponent_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use for the exponent.", unparsed_arg); }
void base_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the base.", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the modulus.", unparsed_arg); }

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &mod, 0)) conditional_goodbye(n(error_specification(mod_error, -1)));
    unsigned long base;     unparsed_arg = argv[2]; if (!str_represents_ul(unparsed_arg, &base, 0)) conditional_goodbye(n(error_specification(base_error, -2)));
    unsigned long exponent; unparsed_arg = argv[3]; if (!str_represents_ul(unparsed_arg, &exponent, 0)) conditional_goodbye(n(error_specification(exponent_error, -3)));
    // ^^^ Parse terminal arguments

    fprintf(stdout, "%lu^%lu %% %lu = %lu\n", base, exponent, mod, mod_exponentiate(base, exponent));
    // ^^^ Perform modular exponentiation using the "FINITE_N_exponentiation()" function
    return 0;
}
