// Program descriptions:
// Displays the multiplicative inverse.
//
// Developer instructions:
// Make the ouput of this program such that (mod %%) never changes.
#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.extended.h"
#define NUMERATOR 1
// definit^on and l^brary ^nclus^ons

unsigned long common_divisor, denominator, mod;

void ______group_element_failed_to_parse() { fprintf(stderr, "Please provide as second argument an element within \u2115/\u2115%s*.", (*argv_ptr)[1]); }
void group_specification_failed_to_parse() { fprintf(stderr, "Please provide as first argument a modulus so I know what multiplicative group to take the inverse within."); }
void not_a_member_of_an_equivalence_class_from_the_quotient_group()
{
    fprintf(stderr, "%lu | %lu  &&  %lu | %lu\n", common_divisor, denominator, common_divisor, *_mod);
    fprintf(stderr, "## --> %i < GCD(%lu, %lu)  &&  GCD(%lu, %lu) > %i\n", NUMERATOR, denominator, *_mod, denominator, *_mod, NUMERATOR);
    fprintf(stderr, "## --> %lu is not coprime to %lu\n", denominator, *_mod);
    fprintf(stderr, "## --> %lu is neither an element from \u2115%lu*, nor from \u2115/%lu\u2115*; or representing an element from \u2115/%lu\u2115* !\n", denominator, *_mod, *_mod, *_mod);
    fprintf(stderr, "## --> %lu does not have a multiplicative inverse within \U0001D53D%lu!\n", denominator, *_mod);
    fprintf(stderr, "#");
    // fprintf(stderr, " %lu | %lu  &&  %lu | %lu\n-->  1 < GCD(%lu, %lu)\n-->  %lu is not coprime with %lu\n-->  %lu is neither from \u2115%lu*; nor from \u2115/%lu\u2115*\n-->  within the finite field F%lu %lu does not have a multiplicative inverse!", common_divisor, *_mod, common_divisor, *_mod, denominator, *_mod, denominator, *_mod, denominator, *_mod, *_mod, *_mod, denominator);
}
// error functions for incorrect usage ^^

int main(int argc, char **argv) { mod = denominator = ADDITIVE_IDENTITY; _mod = &mod; argv_ptr = &argv; 
    conditional_goodbye(n(n(error_specification(group_specification_failed_to_parse, n(mod_ul_parse_str(              argv[1], -1)))))); int numerator = 1;                                
    conditional_goodbye(n(n(error_specification(______group_element_failed_to_parse, n(   _ul_parse_str(&denominator, argv[2], -2))))));
    conditional_goodbye(error_message(not_a_member_of_an_equivalence_class_from_the_quotient_group, -3 * !(!((common_divisor = GCD(denominator, mod)) - 1))));
    // fix multiplicative group, inverse of inverse and numerator to the division function (namely 'mod_divide')

    fprintf(stdout, "%lu^-%i \u2261 %i / %lu \u2261 ", denominator, NUMERATOR, NUMERATOR, denominator); _mod = &mod;
    if (denominator != mod_conditional_cap(denominator)) fprintf(stdout, "%i / %lu \u2261 ", NUMERATOR, denominator = mod_conditional_cap(denominator));
    fprintf(stdout, "%lu	(mod %lu)\n", mod_divide(NUMERATOR, denominator), *_mod); return 0;
    // (verbosely) print the result ^^^
}
