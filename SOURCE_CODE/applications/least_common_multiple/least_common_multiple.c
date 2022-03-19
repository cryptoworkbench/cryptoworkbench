// Takes the LCM of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.extended.h"
#include "../../libraries/mathematics/maths.basic.h"
#define STARTING_INDEX_OF_ARGS_LIST 1
// library inclusions ^

unsigned int lcm_function_argument_count, i;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", STARTING_INDEX_OF_ARGS_LIST + i); };
void argument_count() { fprintf(stderr, "The LCM (Least Common Multiple) function requires at least 2 arguments!"); }
// error functions ^

int main(int argc, char **argv) { i_ = &i; array_size_ = &lcm_function_argument_count; argv_ptr = &argv;
    // initialize everything      ^

    conditional_goodbye(n(n(error_specification(argument_count, -(2 > (lcm_function_argument_count = argc - STARTING_INDEX_OF_ARGS_LIST))))));
    // check amount of inputs ^

    arguments_array = UL_array_of_SIZE(lcm_function_argument_count);
    LOOP_ul_parse_str(argument_failed_to_parse, STARTING_INDEX_OF_ARGS_LIST);

    i = 0; fprintf(stdout, "LCM("); LOOP_ul_parsed_strs(); fprintf(stdout, ") = %lu\n", UNRESTRICTED_LCM(arguments_array, lcm_function_argument_count)); return 0;
}
