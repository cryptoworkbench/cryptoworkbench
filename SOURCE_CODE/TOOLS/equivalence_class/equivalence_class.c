#include <stdio.h> // 'fprintf()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'extern ul MOD;'

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], MOD_LOCATION_REPORT())) { fprintf(stderr, "%s is not a suitable value for the field modulus!\n", argv[1]); exit(-1); } ul a;
    if (3 > argc || !str_represents_ul(argv[2], &a)) { fprintf(stderr, "%s is not a suitable value to take a modulus of!\n", argv[2]); exit(-1); }
    fprintf(stdout, "%lu \u2261 %lu (%% %lu) -> %lu %% %lu = %lu\n", a, a % _REPORT_MOD(), _REPORT_MOD(), a, _REPORT_MOD(), a % _REPORT_MOD());
    return 0;
}
