#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "logbook_functions.h"
#define GROUP_EXPORTER "group_examplifier"
#define FILENAME_BODY "_group_of_integers_modulo"

char *adjective = "multiplicative"; // <<< We expect to be using this adjective
const char *alt_adjective = "additive";

char *group_operation = "*"; // <<< I expect to most handle multiplicative groups
const char *alt_group_operation = "+";

char *identity_char = "1";
const char *alt_identity_char = "0";

const char *folder_name = "../registry/";
const char *filename_body = "_group_of_integers_modulo_";
const char *program_to_use = "group_examplifier";

// ### Cannot pass argv[1] as *argv_one, *argv_one is freed in this function. Use 'open_modular_group(argv[0], str_from_ul(group->modulus));'. >>
FILE *open_modular_group(FILE *logbook_fs, char *argv_zero, unsigned long modulus, unsigned long identity, char **location_of_char_pointer_to_argv_one) {
    if (identity == 0) {
	adjective = (char *) alt_adjective;
	group_operation = (char *) alt_group_operation;
	identity_char = (char *) alt_identity_char; }
    // ^^^ Settle on language to appropiate

    char *modulus_string = str_from_ul(modulus, 0);
    char *file_to_open = (char *) malloc(sizeof(char) * (strlen(folder_name) + strlen(adjective) + strlen(filename_body) + char_in_val(modulus) + 1));
    *copy_over(copy_over(copy_over(copy_over(file_to_open, folder_name), adjective), filename_body), modulus_string) = 0;
    // ^^^ Prepare path to pass on to "fopen()"

    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(file_to_open, "r"))) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "<\u2124/%lu\u2124, %s> does not seem to already have been registered, for there is no such file; '%s' ===>\n", argv_zero, modulus, group_operation, file_to_open);
	char *required_command = (char *) malloc(sizeof(char) * ((2 * char_in_val(modulus)) + strlen(GROUP_EXPORTER) + 6 + strlen(folder_name) + strlen(adjective) + strlen(FILENAME_BODY) + 1));
	sprintf(required_command, "%s %lu %lu > %s%s_group_of_integers_modulo_%s", GROUP_EXPORTER, modulus, identity, folder_name, adjective, modulus_string);
	// *copy_over(copy_over(copy_over(copy_over(copy_over(required_command, program_to_use), " "), modulus_string), " "), identity_char) = 0; free(modulus_string);

	fprintf(logbook_fs, LOGBOOK_FORMULA "Running '%s' externally to register <\u2124/%lu\u2124, %s>\n", argv_zero, required_command, modulus, group_operation); system(required_command);

	if (!(modular_group_fs = fopen(file_to_open, "r"))) { 
	    fprintf(logbook_fs, LOGBOOK_FORMULA "ERROR: failed to create registry file using \"%s\".\n", argv_zero, required_command);
	    return NULL; } free(required_command); }
    if (modular_group_fs != NULL) fprintf(logbook_fs, LOGBOOK_FORMULA "Interpreting <\u2124/%lu\u2124, %s> from '%s'\n", argv_zero, modulus, group_operation, file_to_open);
    // ^^^ Notify user upon successfully opening the desired file

    *location_of_char_pointer_to_argv_one = file_to_open;
    return modular_group_fs;
}
