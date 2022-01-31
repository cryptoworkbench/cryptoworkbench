#include <stdio.h> // 'fprintf()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'extern ul mod;'

int main(int argc, char **argv) { ul mod; mod_ = &mod;
    if (!str_represents_ul(argv[1], &mod)) { fprintf(stderr, "%s is not a suitable value for the field modulus!\n", argv[1]); exit(-1); } ul a;
    if (!str_represents_ul(argv[2], &a)) { fprintf(stderr, "%s is not a suitable value to take a modulus of!\n", argv[2]); exit(-1); }
    fprintf(stdout, "%lu \u2261 %lu (%% %lu) -> %lu %% %lu = %lu\n", a, a % mod, mod, a, mod, a % mod); a = 6; return 0; }
