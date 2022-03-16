/* PROGRAM DESCRIPTION:
 * Takes the modulus of a number. Can be used to find out which equivalence class best represents a member from a quotient group.
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

void mod_error() {
    fprintf(stderr, "\'\u2124%s\', \'\u2124/\u2124%s\', \'\u2115%s\', and \'\u2115/\u2115%s\' do not represent any (finite (quotient)) group, neither does \'\U0001D53D%s\' represent any field!\n\n", (*argv_location)[1], (*argv_location)[1], (*argv_location)[1], (*argv_location)[1], (*argv_location)[1]); fprintf(stderr, "Please specify as first argument the modulus to work with!		(0 to not divide \u2115)");
}

void a_error() { fprintf(stderr, "'%s' is not a suitable value to take a modulus of!", (*argv_location)[2]); }
// error functions ^

int main(int argc, char **argv) { argv_location = &argv;
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_error, n(ul_parse_str(argv[1], &mod, -1))))));  mod_ = &mod;
    unsigned long a;   conditional_goodbye(n(n(error_specification(a_error, n(ul_parse_str(argv[2], &a, -2))))));
    // take in variables ^

    unsigned long result; fprintf(stdout, "%lu mod %lu = %lu -> %lu \u2261 %lu (mod %lu)\n", a, mod, result = mod_conditional_cap(a), a, result, mod);
    // explain the modulus operation ^

    return 0;
}
