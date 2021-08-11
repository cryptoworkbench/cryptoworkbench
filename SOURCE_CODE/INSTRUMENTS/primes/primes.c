#include <stdio.h> // << Needed for "fprintf()"
#include <stdlib.h> // << Needed for "malloc()"
#include <signal.h> // << Needed for "kill()" and "SIGCONT"
#include <unistd.h> // << Needed for "exit()"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/SIGNAL.h"

unsigned long Sieve_CAP, Notice_INTERVAL, number_of_primes;
pid_t parent_PID;
char *argv_zero;

void QUIT_ON_ARGV_TWO_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as notice interval.\n", argv_ONE); exit(-1); }
void QUIT_ON_ARGV_ONE_ERROR(char *argv_ONE) { fprintf(stderr, "Failed to understand '%s' as sieve CAP.\n", argv_ONE); exit(-1); }

void CONT(int sig) {
    fprintf(stderr, "Child received CONT signal from parent.\n");
}

void FREEZE(int sig) {
    fprintf(stderr, "The child process received the signal 'SIGINT'.\n");
    fprintf(stderr, "The child process speaking: %lu primes should been printf'ed to \"STDOUT\".\n", number_of_primes);
    kill(parent_PID, SIGINT); // Make parent fflush my stdout
    pause();
    alarm(4);
}

void ALRM(int sig) {
    raise(SIGINT);
}

int main(int argc, char **argv) {
    argv_zero = argv[0];
    catch_signal(SIGALRM, ALRM); // <<< Self interrupting timer
    catch_signal(SIGINT, FREEZE); // << To receive "go-ahead" signal from parent

    parent_PID = getppid();
    fprintf(stderr, "Child: parent PID = %i.\n", parent_PID);
    // ^^ Tell them who I am (where I came from)

    if (2 > argc || !(ul_ptr_from_str(&Sieve_CAP, argv[1]))) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    if (3 > argc || !(ul_ptr_from_str(&Notice_INTERVAL, argv[2]))) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    fprintf(stderr, "Child: Sieve_CAP = %lu.\n", Sieve_CAP);
    fprintf(stderr, "Child: Notice_INTERVAL = %lu.\n", Notice_INTERVAL);
    // ^^ Get input

    alarm(4);
    char *Sieve = (char *) malloc(sizeof(char) * Sieve_CAP);
    fprintf(stderr, "Child: sieve allocated.\n");
    // ^^ Allocate sieve area in memory

    unsigned long x; for (x = 0; x < Sieve_CAP; x++) Sieve[x] = 0;
    fprintf(stderr, "Child: sieve initialized.\n");
    // ^^ Initialize sieve

    for (x = 2; x * x < Sieve_CAP; x++) for (unsigned long y = x; y * x < Sieve_CAP; y++) Sieve[y * x] = 1;
    fprintf(stderr, "Child: all composites have been sieved out.\n");
    // ^^ Sieve out composites

    number_of_primes = 0;
    fprintf(stderr, "Child process '%s' started the spitting of primes.\n", argv_zero);
    setvbuf(stdout, NULL, _IONBF, 0);
    for (x = 2; x < Sieve_CAP; x++)
    {
	if (Sieve[x] == 0) // << Spot difference
	{
	    fprintf(stdout, "%lu\n", x);
	    number_of_primes++;
	    /*
	    if (number_of_primes % Notice_INTERVAL == 0) {
		kill(parent_PID, SIGCONT); // Make parent fflush my stdout
		pause(); // Pause to wait
	    }
	    */
	}
    }
    // ^^ Print all primes to "stdout"

    fprintf(stderr, "\n'%s' printed %lu primes.\n", argv[0], number_of_primes);
    return 0;
}
