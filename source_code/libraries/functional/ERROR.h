#include <stdio.h> // <<< Needed for "fprintf()"
#include <stdlib.h> // <<< Needed for "exit()"

#define FORK_ERROR "Failed to fork."
#define PIPE_ERROR "Failed to pipe."

void fork_error_QUIT();
void pipe_error_QUIT();
