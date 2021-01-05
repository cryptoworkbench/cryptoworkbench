#include "prime_lookup_library.h"

int _read_prime(unsigned long *prime_space_ptr, FILE *prime_table_fs, int binary_mode) {
    if (binary_mode)
	return fread(prime_space_ptr, sizeof(unsigned long), 1, prime_table_fs);
    else
	return fscanf(prime_table_fs, "%lu\n", prime_space_ptr) + 1;
}

unsigned long _prime_inner(unsigned long potential_prime, FILE *prime_table_fs, int binary_mode) {
    unsigned long RETURN_CODE = 2; // <=== Start off assuming the prime table is too short
    unsigned long current_prime;

    for (unsigned long prime_no = 1; _read_prime(&current_prime, prime_table_fs, binary_mode); prime_no++) {
	if (!(current_prime * current_prime > potential_prime)) {
	    if (potential_prime % current_prime == 0) { RETURN_CODE = 0; break; }
	    else { continue; }
	} else { RETURN_CODE = 1; break; }
    } fclose(prime_table_fs);

    return RETURN_CODE;
}

unsigned long prime(unsigned long potential_prime, char *prime_table_filename, int binary_mode) {
    FILE *prime_table_fs;
    if (!(prime_table_fs = fopen(prime_table_filename, "r")))
	return 3; // Error code 3 --> 'fprintf(stderr, "Failed to open file containing prime table.\n");'
    /* ### ^^^ ### Immediately terminate when the prime table file cannot be opened ### ^^^ ### */

    if (potential_prime == ADDITIVE_IDENTITY || potential_prime == MULTIPLICATIVE_IDENTITY) {
	fclose(prime_table_fs); // Close prime table filestream we just opened
	return 0;  //  Return value 0 --> 'fprintf(stdout, "%lu is not prime.\n", potential_prime);'
    } /* ### ^^^ ### Nor the additive, neither the multiplicative identity are prime! ### ^^^ ### */

    return _prime_inner(potential_prime, prime_table_fs, binary_mode); // "_prime_inner" automatically closes prime_table_fs
}
