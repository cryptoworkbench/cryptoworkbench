#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

void b_not_parsable() { fprintf(stderr, "Please specify as fourth argument the second value to do the group operation with."); }
void a_not_parsable() { fprintf(stderr, "Please specify as third argument the first value to do the group operation with."); }
void mod_not_parsable() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }

int main(int argc, char **argv) {
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_not_parsable, n(str_represents_ul(argv[1], &mod, -1)))))); mod_ = &mod;
    unsigned long id;  conditional_goodbye(n(error_message(identity_SELECTOR_error, identity_set(&id, identity_SELECTOR(argv[2]), -2)))); id_ = &id;
    unsigned long a;   conditional_goodbye(n(n(error_specification(a_not_parsable, n(str_represents_ul(argv[3], &a, -3))))));
    unsigned long b;   conditional_goodbye(n(n(error_specification(b_not_parsable, n(str_represents_ul(argv[4], &b, -4))))));

    __finite_field_operation group_operation = id_finite_group_operation();
    if (mod) fprintf(stdout, "%lu %s %lu \u2261 %lu	(mod %lu)\n", a, id_as_operation_symbol(), b, group_operation(a, b), mod);
    else fprintf(stdout, "%lu %s %lu = %lu	(within the infinite field of natural numbers)\n", a, id_as_operation_symbol(), b, group_operation(a, b));
    return 0; }
