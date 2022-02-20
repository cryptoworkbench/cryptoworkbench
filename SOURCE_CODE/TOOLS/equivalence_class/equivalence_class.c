/* PROGRAM DESCRIPTION:
 * Takes the modulus of a number.
 *
 * Can be used to find out which equivalence class best represents a member from a quotient group. .. ..
 *
 * DEVELOPERs NOTEs:
 * Nothing to be improved here.
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

void mod_error() { fprintf(stderr, "'%s' is not a suitable value for the field modulus!", unparsed_arg); }
void a_error() { fprintf(stderr, "'%s' is not a suitable value to take a modulus of!", unparsed_arg); }
// error functions ^

int main(int argc, char **argv) { unparsed_arg = argv[1]; unsigned long mod; mod_ = &mod; 
    conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(unparsed_arg, mod_, -1)))))); unparsed_arg = argv[2]; unsigned long a;
    conditional_goodbye(n(n(error_specification(a_error, n(str_represents_ul_(unparsed_arg, &a, -2))))));
    // take in variables ^

    fprintf(stdout, "%lu \u2261 %lu (%% %lu) -> %lu %% %lu = %lu\n", a, a % mod, mod, a, mod, a % mod); return 0;
    // finish cleanly ^
}
