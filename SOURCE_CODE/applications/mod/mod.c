/* PROGRAM DESCRIPTION:
 * Takes the modulus of a number. Can be used to find out which equivalence class best represents a member from a quotient group.
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.extended.h"
// library inclusions ^

unsigned long mod, a;
// global variable declarations ^ 

void mod_failed_to_parse() {
    fprintf(stderr, "\'\u2124%s\', \'\u2124/\u2124%s\', \'\u2115%s\', and \'\u2115/\u2115%s\' do not represent any (finite (quotient)) group, neither does \'\U0001D53D%s\' represent any field!\n\n", (*argv_ptr)[1], (*argv_ptr)[1], (*argv_ptr)[1], (*argv_ptr)[1], (*argv_ptr)[1]); fprintf(stderr, "Please specify as first argument the modulus to work with!		(0 to not divide \u2115)");
}

void __a_failed_to_parse() { fprintf(stderr, "'%s' is not a suitable value to take a modulus of!", (*argv_ptr)[2]); }
// error functions ^

int main(int argc, char **argv) { mod = a = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(mod_failed_to_parse, n(_ul_parse_str(&mod, argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(__a_failed_to_parse, n(_ul_parse_str(&  a, argv[2], -2))))));
    // take in variables ^

    mod_ = &mod; unsigned long result; fprintf(stdout, "%lu mod %lu = %lu -> %lu \u2261 %lu (mod %lu)\n", a, mod, result = mod_conditional_cap(a), a, result, mod);
    // explain the modulus operation ^

    return 0;
}
