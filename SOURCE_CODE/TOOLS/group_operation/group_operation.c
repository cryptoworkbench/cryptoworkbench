#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

const char *MOD_not_parsable = "please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers).";
const char *a_not_parsable = "please specify as second argument the first value to do the group operation with.";
const char *b_not_parsable = "please specify as third argument the second value to do the group operation with.";
const char *ID_not_parsable = "please specify as fourth argument '0' for the additive group identity or '1' for the multiplicative group identity.";

const char *local_switch(int index) { if (index == 1) return MOD_not_parsable; else if (index == 2) return a_not_parsable; else if (index == 3) return b_not_parsable; else if (index == 4) return ID_not_parsable; }

unsigned long mod; int main(int argc, char **argv) { mod_ = &mod; local_error_selector = local_switch;
    if (!str_represents_ul(argv[1], mod_)) arg_not_parsable(argv, 1); unsigned long a;
    if (!str_represents_ul(argv[2], &a)) arg_not_parsable(argv, 2); unsigned long b;
    if (!str_represents_ul(argv[3], &b)) arg_not_parsable(argv, 3); unsigned long ID;
    if (!match_variadic(argv[4], 2, "0", "1")) arg_not_parsable(argv, 4); str_represents_ul(argv[4], &ID);
    _group_operation operation = _operation_from_ID(ID);
    if (mod) fprintf(stdout, "%lu %s %lu \u2261 %lu	(mod %lu)\n", a, ID_denoted_by_operation_symbol(ID), b, operation(a, b, mod), mod);
    else fprintf(stdout, "%lu %s %lu = %lu	(within the infinite field of natural numbers)\n", a, ID_denoted_by_operation_symbol(ID), b, operation(a, b, mod));
    return 0; }
