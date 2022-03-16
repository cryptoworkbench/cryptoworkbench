// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

unsigned long *arguments_array; int gcd_function_argument_count, i;
// global variable declarations ^

void argument_parse() { fprintf(stderr, "Failed to parse '%s'!", (*argv_location)[1 + i]); };
void argument_count() { fprintf(stderr, "The GCD (Greatest Common Divisor) function requires at least 2 arguments!"); }
// error functions ^

void args_list() { fprintf(stdout, "%lu", arguments_array[i]); if (i + 1 == gcd_function_argument_count) return; i++; fprintf(stdout, ", "); args_list(); }
// recursive function which prints the arguments

int main(int argc, char **argv) { argv_location = &argv;
    conditional_goodbye(n(n(error_specification(argument_count, -(2 > (gcd_function_argument_count = argc - 1))))));
    arguments_array = (unsigned long *) malloc(sizeof(unsigned long) * gcd_function_argument_count); for (i = 0; i < gcd_function_argument_count; i++)
    conditional_goodbye(n(n(error_specification(argument_parse, n(ul_parse_str(i + arguments_array, argv[1 + i], -(2 + i))))))); i = 0;
    fprintf(stdout, "GCD("); args_list(); fprintf(stdout, ") = %lu\n", UNRESTRICTED_GCD(arguments_array, gcd_function_argument_count)); return 0;
}
