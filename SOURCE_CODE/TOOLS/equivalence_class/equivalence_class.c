#include <stdio.h> // 'fprintf()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'extern ul mod;'

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &mod_)) { fprintf(stderr, "%s is not a suitable value for the field modulus!\n", argv[1]); exit(-1); } ul a;
    if (3 > argc || !str_represents_ul(argv[2], &a)) { fprintf(stderr, "%s is not a suitable value to take a modulus of!\n", argv[2]); exit(-1); }
    fprintf(stdout, "%lu \u2261 %lu (%% %lu) -> %lu %% %lu = %lu\n", a, a % mod_, mod_, a, mod_, a % mod_); a = 2;
    fprintf(stdout, "%lu \u2261 %lu (%% %lu)\n", a, _conditional_field_cap(a, 0), 0); ul b = 3;
    fprintf(stdout, "%lu + %lu \u2261 %lu (%% %lu)\n", a, b, _add(a, b, 0), 0);
    fprintf(stdout, "%lu * %lu \u2261 %lu (%% %lu)\n", a, b, _multiply(a, b, 0), 0);
    fprintf(stdout, "%lu ^ %lu \u2261 %lu (%% %lu)\n", a, b, _exponentiate(a, b, 0), 0); ul c = 6;
    fprintf(stdout, "%lu / %lu \u2261 %lu (%% %lu)\n", c, b, _divide(c, b, 0), 0);
    return 0;
}
