// TO DO's:
// Write an alternation from this design which also accepts '0' as mod value.
// In said case the program takes a third argument specifying the upper-bound of the range of x to calculate (since we still always start at 0).
// If such argument is missing fprintf() and fscanf() can take care of that.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

int number_of_coefficients; unsigned long i; unsigned long *coefficient;
// global variable definitions ^

void coefficient_failed_to_parse() { fprintf(stderr, "Coefficient failed to parse!"); }
void _______wrong_argument_count() { fprintf(stderr, "The no coefficients were supplied!"); }
void __________________mod_error() { fprintf(stderr, "Please provide as first argument a modulus with which to divide the infinite field of natural numbers \u2115!"); }
// error functions ^

void coefficients_allocate() { coefficient = (unsigned long *) malloc(sizeof(unsigned long) * number_of_coefficients); }
void coefficients__display() { fprintf(stdout, "%c = %lu", 'a' + i, coefficient[i]); if (i + 1 == number_of_coefficients) return; i++; fprintf(stdout, ", "); coefficients__display(); }
// functions for coefficient handling ^

int main(int argc, char **argv) { unsigned long mod;
        conditional_goodbye(n(n(error_specification(__________________mod_error, n(ul_parse_str(argv[1], &mod, -1)))))); mod_ = &mod;
        conditional_goodbye(n(n(error_message      (_______wrong_argument_count, -4 * (!(number_of_coefficients = argc - 2)))))); coefficients_allocate(); for (i = 0; i < number_of_coefficients; i++)
	conditional_goodbye(n(n(error_specification(coefficient_failed_to_parse, n(ul_parse_str(argv[i + 2], coefficient + i, -3)))))); i = 0;
    fprintf(stdout, "Plotting polynomial with coefficients:\n"); coefficients__display(); fprintf(stdout, "\n\n");
    // handle terminal inputs ^

    unsigned long range_bound = mod; fprintf(stdout, "Number of coordinates that follow: "); if (!(*mod_)) fscanf(stdin, "%lu", &range_bound); else fprintf(stdout, "%lu\n", range_bound);
    // if the infinite field of Natural numbers (N) was not divided into quotient groups (by a modulus), ask how many coordinates should follow ^

    for (unsigned long x = 0; x < range_bound; x++) fprintf(stdout, "(%lu, %lu)\n", x, mod_polynomial(x, coefficient, number_of_coefficients)); free(coefficient);
    return 0;
}
