#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
ul mod;

int main(int argc, char **argv) { ul a;
    if (2 > argc || !str_represents_ul(argv[1], &a)) { exit(-1); } ul b;
    if (3 > argc || !str_represents_ul(argv[2], &b)) { exit(-2); }
    fprintf(stdout, "The least common multiple of %lu and %lu is %lu.\n", a, b, least_common_multiple(a, b));
    return 0;
}
