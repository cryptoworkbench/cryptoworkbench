#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../libraries/functional/ERROR.h"
#include "../../libraries/functional/SIGNAL.h"
#include "../../libraries/functional/string.h"
#define PRIMES ".primes"

FILE *OUTPUT, *Primes_STDOUT;
pid_t Child_PID;
unsigned long sieve_CAP, notice_INTERVAL, count;

void QUIT_ON_ARGV_TWO_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as notice interval.\n", argv_ONE); exit(-1); }
void QUIT_ON_ARGV_ONE_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as sieve CAP.\n", argv_ONE); exit(-1); }

void FLUSH(int sig) {
    fflush(OUTPUT);
    fprintf(stdout, "Parent process flush filestream: currently %lu primes should be at their destination file.\n", count);
    /*
    fclose(OUTPUT);
    OUTPUT = fopen("prime_table", "a");
    fprintf(stdout, "Reopened output FS.\n");
    */

    kill(Child_PID, SIGCONT);
    // ^^ Continue child process again
}

int main(int argc, char **argv) { catch_signal(SIGINT, FLUSH); char *output_PATH = "table";
    if (2 > argc || !(ul_ptr_from_str(&sieve_CAP, argv[1]))) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    if (3 > argc || !(ul_ptr_from_str(&notice_INTERVAL, argv[2]))) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    // ^^ Interpret "sieve_CAP" and "notice_INTERVAL"

    int fd[2]; if (pipe(fd) == -1) pipe_error_QUIT(); // << Pipe
    Child_PID = fork(); if (Child_PID == -1) fork_error_QUIT(); // << Fork
    // ^^ Quit if we can

    if (!Child_PID) { dup2(fd[1], 1); close(fd[0]); execlp(PRIMES, PRIMES, argv[1], argv[2], NULL); } // << Happens in the child
    else close(fd[1]); // << Close write end at the parent

    Primes_STDOUT = fdopen(fd[0], "r");
    setvbuf(Primes_STDOUT, NULL, _IONBF, 0);
    OUTPUT = fopen("prime_table", "w");
    // ^^ Open filestreams

    unsigned long element; count = 0;
    while (fscanf(Primes_STDOUT, "%lu\n", &element) == 1) { count++;
	fprintf(OUTPUT, "%lu\n", element);
	// fprintf(stdout, "%lu\n", element);
    }
    // ^^ Interpret from child process and fprintf to "prime_table"

    fprintf(stdout, "Parent process wrote %lu elements to %s.\n\n", count, output_PATH);
    // ^^ Summarize

    fprintf(stdout, "\nWaiting for PID '%i' (which is an instance of the executable '" PRIMES "' I am running as child process) to die.\n", Child_PID);
    int RAW_exit_status; waitpid(Child_PID, &RAW_exit_status, 0); int exit_status = WEXITSTATUS(RAW_exit_status);
    fprintf(stdout, "\nCHILD PROCESS EXIT STATUS: '%i'.\n", exit_status);
    // ^^ Wait for child process to die

    return 0;
}
