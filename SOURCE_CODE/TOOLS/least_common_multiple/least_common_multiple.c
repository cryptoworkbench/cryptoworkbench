#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"

const char *variable_a_ERROR = "please provide as first argument the first number to take the LCM with.";
const char *variable_b_ERROR = "please provide as second argument the second number to take the LCM with.";

const char *local_switch(int INDEX) { switch (INDEX) { case 1: return variable_a_ERROR; case 2: return variable_b_ERROR; }; }

int main(int argc, char **argv) { local_error_selector = local_switch; unsigned long a;
    if (!str_represents_ul(argv[1], &a)) str_does_not_represent_suitable_ul(argv, 1); unsigned long b;
    if (!str_represents_ul(argv[2], &b)) str_does_not_represent_suitable_ul(argv, 2);
    fprintf(stdout, "The least common multiple of %lu and %lu is %lu.\n", a, b, least_common_multiple(a, b));
    return 0;
}
