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
    
    fprintf(stdout, "Plotting polynomial with coefficients:\n");
    i = 0; char symbol = 'a'; while (1) { fprintf(stdout, "%c = %lu", symbol, *coefficient[i]); if (!coefficient[i + 1]) break; i++; symbol++; fprintf(stdout, ", "); }
    if (mod) fprintf(stdout, "	(mod %lu)", mod); fprintf(stdout, "\n\n");

    unsigned long range_bound = mod;
    fprintf(stdout, "Number of coordinates to plot: ");
    if (!(*mod_)) fscanf(stdin, "%lu", &range_bound);
    else fprintf(stdout, "%lu\n", range_bound);

    for (unsigned long x = 0; x < range_bound; x++) fprintf(stdout, "(%lu, %lu)\n", x, _polynomial(coefficient, x, *mod_));
    free(coefficient); return 0; }

