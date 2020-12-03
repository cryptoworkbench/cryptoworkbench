#include <stdio.h>
#include <stdlib.h>
#include "../../../../libraries/functional/string.h"
#include "../../../../libraries/mathematics/maths_verbose.h"

int main(int argc, char *argv[]) {
    unsigned long a, b;
    /* Declare two variables, 'a', and 'b', and
     * 1). Assign to them the values present in the first two arguments if present
     * 2). If no arguments are present do nothing
     */

     switch (argc) { 
	case 3:
	    string_to_unsigned_long(argv[2], &b);
	case 2:
	    string_to_unsigned_long(argv[1], &a);
	    break;
	default:
	    fprintf(stderr, "Syntax error.\n\nProgram does not support more than two simultaneous inputs, run repeatedly to arrive at your answer.\n\n\nReturning -1.\n");
	    return -1;
    } /* Inform user on what kind of program this is */ printf("This program calculates the GCD of two numbers.\n\n");

    /* And take in the remaining required values which were not taken in previously */
    if (argc < 3) { printf("Please put in a number: "); scanf("%lu", &b); /* Take in one number */ }
    if (argc < 2) { printf("Please put in a number: "); scanf("%lu", &a); /* Take in another */ }

    return_gcd_calculation(a, b); // Run the program
    return 0;
}
