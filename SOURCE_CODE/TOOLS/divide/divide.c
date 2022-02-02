#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for 'mod_inverse()'

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *denominator_parsing_error = "Please provide as second argument the denominator.";
const char *numerator_parsing_error = "Please provide as third argument the numerator.";

const char *local_switch(int INDEX) { switch (INDEX) { case 1: return MOD_parsing_error; case 2: return denominator_parsing_error; case 3: return numerator_parsing_error; }; }

unsigned long mod; int main(int argc, char **argv) { mod_ = &mod; local_error_selector = local_switch;
    if (!str_represents_ul(argv[1], &mod)) str_does_not_represent_suitable_ul(argv, 1); unsigned long denominator;
    if (!str_represents_ul(argv[2], &denominator)) str_does_not_represent_suitable_ul(argv, 2); unsigned long numerator;
    if (!str_represents_ul(argv[3], &numerator)) str_does_not_represent_suitable_ul(argv, 3);
    fprintf(stdout, "%lu / %lu \u2261 %lu (mod %lu)\n", denominator, numerator, mod_divide(denominator, numerator), mod);
    return 0;
}
