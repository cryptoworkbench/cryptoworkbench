// Program description: performs modular exponentiation using the 'square and multiply' method for modular exponentiation (which is implemented in math.c). Not much to be said here.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

void exponent_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use for the exponent.", unparsed_arg); }
void base_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the base.", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the modulus.", unparsed_arg); }
// error functions ^^^

int main(int argc, char **argv) { unsigned long mod;
    mod_ = &mod;            conditional_goodbye(n(n(error_specification(mod_error, ul_parse_str(argv[1], mod_, -1)))));
    unsigned long base;     conditional_goodbye(n(n(error_specification(base_error, ul_parse_str(argv[2], &base, -1)))));
    unsigned long exponent; conditional_goodbye(n(n(error_specification(exponent_error, ul_parse_str(argv[3], &exponent, -1)))));
    fprintf(stdout, "%lu^%lu %% %lu = %lu\n", base, exponent, mod, mod_exponentiate(base, exponent)); return 0;
}
