// Program description:
// Takes the LCM of two numbers.
//
// DEVELOPERS NOTICE:
// I wish this TOOL was like the TOOL 'greatest_common_divisor' which can take any amouny of arguments greater than one.
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"

void variable_a_error() { fprintf(stderr, "Please provide as first argument the first number to take the LCM with."); }
void variable_b_error() { fprintf(stderr, "Please provide as second argument the second number to take the LCM with."); }

int main(int argc, char **argv) {
    unsigned long a; conditional_goodbye(n(n(error_specification(variable_a_error, n(str_represents_ul(argv[1], &a, -1))))));
    unsigned long b; conditional_goodbye(n(n(error_specification(variable_b_error, n(str_represents_ul(argv[2], &b, -2))))));
    fprintf(stdout, "The least common multiple of %lu and %lu is %lu.\n", a, b, least_common_multiple(a, b));
    return 0;
}
