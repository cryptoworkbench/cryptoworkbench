#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/ERROR.h"
#define PRIMES ".primes"

FILE *GENERATED_PRIME_TABLE, STDOUT_from_PRIMES;
unsigned long sieve_CAP, notice_INTERVAL;
int fds[2]; // << We are goin to create a pipe

unsigned long verbose(FILE *INPUT, FILE *OUTPUT) {
    unsigned long element; unsigned long count = 0;
    while (fscanf(INPUT, "%lu\n", &element) == 1)
    { fprintf(OUTPUT, "%lu\n", element); count++; }

    return count;
} // <^^ Simple version

unsigned long explicit(FILE *INPUT, FILE *OUTPUT, unsigned long notice_INTERVAL, char *output_PATH) {
    unsigned long element; unsigned long count = 0;
    while (fscanf(INPUT, "%lu\n", &element) == 1) { fprintf(OUTPUT, "%lu\n", element); count++;
	if (count % notice_INTERVAL == 0) fprintf(stdout, "Printed %i prime to '%s'\n", notice_INTERVAL, output_PATH); }
    return count;
} // <^^ Complex (explicit) version

unsigned long count(int argc, unsigned long notice_interval, char *output_PATH) {
    FILE *CHILD_STDOUT = fdopen(fds[0], "r");
    FILE *PRIME_TABLE_FS = fopen(output_PATH, "w");
    // ^^ Make these

    unsigned long return_value;
    if (argc == 2) return_value = verbose(CHILD_STDOUT, PRIME_TABLE_FS);
    else return_value = explicit(CHILD_STDOUT, PRIME_TABLE_FS, notice_INTERVAL, output_PATH);
    close(fds[0]);
    // ^^ Calculate return value

    fclose(PRIME_TABLE_FS);
    return return_value;
}

void QUIT_ON_ARGV_TWO_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as notice interval.\n", argv_ONE); exit(-1); }
void QUIT_ON_ARGV_ONE_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as sieve CAP.\n", argv_ONE); exit(-1); }

/* INFLECTION POINT */

int main(int argc, char **argv) { char *output_PATH = "table";
    if (2 > argc || !(ul_ptr_from_str(&sieve_CAP, argv[1]))) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    if (2 < argc && (ul_ptr_from_str(&notice_INTERVAL, argv[2])) == NULL) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    if (pipe(fds) == -1) pipe_error_QUIT();
    // ^^^ Quit if we can

    pid_t primes_PID = fork(); if (primes_PID == -1) fork_error_QUIT();
    // ^^^ Only then we should "fork();"

    if (!primes_PID) { dup2(fds[1], 1); close(fds[0]); execlp(PRIMES, PRIMES, argv[1], NULL); } // << Happens in the child
    else close(fds[1]); // << Close write end at the parent

    int amount = count(argc, notice_INTERVAL, output_PATH);
    fprintf(stdout, "Wrote %lu elements to %s.\n\n", amount, output_PATH);
    // ^^^ Finalize

    fprintf(stdout, "\nWaiting for PID '%i' (which is an instance of the executable '" PRIMES "' I am running as child process) to die.\n", primes_PID);
    int RAW_exit_status; waitpid(primes_PID, &RAW_exit_status, 0); int exit_status = WEXITSTATUS(RAW_exit_status);
    fprintf(stdout, "\nChild process exit status: '%i'.\n", exit_status);
    // ^^^ Wait for child process to die

    return 0;
}
