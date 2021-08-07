#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ERROR_MESSAGE "The Linux tool 'rm' does not seem to be installed on your system. This is a fatal error.\n\nReturning '-1'.\n"

int main() {
    execlp("rm", "rm", ".LOGBOOK", 0);
    // ^^ Removes "../laboratory_LOGBOOK"

    fprintf(stderr, ERROR_MESSAGE);
    return -1;
}
