// Takes the additive inverse of a number using the mathematics library 'maths.c' ||
// "##### ===> END OF PROGRAM DESCRIPTION!                             <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'STR_could_be_parsed_into_UL()'
#include "../../libraries/mathematics/maths.h" // needed for 'additive_inverse()'
UL MOD; // < handle library inclusions ^^

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Please provide as first argument the modulus.";
const char *ID_parsing_error = "Please provide as second argument the number to take the additive inverse of.";
const char *GENERIC_parsing_error_EXIT_STATUS = "Terminating with exit status '-%i'.\n";

void argv_ERROR(char **argv, int index) { const char *error_specific_message;
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
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MOD)) argv_ERROR(argv, 1); UL inv_of_additive_inv;
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &inv_of_additive_inv)) argv_ERROR(argv, 2);
    fprintf(stdout, "The additive inverse of %lu is %lu mod %lu.\n", inv_of_additive_inv, additive_inverse(inv_of_additive_inv), MOD);
    return 0;
}
