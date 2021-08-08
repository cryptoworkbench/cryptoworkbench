#include <stdio.h> // << Needed for "fprintf()"
#include <stdlib.h> // << Needed for "malloc()"
#include <unistd.h> // << Needed for "exit()"
#include "../../libraries/functional/string.h"

unsigned long Sieve_CAP;

void QUIT(char *prog_NAME) {
    fprintf(stderr, "Failed to understand %s as sieve CAP.\n", prog_NAME);
    exit(-1);
}

int main(int argc, char **argv) {
    if (2 > argc || !(ul_ptr_from_str(&Sieve_CAP, argv[1]))) QUIT(argv[1]);
    // ^^ Get input

    char *Sieve = malloc(sizeof(char) * Sieve_CAP);
    // ^^ Allocate sieve area in memory

    unsigned long x; for (x = 0; x < Sieve_CAP; x++) Sieve[x] = 0;
    // ^^ Initialize sieve

    for (x = 2; x * x < Sieve_CAP; x++) for (unsigned long y = x; y * x < Sieve_CAP; y++) Sieve[y * x] = 1;
    // ^^ Mark all composites negative

    unsigned long number_of_primes = 0;
    for (x = 2; x < Sieve_CAP; x++) if (Sieve[x] == 0)
    { fprintf(stdout, "%lu\n", x); number_of_primes++; }
    // ^^ Print all primes to "stdout"

    fprintf(stdout, "\nPrinted %lu primes.\n", number_of_primes);
    return 0;
}
