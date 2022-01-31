// TO DO's:
// Write an alternation from this design which also accepts '0' as mod value.
// In said case the program takes a third argument specifying the upper-bound of the range of x to calculate (since we still always start at 0).
// If such argument is missing fprintf() and fscanf() can take care of that.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'SINGULAR_polynomial_over_GF()'

int main(int argc, char **argv) { ul mod; mod_ = &mod;
    if (2 > argc || !str_represents_ul(argv[1], &mod)) { fprintf(stderr, "%s is not mod!\n", argv[1]); exit(-1); } unsigned long x;
    // ^^ Process mandatory variables

    unsigned long number_of_coefficients;
    if (!(number_of_coefficients = argc - 2)) { fprintf(stderr, "Please fill out the remainder of the arguments with coefficients.\n\nTerminating with exit status '-4'.\n"); return -4; }

    unsigned long **coefficient = (unsigned long **) malloc(sizeof(unsigned long *) * (number_of_coefficients + 1));
    for (unsigned long i = 0; i < number_of_coefficients; i++) coefficient[i] = (unsigned long *) malloc(sizeof(unsigned long)); coefficient[number_of_coefficients] = NULL;
    for (unsigned long i = 0; i < number_of_coefficients; i++) if (!str_represents_ul(argv[i + 2], coefficient[i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 2]); return -2; }

    fprintf(stdout, "(x, y) : 'y \u2261 ");
    unsigned long i = 0; while (1) {
	fprintf(stdout, "%lu", *coefficient[i]);
	if (!coefficient[i + 1]) break; fprintf(stdout, " * x^%lu + ", i); i++;
    } fprintf(stdout, "	(mod %lu)'\n", mod); // \u21E8 \u2794 \u279C \u279F \u27A0
    
    for (unsigned long x = 0; x < mod; x++) fprintf(stdout, "(%lu, %lu)\n", x, mod_polynomial(coefficient, x));
    free(coefficient); return 0; }
