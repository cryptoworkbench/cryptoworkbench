// Takes the LCM of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.basic.h"
// library inclusions ^

unsigned long *arguments_array; unsigned int lcm_function_argument_count, i;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", 1 + i); };
void argument_count() { fprintf(stderr, "The LCM (Least Common Multiple) function requires at least 2 arguments!"); }
// error functions ^

void args_list() { fprintf(stdout, "%lu", arguments_array[i]); if (i + 1 == lcm_function_argument_count) return; i++; fprintf(stdout, ", "); args_list(); }
// recursive function which prints the arguments

int main(int argc, char **argv) { argv_ptr = &argv;
    // initialize everything      ^

    conditional_goodbye(n(n(error_specification(argument_count, -(2 > (lcm_function_argument_count = argc - 1))))));
    // check amount of inputs ^

    arguments_array = UL_array_of_SIZE(lcm_function_argument_count);
    LOOP_ul_parse_str(argument_failed_to_parse, arguments_array, lcm_function_argument_count, &i, 1);

    i = 0; fprintf(stdout, "LCM("); args_list(); fprintf(stdout, ") = %lu\n", UNRESTRICTED_LCM(arguments_array, lcm_function_argument_count)); return 0;
}
