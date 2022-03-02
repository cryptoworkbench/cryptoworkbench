// Takes the additive mod_inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                                 <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void generic_parsing_error() { fprintf(stderr, "%s is not something I am able to understand as a number."); }
void mod_parsing_error() { fprintf(stderr, "Please provide as first argument the modulus."); }
void id_parsing_error() { fprintf(stderr, "Please provide as second argument the number to take the additive inverse of."); }

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod;
    conditional_goodbye(n(n(error_specification(mod_parsing_error, n(ul_parse_str(argv[1], mod_, -1)))))); unsigned long inverse_of_additve_inverse;
    conditional_goodbye(n(n(error_specification(id_parsing_error, n(ul_parse_str(argv[2], &inverse_of_additve_inverse, -2)))))); unsigned long additive_inverse = mod_inverse(inverse_of_additve_inverse);
    fprintf(stdout, "x - %lu \u2261 x + %lu (mod %lu)\n\n", inverse_of_additve_inverse, additive_inverse, mod);
    fprintf(stdout, "The additive inverse of %lu under modulus %lu arithmetic is %lu.\n", inverse_of_additve_inverse, mod, additive_inverse);
    return 0;
}
