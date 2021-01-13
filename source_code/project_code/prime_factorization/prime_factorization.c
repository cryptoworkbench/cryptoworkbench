/* DESCRIPTION:
 * modification of 'lookup_factorize()' in order to use a prime table in order to immediately factorize down to the prime factors.
 *
 * Closes and opens prime_table_fs constantly in order to start reading from the beginning again.
 *
 * I wrote this quickly but I think it is good. I believe it handles all exceptions well.
 * When the prime table is too short, when the factor set is just one prime, when the factor set is multiple primes, etc
 */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"

unsigned long prime_factorize(unsigned long presumed_composite, int binary_mode, char *name) {
    do {
	FILE *prime_table_fs;
	if ( !(prime_table_fs = fopen(name, "r"))) {
	    fprintf(stderr, "Failed to open prime table\n");
	    return -1; }
	// ^^ open prime_table_fs

	unsigned long potential_divisor;
	while (1) {
	    if (_read_prime(&potential_divisor, prime_table_fs, binary_mode)) {
		if (potential_divisor * potential_divisor > presumed_composite) {
		    fprintf(stdout, "%lu\n", presumed_composite);
		    return presumed_composite; // successfully factorized
		} else if (presumed_composite % potential_divisor == 0) {
		    do {
			fprintf(stdout,"%lu * ", potential_divisor);
			presumed_composite = presumed_composite / potential_divisor;
		    } while (presumed_composite % potential_divisor == 0);
		    fclose(prime_table_fs);
		    break; // stop reading prime table from current location and reopen to start reading from the beginning again
		}
	    } else {
		fprintf(stderr, "Prime table too short!\n");
		return 0; // prime table too short
	    }
	}
    } while (presumed_composite != 1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Wrong argument count.\n");
	return -1;
    } unsigned long factor_set = str_to_ul(argv[1]);
    unsigned long result = prime_factorize(factor_set, 1, argv[2]);

    // The following three are the only possibilities
    int ret_val;
    if (result) {
	if (result == factor_set) { ret_val = 0; }
	else { ret_val = 1; }
    } else ret_val = -2; // -1 is already reserved

    switch (ret_val) {
	case -2:
	    fprintf(stderr, "Prime table insufficient.\n");
	    break;
	case 0:
	    fprintf(stdout, "%lu is prime.\n", factor_set);
	    break;
	case 1:
	    fprintf(stdout, "%lu is composite.\n", factor_set);
    } return ret_val; }
// ^^ End main with this nice switch mechanism
