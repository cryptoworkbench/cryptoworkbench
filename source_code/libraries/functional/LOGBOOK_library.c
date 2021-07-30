/* ABSTRACT:
 * This library is for file access from ~/laboratory/instruments into ~/laboratory/registry/ (so "../registry", as this library's header file reveals)
 *
 * DEVELOPERS NOTES:
 * I noticed when I remove the "../registry/" folder I get something like:
 * sh: 1: cannot create ../registry/multiplicative_group_of_integers_mod_67: Directory nonexistent
 * Segmentation fault
 *
 * Unfortunately "FLUSH_TO_LOGBOOK()" does pass through the appropiate return value to "main()".
 */
#include "LOGBOOK_library.h" // <<< Needed for definition of the definition of LOGBOOK_FORMULA
#define FOLDER_NAME "registry/"
#define GROUP_EXPORTER "group_examplifier"
#define FILENAME_BODY "_group_of_integers_mod_"

char *multiplication_symbol = "*"; // <<< I expect to most handle multiplicative groups
char *addition_symbol = "+";

char *OPERATION_SYMBOL(unsigned long ID) {
    if (ID)
	return multiplication_symbol;
    else
	return addition_symbol;
}

char *multiplication = "multiplicative";
char *addition = "additive";

char *ADJECTIVE_TO_USE(unsigned long ID) {
    if (ID)
	return multiplication;
    else
	return addition;
}

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value; }
// ^^^ Returns an output buffer for logbook_fs

void FLUSH_TO_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line) {
    FILE *logbook_fs; if (logbook_fs = fopen(LOGBOOK_PATH, "a")) { fprintf(logbook_fs, LOGBOOK_FORMULA "%s\n", prog_NAME, TO_BE_APPENDED_logbook_line); fclose(logbook_fs); }
    // ^^^ Upon successfull opening of logbook_fs, append the line TO BE APPENDED to the logbook text file

    else {
	fprintf(stderr, "%s will abort now because it failed to append to the logbook the following line:\n", prog_NAME);
	fprintf(stderr, "\"%s\"\n\n", TO_BE_APPENDED_logbook_line);
	fprintf(stderr, "Now I am going to exit with error code '-10' \u2261 246 (mod 2^8). Presumably you can check with 'echo $?'.\n"); exit(-10); }
}
// ^^^ Sends a single line of logging to the logbook file, prints error to stderr and returns -10 upon failure.

FILE *open_modular_GROUP_in_the_NAME_of(struct group_prams *GROUP, char *prog_NAME, char **path_to_file_INSERTMENT_SLOTH) {
    char *adjective = ADJECTIVE_TO_USE(GROUP->ID);
    // ^^^ Settle on language to appropiate

    char *PATH_TO_FILE = (char *) malloc(sizeof(char) * (3 + str_len(FOLDER_NAME) + str_len(adjective) + str_len(FILENAME_BODY) + char_in_val(GROUP->CAP) + 1));
    sprintf(PATH_TO_FILE, "../" FOLDER_NAME "%s" FILENAME_BODY "%lu", adjective, GROUP->CAP);
    // ^^^ Prepare path to pass on to "fopen()"

    char *BUFFER = BUFFER_OF_SIZE(200);
    // ^^^ Artificially create a 200 byte buffer within program scape and avoid using the filestream buffers

    // ### BEGIN PROGRAM OPERATION ===>
    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) {
	char *symbol = OPERATION_SYMBOL(GROUP->ID);
	sprintf(BUFFER, "Failed to secure a filestream sourced by '%s' \u21D2 the group denoted <\u2124/%lu\u2124, %s> does not seem to already have been registered", PATH_TO_FILE, GROUP->CAP, symbol); FLUSH_TO_LOGBOOK(prog_NAME, BUFFER);
	char *required_command = (char *) malloc(sizeof(char) * (str_len(GROUP_EXPORTER) + 1 + char_in_val(GROUP->CAP) + 1 + char_in_val(GROUP->ID) + 1 + str_len(PATH_TO_FILE) + 9));
	sprintf(required_command, "%s %lu %lu %s && sync", GROUP_EXPORTER, GROUP->CAP, GROUP->ID, PATH_TO_FILE);
	sprintf(BUFFER, "Sending '%s' to the operating system in an effort to manually register <\u2124/%lu\u2124, %s>", required_command, GROUP->CAP, symbol); FLUSH_TO_LOGBOOK(prog_NAME, BUFFER);
	system(required_command);

	if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) { 
	    sprintf(BUFFER, "ERROR: failed to create the required registry file using '%s'", required_command); FLUSH_TO_LOGBOOK(prog_NAME, BUFFER); free(required_command);
	    return NULL; }
	free(required_command);
    } if (modular_group_fs != NULL) sprintf(BUFFER, "Successfully secured a filestream sourced by '%s'", PATH_TO_FILE); FLUSH_TO_LOGBOOK(prog_NAME, BUFFER);
    free(BUFFER); *path_to_file_INSERTMENT_SLOTH = PATH_TO_FILE; 
    return modular_group_fs; }
// ^^^ Function to open modular groups 
