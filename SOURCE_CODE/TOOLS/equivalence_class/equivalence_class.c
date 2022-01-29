#include <stdio.h> // 'fprintf()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'extern ul mod;'

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_location_OF_MOD())) { fprintf(stderr, "%s is not a suitable value for the field modulus!\n", argv[1]); exit(-1); } ul a;
    if (3 > argc || !str_represents_ul(argv[2], &a)) { fprintf(stderr, "%s is not a suitable value to take a modulus of!\n", argv[2]); exit(-1); }
    fprintf(stdout, "%lu \u2261 %lu (%% %lu) -> %lu %% %lu = %lu\n", a, a % _REPORT_mod(), _REPORT_mod(), a, _REPORT_mod(), a % _REPORT_mod());
    return 0;
}
