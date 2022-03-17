// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

unsigned long *arguments_array; int lcm_function_argument_count, i;
// global variable declarations ^

void argument_parse() { fprintf(stderr, "Failed to parse '%s'!", (*argv_loc)[1 + i]); };
void argument_count() { fprintf(stderr, "The LCM (Least Common Multiple) function requires at least 2 arguments!"); }
// error functions ^

void args_list() { fprintf(stdout, "%lu", arguments_array[i]); if (i + 1 == lcm_function_argument_count) return; i++; fprintf(stdout, ", "); args_list(); }
// recursive function which prints the arguments

int main(int argc, char **argv) { argv_loc = &argv;
    conditional_goodbye(n(n(error_specification(argument_count, -(2 > (lcm_function_argument_count = argc - 1))))));
    arguments_array = (unsigned long *) malloc(sizeof(unsigned long) * lcm_function_argument_count); for (i = 0; i < lcm_function_argument_count; i++)
    conditional_goodbye(n(n(error_specification(argument_parse, n(ul_parse_str(i + arguments_array, argv[1 + i], -(2 + i))))))); i = 0;
    fprintf(stdout, "LCM("); args_list(); fprintf(stdout, ") = %lu\n", UNRESTRICTED_LCM(arguments_array, lcm_function_argument_count)); return 0;
}
