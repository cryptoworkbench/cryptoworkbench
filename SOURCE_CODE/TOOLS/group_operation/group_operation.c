#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

void b_not_parsable() { fprintf(stderr, "Please specify as fourth argument the second value to do the group operation with."); }
void a_not_parsable() { fprintf(stderr, "Please specify as third argument the first value to do the group operation with."); }
// void id_not_parsable() { fprintf(stderr, "Please specify as second argument '0' for the additive group identity or '1' for the multiplicative group identity."); }
void mod_not_parsable() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }

// conditional_goodbye(n(n(error_specification(mod_error, n(str_represents_ul_(argv[1], &mod, -1)))))); unsigned long numerator;
int main(int argc, char **argv) { unsigned long mod; mod_ = &mod;
    conditional_goodbye(n(n(error_specification(mod_not_parsable, n(str_represents_ul_(argv[1], mod_, -1)))))); unsigned long id;
    // conditional_goodbye(n(n(error_specification(n(error_message(n(identity_SELECTOR_error), identity_set(&id, identity_SELECTOR(argv[2]), -2))))))); unsigned long a;
    conditional_goodbye(n(n(error_message(identity_SELECTOR_error, identity_set(&id, identity_SELECTOR(argv[2]), -2))))); unsigned long a;
    // if (!match_variadic(argv[4], 2, "0", "1")) exit(-4); str_represents_ul(argv[4], &ID);
    conditional_goodbye(n(n(error_specification(a_not_parsable, n(str_represents_ul_(argv[3], &a, -3)))))); unsigned long b;
    conditional_goodbye(n(n(error_specification(b_not_parsable, n(str_represents_ul_(argv[4], &b, -4))))));

    _group_operation operation = _operation_from_ID(id);
    if (mod) fprintf(stdout, "%lu %s %lu \u2261 %lu	(mod %lu)\n", a, _as_operation_symbol(id), b, operation(a, b, mod), mod);
    else fprintf(stdout, "%lu %s %lu = %lu	(within the infinite field of natural numbers)\n", a, _as_operation_symbol(id), b, operation(a, b, mod));
    return 0; }
