// Program description: performs modular exponentiation using the 'square and multiply' method for modular exponentiation (which is implemented in math.c). Not much to be said here.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

unsigned long mod, base, exponent;

void exponent_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use for the exponent.", (*argv_ptr)[3]); }
void ____base_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the base.", (*argv_ptr)[2]); }
void _____mod_failed_to_parse() { fprintf(stderr, "\nFailed to understand '%s' as the value to use as the modulus.", (*argv_ptr)[1]); }
// error functions ^^^

int main(int argc, char **argv) { mod = base = exponent = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(_____mod_failed_to_parse, ul_parse_str(&     mod, argv[1], -1)))));
    conditional_goodbye(n(n(error_specification(____base_failed_to_parse, ul_parse_str(&    base, argv[2], -2)))));
    conditional_goodbye(n(n(error_specification(exponent_failed_to_parse, ul_parse_str(&exponent, argv[3], -3)))));
    // take in finite field, base, and exponent for function ^

    mod_ = &mod; fprintf(stdout, "%lu^%lu modulus %lu = %lu\n", base, exponent, mod, mod_exponentiate(base, exponent));
    // give result ^
    
    return 0;
}
