#include <stdio.h>

int main(int argc, char **argv) {
    int STDOUT = fileno(stdout);
    int STDERR = fileno(stderr);
    FILE *main_fs = stdout;
    int _STDOUT = fileno(main_fs);
    FILE *main_err = stderr;
    int _STDERR = fileno(main_err);
    FILE *FILE_LOL = fopen("lol", "r");
    int _FILE_LOL = fileno(FILE_LOL);

    fprintf(stdout, "This is the index of fs stdout: %i\n", STDOUT);
    fprintf(stdout, "And this is the index of fs stderr: %i\n", STDERR);
    fprintf(stdout, "And this is the index of main_fs: %i\n", _STDOUT);
    fprintf(stdout, "And this is the index of main_err: %i\n", _STDERR);
    fprintf(stdout, "And this is the index of FILE_LOL: %i\n", _FILE_LOL);
    return 0;
}
