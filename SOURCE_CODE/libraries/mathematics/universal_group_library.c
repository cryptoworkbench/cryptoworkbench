// See dev note at line 28. That is the only issue.
#include "universal_group_library.h"

enum GROUP_IDentity *STR_could_be_parsed_into_enum_GROUP_IDentity(char *STR, enum GROUP_IDentity *ID) {
    if (match(STR, additive_signs)) { *ID = ADDITIVE; return ID; }
    else if (match(STR, multiplicative_signs)) { *ID = MULTIPLICATIVE; return ID; }
    else return NULL;
}

const char *numerical_denomination_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? additive_signs[0] : multiplicative_signs[0]; }
const char *operation_symbol_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? additive_signs[1] : multiplicative_signs[1]; }
const char *noun_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? additive_signs[2] : multiplicative_signs[2]; }
const char *multiple_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? additive_signs[3] : multiplicative_signs[3]; }
const char *adjective_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? additive_signs[4] : multiplicative_signs[4]; }
int boolean_from_ID_Sloth(group_OBJ group) { return (group->ID == ADDITIVE) ? 0 : 1; }

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value;
}

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line) {
    fprintf(logbook_fs, LOGBOOK_FORMULA "%s\n", argv_ZERO, TO_BE_APPENDED_logbook_line);
    fflush(logbook_fs);
}

void open_and_append_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line) {
    if ( !(logbook_fs = fopen(LOGBOOK_PATH, "a"))) { fprintf(stderr, "Failed to open logbook!\n"); exit(-10); }
    fprintf(logbook_fs, LOGBOOK_FORMULA "%s\n", prog_NAME, TO_BE_APPENDED_logbook_line); fflush(logbook_fs);
}

FILE *open_group(char *prog_NAME, group_OBJ group, char *MOD) {
    argv_ZERO = prog_NAME;
    // ^^ Set the gobal variable "argv_ZERO" based on what was passed on to this function as "argv[0]"

    if ( !(logbook_fs = fopen(LOGBOOK_PATH, "a"))) { fprintf(stderr, "Failed to open logbook!\n"); exit(-10); }
    // ^^ Exit when the logbook won't open

    const char *group_ID = numerical_denomination_from_ID_Sloth(group);
    const char *adjective = adjective_from_ID_Sloth(group);
    const char *operation_symbol = operation_symbol_from_ID_Sloth(group);
    // ^^ Prepare the char pointers "open_group_as_INNER()" needs

    FILE *opened_group = open_group_INNER(MOD, group_ID, adjective, operation_symbol, BUFFER_OF_SIZE(200));
    return opened_group;
}

FILE *open_group_INNER(char *group_MOD, const char *numerical_denomination, const char *adjective, const char *symbol, char *LINE) {
    char *name_of_FILE = (char *) malloc(sizeof(char) * (str_len(adjective) + str_len(FILENAME_BODY) + str_len(group_MOD) + 1));
    sprintf(name_of_FILE, "%s%s%s", adjective, FILENAME_BODY, group_MOD);
    // ^^ Prepare the filename

    path_to_FILE = (char *) malloc(sizeof(char) * (str_len(ARCHIVE_FOLDER) + str_len(name_of_FILE) + 1));
    sprintf(path_to_FILE, ARCHIVE_FOLDER "%s", name_of_FILE);
    // ^^ Prepare the path

    // ### Begin program operation ===>
    FILE *group_fs = NULL; if (!(group_fs = fopen(path_to_FILE, "r"))) { // << If the file does not exist
	sprintf(LINE, "Could not to open '%s'", path_to_FILE); append_to_LOGBOOK(LINE);
	// ^^ Explain that the needed file does not exist 

	sprintf(LINE, "Assuming the 'ARCHIVE/' folder was there and it wasn't a permission thing, I will try to use '"ELEMENT_EXPORTER"' to autonomously archive \u2115%s%s", group_MOD, symbol); append_to_LOGBOOK(LINE);

	sprintf(LINE, "%s using " ELEMENT_EXPORTER, argv_ZERO); // << Use LINE in order to send along a special "argv[0]" to "group_exporter"
	char *ELEMENT_EXPORTER_argv[] = {LINE, group_MOD, (char *) numerical_denomination, 0};
	// ^^ Prepare the char pointer array "group_exporter" will receive as "char *argv[]" (a.k.a. "char **argv")

	int fd[2]; if (pipe(fd) == -1) { fprintf(stderr, "Failed to open pipe.\n"); exit(-1); }
	// ^^ Open pipe

	pid_t group_exporter_PID = fork(); if (group_exporter_PID == -1) { sprintf(LINE, FORK_ERROR); append_to_LOGBOOK(LINE); exit(-10); }
	// ^^ Fork

	if (!group_exporter_PID) { dup2(fd[1], 1); close(fd[0]);
	    execvp(ELEMENT_EXPORTER, ELEMENT_EXPORTER_argv); }
	// ^^ Execute "group_exporter" with it's "STDOUT" directed to the write end of the pipe (namely "fd[1]")

	FILE *group_exporter_STDOUT = fdopen(fd[0], "r");
	// ^^ Fix a new file descriptor

	FILE *NEEDED_FILE = fopen(path_to_FILE, "w"); // << Create a filestream for the file we are about to create
	unsigned long element; while (fscanf(group_exporter_STDOUT, "%lu\n", &element) == 1) fprintf(NEEDED_FILE, "%lu\n", element); fclose(NEEDED_FILE);
	// ^^ Extract elements from "group_exporter" output and "fprintf()" them into an empty file with the appropiate name

	int ELEMENT_EXPORTER_exit_status_RAW;
	waitpid(group_exporter_PID, &ELEMENT_EXPORTER_exit_status_RAW, 0);
	// ^^ Wait for the child process to finish

	int ELEMENT_EXPORTER_exit_status = WEXITSTATUS(ELEMENT_EXPORTER_exit_status_RAW);
	if (ELEMENT_EXPORTER_exit_status && (group_fs = fopen(path_to_FILE, "r"))) {
	    sprintf(LINE, ELEMENT_EXPORTER " returned an exit status of '%i' \u21D2 \u2115%s%s should be registered now", ELEMENT_EXPORTER_exit_status, group_MOD, symbol);
	    append_to_LOGBOOK(LINE); }
	else {
	    sprintf(LINE, "FATAL ERROR: failed to create the required registry file using '"ELEMENT_EXPORTER"'");
	    append_to_LOGBOOK(LINE); exit(0); }
    } if (group_fs != NULL) sprintf(LINE, "Successfully opened '%s'", path_to_FILE); append_to_LOGBOOK(LINE);
    free(LINE);
    return group_fs;
}

void close_group(char *group_CAP, char *symbol_to_use, FILE *opened_group) { char *BUFFER = BUFFER_OF_SIZE(200);
    sprintf(BUFFER, "Sourced \u2115%s%s from '%s'", group_CAP, symbol_to_use, path_to_FILE); append_to_LOGBOOK(BUFFER); fclose(opened_group);
    sprintf(BUFFER, "Closed '%s'", path_to_FILE); free(path_to_FILE); append_to_LOGBOOK(BUFFER); free(BUFFER); close_logbook();
}

void close_logbook() {
    fclose(logbook_fs);
}
