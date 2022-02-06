#include <stdio.h>
#include "../../libraries/mathematics/universal_group_library.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void argument_ERROR(const char *char_PTR_one, const char *char_PTR_two) { fprintf(stderr, " failed to understand the %s argument as the %s.\n\n", char_PTR_one, char_PTR_two); }
const char *first[] = {"first", "modulus"}; void error_ONE() { argument_ERROR(first[0], first[1]); }
const char *second[] = {"second", "group's identity element"}; void error_TWO() { argument_ERROR(second[0], second[1]); }
// ^ stuff for incorrect terminal arguments

int main(int argc, char **argv) { unsigned long mod, id; mod_ = &mod;
    if (!str_represents_ul(argv[1], mod_)) error_message(error_ONE, 1);
    if (!argv[2] || !match_variadic(argv[2], 2, "0", "1")) error_message(error_TWO, 2); else str_represents_ul(argv[2], &id);
    unsigned long count = 0; for (unsigned long element = id; element < mod; element++) if (id == ADDITIVE_IDENTITY || GCD(mod, element) == MULTIPLICATIVE_IDENTITY) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\nExported %lu elements.\n", count); // absolutely needed here because otherwise 'universal_group_library' won't stop trying to read from this program's STDOUT
    return 0; }
