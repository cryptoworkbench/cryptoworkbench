#include <stdio.h>
#include <stdlib.h>

#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDOUT_ARGV_ONE_INSTRUCTION "Please provide as second argument '0' for the ADDITIVE IDENTITY or '1' for the MULTIPLICATIVE IDENTITY.\n"
#define HELP_INFORMATION "Program usage: %s <CAP> <ID> [horizontal offset] [vertical offset] [output filename]\n\n<MANDATORY ARGUMENTS> are denoted like this. The program won't run without these.\n\n[optional arguments] are denoted like this. They are not very necessary.\n"

void HELP_AND_QUIT(char *prog_NAME);
void MOD_not_parsable_ERROR(char *argv_one);
void ID_not_parsable_ERROR(char *argv_two);
