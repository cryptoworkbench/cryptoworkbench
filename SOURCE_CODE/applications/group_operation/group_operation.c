// DEVELOPERs note:
// I need to make this program cooperative again with some generic function which uses 'mod_' and 'id_'
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void __b_failed_to_parse() { fprintf(stderr, "Please specify as fourth argument the second value to do the group operation with."); }
void __a_failed_to_parse() { fprintf(stderr, "Please specify as third argument the first value to do the group operation with."); }
void _id_failed_to_parse() { fprintf(stderr, "Please specify as second argument the identity element of the group whose subgroups to examplify."); list_plausable_group_identity_descriptions(); }
void mod_failed_to_parse() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }

int main(int argc, char **argv) {
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_failed_to_parse, n(      ul_parse_str(&mod, argv[1], -1)))))); mod_ = &mod;
    int id;            conditional_goodbye(n(n(error_specification(_id_failed_to_parse, n(identity_parse_str( &id, argv[2], -2)))))); id_ = &id;
    unsigned long a;   conditional_goodbye(n(n(error_specification(__a_failed_to_parse, n(      ul_parse_str(  &a, argv[3], -3))))));
    unsigned long b;   conditional_goodbye(n(n(error_specification(__b_failed_to_parse, n(      ul_parse_str(  &b, argv[4], -4))))));
    // take in arguments ^^^^

    field_operation group_operation = ___field_operation(id);
    fprintf(stdout,    "%lu %s %lu ", a, id_as_operation_symbol(), b); if (mod) fprintf(stdout, "\u2261"); else fprintf(stdout, "="); fprintf(stdout, " %lu", group_operation(a, b));
    if (mod) fprintf(stdout, "	(mod %lu)", mod); fprintf(stdout, "\n");
    return 0;
}
