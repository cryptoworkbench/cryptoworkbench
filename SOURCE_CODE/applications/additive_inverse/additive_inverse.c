// Takes the additive mod_inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                                 <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus."); }
void _id_failed_to_parse() { fprintf(stderr, "Please provide as second argument the number to take the additive inverse of."); }

int main(int argc, char **argv) {
    unsigned long mod = 0;                        conditional_goodbye(n(n(error_specification(mod_failed_to_parse, n(ul_parse_str(                       &mod, argv[1], -1))))));
    unsigned long inverse_of_additive_inverse = 0; conditional_goodbye(n(n(error_specification(_id_failed_to_parse, n(ul_parse_str(&inverse_of_additive_inverse, argv[2], -2)))))); mod_ = &mod;

    fprintf(stdout, "x - %lu \u2261 ", inverse_of_additive_inverse);
    if (inverse_of_additive_inverse != mod_conditional_cap(inverse_of_additive_inverse)) fprintf(stdout, "x - %lu \u2261 ", inverse_of_additive_inverse = mod_conditional_cap(inverse_of_additive_inverse));
    unsigned long additive_inverse; fprintf(stdout, "x + %lu	(mod %lu)\n\n", additive_inverse = mod_inverse(inverse_of_additive_inverse), *mod_);
    fprintf(stdout, "The additive inverse of %lu under modulus %lu arithmetic is %lu.\n", inverse_of_additive_inverse, mod, additive_inverse);
    return 0;
}
