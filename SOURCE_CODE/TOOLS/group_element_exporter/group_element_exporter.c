#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

void argument_ERROR(const char *char_PTR_one, const char *char_PTR_two) { fprintf(stderr, " failed to understand the %s argument as the %s.\n\n", char_PTR_one, char_PTR_two); }
const char *first[] = {"first", "modulus"}; void error_ONE() { argument_ERROR(first[0], first[1]); }
const char *second[] = {"second", "group's identity element"}; void error_TWO() { argument_ERROR(second[0], second[1]); }
// ^ stuff for incorrect terminal arguments

void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus of the additive or multiplicative group."); }

int main(int argc, char **argv) {
    unsigned long mod; conditional_goodbye(n(n(error_specification(mod_failed_to_parse, ul_parse_str(argv[1], &mod, -1)))));
    int id;            conditional_goodbye(n(n(error_message(identity_SELECTOR_error, identity_set(&id, identity_SELECTOR(argv[2]), -2)))));
    unsigned long count = 0; for (unsigned long element = id; element < mod; element++) if (id == ADDITIVE_IDENTITY || GCD(mod, element) == MULTIPLICATIVE_IDENTITY) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\nExported %lu elements.\n", count); // absolutely needed here because otherwise 'group_library.c' won't stop trying to read from this program's STDOUT
    return 0; }
