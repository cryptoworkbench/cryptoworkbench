// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

int array_index = 0;
// global variable declarations ^

void argument_parse() { fprintf(stderr, "Failed to parse '%s'!", (*argv_location)[1 + array_index]); };
void argument_count() { fprintf(stderr, "The LCM (Least Common Multiple) function requires at least 2 arguments!"); }
// error functions ^

int main(int argc, char **argv) { argv_location = &argv; unsigned long lcm_function_argument_count;
    conditional_goodbye(n(n(error_specification(argument_count, -(2 > (lcm_function_argument_count = argc - 1))))));
    unsigned long *arguments_array = (unsigned long *) malloc(sizeof(unsigned long) * lcm_function_argument_count); for (array_index = 0; array_index < lcm_function_argument_count; array_index++)
    conditional_goodbye(n(n(error_specification(argument_parse, n(str_represents_ul(argv[1 + array_index], (array_index + arguments_array), -(2 + array_index)))))));
    fprintf(stdout, "The least common multiple of the %i supplied arguments is %lu\n", lcm_function_argument_count, UNRESTRICTED_LCM(arguments_array, lcm_function_argument_count)); return 0;
}
