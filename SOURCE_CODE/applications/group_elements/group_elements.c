#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.extended.h"

group_operation_ group_operation; unsigned long mod;
//               ^  variable declarations       ^

void _id_failed_to_parse() { fprintf(stderr, "Please provide as second argument the group's operation (identity element)."); list_plausable_group_identity_descriptions(2); }
void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the additive group's or the multiplicative group's modulus."); }
// error functions ^

int main(int argc, char **argv) { mod = ADDITIVE_IDENTITY; argv_ptr = &argv;
    group_parse(&mod, &group_operation, mod_failed_to_parse, _id_failed_to_parse, 1);

    unsigned long count = 0;
    for (unsigned long element = (group_operation == _multiply); element < mod; element++)
	if (group_operation == _add || GCD(mod, element) == MULTIPLICATIVE_IDENTITY) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\n\u2115%s%s contains %lu elements.\n", argv[1], sign_array(1), count); // absolutely needed here because otherwise 'group_library.c' won't stop trying to read from this program's STDOUT
    return 0; }
