/* Most efficient prime table lookup primality check mathemematically possible.
 *
 * The greatest number I am guarenteed to be able to inform you of wether is prime or not is the greatest prime in the prime table squared, but this number could obviously never be prime,
 * thus the largest prime that I can affirm for you is prime is the greatest prime that is in the prime table.
 * All numbers in between must be composite or else I would have determined they are composite by their first prime factor in the prime table.
 *
 * You can use the handy dany tool first_prime_greater than to confirm this behaviour.
 *
 * The first step would be to square the greatest prime in your prime lookup table.
 */
#include <stdio.h>
#include <stdlib.h> // 'fopen()', 'fclose()'
#include "../libraries/functional/string.h"
#include "../libraries/mathematics/maths.h"

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Wrong number of arguments.\n");
	return -1;
    } unsigned long potential_prime = string_to_unsigned_long(argv[1]);

    int binary_mode = 0; // We start of assuming binary_mode is off
    printf("Is %s a binary prime table? (0/1): ", argv[2]);
    fscanf(stdin, "%i", &binary_mode); if (binary_mode < 0) { binary_mode = 0; }

    FILE *prime_table_fs;
    if (!(prime_table_fs = fopen(argv[2], "r"))) {
	fprintf(stderr, "Error\n");
	return -2; }

    if (prime(potential_prime, binary_mode, prime_table_fs))
	fprintf(stdout, "%lu is prime.\n", potential_prime);
    else {
	fprintf(stdout, "%lu is not prime.\n", potential_prime);
    } fclose(prime_table_fs);

    return 0;
}
