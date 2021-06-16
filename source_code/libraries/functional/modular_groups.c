#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "logbook_functions.h"

char *adjective_to_use = "multiplicative"; // <<< We expect to be using this adjective
const char *alternative_adjective = "additive";
const char *folder_name = "modular_groups/";
const char *filename_main = "_group_of_integers_modulo_";
const char *required_program = "group_examplifier";
const char *stderr_redirect = " 2> /dev/null";

FILE *open_modular_group(FILE *logbook_fs, char *argv_zero, unsigned long modulus, unsigned long identity, char **location_of_char_pointer_to_argv_one) {
    if (identity == 0) adjective_to_use = (char *) alternative_adjective;
    // ^^^ Determine adjective to use

    char *modulus_string = str_from_ul(modulus, 0);
    char *file_to_open = (char *) malloc(sizeof(char) * (strlen(folder_name) + strlen(adjective_to_use) + strlen(filename_main) + char_in_val(modulus) + 1)); // << + 1 for the string terminator
    *copy_over(copy_over(copy_over(copy_over(file_to_open, folder_name), adjective_to_use), filename_main), modulus_string) = 0;
    // ^^^ Prepare path to pass on to "fopen()"

    printf("Opening %s\n", file_to_open);
    // ^^^ Test in stdout
    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(file_to_open, "r"))) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "No file named '%s'\n", argv_zero, file_to_open);
	char *required_command = (char *) malloc(sizeof(char) * (strlen(required_program) + 1 + char_in_val(modulus) + strlen(stderr_redirect) + 1));
	char *freeze = copy_over(copy_over(copy_over(copy_over(required_command, required_program), " "), modulus_string), " "); free(modulus_string);
	if (identity == 0)
	    *copy_over(copy_over(freeze, "0"), stderr_redirect) = 0;
	else if (identity == 1)
	    *copy_over(copy_over(freeze, "1"), stderr_redirect) = 0;

	fprintf(logbook_fs, LOGBOOK_FORMULA "Sending to terminal '%s'\n", argv_zero, required_command); system(required_command);

	if (!(modular_group_fs = fopen(file_to_open, "r")))
	{ fprintf(logbook_fs, LOGBOOK_FORMULA "ERROR: failed to create file using '%s'\n", argv_zero, required_command); return NULL; } free(required_command); }
    if (modular_group_fs != NULL) fprintf(logbook_fs, LOGBOOK_FORMULA "Successfully opened '%s'\n", argv_zero, file_to_open);
    // ^^^ Notify user upon successfully opening the desired file

    *location_of_char_pointer_to_argv_one = file_to_open;
    return modular_group_fs;
}
