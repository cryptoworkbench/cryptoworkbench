// DEVELOPERs note:
// I need to make this program cooperative again with some generic function which uses 'mod_' and 'id_'
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.extended.h"

int function_arg_count, i, id; unsigned long *arguments_array; unsigned long ans, mod;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", 3 + i); };
void ___array_failed_to_parse() { fprintf(stderr, "This function requires at least two inputs!"); };
void sp_array_failed_to_parse() {
    fprintf(stderr, "Please specify from the second argument onward numbers to %s within the finite field F%s.", id_as_verb(), (*argv_ptr)[1]);
}
void ______id_failed_to_parse() { fprintf(stderr, "Please specify as second argument the identity element of the group whose subgroups to examplify."); list_plausable_group_identity_descriptions(2); }
void _____mod_failed_to_parse() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }

int main(int argc, char **argv) { mod = id = ADDITIVE_IDENTITY; mod_ = &mod; id_ = &id; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(_____mod_failed_to_parse, n(                                                   mod_ul_parse_str(argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(______id_failed_to_parse, n(                                              id_identity_parse_str(argv[2], -2))))));
    conditional_goodbye(n(n(error_specification(sp_array_failed_to_parse, n(n(error_message(___array_failed_to_parse, (2 > (function_arg_count = argc -3))  * -3)))))));
    arguments_array = UL_array_of_SIZE(function_arg_count); for (i = 0; i < function_arg_count; i++)
    conditional_goodbye(n(n(error_specification(argument_failed_to_parse, n(_ul_parse_str(i + arguments_array, argv[3 + i], -(4 + i)))))));
    // take in arguments ^^^^

    mod_ = &mod; group_operation group_operation = id_group_operation();
    const char *symb = id_as_operation_symbol(); ans = id; i = 0;
    do {ans = group_operation(ans, arguments_array[i]);
	fprintf(stdout, "%lu", arguments_array[i]);
	if (i + 1 == function_arg_count) break; i++; fprintf(stdout, " %s ", symb);
    } while (1); fprintf(stdout, " \u2261 %lu", ans); if (mod) fprintf(stdout, "	(mod %s)", argv[1]); fprintf(stdout, "\n");

    return 0;
}
