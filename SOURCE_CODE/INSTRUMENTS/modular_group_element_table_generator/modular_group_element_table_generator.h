#include <stdio.h>
#include <unistd.h>
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "flush_to_LOGBOOK()"
#include "../../libraries/functional/string.h" // <<< Needed for "ul_ptr_from_str()"
// ^^^ LIBRARY INCLUSIONS

#define ARGV_TWO_INSTRUCTION "Please provide as second argument '0' for the additive identity,\nOr '1' for the multiplicative identity.\n"
#define ARGV_ONE_INSTRUCTION "Please provide as first argument the modulus of the group (in decimal notation).\n"
#define MULTIPLICATIVE_IDENTITY 1
#define ADDITIVE_IDENTITY 0
// ^^^ DEFINITIONS

struct group_STRUCT _group;
// ^^^ PROGRAM VARIABLES

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one);
void QUIT_ON_ARGV_TWO_ERROR(char *argv_two);
