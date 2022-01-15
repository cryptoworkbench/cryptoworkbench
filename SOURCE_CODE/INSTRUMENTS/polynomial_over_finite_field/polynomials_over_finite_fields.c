// Developer's notes
// Use "\U0001D53D" for a capital double stroke F
// Use "\U0001D557" for a lower case double stroke f
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'polynomial_over_finite_field()'
ul MOD = 0;

int main(int argc, char **argv) { // 'ul MOD' is at line 4
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { fprintf(stderr, "%s is not MOD!\n", argv[1]); exit(-1); } ul x;
    if (3 > argc || !str_represents_ul(argv[2], &x)) { fprintf(stderr, "%s is not x!\n", argv[2]); exit(-2); }
    // ^^ Process mandatory variables

    ul number_of_coefficients = argc - 3;
    if (number_of_coefficients) {
	// fprintf(stdout, "Computing a %lund degree polynomial over \U0001D53D%lu.\n\n", number_of_coefficients - 1, MOD); // u1D53D doesn't work u1D557 neither u0046 doesnt
	// ^ Announce scale of operation

	unsigned long **coefficients = (unsigned long **) malloc(sizeof(unsigned long *) * (number_of_coefficients + 1));
	for (ul i = 0; i < number_of_coefficients; i++) coefficients[i] = (unsigned long *) malloc(sizeof(unsigned long)); coefficients[number_of_coefficients] = 0;
	// ^ Prepare array of appriopiate size

	fprintf(stdout, "Coefficients given by arguments:\n"); char symbol = 'a';
	for (ul i = 0; i + 3 < argc; i++) {
	    if (!str_represents_ul(argv[i + 3], coefficients[number_of_coefficients - 1 - i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 3]); exit(-3); }
	    fprintf(stdout, "%c: %lu\n", symbol, *coefficients[number_of_coefficients - 1 - i]); symbol++;
	} printf("\n");

	for (ul x = 0; x < MOD; x++) fprintf(stdout, "f(%lu) = %lu\n", x, polynomial_over_finite_field(coefficients, x));
	return 0;
    } else { fprintf(stderr, "Please fill out the remainder of the arguments with coefficients.\n\nTerminating with exit status '-4'.\n"); return -4; }
}
