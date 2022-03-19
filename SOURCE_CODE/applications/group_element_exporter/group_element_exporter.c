#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.extended.h"

int id; unsigned long mod;

void _id_failed_to_parse() { fprintf(stderr, "Please provide as second argument the group's operation (identity element)."); list_plausable_group_identity_descriptions(2); }
void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the additive group's or the multiplicative group's modulus."); }
// error functions ^

int main(int argc, char **argv) { mod = id = ADDITIVE_IDENTITY; mod_ = &mod; id_ = &id; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(mod_failed_to_parse, n(     mod_ul_parse_str(argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(_id_failed_to_parse, n(id_identity_parse_str(argv[2], -2))))));
    unsigned long count = 0; for (unsigned long element = id; element < mod; element++) if (id == ADDITIVE_IDENTITY || GCD(mod, element) == MULTIPLICATIVE_IDENTITY) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\nExported %lu elements.\n", count); // absolutely needed here because otherwise 'group_library.c' won't stop trying to read from this program's STDOUT
    return 0; }
