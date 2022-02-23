// TO DO's:
// Write an alternation from this design which also accepts '0' as mod value.
// In said case the program takes a third argument specifying the upper-bound of the range of x to calculate (since we still always start at 0).
// If such argument is missing fprintf() and fscanf() can take care of that.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

unsigned long i; char *unparsed_arg;
// global variable definitions ^

void coefficient_failed_to_parse() { fprintf(stderr, "Coefficient failed to parse!"); }
void wrong_argument_count() { fprintf(stderr, "The no coefficients were supplied!"); }
void mod_error() { fprintf(stderr, "'%s' is not mod!", unparsed_arg); }
// error functions ^

int main(int argc, char **argv) { unparsed_arg = argv[1];
    unsigned long mod;                    conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(argv[1], &mod, -1)))))); mod_ = &mod;
    // take in mod ^

    unsigned long number_of_coefficients; conditional_goodbye(n(n(error_message(wrong_argument_count, -4 * (!(number_of_coefficients = argc - 2))))));
    // set 'number_of_coefficients' and simultaneously check if the required amount was met ^

    unsigned long *coefficient = (unsigned long *) malloc(sizeof(unsigned long) * number_of_coefficients);
    for (i = 0; i < number_of_coefficients; i++) conditional_goodbye(n(n(error_specification(coefficient_failed_to_parse, n(str_represents_ul_(argv[i + 2], coefficient + i, -3))))));
    
    fprintf(stdout, "Plotting polynomial with coefficients:\n");
    i = 0; char symbol = 'a';
    while (1) {
	fprintf(stdout, "%c = %lu", symbol, coefficient[i]);
	if (i + 1 == number_of_coefficients) break; i++;
	symbol++; fprintf(stdout, ", ");
    } if (mod) fprintf(stdout, "	(mod %lu)", mod); fprintf(stdout, "\n\n");

    unsigned long range_bound = mod;
    fprintf(stdout, "Number of coordinates that follow: ");
    if (!(*mod_)) fscanf(stdin, "%lu", &range_bound);
    else fprintf(stdout, "%lu\n", range_bound);

    for (unsigned long x = 0; x < range_bound; x++) fprintf(stdout, "(%lu, %lu)\n", x, mod_Polynomial(coefficient, x, number_of_coefficients));
    free(coefficient); return 0; }

