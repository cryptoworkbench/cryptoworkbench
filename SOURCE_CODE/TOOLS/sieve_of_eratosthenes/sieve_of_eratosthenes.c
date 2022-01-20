#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // needed for: definition 'EXIT_STATUS_GOODBYE', pointer 'str_represents_u()'
#include "../../libraries/mathematics/maths.h" // needed for: definition 'ADDITIVE_IDENTITY', type definition 'ul'
ul MOD; // this time we will use unsigned long 'MOD' to interpret the upper-bound to the sieve / it's limit ^^

#define ERROR_MESSAGE "I am the sieve of eratosthenes. I am the most efficient algorithm for calculating all primes under a certain limit.\n\nTell me to what limit to calculate; '%s' is not interpretable as a number / limit.\n\n\n"

void error_and_exit(char *argv_one) { int exit_status = - 1;
    fprintf(stderr, ERROR_MESSAGE, argv_one);
    fprintf(stderr, EXIT_STATUS_GOODBYE, exit_status);
    exit(exit_status);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) error_and_exit(argv[1]);
    // ^ Deal with user input

    char *sieve = (char *) malloc(sizeof(char) * (MOD - 1)); // we allocate a spot less because I do not see the number one as a prime, or perhaps because it isn't ... ... ...
    ul i; for (i = 2; i <= MOD; i++) sieve[i - 2] = 1; for (i = 2; i * i <= MOD; i++) for (ul j = i; j * i <= MOD; j++) sieve[(j * i) - 2] = 0;
    // ^^ Prepare everything for printing out all primes less than 'MOD'

    ul number_of_primes_under_MOD = ADDITIVE_IDENTITY; for (i = 2; i <= MOD; i++) if (sieve[i - 2]) { fprintf(stdout, "%lu\n", i); number_of_primes_under_MOD++; }
    // ^ Print all primes less than 'MOD' to stdout

    fprintf(stdout, "\nPrinted %lu primes.\n", number_of_primes_under_MOD); return 0;
    // ^ Terminate program like this
}
