// Developer's notes
// Use "\U0001D53D" for a capital double stroke F
// Use "\U0001D557" for a lower case double stroke f
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'SINGULAR_polynomial_over_GF()'

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_LOCATION_OF_mod())) { fprintf(stderr, "%s is not mod!\n", argv[1]); exit(-1); } unsigned long x;
    // ^^ Process mandatory variables

    unsigned long number_of_coefficients;
    if (!(number_of_coefficients = argc - 2)) { fprintf(stderr, "Please fill out the remainder of the arguments with coefficients.\n\nTerminating with exit status '-4'.\n"); return -4; }

    unsigned long **coefficients = (unsigned long **) malloc(sizeof(unsigned long *) * (number_of_coefficients + 1));
    for (ul i = 0; i < number_of_coefficients; i++) coefficients[i] = (unsigned long *) malloc(sizeof(unsigned long)); coefficients[number_of_coefficients] = NULL;
    // ^ Prepare array of appriopiate size

    // for (ul i = 0; i + 2 < argc; i++) if (!str_represents_ul(argv[i + 2], coefficients[i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 2]); return -2; }
    for (ul i = 0; i < number_of_coefficients; i++) if (!str_represents_ul(argv[i + 2], coefficients[i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 2]); return -2; }

    fprintf(stdout, "(x, y) : 'y \u2261 ", _REPORT_mod());
    ul i = 0; while (1) {
	fprintf(stdout, "%lu", *coefficients[i]);
	if (!coefficients[i + 1]) break; fprintf(stdout, " * x^%lu + ", i); i++;
    } fprintf(stdout, "	(mod %lu)'\n", _REPORT_mod()); // \u21E8 \u2794 \u279C \u279F \u27A0
    
    for (ul x = 0; x < _REPORT_mod(); x++) fprintf(stdout, "(%lu, %lu)\n", x, polynomial_over_GF(coefficients, x)); return 0;
}
