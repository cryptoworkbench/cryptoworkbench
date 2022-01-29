#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // contains: function 'str_represents_u()', definition 'EXIT_STATUS_GOODBYE'
#include "../../libraries/mathematics/maths.h" // contains: function 'sieve_of_eratosthenes()', 'primes_printed_from_sieve_array_to_FS()', TYPE definition (typedef) 'ul', definition 'ADDITIVE_IDENTITY', 'extern ul mod'
ul mod; // this time we will use unsigned long 'mod' to interpret the upper-bound to the sieve / it's limit ^^

#define ERROR_MESSAGE "I am the sieve of eratosthenes. I am the most efficient algorithm for calculating all primes under a certain limit.\n\nTell me to what limit to calculate; '%s' is not interpretable as a number / limit.\n\n\n"

void error_and_exit(char *argv_one) { int exit_status = - 1;
    fprintf(stderr, ERROR_MESSAGE, argv_one);
    fprintf(stderr, EXIT_STATUS_GOODBYE, exit_status);
    exit(exit_status);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &mod)) error_and_exit(argv[1]);
    fprintf(stdout, "\nPrinted %lu primes.\n", primes_printed_from_sieve_array_to_FS(sieve_of_eratosthenes(mod), mod, stdout));
    return 0;
}
