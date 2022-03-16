// Program description: performs modular exponentiation using the 'square and multiply' method for modular exponentiation (which is implemented in math.c). Not much to be said here.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

void exponent_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use for the exponent.", unparsed_arg); }
void ____base_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the base.", unparsed_arg); }
void _____mod_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the modulus.", unparsed_arg); }
// error functions ^^^

int main(int argc, char **argv) {
    unsigned long mod;      conditional_goodbye(n(n(error_specification(_____mod_failed_to_parse, ul_parse_str(     &mod, argv[1], -1)))));
    unsigned long base;     conditional_goodbye(n(n(error_specification(____base_failed_to_parse, ul_parse_str(    &base, argv[2], -2)))));
    unsigned long exponent; conditional_goodbye(n(n(error_specification(exponent_failed_to_parse, ul_parse_str(&exponent, argv[3], -3))))); mod_ = &mod;
    fprintf(stdout, "%lu^%lu modulus %lu = %lu\n", base, exponent, mod, mod_exponentiate(base, exponent)); return 0;
}
