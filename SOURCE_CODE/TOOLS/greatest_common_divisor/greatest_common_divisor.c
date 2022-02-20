// Takes the GCD of an arbitrary number of numbers
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

int array_index = 0;
// global variable declarations ^

void argument_parse() { fprintf(stderr, "Failed to parse '%s'!", (*argv_location)[1 + array_index]); };
void argument_count() { fprintf(stderr, "The GCD (Greatest Common Divisor) function requires at least 2 arguments!"); }
// error functions ^

int main(int argc, char **argv) { unsigned long gcd_function_argument_count = argc - 1; argv_location = &argv;
    conditional_goodbye(n(n(error_specification(argument_count, -(2 > gcd_function_argument_count)))));
    unsigned long **arguments_array = (unsigned long **) malloc(sizeof(unsigned long *) * gcd_function_argument_count);
    for (array_index = 0; array_index < gcd_function_argument_count; array_index++)
    { conditional_goodbye(n(n(error_specification(argument_parse, n(str_represents_ul_(argv[1 + array_index], (arguments_array[array_index] = (unsigned long *) malloc(sizeof(unsigned long))), -(2 + array_index)))))));}
    printf("GCD of arguments: %lu\n", UNRESTRICTED_GCD(arguments_array, gcd_function_argument_count)); return 0;
}
