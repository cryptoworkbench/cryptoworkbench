/*
 * TO DO's:
 * - Make it such that when 0 is entered again infinite points will be printed!
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.extended.h"

int number_of_coefficients, i; unsigned long *coefficient; unsigned long mod;
// global variable definitions ^

void coefficient_failed_to_parse() { fprintf(stderr, "Coefficient failed to parse!"); }
void _______wrong_argument_count() { fprintf(stderr, "The no coefficients were supplied!"); }
void ________mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument a modulus with which to divide the infinite field of natural numbers \u2115!"); }
// error functions ^

void coefficients_allocate() { coefficient = (unsigned long *) malloc(sizeof(unsigned long) * number_of_coefficients); }
void coefficients__display() { fprintf(stdout, "%c = %lu", 'a' + i, coefficient[i]); if (i + 1 == number_of_coefficients) return; i++; fprintf(stdout, ", "); coefficients__display(); }
// functions for coefficient handling ^

int main(int argc, char **argv) { mod = ADDITIVE_IDENTITY; mod_ = &mod;
    conditional_goodbye(n(n(error_specification(________mod_failed_to_parse, n(mod_ul_parse_str(argv[1], -1))))));
    conditional_goodbye(n(n(error_message      (_______wrong_argument_count, -4 * !(number_of_coefficients = argc - 2))))); coefficients_allocate(); for (i = 0; i < number_of_coefficients; i++)
    conditional_goodbye(n(n(error_specification(coefficient_failed_to_parse, n(_ul_parse_str(coefficient + i, argv[i + 2], -3)))))); i = 0;
    fprintf(stdout, "Plotting polynomial with coefficients:\n"); coefficients__display(); fprintf(stdout, "\n\n");
    // handle terminal inputs ^

    unsigned long range_bound = mod; fprintf(stdout, "Number of coordinates that follow: "); if (!mod) fscanf(stdin, "%lu", &range_bound); else fprintf(stdout, "%lu\n", range_bound);
    // if the infinite field of Natural numbers (N) was not divided into quotient groups (by a modulus), ask how many coordinates should follow ^

    for (unsigned long x = 0; x < range_bound; x++) fprintf(stdout, "(%lu, %lu)\n", x, mod_polynomial(x, coefficient, number_of_coefficients)); free(coefficient);
    return 0;
}
