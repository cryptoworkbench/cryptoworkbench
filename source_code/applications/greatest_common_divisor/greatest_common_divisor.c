// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.extended.h"
#include "../../libraries/mathematics/maths.basic.h"
#define STARTING_INDEX_OF_ARGS_LIST 1
// library inclusions ^

unsigned int gcd_function_argument_count, i;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", STARTING_INDEX_OF_ARGS_LIST + i); };
void argument_count_failure() { fprintf(stderr, "The GCD (Greatest Common Divisor) function requires at least 2 arguments!"); }
// error functions ^

int main(int argc, char **argv) { i_ = &i; array_size_ = &gcd_function_argument_count; argv_ptr = &argv;
    // initialize everything      ^

    conditional_goodbye(n(n(error_specification(argument_count_failure, -(2 > (gcd_function_argument_count = argc - STARTING_INDEX_OF_ARGS_LIST))))));
    // check amount of arguments ^

    LOOP_ul_parse_str(argument_failed_to_parse, STARTING_INDEX_OF_ARGS_LIST);
    i = 0; fprintf(stdout, "GCD("); LOOP_ul_parsed_strs(LOOP_array, gcd_function_argument_count); fprintf(stdout, ") = %lu\n", UNRESTRICTED_GCD(LOOP_array, gcd_function_argument_count));
    free(LOOP_array);
    return 0;
}
