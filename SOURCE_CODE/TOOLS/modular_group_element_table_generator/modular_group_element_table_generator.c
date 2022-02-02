#include <stdio.h>
#include "../../libraries/mathematics/universal_group_library.h" // Needed for: 'open_and_append_to_LOGBOOK()'
#include "../../libraries/functional/string.h" // Needed for 'STR_could_be_parsed_into_UL()'
#include "../../libraries/mathematics/maths.h" // Need for 'GCD()', 'ADDITIVE_IDENTITY', 'MULTIPLICATIVE_IDENTITY'
unsigned long mod; // < Hanle library variable declared 'extern' ^^ handle library inclusions

#define ARGV_TWO_INSTRUCTION "Please provide as second argument '0' for the additive identity,\nOr '1' for the multiplicative identity.\n"
#define ARGV_ONE_INSTRUCTION "Please provide as first argument the modulus of the group (in decimal notation).\n"
// ^ Definitions

const char *mod_not_parsable = " please provide as first argument the modulus.";
const char *id_not_parsable = " please provide as second argument the group's identity element.";

const char *local_switch(int index) {
    switch (index) {
	case 1: return mod_not_parsable;
	case 2: return id_not_parsable;
    };
}

unsigned long mod, id; int main(int argc, char **argv) { mod_ = &mod; id_ = &id; local_error_selector = local_switch;
    if (!str_represents_ul(argv[1], mod_)) str_does_not_represent_suitable_ul(argv, 1);
    if (!match_variadic(argv[2], 2, "0", "1")) str_does_not_represent_suitable_ul(argv, 2); else str_represents_ul(argv[2], id_);
    unsigned long count = 0; for (unsigned long element = id; element < mod; element++) if (id == ADDITIVE_IDENTITY || GCD(mod, element) == MULTIPLICATIVE_IDENTITY) { fprintf(stdout, "%lu\n", element); count++; }
    fprintf(stdout, "\nExported %lu elements.\n", count); return 0;
}
