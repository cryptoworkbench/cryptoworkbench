/* ABSTRACT:
 * This library is for file access from ~/laboratory/instruments into ~/laboratory/registry/ (so "../registry", as this library's header file reveals)
 *
 * DEVELOPERS NOTES:
 * I noticed when I remove the "../registry/" folder I get something like:
 * sh: 1: cannot create ../registry/multiplicative_group_of_integers_mod_67: Directory nonexistent
 * Segmentation fault
 *
 * Unfortunately "flush_to_LOGBOOK()" does pass through the appropiate return value to "main()".
 */
#include "LOGBOOK_library.h" // <<< Needed for definition of the definition of LOGBOOK_FORMULA
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group"
#define FOLDER_NAME "registry/"
#define GROUP_EXPORTER "group_examplifier"
#define FILENAME_BODY "_group_of_integers_mod_"

char *combination_SYMBOL_for_(unsigned long ID) { return (ID == 1) ? "*" : "+"; }
char *ADJECTIVE_TO_USE(unsigned long ID) { return (ID == 1) ? "multiplicative" : "additive"; }

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value; }
// ^^^ Returns an output buffer for logbook_fs

void flush_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line) {
    FILE *logbook_fs; if (logbook_fs = fopen(LOGBOOK_PATH, "a")) { fprintf(logbook_fs, LOGBOOK_FORMULA "%s\n", prog_NAME, TO_BE_APPENDED_logbook_line); fclose(logbook_fs); }
    // ^^^ Upon successfull opening of logbook_fs, append the line TO BE APPENDED to the logbook text file

    else {
	fprintf(stderr, "%s will abort now because it failed to append to the logbook the following line:\n", prog_NAME);
	fprintf(stderr, "\"%s\"\n\n", TO_BE_APPENDED_logbook_line);
	fprintf(stderr, "Now I am going to exit with error code '-10' \u2261 246 (mod 2^8). Presumably you can check with 'echo $?'.\n"); exit(-10); }
}
// ^^^ Sends a single line of logging to the logbook file, prints error to stderr and returns -10 upon failure.

FILE *open_modular_GROUP_in_the_NAME_of(struct group_prams *GROUP, char *prog_NAME, char **path_to_filename_INSERTMENT_SLOTH) {
    return open_modular_GROUP_in_the_NAME_of_INNER(GROUP, prog_NAME, path_to_filename_INSERTMENT_SLOTH, combination_SYMBOL_for_(GROUP->ID), BUFFER_OF_SIZE(200));
}

FILE *open_modular_GROUP_in_the_NAME_of_INNER(struct group_prams *GROUP, char *prog_NAME, char **path_to_filename_INSERTMENT_SLOTH, char *SYMBOL, char *BUFFER) {
    char *adjective = ADJECTIVE_TO_USE(GROUP->ID);
    // ^^^ Settle on language to appropiate

    char *PATH_TO_FILE = (char *) malloc(sizeof(char) * (3 + str_len(FOLDER_NAME) + str_len(adjective) + str_len(FILENAME_BODY) + char_in_val(GROUP->CAP) + 1));
    sprintf(PATH_TO_FILE, "../" FOLDER_NAME "%s" FILENAME_BODY "%lu", adjective, GROUP->CAP);
    // ^^^ Prepare path to pass on to "fopen()"

    // ### BEGIN PROGRAM OPERATION ===>
    FILE *modular_group_fs = NULL;
    if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) {
	sprintf(BUFFER, "Failed to secure a filestream sourced by '%s' \u21D2 the group denoted <\u2124/%lu\u2124, %s> does not seem to already have been registered", PATH_TO_FILE, GROUP->CAP, SYMBOL); flush_to_LOGBOOK(prog_NAME, BUFFER);
	pid_t pid = fork(); if (pid == -1) { sprintf(BUFFER, FORK_ERROR); flush_to_LOGBOOK(prog_NAME, BUFFER); exit(-10); }
	char *group_CAP = (char *) malloc(sizeof(char)); group_CAP = str_from_ul(GROUP->CAP, 0);
	char *group_ID = (char *) malloc(sizeof(char)); group_ID = str_from_ul(GROUP->ID, 0);
	char *arguments[] = {GROUP_EXPORTER, group_CAP, group_ID, PATH_TO_FILE, 0};
	if (!pid) execvp(arguments[0], arguments);
	int exit_status;
	waitpid(pid, &exit_status, 0);

	char *required_command = (char *) malloc(sizeof(char) * (str_len(GROUP_EXPORTER) + 1 + str_len(group_CAP) + 1 + str_len(group_ID) + 1 + str_len(PATH_TO_FILE) + 9));
	sprintf(required_command, "%s %s %s %s", GROUP_EXPORTER, group_CAP, group_ID, PATH_TO_FILE);
	sprintf(BUFFER, "Sending '%s' to the operating system in an effort to manually register <\u2124/%lu\u2124, %s>", required_command, GROUP->CAP, SYMBOL); flush_to_LOGBOOK(prog_NAME, BUFFER);
	if (!(modular_group_fs = fopen(PATH_TO_FILE, "r"))) { 
	    sprintf(BUFFER, "ERROR: failed to create the required registry file using '%s'", required_command); flush_to_LOGBOOK(prog_NAME, BUFFER); free(required_command);
	    exit(0);
	} free(required_command);
    } if (modular_group_fs != NULL) sprintf(BUFFER, "Successfully secured a filestream sourced by '%s'", PATH_TO_FILE); flush_to_LOGBOOK(prog_NAME, BUFFER);
    *path_to_filename_INSERTMENT_SLOTH = PATH_TO_FILE; 
    return modular_group_fs;
}

/* ### OLD:
FILE *WRAPPER(struct group_prams *GROUP, char *prog_NAME, char **filename) {
    char *combination_SYMBOL = combination_SYMBOL_for_(GROUP->ID);
    char *BUFFER = BUFFER_OF_SIZE(200);
    FILE *element_database = open_modular_GROUP_in_the_NAME_of_INNER(GROUP, prog_NAME, filename, combination_SYMBOL, BUFFER);
    sprintf(BUFFER, "Sourced <\u2124/%lu\u2124, %s> successfully from the filestream", GROUP->CAP, combination_SYMBOL); flush_to_LOGBOOK(prog_NAME, BUFFER); fclose(element_database);
    sprintf(BUFFER, "Closed the filestream sourced by '%s'", filename); free(filename); flush_to_LOGBOOK(prog_NAME, BUFFER); free(BUFFER);
    return element_database;
} */
