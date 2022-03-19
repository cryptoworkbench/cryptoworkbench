// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.basic.h"
// library inclusions ^

unsigned int gcd_function_argument_count, i; unsigned long *arguments_array;
// global variable declarations ^

void argument_failed_to_parse() { fprintf(stderr, "%ith argument failed to parse!", 1 + i); };
void argument_count_failure() { fprintf(stderr, "The GCD (Greatest Common Divisor) function requires at least 2 arguments!"); }
// error functions ^

void args_list() { fprintf(stdout, "%lu", arguments_array[i]); if (i + 1 == gcd_function_argument_count) return; i++; fprintf(stdout, ", "); args_list(); }
// recursive function which prints the arguments

int main(int argc, char **argv) { argv_ptr = &argv;
    // initialize everything      ^

    conditional_goodbye(n(n(error_specification(argument_count_failure, -(2 > (gcd_function_argument_count = argc - 1))))));
    // check amount of arguments ^

    arguments_array = UL_array_of_SIZE(gcd_function_argument_count);
    LOOP_ul_parse_str(argument_failed_to_parse, arguments_array, gcd_function_argument_count, &i, 1);

    i = 0; fprintf(stdout, "GCD("); args_list(); fprintf(stdout, ") = %lu\n", UNRESTRICTED_GCD(arguments_array, gcd_function_argument_count)); return 0;
}
