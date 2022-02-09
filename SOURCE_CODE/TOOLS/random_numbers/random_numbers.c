#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

char *unparsed_arg; unsigned long mod;
// global variable declarations ^

void quantity_error() { fprintf(stderr, "\nFailed to interpet '%s' as amount of random numbers to generate.\n\n", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to interpet '%s' as size.\n\n", unparsed_arg); }
_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: return mod_error; case 2: return quantity_error; }; }
// error functions ^

int main(int argc, char **argv) { unsigned long upper_bound; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &upper_bound)) error_message(error_selector(1), -1); unsigned long quantity; unparsed_arg = argv[2];
    if (!str_represents_ul(unparsed_arg, &quantity)) error_message(error_selector(2), -2);
    // interpret terminal arguments ^

    // for (unsigned long i = 1; i != quantity + 1; i++) fprintf(stdout, "Random number %lu: %lu\n", i, random_number(upper_bound));
    unsigned long i = 1; do {
	fprintf(stdout, "Random number %lu: %lu\n", i, random_number(upper_bound)); i++;
    } while (i != quantity);
    return 0; }
    // get specified amount of random numbers from '/dev/urandom' and return peacefully
