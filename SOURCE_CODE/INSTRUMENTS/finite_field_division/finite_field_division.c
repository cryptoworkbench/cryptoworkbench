// Performs modular division using the function "modular_division()", a function which is from the "maths.c" library over at: "/SOURCE_CODE/libraries/mathematics/"  ||
//                                                                                                                                                                   ||
// "###==> my own reflections about this program's operations -->                                                                                                    ||
// Looking at the output I wished for algebra explanatory purposes that I could say there the multiplicative inverse of the denominator but                         "||
// the finite field division is calculated using the isomorphism between the multiplicative group and it's additive structucal equivalent.  ...  ...  ...           "||
//                                                                                                                                                                  "||
// SO the multiplicative inverse of the denominator is not even calculated anywhere by the code employed for this application. Actually that is just how I like it. "||
// "###==> end of my own reflections about this program's operations.                                                                                               "||
//                                                                                                                                                                   ||
// "##### ===> END OF DEVELOPERS NOTES!                                                                                                                   <=== ####" ||

#include <stdio.h>
#include "../../libraries/functional/string.h" // needed for 'STR_could_be_parsed_into_UL()'
#include "../../libraries/mathematics/maths.h" // needed for 'additive_inverse()'
UL MOD; // < handle library inclusions ^^

const char *argv_ONE[] = {"first", "modulus"};
const char *argv_TWO[] = {"second", "numerator"};
const char *argv_THREE[] = {"third", "denominator"};

void argv_ERROR(char **argv, int index) { const char **error_specific_message;
    switch (index) {
	case 1: error_specific_message = argv_ONE; break;
	case 2: error_specific_message = argv_TWO; break;
	case 3: error_specific_message = argv_THREE;
    }; // ^ Determine what variable to complain about

    fprintf(stderr, "%s is not something I am able to understand as a number; please provide as %s argument the %s for this finite field division.\n\nTerminating with exit status '-%i'.\n", argv[index], error_specific_message[0], error_specific_message[1], index);
    // ^ Complain about this parsing impossibility

    exit(-index); // < & finally terminate with stderr promised exit status
}

int main(int argc, char **argv) { // 'UL MOD' is at line 7
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MOD)) argv_ERROR(argv, 1); UL numerator;
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &numerator)) argv_ERROR(argv, 2); UL denominator;
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &denominator)) argv_ERROR(argv, 3);
    fprintf(stdout, "%lu / %lu \u2261 %lu * %lu^(-%u) \u2261 %lu (mod %lu).\n", numerator, denominator, numerator, denominator, MULTIPLICATIVE_IDENTITY, modular_division(numerator, denominator), MOD);
    return 0;
}
