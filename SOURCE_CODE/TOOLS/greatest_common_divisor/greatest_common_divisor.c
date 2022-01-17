#include <stdio.h> // 'fprintf()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'GCD()'
ul MOD; // < Must be included because of 'maths.h'

int main(int argc, char **argv) { ul a;
    if (2 > argc || !str_represents_ul(argv[1], &a)) { fprintf(stderr, "%s is not MOD!\n", argv[1]); exit(-1); } ul b;
    if (3 > argc || !str_represents_ul(argv[2], &b)) { fprintf(stderr, "%s is not b!\n", argv[2]); exit(-2); }
    fprintf(stdout, "GCD(%lu, %lu) = %lu\n", a, b, GCD(a, b));
    return 0;
}
