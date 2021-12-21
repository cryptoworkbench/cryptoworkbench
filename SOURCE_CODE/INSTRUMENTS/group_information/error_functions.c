#include "error_functions.h"

void ID_not_parsable_ERROR(char *argv_one, char *argv_two) {
    fprintf(stdout, STDOUT_ARGV_ONE_INSTRUCTION, argv_one, argv_one, argv_one, argv_two);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is not in the first list nor in the second. Returning '-2'.\n", argv_two);
    exit(-2);
}

void MOD_not_parsable_ERROR(char *argv_one) {
    fprintf(stdout, STDOUT_ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from ARCHIVE/ the group '\u2115%s*' makes no sense to me. Returning '-1'.\n", argv_one);
    exit(-1);
}

void HELP_AND_QUIT(char *prog_NAME) {
    fprintf(stderr, HELP_INFORMATION, prog_NAME);
    exit(0);
}
