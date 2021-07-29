#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    system("rm ../LABORATORY_LOGBOOK");
    execlp("touch", "touch", "../LABORATORY_LOGBOOK");
    fprintf(stderr, "Something must have gone wrong but I do not know what.\n\nReturning '-1'.\n"); exit(-1); }
