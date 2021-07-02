/* ABSTRACT:
 * This library is for file access from ~/laboratory/instruments into ~/laboratory/registry/ (so "../registry", as this library's header file reveals)
 */
#include <stdio.h>
#include <stdlib.h> // <<< Needed for malloc
#include "string.h"
#include "logbook_functions.h" // <<< Needed for definition of LOGBOOK_FORMULA and public variable "FILE *logbook_fs"
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

FILE *open_logbook() { return fopen(LOGBOOK_NAME, "a"); }
// void close_logbook() { fclose(logbook_fs); }

// ### Supposed to be called as "open_modular_group(open_logbook(),  . . . etc"
FILE *open_modular_group(FILE *logbook_fs, char *program_name, unsigned long modulus, unsigned long identity, char **location_of_char_pointer_to_filename_in_allocated_memory) {
// ^^^ Cannot pass argv[1] as *argv_one, *argv_one is freed in this function. Use 'open_modular_group(argv[0], str_from_ul(group->modulus));'. >>
    if (identity == 0) {
	adjective = (char *) alt_adjective;
	group_operation = (char *) alt_group_operation;
	identity_char = (char *) alt_identity_char; }
    // ^^^ Settle on language to appropiate

    char *mod_str = str_from_ul(modulus, 0);
    char *file_to_open = (char *) malloc(sizeof(char) * (strlen(folder_name) + strlen(adjective) + strlen(filename_body) + strlen(mod_str) + 1));
    *copy_over(copy_over(copy_over(copy_over(file_to_open, folder_name), adjective), filename_body), mod_str) = 0;
    // ^^^ Prepare path to pass on to "fopen()"

    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(file_to_open, "r"))) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "<\u2124/%s\u2124, %s> does not seem to already have been registered, for there is no such file '%s' ===>\n", program_name, mod_str, group_operation, file_to_open);
	char *required_command = (char *) malloc(sizeof(char) * ((2 * char_in_val(modulus)) + strlen(GROUP_EXPORTER) + 6 + strlen(folder_name) + strlen(adjective) + strlen(FILENAME_BODY) + 9));
	sprintf(required_command, "%s %lu %lu > %s%s_group_of_integers_modulo_%s && sync", GROUP_EXPORTER, modulus, identity, folder_name, adjective, mod_str);

	fprintf(logbook_fs, LOGBOOK_FORMULA "Running '%s' externally to register <\u2124/%s\u2124, %s>\n", program_name, required_command, mod_str, group_operation);
	system(required_command); // <<< Sends operation to system, while ^^^ notifies of operation

	if (!(modular_group_fs = fopen(file_to_open, "r"))) { 
	    fprintf(logbook_fs, LOGBOOK_FORMULA "ERROR: failed to create registry file using \"%s\".\n", program_name, required_command);
	    return NULL; }
	// For debugging of interlinked mechanism of DH_KAP to SUBGROUP_EXAMPLIFIER back to DH_KAP
	// else printf("PRINTING FROM OPEN_MODULAR_GROUP(): SUCCESS!\n");
	free(required_command);
    } if (modular_group_fs != NULL) fprintf(logbook_fs, LOGBOOK_FORMULA "Interpreting <\u2124/%s\u2124, %s> from '%s'\n", program_name, mod_str, group_operation, file_to_open); // <<< Notify user upon successfully opening the desired file

    *location_of_char_pointer_to_filename_in_allocated_memory = file_to_open;
    fclose(logbook_fs); return modular_group_fs; }
// ^^^ Function to open modular groups 
