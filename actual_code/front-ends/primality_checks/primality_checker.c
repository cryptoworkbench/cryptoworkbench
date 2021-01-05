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
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.h" // 'prime()';

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Wrong number of arguments.\n");
	return -1;
    } unsigned long potential_prime = string_to_unsigned_long(argv[1]);

    int binary_mode = 0; // We start of assuming binary_mode is off
    printf("Is %s a binary prime table? (0/1): ", argv[2]);
    fscanf(stdin, "%i", &binary_mode); if (binary_mode < 0) { binary_mode = 0; }

    switch (prime(potential_prime, argv[2], binary_mode)) {
	case 0:
	    fprintf(stdout, "%lu is not prime.\n", potential_prime);
	    return 0;
	case 1:
	    fprintf(stdout, "%lu is prime.\n", potential_prime);
	    return 0;
	case 2:
	    fprintf(stderr, "Prime table too short!\n");
	    return -1;
	case 3:
	    fprintf(stderr, "Failed to open prime table file.\n");
	    return -1;
    }
}
