#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int skip = 1;

    // ### NOW BEGINS THE MAGIC
    pid_t pid = fork();
    if (pid == -1) {
	fprintf(stderr, "Failed to fork process: %s\n", strerror(errno));
	return -1; }
    else if (!pid) {
	if(execvp(*(argv + skip), argv + skip))
	    fprintf(stderr, "Failed to find %s\n", *(argv + skip)); }

    fprintf(stdout, "This is the parent process speaking.\n");
    char *NAME = (char *) malloc(sizeof(char) * 200);
    fprintf(stdout, "Please tell me your name: ");
    fscanf(stdin, "%s", NAME);
    fprintf(stdout, "Did I understand correctly that your name was \"%s\"?\n", NAME);
    free(NAME);
    fprintf(stdout, "Reached the end of program. Quiting.\n");
    return 0;
}
