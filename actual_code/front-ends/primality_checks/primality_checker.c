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
#include "../../../libraries/mathematics/primality_checkers/prime_lookup_library.h" // 'prime()';
#include "../../../libraries/functional/string.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "Wrong number of arguments.\n");
	return -1;
    } fprintf(stdout, "Hello, I'm %s, I check for primality using a prime table in order to lookup potential prime divisors quickly.\n\n", argv[0]);

    unsigned long potential_prime;
    fprintf(stdout, "Please tell me what number to check for primality: ");
    fscanf(stdin, "%lu", &potential_prime); fprintf(stdout, "\n");

    int binary_mode = 0; // We start of assuming binary_mode is off
    fprintf(stdout, "Did you supply me with a binary prime table? (0/1): ");
    fscanf(stdin, "%i", &binary_mode); if (binary_mode < 0) { binary_mode = 0; }

    switch (prime(potential_prime, argv[1], binary_mode)) {
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
