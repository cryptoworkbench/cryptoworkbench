#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void mod_error() { fprintf(stderr, "Please provide as first argument the modulus."); }
void numerator_error() { fprintf(stderr, "Please provide as second argument the numerator."); }
void denominator_error() { fprintf(stderr, "Please provide as third argument the denominator."); }
// error functions ^^^

int main(int argc, char **argv) {
    unsigned long mod;         conditional_goodbye(n(n(error_specification(mod_error, n(ul_parse_str(argv[1], &mod, -1))))));
    unsigned long numerator;   conditional_goodbye(n(n(error_specification(numerator_error, n(ul_parse_str(argv[2], &numerator, -2))))));
    unsigned long denominator; conditional_goodbye(n(n(error_specification(denominator_error, n(ul_parse_str(argv[3], &denominator, -3))))));
    // take in necessary information from terminal arguments ^^^

    if (numerator >= mod || mod <= denominator) fprintf(stderr, "%lu / %lu \u2261 ", numerator, denominator); mod_ = &mod; numerator = mod_conditional_field_cap(numerator); // *
    denominator = mod_conditional_field_cap(denominator); fprintf(stdout, "%lu / %lu \u2261 %lu (mod %lu)\n", numerator, denominator, mod_divide(numerator, denominator), mod);
    // calculate result and display it correctly ^^^ ^^
    return 0;
}
// * at line 15: to write conditional clause with closed domain notation NAND approach: 	'   !(numerator < mod && mod > denominator)	'
