#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

unsigned long mod; int main(int argc, char **argv) { mod_ = &mod;
    if (2 > argc || !str_represents_ul(argv[1], mod_)) { fprintf(stderr, "error 1\n"); exit(-1); } ul a;
    if (3 > argc || !str_represents_ul(argv[2], &a)) { fprintf(stderr, "error 2\n"); exit(-2); } ul b;
    if (4 > argc || !str_represents_ul(argv[3], &b)) { fprintf(stderr, "error 3\n"); exit(-3); } ul ID;
    if (5 > argc || !match_variadic(argv[4], 2, "0", "1")) { fprintf(stderr, "error 4\n"); exit(-4); } str_represents_ul(argv[4], &ID);
    _group_operation operation = _operation_from_ID(ID); if (mod) fprintf(stdout, "%lu %s %lu \u2261 %lu	(mod %lu)\n", a, ID_denoted_by_operation_symbol(ID), b, operation(a, b, mod), mod);
    else fprintf(stdout, "%lu %s %lu = %lu	(within the infinite field of natural numbers)\n", a, ID_denoted_by_operation_symbol(ID), b, operation(a, b, mod)); return 0;
}
