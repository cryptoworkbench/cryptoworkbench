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
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process"
#define GROUP_EXPORTER "group_exporter"
#define FILENAME_BODY "_group_of_integers_mod_"

char *symbol_to_use(unsigned long ID) {
    return (ID == 0) ? "+" : "*";
}

char *adjective_to_use(unsigned long ID) {
    return (ID == 0) ? "additive" : "multiplicative";
}

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value;
}

void flush_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line) {
    FILE *logbook_fs; if (logbook_fs = fopen(LOGBOOK_PATH, "a")) {
	fprintf(logbook_fs, LOGBOOK_FORMULA "%s\n", prog_NAME, TO_BE_APPENDED_logbook_line); fclose(logbook_fs);
    }

    else {
	fprintf(stderr, "%s will abort now because it failed to append to the logbook the following line:\n", prog_NAME);
	fprintf(stderr, "\"%s\"\n\n", TO_BE_APPENDED_logbook_line);
	fprintf(stderr, "Now I am going to exit with error code '-10' \u2261 246 (mod 2^8). Presumably you can check with 'echo $?'.\n");
	exit(-10);
    }
}

FILE *open_group_as_(char *prog_NAME, struct group_prams *group, char **path_to_filename_INSERTMENT_SLOTH, char **group_CAP_INSERTMENT_SLOTH) {
    *group_CAP_INSERTMENT_SLOTH = str_from_ul(group->CAP, 0);
    char *group_ID = str_from_ul(group->ID, 0);
    char *adjective = adjective_to_use(group->ID);
    char *symbol = symbol_to_use(group->ID);
    char *BUFFER = BUFFER_OF_SIZE(200);
    // ^^ Prepare the char pointers "open_group_as_INNER()" needs

    FILE *opened_group = open_group_as_INNER(prog_NAME, path_to_filename_INSERTMENT_SLOTH, *group_CAP_INSERTMENT_SLOTH, group_ID, adjective, symbol, BUFFER);
    return opened_group;
}

FILE *open_group_as_INNER(char *prog_NAME, char **path_to_filename_INSERTMENT_SLOTH, char *group_CAP, char *group_ID, char *adjective, char *symbol, char *BUFFER) {
    char *name_of_FILE = (char *) malloc(sizeof(char) * (str_len(adjective) + str_len(FILENAME_BODY) + str_len(group_CAP) + 1));
    sprintf(name_of_FILE, "%s%s%s", adjective, FILENAME_BODY, group_CAP);
    // ^^ Prepare the filename

    char *path_to_FILE = (char *) malloc(sizeof(char) * (str_len(REGISTRY_PATH) + str_len(name_of_FILE) + 1));
    sprintf(path_to_FILE, REGISTRY_PATH "%s", name_of_FILE);
    // ^^ Prepare the path

    // ### Begin program operation ===>
    FILE *modular_group_fs = NULL; if (!(modular_group_fs = fopen(path_to_FILE, "r"))) { // << If the file does not exist
	sprintf(BUFFER, "ERROR: no such file '%s' \u21D2 <\u2124/%s\u2124, %s> does not seem to have been exported before", path_to_FILE, group_CAP, symbol);
	flush_to_LOGBOOK(prog_NAME, BUFFER);
	// ^^ Complain

	sprintf(BUFFER, "Using the external tool '"GROUP_EXPORTER"' to export <\u2124/%s\u2124, %s>", group_CAP, symbol);
	flush_to_LOGBOOK(prog_NAME, BUFFER);
	// ^^ Notify we are going to use group_examplifier

	sprintf(BUFFER, "%s running " GROUP_EXPORTER, prog_NAME); // << Use BUFFER in order to send along a special "argv[0]" to "group_examplifier"
	char *GROUP_EXPORTER_argv[] = {BUFFER, group_CAP, group_ID, 0};
	// ^^ Prepare a special "argv[0]" for "group_examplifier"

	pid_t group_exporter = fork(); if (group_exporter == -1) { sprintf(BUFFER, FORK_ERROR); flush_to_LOGBOOK(prog_NAME, BUFFER); exit(-10); }
	// ^^ Fork

	if (!group_exporter) { // << If we managed to fork
	    FILE *NEEDED_FILE = fopen(path_to_FILE, "w"); // <<< Create the file which did not yet exist
	    if (dup2(fileno(NEEDED_FILE), 1) == -1) { fprintf(stderr, FILE_DESCRIPTOR_ERROR); exit(-10); } // <<< Error when the filestream would not duplicate
	    execvp(GROUP_EXPORTER, GROUP_EXPORTER_argv); // <<< If all is well and fine, have the child process be "group_exporter" in order to export the group
	}

	int GROUP_EXPORTER_exit_status_RAW;
	waitpid(group_exporter, &GROUP_EXPORTER_exit_status_RAW, 0); free(group_ID);
	// ^^ Wait for the child process to finish

	int GROUP_EXPORTER_exit_status = WEXITSTATUS(GROUP_EXPORTER_exit_status_RAW);
	if (GROUP_EXPORTER_exit_status && (modular_group_fs = fopen(path_to_FILE, "r"))) {
	    sprintf(BUFFER, GROUP_EXPORTER " returned an exit status of '%i' \u21D2 <\u2124/%s\u2124, %s> should be registered now", GROUP_EXPORTER_exit_status, group_CAP, symbol);
	    flush_to_LOGBOOK(prog_NAME, BUFFER); }
	else {
	    sprintf(BUFFER, "FATAL ERROR: failed to create the required registry file using '"GROUP_EXPORTER"'");
	    flush_to_LOGBOOK(prog_NAME, BUFFER);
	    exit(0); }
    } if (modular_group_fs != NULL) sprintf(BUFFER, "Successfully secured a filestream sourced by '%s'", path_to_FILE); flush_to_LOGBOOK(prog_NAME, BUFFER);
    free(BUFFER); *path_to_filename_INSERTMENT_SLOTH = path_to_FILE; 
    return modular_group_fs;
}

void close_group(char *prog_NAME, char *group_CAP, char *symbol_to_use, char *path_to_filename, FILE *opened_group) { char *BUFFER = BUFFER_OF_SIZE(200);
    sprintf(BUFFER, "Successfully sourced <\u2115/%s\u2115, %s> from '%s'", group_CAP, symbol_to_use, path_to_filename); flush_to_LOGBOOK(prog_NAME, BUFFER); fclose(opened_group);
    sprintf(BUFFER, "Closed the filestream sourced by '%s'", path_to_filename); free(path_to_filename); flush_to_LOGBOOK(prog_NAME, BUFFER); free(BUFFER);
}
