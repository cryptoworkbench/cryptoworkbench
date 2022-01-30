// Takes the additive mod_inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                             <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for '_mod', 'mod_inverse()'

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *ID_parsing_error = "Please provide as second argument the number to take the additive mod_inverse of.";
const char *GENERIC_parsing_error_EXIT_STATUS = "Terminating with exit status '-%i'.\n";

void arg_not_parsable(char **argv, int index) { const char *error_specific_message;
    if (index == 1) error_specific_message = MOD_parsing_error;
    else if (index == 2) error_specific_message = ID_parsing_error;
    // ^ Determine what variable to complain about

    fprintf(stderr, GENERIC_parsing_error, argv[index]);
    fprintf(stderr, "%s\n\n", error_specific_message);
    fprintf(stderr, GENERIC_parsing_error_EXIT_STATUS, index);
    // ^ Complain about parsing impossibility

    exit(-index); // < & finally terminate with stderr promised exit status
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &_mod)) arg_not_parsable(argv, 1); unsigned long inverse_of_additve_inverse;
    if (3 > argc || !str_represents_ul(argv[2], &inverse_of_additve_inverse)) arg_not_parsable(argv, 2);
    unsigned long additive_inverse = mod_inverse(inverse_of_additve_inverse);
    fprintf(stdout, "x - %lu \u2261 x + %lu (mod %lu)\n\n", inverse_of_additve_inverse, additive_inverse, _mod);
    fprintf(stdout, "The additive inverse of %lu under modulus %lu arithmetic is %lu.\n", inverse_of_additve_inverse, _mod, additive_inverse);
    return 0;
}
