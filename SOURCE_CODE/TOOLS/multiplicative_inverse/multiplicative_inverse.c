// Program descriptions:
// Displays the multiplicative inverse.
//
// Developer instructions:
// Make the ouput of this program such that (mod %%) never changes.
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#define NUMERATOR 1
// definit^on and l^brary ^nclus^ons

unsigned long denominator, common_divisor;

void multiplicative_group_element_error() { fprintf(stderr, "Please provide as second argument an element within \u2115/\u2115%s*.", (*argv_location)[1]); }
void mod_error() { fprintf(stderr, "Please provide as first argument a modulus so I know what multiplicative group to take the inverse within."); }
void not_a_member_of_an_equivalence_class_from_the_quotient_group()
{
    fprintf(stderr, "%lu | %lu  &&  %lu | %lu\n", common_divisor, denominator, common_divisor, *mod_);
    fprintf(stderr, "--> %i < GCD(%lu, %lu) > %i\n", NUMERATOR, denominator, *mod_, NUMERATOR);
    fprintf(stderr, "--> %lu is not coprime to %lu\n", denominator, *mod_);
    fprintf(stderr, "--> %lu is neither an element from \u2115%lu*, nor from \u2115/%lu\u2115*; or representing an element from \u2115/%lu\u2115* !\n", denominator, *mod_, *mod_, *mod_);
    fprintf(stderr, "--> Within the finite field \U0001D53D%lu %lu does not have a multiplicative inverse!", *mod_, denominator);

    // fprintf(stderr, " %lu | %lu  &&  %lu | %lu\n-->  1 < GCD(%lu, %lu)\n-->  %lu is not coprime with %lu\n-->  %lu is neither from \u2115%lu*; nor from \u2115/%lu\u2115*\n-->  within the finite field F%lu %lu does not have a multiplicative inverse!", common_divisor, *mod_, common_divisor, *mod_, denominator, *mod_, denominator, *mod_, denominator, *mod_, *mod_, *mod_, denominator);
}
// error functions for incorrect usage ^^

int main(int argc, char **argv) { argv_location = &argv; 
    unsigned long multiplicative_group_modulus;   conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul(argv[1], &multiplicative_group_modulus, -1)))))); mod_ = &multiplicative_group_modulus;
    int numerator = 1;                            conditional_goodbye(n(n(error_specification(multiplicative_group_element_error, n(str_represents_ul(argv[2], &denominator, -2))))));
    conditional_goodbye(n(error_message(not_a_member_of_an_equivalence_class_from_the_quotient_group, -3 * !(!((common_divisor = GCD(denominator, multiplicative_group_modulus)) - 1)))));
    // process terminal arguments using this genious construction ^^^

    fprintf(stdout, "%lu^-%i \u2261 %i / %lu \u2261 ", denominator, NUMERATOR, NUMERATOR, denominator);
    if (denominator != mod_conditional_field_cap(denominator)) fprintf(stdout, "%i / %lu \u2261 ", NUMERATOR, denominator = mod_conditional_field_cap(denominator));
    fprintf(stdout, "%lu	(mod %lu)\n", mod_divide(NUMERATOR, denominator), *mod_); return 0;
    // (verbosely) print the result ^^^
}
