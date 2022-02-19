#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for 'mod_inverse()'

const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *denominator_parsing_error = "Please provide as third argument the denominator.";
const char *numerator_parsing_error = "Please provide as second argument the numerator.";

void mod_error() { fprintf(stderr, MOD_parsing_error); }
void denominator_error() { fprintf(stderr, denominator_parsing_error); }
void numerator_error() { fprintf(stderr, numerator_parsing_error); }

unsigned long mod; int main(int argc, char **argv) { mod_ = &mod;
    conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(argv[1], &mod, -1)))))); unsigned long numerator;
    conditional_goodbye(n(n(error_specification(numerator_error, n(str_represents_ul_(argv[2], &numerator, -2)))))); unsigned long denominator;
    conditional_goodbye(n(n(error_specification(denominator_error, n(str_represents_ul_(argv[3], &denominator, -3))))));

    fprintf(stdout, "%lu / %lu \u2261 %lu (mod %lu)\n", numerator, denominator, mod_divide(numerator, denominator), mod);
    return 0;
}
