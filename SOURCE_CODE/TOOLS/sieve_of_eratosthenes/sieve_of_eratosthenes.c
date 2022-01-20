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

    char *sieve = sieve_of_eratosthenes(MOD);
    fprintf(stdout, "\nPrinted %lu primes.\n", primes_printed_from_sieve_array_to_FS(sieve, MOD, stdout));
    free(sieve); return 0;
    // ^ Terminate program like this
}
