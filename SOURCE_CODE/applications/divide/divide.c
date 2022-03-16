#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void ___quotient_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus."); }
void __numerator_failed_to_parse() { fprintf(stderr, "Please provide as second argument the numerator."); }
void denominator_failed_to_parse() { fprintf(stderr, "Please provide as third argument the denominator."); }
// error functions ^^^

int main(int argc, char **argv) {
    unsigned long ________mod; conditional_goodbye(n(n(error_specification(___quotient_failed_to_parse, n(ul_parse_str(&________mod, argv[1], -1))))));
    unsigned long __numerator; conditional_goodbye(n(n(error_specification(__numerator_failed_to_parse, n(ul_parse_str(&__numerator, argv[2], -2))))));
    unsigned long denominator; conditional_goodbye(n(n(error_specification(denominator_failed_to_parse, n(ul_parse_str(&denominator, argv[3], -3))))));
    // take in necessary information from terminal arguments ^^^

    if (__numerator >= ________mod || ________mod <= denominator) fprintf(stderr, "%lu / %lu \u2261 ", __numerator, denominator); mod_ = &________mod; __numerator = mod_conditional_field_cap(__numerator);
    denominator = mod_conditional_field_cap(denominator); fprintf(stdout, "%lu / %lu \u2261 %lu (mod %lu)\n", __numerator, denominator, mod_divide(__numerator, denominator), ________mod);
    // calculate result and display it correctly ^^^ ^^
    return 0;
}
