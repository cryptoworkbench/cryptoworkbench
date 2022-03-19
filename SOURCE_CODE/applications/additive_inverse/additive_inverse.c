// Takes the additive mod_inverse of a number using the mathematics library 'maths.extended.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                                 <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.extended.h"

unsigned long mod, inverse_of_additive_inverse;

void ______________mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus."); }
void inverse_of_result_failed_to_parse() { fprintf(stderr, "Please provide as second argument the number to take the additive inverse of."); }

int main(int argc, char **argv) { mod = inverse_of_additive_inverse = ADDITIVE_IDENTITY; mod_ = &mod;
    conditional_goodbye(n(n(error_specification(______________mod_failed_to_parse, n(mod_ul_parse_str(argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(inverse_of_result_failed_to_parse, n(_ul_parse_str(&inverse_of_additive_inverse, argv[2], -2))))));
    // take in terminal arguments ^

    fprintf(stdout, "x - %lu \u2261 ", inverse_of_additive_inverse);
    if (inverse_of_additive_inverse != mod_conditional_cap(inverse_of_additive_inverse)) fprintf(stdout, "x - %lu \u2261 ", inverse_of_additive_inverse = mod_conditional_cap(inverse_of_additive_inverse));
    unsigned long additive_inverse; fprintf(stdout, "x + %lu	(mod %lu)\n\n", additive_inverse = mod_inverse(inverse_of_additive_inverse), *mod_);
    fprintf(stdout, "The additive inverse of %lu under modulus %lu arithmetic is %lu.\n", inverse_of_additive_inverse, mod, additive_inverse);
    // display result ^

    return 0;
}
