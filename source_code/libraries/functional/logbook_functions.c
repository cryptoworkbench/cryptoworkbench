/* ABSTRACT:
 * This library is for file access from ~/laboratory/instruments into ~/laboratory/registry/ (so "../registry", as this library's header file reveals)
 *
 * DEVELOPERS NOTES:
 * I noticed when I remove the "../registry/" folder I get something like:
 * sh: 1: cannot create ../registry/multiplicative_group_of_integers_mod_67: Directory nonexistent
 * Segmentation fault
 *
 * Unfortunately "FLUSH_TO_FS()" does pass through the appropiate return value to "main()".
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

char *operation_symbol = "*"; // <<< I expect to most handle multiplicative groups
const char *alt_operation_symbol = "+";

const char *folder_name = "../registry/";
const char *program_to_use = "./group_examplifier";

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value;
} // ^^^ Returns an output buffer for logbook_fs

FILE *open_logbook()  {
    FILE *return_value = fopen(LOGBOOK_PATH, "a");
    return return_value; }

int FLUSH_TO_FS(char *program_name, char *TO_BE_APPENDED_logbook_line) {
    FILE *logbook_fs = open_logbook();
    if (logbook_fs) { fprintf(logbook_fs, LOGBOOK_FORMULA "%s", program_name, TO_BE_APPENDED_logbook_line); fclose(logbook_fs); return 0; }
    // ^^^ Upon successfull opening of logbook_fs, append the line TO BE APPENDED to the logbook text file

    else {
	fprintf(stderr, "%s WILL ABORT NOW because it failed to append to the logbook the following line:\n", program_name);
	fprintf(stderr, "\"%s\"\n\n", TO_BE_APPENDED_logbook_line);
	fprintf(stderr, "EXITING '-10'\n"); return -10; } }
// ^^^ Sends a single line of logging to the logbook file, prints error to stderr and returns -10 upon failure.

// ### Supposed to be called as "open_modular_group(open_logbook(),  . . . etc", beware that the char pointer "program_name" is freed in this function
FILE *open_group_as(struct group_prams group, char *program_name, char **path_to_file_INSERTMENT_SLOTH) {
    if (group.ID == 0) { adjective = (char *) alt_adjective; operation_symbol = (char *) alt_operation_symbol; }
    // ^^^ Settle on language to appropiate

    char *PATH_TO_FILE = (char *) malloc(sizeof(char) * (3 + str_len(FOLDER_NAME) + str_len(adjective) + str_len(FILENAME_BODY) + char_in_val(group.CAP) + 1));
    sprintf(PATH_TO_FILE, "../" FOLDER_NAME "%s" FILENAME_BODY "%lu", adjective, group.CAP);
    // ^^^ Prepare path to pass on to "fopen()"

    char *BUFFER = BUFFER_OF_SIZE(200);
    // ^^^ Artificially create a 200 byte buffer within program scape and avoid using the filestream buffers

    // ### BEGIN PROGRAM OPERATION ===>
    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) {
	sprintf(BUFFER, "Failed to secure a filestream sourced by '%s' \u21D2 the group denoted <\u2124/%lu\u2124, %s> does not seem to already have been registered\n", PATH_TO_FILE, group.CAP, operation_symbol); FLUSH_TO_FS(program_name, BUFFER);
	char *required_command = (char *) malloc(sizeof(char) * (str_len(GROUP_EXPORTER) + 1 + char_in_val(group.CAP) + 1 + char_in_val(group.ID) + 3 + str_len(PATH_TO_FILE) + 8));
	sprintf(required_command, "%s %lu %lu > %s && sync", GROUP_EXPORTER, group.CAP, group.ID, PATH_TO_FILE, FOLDER_NAME);

	sprintf(BUFFER, "Sending '%s' to the operating system in an effort to manually register <\u2124/%lu\u2124, %s>\n", required_command, group.CAP, operation_symbol); FLUSH_TO_FS(program_name, BUFFER);
	system(required_command); // <<< Sends operation to system, while ^^^ sends a notification of the operation to the logbook
	sprintf(BUFFER, "The command '%s' has been send to the operating system which presumably executed it correctly\n", required_command); FLUSH_TO_FS(program_name, BUFFER);

	if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) { 
	    sprintf(BUFFER, "ERROR: failed to create registry file using \"%s\".\n", required_command); FLUSH_TO_FS(program_name, BUFFER);
	    return NULL; }
	free(required_command);
    } if (modular_group_fs != NULL) sprintf(BUFFER, "Successfully secured a filestream sourced by '%s'\n", PATH_TO_FILE, group.CAP, operation_symbol); FLUSH_TO_FS(program_name, BUFFER);
    free(BUFFER); *path_to_file_INSERTMENT_SLOTH = PATH_TO_FILE; 
    return modular_group_fs; }
// ^^^ Function to open modular groups 
