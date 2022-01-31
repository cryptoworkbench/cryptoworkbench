// Takes the additive mod_inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                             <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for 'mod_', 'mod_inverse()'

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *ID_parsing_error = "Please provide as second argument the number to take the additive inverse of.";

const char *local_switch(int index) { return (index - 1) ? ID_parsing_error : MOD_parsing_error; }

unsigned long mod; int main(int argc, char **argv) { mod_ = &mod; local_error_selector = local_switch;
    if (2 > argc || !str_represents_ul(argv[1], mod_)) arg_not_parsable(argv, 1); unsigned long inverse_of_additve_inverse;
    if (3 > argc || !str_represents_ul(argv[2], &inverse_of_additve_inverse)) arg_not_parsable(argv, 2);
    unsigned long additive_inverse = mod_inverse(inverse_of_additve_inverse);
    fprintf(stdout, "x - %lu \u2261 x + %lu (mod %lu)\n\n", inverse_of_additve_inverse, additive_inverse, mod);
    fprintf(stdout, "The additive inverse of %lu under modulus %lu arithmetic is %lu.\n", inverse_of_additve_inverse, mod, additive_inverse);
    return 0;
}
