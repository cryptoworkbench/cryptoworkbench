// exports a prime table
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/maths.basic.h"

unsigned long limit;

void limit_error() { fprintf(stderr, "Failed to understand '%s' as the limit to my sieve.", (*argv_ptr)[1]); }

int main(int argc, char **argv) { limit = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(limit_error, n(_ul_parse_str(&limit, argv[1], -1))))));
    char *output_filename = _REPORT_standard_prime_table_filename(); if (2 < argc) output_filename = argv[2];
    // process terminal arguments ^

    FILE *FS_to_external_prime_table = fopen(output_filename, "w"); fprintf(stdout, "Exported %lu primes to external file '%s' (which is all primes less than %lu).\n", primes_printed_from_sieve_array_to_FS(sieve_of_eratosthenes(limit), limit, FS_to_external_prime_table), output_filename, limit); fclose(FS_to_external_prime_table); return 0;
    // prime table will be overwritten if it already exists, with other words: outputting to the same output file again with a lesser 'limit' shrinks the prime table ^^
}
