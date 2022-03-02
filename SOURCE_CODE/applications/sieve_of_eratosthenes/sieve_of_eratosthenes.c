#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // contains: function 'str_represents_u()', definition 'EXIT_STATUS_GOODBYE'
#include "../../libraries/mathematics/maths.h" // contains: function 'sieve_of_eratosthenes()', 'primes_printed_from_sieve_array_to_FS()', TYPE definition (typedef) 'ul', definition 'ADDITIVE_IDENTITY', 'extern ul mod'

#define ERROR_MESSAGE "I am the sieve of eratosthenes. I am the most efficient algorithm for calculating all primes under a certain limit.\n\nTell me to what limit to calculate; '%s' is not interpretable as a number / limit.\n\n\n"

void error_and_exit(char *argv_one) { int exit_status = - 1;
    fprintf(stderr, ERROR_MESSAGE, argv_one);
    fprintf(stderr, EXIT_STATUS_GOODBYE, exit_status);
    exit(exit_status);
}

void limit_failed_to_parse() {
    fprintf(stderr, "Failed to understand '%s' as the limit for the sieve function.", unparsed_arg);
}

int main(int argc, char **argv) { unparsed_arg = argv[1];
    unsigned long limit; conditional_goodbye(n(n(error_specification(limit_failed_to_parse, n(ul_parse_str(argv[1], &limit, -1))))));
    fprintf(stdout, "\nPrinted %lu primes.\n", primes_printed_from_sieve_array_to_FS(sieve_of_eratosthenes(limit), limit, stdout));
    return 0;
}
