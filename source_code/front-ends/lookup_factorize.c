/* Idea's:
 * Modify the prime() function so that it
 */
#include <stdio.h>
#include "../libraries/functional/string.h"
#include "../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
const char *wrong_argument_count = "Wrong number of arguments.\n";
const char *cannot_open_fs = "Could not open specified prime table file '%s' in working directory.\n\nDid you already run ../../project_code/prime_table_generator/prime_table_generator in order to generate a new prime table?\n\n\nERROR CODE '-1': Prime table cannot be opened.\n\nExiting '-2'.\n";

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, wrong_argument_count);
	return -1;
    } unsigned long potential_prime = ul_from_str(argv[1]);
    // ^ Check argument count

    if (potential_prime == ADDITIVE_IDENTITY || potential_prime == MULTIPLICATIVE_IDENTITY) {
	fprintf(stdout, "Neither the additive nor the multiplicative identity are prime!\n");
	return 2; }
    // ^ Check for silly questions

    FILE *prime_table_fs;
    if (!(prime_table_fs = fopen(argv[2], "r"))) {
	fprintf(stdout, cannot_open_fs, argv[2]);
	return -2; }
    // ^ Check a filestream to the proposed prime table can indeed be opened

    int binary_mode = 0; // Start of assuming binary_mode is off
    printf("Is %s a binary prime table? (0/1): ", argv[2]);
    fscanf(stdin, "%i", &binary_mode); if (binary_mode < 0) { binary_mode = 0; }
    // ^ Check, by asking, if the supplied prime table is binary

    unsigned long result = lookup_factorize(potential_prime, binary_mode, prime_table_fs); fclose(prime_table_fs);
    fprintf(stdout, "\nThe first divisor of %lu greater than 1 is %lu.\n\n", potential_prime, result);

    if (result < potential_prime) {
	if (result == 1) {
	    fprintf(stderr, "%s is too short to determine if %lu is prime.\n", argv[2], potential_prime);
	    return -3; // <-- Factorization failed because the prime table is too short
	} else {
	    fprintf(stdout, "%lu / %lu = %lu + 0 \u21D2 %lu \u2261 0 (mod %lu) \u21D2 %lu | %lu \u21D2 %lu \u2209 {n \u2208 \u2115 : n is prime}\n", potential_prime, result, potential_prime / result, potential_prime, result, result, potential_prime, potential_prime);
	    return 0; // <-- Successfully factorized
	}
    } else {
	fprintf(stdout, "%lu / %lu = 1 + 0 \u21D2 %lu \u2208 {n \u2208 \u2115 : n is prime}\n", result, potential_prime, potential_prime);
	return 1; // <-- Factorization failed because the number tested was prime
    } }
// ^^ Return codes:
// 2. Reminded end-user that neither the additive identity nor the multiplicative identity are prime
// 1. The number tested was prime
// 0. Successfully factorized nor 0 or 1 argument
// -1. Wrong argument count
// -2. Failed to open prime table
// -3. Factorization failed because the prime table was too short
