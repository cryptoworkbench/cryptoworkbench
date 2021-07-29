#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "../../libraries/functional/LOGBOOK_library.h" // << Needed for the definition of "struct group_prams"
const char *SPECIFICATION_OF_FILES_TO_DELETE = "../registry/*";
const char *SPECIFICATION_OF_DELETER = "rm";

int main(char **argv) {
    pid_t pid = fork();
    // ^^ Try to fork parent process

    if (pid == -1) { fprintf(stderr, "COULD NOT FORK PROCESS.\n\nNow I am going to exit with error code '-1' \u2261 255 (mod 2^8). Presumably you can check with 'echo $?'.\n"); exit(-1); }
    // ^^^ If the parent process could not be forked into a parent process and a future child process; quit and may print to STDERR before

    else if (!pid) { char *BUFFER = BUFFER_OF_SIZE(200);
	if (execlp(SPECIFICATION_OF_DELETER, SPECIFICATION_OF_DELETER, SPECIFICATION_OF_FILES_TO_DELETE, NULL) == -1)
	{ sprintf(BUFFER, "Failed to send '%s %s' to the operating system.", SPECIFICATION_OF_DELETER, SPECIFICATION_OF_FILES_TO_DELETE); FLUSH_TO_FS(argv[0], BUFFER); }

	else
	{
	    sprintf(BUFFER, "'%s %s' has been send to the operating system.", SPECIFICATION_OF_DELETER, SPECIFICATION_OF_FILES_TO_DELETE); FLUSH_TO_FS(argv[0], BUFFER);
	} free(BUFFER); }
    // ^^^ Try to use the child process to delete all of the files in the registry/ folder using "rm ../registry/*"

    return 0; }
// ^^^ And that was all
