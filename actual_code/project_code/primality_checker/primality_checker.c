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
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

unsigned long prime_inner(unsigned long potential_prime, FILE *prime_table_fs, int binary_mode) {
    unsigned long current_prime;

    if (binary_mode) {
	for (unsigned long prime_no = 1; fread(&current_prime, sizeof(unsigned long), 1, prime_table_fs); prime_no++) {
	     if (!(current_prime * current_prime > potential_prime)) {
		 fprintf(stdout, "Is E(P, %lu), namely %lu, a prime factor of %lu?\nDoes %lu divide %lu? ", prime_no, current_prime, potential_prime, current_prime, potential_prime);
		 if (potential_prime % current_prime == 0) {
		    fprintf(stdout, "\n\nYes it does;\n%lu / %lu = %lu + %lu \u21D2 %lu | %lu \u21D2 %lu is composite \u21D2 ", potential_prime, current_prime, potential_prime / current_prime, potential_prime % current_prime, current_prime, potential_prime, potential_prime);
		    return 0; // Composite
		 } else {
		     fprintf(stdout, "No.\n\n");
		     continue; // current_prime does not divide potential_prime, update current_prime
		 }
	     } else {
		 fprintf(stdout, "Noticed prime #%lu is actually greater than the root of the number we are testing for primality:\n%lu * %lu = %lu ---> %lu^2 > %lu", prime_no, current_prime, current_prime, current_prime * current_prime, current_prime, potential_prime, potential_prime);
		 return 1;
	     }
	}
    } else {
	for (unsigned long prime_no = 1; fscanf(prime_table_fs, "%lu\n", &current_prime) + MULTIPLICATIVE_IDENTITY; prime_no++) {
	     if (!(current_prime * current_prime > potential_prime)) {
		 fprintf(stdout, "Is E(P, %lu), namely %lu, a prime factor of %lu?\nDoes %lu divide %lu? ", prime_no, current_prime, potential_prime, current_prime, potential_prime);
		 if (potential_prime % current_prime == 0) {
		    fprintf(stdout, "\n\nYes it does;\n%lu / %lu = %lu + %lu \u21D2 %lu | %lu \u21D2 %lu is composite \u21D2 ", potential_prime, current_prime, potential_prime / current_prime, potential_prime % current_prime, current_prime, potential_prime, potential_prime);
		    return 0; // Composite
		 } else {
		     fprintf(stdout, "No.\n\n");
		     continue; // current_prime does not divide potential_prime, update current_prime
		 }
	     } else {
		 fprintf(stdout, "Noticed prime #%lu is actually greater than the root of the number we are testing for primality:\n%lu * %lu = %lu \u21D2 %lu^2 > %lu", prime_no, current_prime, current_prime, current_prime * current_prime, current_prime, potential_prime, potential_prime);
		 return 1;
	     }
	}
    } return 2;
}

unsigned long prime(unsigned long potential_prime, char *prime_table_filename, int binary_mode) {
    if (potential_prime == ADDITIVE_IDENTITY || potential_prime == MULTIPLICATIVE_IDENTITY)
	return 0; // Nor the additive, neither the multiplicative identity are prime.

    fprintf(stdout, "In order to talk about this in a mathematical manner, I define the following function:\n");
    fprintf(stdout, "E(P, i) = prime number i for some i in N (N as in N the infinite set including all natural numbers, but excluding 0).\n\n");
    fprintf(stdout, "For example;\nE(P, 1) = 2\nE(P, 2) = 3\nE(P, 3) = 5\nEtcetera, you get the idea . . .\n\n");
    fprintf(stdout, "P.s. I'm checking for primality with %s.\n\n\n", prime_table_filename);
    fprintf(stdout, "The following question(s) need to be asked:\n");
    FILE *prime_table_fs;
    if (!(prime_table_fs = fopen(prime_table_filename, "r")))
	return 3; // Error code 3 --> 'printf("Failed to open file containing prime table.\n"); return -1;'

    unsigned long ret_val = prime_inner(potential_prime, prime_table_fs, binary_mode); fclose(prime_table_fs);
    return ret_val;
}

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

    system("clear");
    unsigned long ret_val = prime(potential_prime, argv[1], binary_mode);
    switch (ret_val) {
	case 0:
	    fprintf(stdout, "%lu is not prime.\n", potential_prime);
	    break;
	case 1:
	    fprintf(stdout, "\n\n%lu must be prime or we would have found a factor already.\n", potential_prime);
	    break;
	case 2:
	    fprintf(stderr, "Prime table too short!\n");
	    return -1;
	case 3:
	    fprintf(stderr, "Failed to open file containing prime table.\n");
	    return -1;
    }
}
