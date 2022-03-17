#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

unsigned long upper_bound, quantity;

void _____mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the maximum size to the random numbers.", (*argv_ptr)[1]); }
void quantity_failed_to_parse() { fprintf(stderr, "Failed to interpet '%s' as amount of random numbers to generate.", (*argv_ptr)[2]); }
// error functions ^

int main(int argc, char **argv) { upper_bound = quantity = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(_____mod_failed_to_parse, n(ul_parse_str(&upper_bound, argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(quantity_failed_to_parse, n(ul_parse_str(&   quantity, argv[2], -2))))));
    // interpret terminal arguments ^

    unsigned long i = 1; do { fprintf(stdout, "Random number %lu: %lu\n", i, urandom_number(upper_bound)); i++; } while (i != quantity + 1); close_urandom(); return 0; }
    // get specified amount of random numbers from '/dev/urandom' and return peacefully
