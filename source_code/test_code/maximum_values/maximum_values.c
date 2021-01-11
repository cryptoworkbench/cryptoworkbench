#include <stdio.h>
#include <limits.h>
#include "../../../libraries/functional/string.h"

int main(int argc, char *argv[]) {
    fprintf(stdout, "Number of bytes a max occupies: %lu\n", sizeof(long));
    fprintf(stdout, "LONG_MAX: %li\n", LONG_MAX);
    fprintf(stdout, "And this takes %lu characters.\n", char_in_val(LONG_MAX));
    fprintf(stdout, "Seems reasonable.\n");
    return 0;
}
