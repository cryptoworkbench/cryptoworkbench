#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // needed for: definition 'EXIT_STATUS_GOODBYE', pointer 'str_represents_u()'
#include "../../libraries/mathematics/maths.h" // needed for: definition 'ADDITIVE_IDENTITY', type definition 'ul'
#define ERROR_MESSAGE "I am the sieve of eratosthenes. I am the most efficient algorithm for calculating all primes under a certain limit.\n\nTell me to what limit to calculate; '%s' is not interpretable as a number / limit.\n\n\n"

void error_and_exit(char *argv_one) { int exit_status = - 1;
    fprintf(stderr, ERROR_MESSAGE, argv_one);
    fprintf(stderr, EXIT_STATUS_GOODBYE, exit_status);
    exit(exit_status);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], MOD_LOCATION_REPORT())) error_and_exit(argv[1]); char *output_filename = REPORT_standard_prime_table_filename();
    if (2 < argc) output_filename = argv[2];
    // ^ Deal with user input

    FILE *FS_to_external_prime_table = fopen(output_filename, "w"); // overwritten if already exists: outputting to the same output file again with a lesser 'MOD' shrinks the prime table
    fprintf(stdout, "Exported %lu primes to external file '%s' (which is all primes less than %lu).\n", primes_printed_from_sieve_array_to_FS(sieve_of_eratosthenes(MOD_REPORT()), MOD_REPORT(), FS_to_external_prime_table), output_filename, MOD_REPORT()); fclose(FS_to_external_prime_table); return 0;
}
