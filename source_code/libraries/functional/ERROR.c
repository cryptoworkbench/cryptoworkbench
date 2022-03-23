#include "ERROR.h"

void fork_error_QUIT() {
    fprintf(stderr, FORK_ERROR);
    exit(-10);
}

void pipe_error_QUIT() {
    fprintf(stderr, PIPE_ERROR);
    exit(-11);
}
