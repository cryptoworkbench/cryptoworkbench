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

int LOGBOOK_APPEND(char *program_name, char *TO_BE_APPENDED_logbook_line) {
    FILE *logbook_fs = NULL;
    if (logbook_fs = fopen(LOGBOOK_PATH, "a")) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "%s", program_name, TO_BE_APPENDED_logbook_line); fclose(logbook_fs);
	return 0; }

    else {
	fprintf(stderr, "%s WILL ABORT NOW because it failed to append to the logbook the following line:\n", program_name);
	fprintf(stderr, "\"%s\"\n\n\n", TO_BE_APPENDED_logbook_line);
	fprintf(stderr, "WHAT A TRAGIC ERROR.\n\n");
	fprintf(stderr, "EXITING '-10'\n"); return -10; }
}
// ^^^ Sends a single line of logging to the logbook file, prints error to stderr and returns -10 upon failure

// ### Supposed to be called as "open_modular_group(open_logbook(),  . . . etc", beware that the char pointer "program_name" is freed in this function
FILE *open_modular_group(char *program_name, unsigned long CAP, unsigned long ID, char **path_to_file_INSERTMENT_SLOTH) {
    if (ID == 0) { adjective = (char *) alt_adjective; group_operation = (char *) alt_group_operation; }
    // ^^^ Settle on language to appropiate

    char *PATH_TO_FILE = (char *) malloc(sizeof(char) * (3 + str_len(FOLDER_NAME) + str_len(adjective) + str_len(FILENAME_BODY) + char_in_val(CAP) + 1));
    sprintf(PATH_TO_FILE, "../" FOLDER_NAME "%s" FILENAME_BODY "%lu", adjective, CAP);
    // ^^^ Prepare path to pass on to "fopen()"

    char *LINE = (char *) malloc(sizeof(char) * 200);
    // ^^^ Artificially create a 200 byte buffer within program scape and avoid using the filestream buffers

    // ### BEGIN PROGRAM OPERATION ===>
    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) {
	sprintf(LINE, "<\u2124/%lu\u2124, %s> does not seem to be in the registry since I failed to open a reading filestream to '%s'\n", CAP, group_operation, PATH_TO_FILE); LOGBOOK_APPEND(program_name, LINE);
	char *required_command = (char *) malloc(sizeof(char) * (str_len(GROUP_EXPORTER) + 1 + char_in_val(CAP) + 1 + char_in_val(ID) + 3 + str_len(PATH_TO_FILE) + 8));
	sprintf(required_command, "%s %lu %lu > %s && sync", GROUP_EXPORTER, CAP, ID, PATH_TO_FILE, FOLDER_NAME);

	sprintf(LINE, "<\u2124/%lu\u2124, %s> I'm gonna register by executing \"%s\"\n", CAP, group_operation, required_command); LOGBOOK_APPEND(program_name, LINE);
	system(required_command); // <<< Sends operation to system, while ^^^ sends a notification of the operation to the logbook
	sprintf(LINE, "Executed \"%s\"\n", required_command); LOGBOOK_APPEND(program_name, LINE);

	if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) { 
	    sprintf(LINE, "ERROR: failed to create registry file using \"%s\".\n", required_command); LOGBOOK_APPEND(program_name, LINE);
	    return NULL; }
	free(required_command);
    } if (modular_group_fs != NULL) sprintf(LINE, "Successfully opened a reading filestream to '%s'\n", PATH_TO_FILE, CAP, group_operation); LOGBOOK_APPEND(program_name, LINE);
    free(LINE); *path_to_file_INSERTMENT_SLOTH = PATH_TO_FILE; 
    return modular_group_fs; }
// ^^^ Function to open modular groups 
