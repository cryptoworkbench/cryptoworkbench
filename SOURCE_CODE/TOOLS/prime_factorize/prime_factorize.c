#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"

int main(int argc, char **argv) { unsigned long composite; unparsed_arg = argv[1];
    if (2 > argc || !str_represents_ul(unparsed_arg, &composite)) error_message(str_not_parsable_as_number, -1);
    // take in composite ^

    printf("Composite: %lu\n", composite);
    return 0;
}
