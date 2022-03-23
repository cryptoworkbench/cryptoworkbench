#include <stdio.h>
#include "../../libraries/functional/string.extended.h"
#include "../../libraries/mathematics/maths.extended.h"
#define STARTING_INDEX_OF_ARGS_LIST 3

struct group group; unsigned long ans; unsigned int function_arg_count, i;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", STARTING_INDEX_OF_ARGS_LIST + i); };
void ___array_failed_to_parse() { fprintf(stderr, "This function requires at least two inputs!"); };
void sp_array_failed_to_parse() {
    fprintf(stderr, "Please specify from the second argument onward numbers to %s within the finite field F%s.", group.sign[5], (*argv_ptr)[1]);
}
void operation_instruction() { fprintf(stderr, "Please specify as second argument the identity element of the group whose subgroups to examplify."); list_plausable_group_identity_descriptions(2); }
void       mod_instruction() { fprintf(stderr, "Please specify as first argument the modulus of the group operation (0 to act upon the infinite group of integers)."); }
// '_failed_to_parse' functions ^^

int main(int argc, char **argv) { i_ = &i; array_size_ = &function_arg_count; group._mod = ADDITIVE_IDENTITY; argv_ptr = &argv;
    group_parse(&group, mod_instruction, operation_instruction, 1);
    // process first two arguments ^^

    conditional_goodbye(n(n(error_specification(sp_array_failed_to_parse, n(n(error_message(___array_failed_to_parse, (2 > (function_arg_count = argc - STARTING_INDEX_OF_ARGS_LIST)) * - STARTING_INDEX_OF_ARGS_LIST)))))));
    // check amount of successive arguments ^

    LOOP_ul_parse_str(argument_failed_to_parse, STARTING_INDEX_OF_ARGS_LIST);

    const char *symb = group.sign[1]; ans = (group.oper == _multiply); i = 0;
    do {ans = group.oper(ans, LOOP_array[i], group._mod);
	fprintf(stdout, "%lu", LOOP_array[i]);
	if (i + 1 == function_arg_count) break; i++; fprintf(stdout, " %s ", symb);
    } while (1);

    if (group._mod) fprintf(stdout, " \u2261 %lu	(mod %s)", ans, argv[1]); else fprintf(stdout, " = %lu", ans); fprintf(stdout, "\n");
    // display result ^^

    free(LOOP_array); return 0;
    // finish cleanly ^^
}
