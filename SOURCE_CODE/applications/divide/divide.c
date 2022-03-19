#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.extended.h"

unsigned long mod, numerator, denominator;

void ___quotient_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus."); }
void __numerator_failed_to_parse() { fprintf(stderr, "Please provide as second argument the numerator."); }
void denominator_failed_to_parse() { fprintf(stderr, "Please provide as third argument the denominator."); }
// error functions ^^^

int main(int argc, char **argv) { mod = numerator = denominator = ADDITIVE_IDENTITY; mod_ = &mod;
    conditional_goodbye(n(n(error_specification(___quotient_failed_to_parse, n(mod_ul_parse_str(              argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(__numerator_failed_to_parse, n(   _ul_parse_str(&  numerator, argv[2], -2))))));
    conditional_goodbye(n(n(error_specification(denominator_failed_to_parse, n(   _ul_parse_str(&denominator, argv[3], -3))))));
    // take in necessary information from terminal arguments ^^^

    if (numerator >= mod || mod <= denominator) fprintf(stderr, "%lu / %lu \u2261 ", numerator, denominator); mod_ = &mod; numerator = mod_conditional_cap(numerator);
    denominator = mod_conditional_cap(denominator); fprintf(stdout, "%lu / %lu \u2261 %lu	(mod %lu)\n", numerator, denominator, mod_divide(numerator, denominator), mod);
    // calculate result and display it correctly ^^^ ^^
    return 0;
}
