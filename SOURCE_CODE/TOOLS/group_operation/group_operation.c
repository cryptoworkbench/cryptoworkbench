// DEVELOPERs note:
// I need to make this program cooperative again with some generic function which uses 'mod_' and 'id_'
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void __b_not_parsable() { fprintf(stderr, "Please specify as fourth argument the second value to do the group operation with."); }
void __a_not_parsable() { fprintf(stderr, "Please specify as third argument the first value to do the group operation with."); }
void mod_not_parsable() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }

int main(int argc, char **argv) {
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_not_parsable, n(str_represents_ul(argv[1], &mod, -1))))));         mod_ = &mod;
    int id;            conditional_goodbye(n(error_message(identity_SELECTOR_error, identity_set(&id, identity_SELECTOR(argv[2]), -2)))); id_ = &id;
    unsigned long a;   conditional_goodbye(n(n(error_specification(__a_not_parsable, n(str_represents_ul(argv[3], &a, -3))))));
    unsigned long b;   conditional_goodbye(n(n(error_specification(__b_not_parsable, n(str_represents_ul(argv[4], &b, -4))))));
    // take in arguments ^^^^

    field_operation group_operation = ___field_operation(id);
    fprintf(stdout,    "%lu %s %lu ", a, id_as_operation_symbol(), b); if (mod) fprintf(stdout, "\u2261"); else fprintf(stdout, "="); fprintf(stdout, " %lu", group_operation(a, b));
    if (mod) fprintf(stdout, "	(mod %lu)", mod); fprintf(stdout, "\n");
    return 0;
}
