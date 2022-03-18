#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // contains: function 'str_represents_u()', definition 'EXIT_STATUS_GOODBYE'
#include "../../libraries/mathematics/math.basic.h" // contains: function 'sieve_of_eratosthenes()', 'primes_printed_from_sieve_array_to_FS()', TYPE definition (typedef) 'ul', definition 'ADDITIVE_IDENTITY', 'extern ul mod'
#define ERROR_MESSAGE "I am the sieve of eratosthenes. I am the most efficient algorithm for calculating all primes under a certain limit.\n\nTell me to what limit to calculate; '%s' is not interpretable as a number / limit.\n\n\n"

unsigned long limit;
// global variable declarations ^

void limit_failed_to_parse() { fprintf(stderr, "Failed to understand '%s' as the limit for the sieve function.", (*argv_ptr)[1]); }
// '_failed_to_parse' functions ^

int main(int argc, char **argv) { limit = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(limit_failed_to_parse, n(ul_parse_str(&limit, argv[1], -1))))));
    fprintf(stdout, "\nPrinted %lu primes.\n", primes_printed_from_sieve_array_to_FS(sieve_of_eratosthenes(limit), limit, stdout));
    return 0;
}
