/* Takes the GCD of an arbitrary number of number. */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

int main(int argc, char **argv) { unsigned long gcd_function_argument_count = argc - 1;
    if (2 > gcd_function_argument_count) exit(-1); // error_message(error_selector(1), -1);
    unsigned long **arguments_array = (unsigned long **) malloc(sizeof(unsigned long *) * gcd_function_argument_count);
    for (unsigned long i = 0; i < gcd_function_argument_count; i++) if (!str_represents_ul(argv[1 + i], (arguments_array[i] = (unsigned long *) malloc(sizeof(unsigned long))))) exit(-(2 + i));

    printf("GCD of arguments: %lu\n", UNRESTRICTED_GCD(arguments_array, gcd_function_argument_count));
    return 0;
}
