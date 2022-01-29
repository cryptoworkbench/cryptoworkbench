// Takes the additive inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                             <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for 'inverse()'

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *ID_parsing_error = "Please provide as second argument the number to take the additive inverse of.";
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
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_location_OF_MOD())) arg_not_parsable(argv, 1); ul inv_of_additive_inv;
    if (3 > argc || !str_represents_ul(argv[2], &inv_of_additive_inv)) arg_not_parsable(argv, 2); fprintf(stdout, "x - %lu \u2261 x + %lu (mod %lu)\n", inv_of_additive_inv, inverse(inv_of_additive_inv), _REPORT_mod());
    return 0;
}
