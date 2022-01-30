#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // needed for 'mod_inverse()'

const char *GENERIC_parsing_error = "%s is not something I am able to understand as a number:\n";
const char *MOD_parsing_error = "Failed to understand the mod.";
const char *denominator_parsing_error = "Failed to understand the denominator.";
const char *numerator_parsing_error = "Failed to understand the nominator.";
const char *GENERIC_parsing_error_EXIT_STATUS = "Terminating with exit status '-%i'.\n";

void arg_not_parsable(char **argv, int index) { const char *error_specific_message;
    if (index == 1) error_specific_message = MOD_parsing_error;
    else if (index == 2) error_specific_message = denominator_parsing_error;
    else if (index == 3) error_specific_message = numerator_parsing_error;
    // ^ Determine what variable to complain about

    fprintf(stderr, GENERIC_parsing_error, argv[index]);
    fprintf(stderr, "%s\n\n", error_specific_message);
    fprintf(stderr, GENERIC_parsing_error_EXIT_STATUS, index);
    // ^ Complain about parsing impossibility

    exit(-index); // < & finally terminate with stderr promised exit status
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &mod_)) arg_not_parsable(argv, 1); unsigned long denominator;
    if (3 > argc || !str_represents_ul(argv[2], &denominator)) arg_not_parsable(argv, 2); unsigned long numerator;
    if (4 > argc || !str_represents_ul(argv[3], &numerator)) arg_not_parsable(argv, 3);
    fprintf(stdout, "%lu / %lu \u2261 %lu (mod %lu)\n", denominator, numerator, mod_division(denominator, numerator), mod_);
    return 0;
}
