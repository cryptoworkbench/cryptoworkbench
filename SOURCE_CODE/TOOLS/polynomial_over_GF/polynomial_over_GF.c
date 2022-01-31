// TO DO's:
// Write an alternation from this design which also accepts '0' as mod value.
// In said case the program takes a third argument specifying the upper-bound of the range of x to calculate (since we still always start at 0).
// If such argument is missing fprintf() and fscanf() can take care of that.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h" // 'SINGULAR_polynomial_over_GF()'

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod;
    if (2 > argc || !str_represents_ul(argv[1], &mod)) { fprintf(stderr, "%s is not mod!\n", argv[1]); exit(-1); }
    // ^^ Process mandatory variables

    unsigned long number_of_coefficients;
    if (!(number_of_coefficients = argc - 2)) { fprintf(stderr, "Please fill out the remainder of the arguments with coefficients.\n\nTerminating with exit status '-4'.\n"); return -4; }

    unsigned long **coefficient = (unsigned long **) malloc(sizeof(unsigned long *) * (number_of_coefficients + 1)); unsigned long i;
    for (i = 0; i < number_of_coefficients; i++) coefficient[i] = (unsigned long *) malloc(sizeof(unsigned long)); coefficient[number_of_coefficients] = NULL;
    for (i = 0; i < number_of_coefficients; i++) if (!str_represents_ul(argv[i + 2], coefficient[i])) { fprintf(stderr, "%s is not interpretable.\n", argv[i + 2]); return -2; }
    
    fprintf(stdout, "(x, y) : 'y \u2261 ");
    i = 0; while (1) { fprintf(stdout, "%lu", *coefficient[i]); if (!coefficient[i + 1]) break; fprintf(stdout, " * x^%lu + ", i); i++; } fprintf(stdout, "	(mod %lu)'\n", mod);

    unsigned long range_bound = mod;
    if (!(*mod_)) {
	fprintf(stdout, "\nPlease tell me how many coordinates to plot (starting from x = 0): ");
	fscanf(stdin, "%lu", &range_bound);
    }

    for (unsigned long x = 0; x < range_bound; x++) fprintf(stdout, "(%lu, %lu)\n", x, _polynomial(coefficient, x, *mod_));
    free(coefficient); return 0; }

