// Developer's notes
// Use "\U0001D53D" for a capital double stroke F
// Use "\U0001D557" for a lower case double stroke f
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'polynomial_over_finite_field()'
ul MOD = 0;

int main(int argc, char **argv) { // 'ul MOD' is at line 4
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "%s is not MOD!\n", argv[1]); exit(-1); } ul x;
    // ^^ Process mandatory variables

    ul number_of_coefficients = argc - 2;
    if (number_of_coefficients) {
	unsigned long **coefficients = (unsigned long **) malloc(sizeof(unsigned long *) * (number_of_coefficients + 1));
	for (ul i = 0; i < number_of_coefficients; i++) coefficients[i] = (unsigned long *) malloc(sizeof(unsigned long)); coefficients[number_of_coefficients] = 0;
	// ^ Prepare array of appriopiate size

	for (ul i = 0; i + 2 < argc; i++) {
	    if (!str_represents_ul(argv[i + 2], coefficients[number_of_coefficients - 1 - i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 2]); return -2; }
	}

	// fprintf(stdout, "Function map of 'f()' over GF(%lu) when f(x) \u2261 ", MOD);
	// fprintf(stdout, "Members of {(x, y) : y \u2261 ");
	fprintf(stdout, "{(x, y) : x, y \u2208 \U0001D53D%lu & y \u2261 ", MOD);
	ul i = 0; while (1) {
	    fprintf(stdout, "%lu", *coefficients[number_of_coefficients - 1 - i]);
	    if (!coefficients[i + 1]) break; fprintf(stdout, " * x^%lu + ", number_of_coefficients - 1 - i); i++;
	} fprintf(stdout, "	(mod %lu)} =\n", MOD); // \u21E8 \u2794 \u279C \u279F \u27A0
	
	/*
	ul i = 0;
	do {fprintf(stdout, "%lu * x^%lu", *coefficients[number_of_coefficients - 1 - i], number_of_coefficients - 1 - i);
	    if (coefficients[i]) 
	    i++;
	} while (1); fprintf(stdout, "%lu\n", *coefficients[number_of_coefficients - 1]);
	*/

	for (ul x = 0; x < MOD; x++) fprintf(stdout, "(%lu, %lu)\n", x, polynomial_over_finite_field(coefficients, x)); return 0;
    } else { fprintf(stderr, "Please fill out the remainder of the arguments with coefficients.\n\nTerminating with exit status '-4'.\n"); return -4; }
}
