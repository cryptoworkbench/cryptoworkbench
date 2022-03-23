#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.extended.h"

struct group group;
//           ^  variable declarations

void _id_instruction() { fprintf(stderr, "Please provide as second argument the group's operation (identity element)."); list_plausable_group_identity_descriptions(2); }
void mod_instruction() { fprintf(stderr, "Please provide as first argument the additive group's or the multiplicative group's modulus."); }
//   ^ error functions 

int main(int argc, char **argv) { argv_ptr = &argv;
    _group = group_parse(&group, mod_instruction, _id_instruction, 1);

    unsigned long count = 0;
    for (unsigned long element = (group.oper == _multiply); element < group._mod; element++)
	if (group.oper != _add && GCD(group._mod, element) == MULTIPLICATIVE_IDENTITY || group.oper == _add) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\n\u2115%s%s contains %lu elements.\n", argv[1], group.sign[1], count); // absolutely needed here because otherwise 'group_library.c' won't stop trying to read from this program's STDOUT
    return 0; }
