/* ABSTRACT:
 * This library is for file access from ~/laboratory/instruments into ~/laboratory/registry/ (so "../registry", as this library's header file reveals)
 */
#include <stdio.h>
#include <stdlib.h> // <<< Needed for malloc
#include "string.h"
#include "logbook_functions.h" // <<< Needed for definition of the definition of LOGBOOK_FORMULA
#define FOLDER_NAME "registry/"
#define GROUP_EXPORTER "./group_examplifier"
#define FILENAME_BODY "_group_of_integers_mod_"

char *adjective = "multiplicative"; // <<< We expect to be using this adjective
const char *alt_adjective = "additive";

char *group_operation = "*"; // <<< I expect to most handle multiplicative groups
const char *alt_group_operation = "+";

const char *folder_name = "../registry/";
const char *program_to_use = "./group_examplifier";

// ### Supposed to be called as "open_modular_group(open_logbook(),  . . . etc", beware that the char pointer "program_name" is freed in this function
FILE *open_modular_group_UNRESTRICTED(char *program_name, unsigned long CAP, unsigned long ID, char **location_of_char_pointer_to_filename_in_allocated_memory, FILE *logbook_fs) {
    if (logbook_fs == NULL) logbook_fs = fopen(LOGBOOK_NAME, "a");
    if (ID == 0) { adjective = (char *) alt_adjective; group_operation = (char *) alt_group_operation; }
    // ^^^ Settle on language to appropiate

    char *file_to_open = (char *) malloc(sizeof(char) * (3 + str_len(FOLDER_NAME) + str_len(adjective) + str_len(FILENAME_BODY) + char_in_val(CAP) + 1));
    sprintf(file_to_open, "../" FOLDER_NAME "%s" FILENAME_BODY "%lu", adjective, CAP);
    // ^^^ Prepare path to pass on to "fopen()"

    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(file_to_open, "r"))) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "<\u2124/%lu\u2124, %s> does not seem to be registered because I failed to open a reading filestream to '%s'\n", program_name, CAP, group_operation, file_to_open);
	// fprintf(logbook_fs, LOGBOOK_FORMULA "\n", program_name, CAP, group_operation, file_to_open);
	char *required_command = (char *) malloc(sizeof(char) * (str_len(GROUP_EXPORTER) + 1 + char_in_val(CAP) + 1 + char_in_val(ID) + 3 + str_len(file_to_open) + 8));
	sprintf(required_command, "%s %lu %lu > %s && sync", GROUP_EXPORTER, CAP, ID, file_to_open, FOLDER_NAME);

	fprintf(logbook_fs, LOGBOOK_FORMULA "Running '%s' externally to register <\u2124/%lu\u2124, %s>\n", program_name, required_command, CAP, group_operation);
	system(required_command); // <<< Sends operation to system, while ^^^ notifies of operation

	if (!(modular_group_fs = fopen(file_to_open, "r"))) { 
	    fprintf(logbook_fs, LOGBOOK_FORMULA "ERROR: failed to create registry file using \"%s\".\n", program_name, required_command);
	    return NULL; }
	free(required_command);
    } if (modular_group_fs != NULL) fprintf(logbook_fs, LOGBOOK_FORMULA "Successfully opened a reading filestream to '%s' \u21D2 <\u2124/%lu\u2124, %s> was found in the registry\n", program_name, file_to_open, CAP, group_operation);

    *location_of_char_pointer_to_filename_in_allocated_memory = file_to_open; 
    fclose(logbook_fs);
    return modular_group_fs; }
// ^^^ Function to open modular groups 

FILE *open_modular_group(FILE *throw_away_logbook_fs, char *program_name, unsigned long CAP, unsigned long ID) {
    char *throw_away_name;
    FILE *return_value = open_modular_group_UNRESTRICTED(program_name, CAP, ID, &throw_away_name, &throw_away_logbook_fs);
    free(throw_away_name);
    fclose(throw_away_logbook_fs);
    return return_value; }
// ^^^ Wrapper for the "_UNRESTRICTED" variant
