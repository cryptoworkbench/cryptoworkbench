#include <stdio.h>
#include "logbook_functions.h"
#define LOGBOOK_NAME "laboratory_logbook"

FILE *open_logbook() {
    FILE *logbook_fs = fopen(LOGBOOK_NAME, "a");
    return logbook_fs;
}

void close_logbook(FILE *logbook_fs) {
    fclose(logbook_fs);
}
