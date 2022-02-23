#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

char *unparsed_arg;
// global variable declarations ^

void quantity_error() { fprintf(stderr, "Failed to interpet '%s' as amount of random numbers to generate.", unparsed_arg); }
void mod_error() { fprintf(stderr, "Please provide as first argument the maximum size to the random numbers.", unparsed_arg); }
_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: return mod_error; case 2: return quantity_error; }; }
// error functions ^

int main(int argc, char **argv) {
    unparsed_arg = argv[1]; unsigned long upper_bound; conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(unparsed_arg, &upper_bound, -1))))));
    unparsed_arg = argv[2]; unsigned long quantity;    conditional_goodbye(n(n(error_specification(quantity_error, n(str_represents_ul_(unparsed_arg, &quantity, -2))))));
    // if (!str_represents_ul(unparsed_arg, &quantity)) error_message(error_selector(2), -2);
    // interpret terminal arguments ^

    unsigned long i = 1; do { fprintf(stdout, "Random number %lu: %lu\n", i, urandom_number(upper_bound)); i++; } while (i != quantity + 1); close_urandom(); return 0; }
    // get specified amount of random numbers from '/dev/urandom' and return peacefully
