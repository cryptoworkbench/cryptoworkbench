#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^^^

void multiplicative_group_element_error() { fprintf(stderr, "Please provide as second argument an element within \u2115/\u2115%s*.", (*argv_location)[1]); }
void mod_error() { fprintf(stderr, "Please provide as first argument a modulus so I know what multiplicative group to take the inverse within."); }
// error functions ^^

int main(int argc, char **argv) { argv_location = &argv; 
    unsigned long multiplicative_group_modulus;      conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul(argv[1], &multiplicative_group_modulus, -1)))))); mod_ = &multiplicative_group_modulus;
    unsigned long element_from_multiplicative_group; conditional_goodbye(n(n(error_specification(multiplicative_group_element_error, n(str_represents_ul(argv[2], &element_from_multiplicative_group, -2))))));
    unsigned long GCD_of_arguments = GCD(element_from_multiplicative_group, multiplicative_group_modulus); if (GCD_of_arguments != 1)
    { fprintf(stderr, "%lu shares a factor of %lu with %lu.\n\n" EXIT_STATUS_GOODBYE, element_from_multiplicative_group, GCD_of_arguments, multiplicative_group_modulus, -3); exit(-3); }
    fprintf(stdout, "%lu^-1 \u2261 %lu	(mod %lu)\n", element_from_multiplicative_group, mod_divide(1, element_from_multiplicative_group), multiplicative_group_modulus); return 0;
}
