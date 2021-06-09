/* ABSTRACT:
 * This program is supposed to illustrate the mathematical mechanics of the Diffie-Hellman key agreement protocol.
 *
 *
 */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
// LIBRARY INCLUSIONS

const char *SYNTAX_ERROR = "INCOMPREHENSIBLE SYNTAX. Returning -1.\n";
const char *REQUIRED_SYNTAX = "MINIMUM REQUIRED SYNTAX:";
const char *FULL_SYNTAX = "MAXIMUM SUPPORTED SYNTAX:";
const char *NECESSARY_INPUT_CLAUSE = "<group modulus>";
const char *SUPPLEMANTARY_INPUT_CLAUSE = "<group generator>";
// ERROR MESSAGES

int main(int argc, char **argv) {
    unsigned long group_modulus, group_generator;
    // DEFINE PROGRAM VARIABLES

    switch (argc) {
	case 3: // >>> Assuming argv[2] is an ASCII string representing a number in base 10
	    group_generator = str_to_ul(argv[2]);
	case 2: // >>> Assuming argv[1] is an ASCII string representing a number in base 10
	    group_modulus = str_to_ul(argv[1]);
	    break;
	case 1:
	    fprintf(stderr, "%s\n\n", SYNTAX_ERROR); // << NOTIFY SOMETHING HAS GONE WRONG
	    fprintf(stderr, "%s\n", REQUIRED_SYNTAX); // < SHOWCASE LEAST REQUIRED INPUT 
	    fprintf(stderr, "	%s %s\n\n", *argv, NECESSARY_INPUT_CLAUSE);
	    fprintf(stderr, "%s\n", FULL_SYNTAX); // < SHOWCASE THE APPRECIATED FORM OF INPUT
	    fprintf(stderr, "	%s %s %s\n", *argv, NECESSARY_INPUT_CLAUSE, SUPPLEMANTARY_INPUT_CLAUSE);
	    return -1;
    } printf("Proposed multiplicative group \u2124_%lu*\n", group_modulus);

    if (argc > 2) {
	printf("Proposed generator %lu\n", group_generator);

	while (GCD(group_generator, group_modulus) != 1) { // << Check to see if the generator is coprime to the group modulus
	    fprintf(stderr, "\nProposed generator is not coprime with the group modulus, please pick an element of the set \u2124_%lu*\n", group_modulus);
	    fprintf(stdout, "Element of the set \u2124_%lu* to use as the generator for an example run of the Diffie-Hellman key agreement protocol: ", group_modulus);
	    fscanf(stdin, "%lu", &group_generator);
	} // << Assuming the group_generator is coprime to the group modulus
    }
    else {
	printf("While loop.\n"); }

    return 0;
}
