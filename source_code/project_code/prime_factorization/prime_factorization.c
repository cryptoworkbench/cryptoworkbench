/* DESCRIPTION:
 * This is a rather convoluted design.
 *
 * Closes and opens prime_table_fs constantly in order to start reading from the beginning again.
 */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#define RESET "\x1B[30m"
#define RED "\x1B[31m"

struct prime_power {
    unsigned long prime;
    unsigned long power;
    struct prime_power *next;
};

void insert_prime_power(struct prime_power **tracer, unsigned long prime_divisor) {
    struct prime_power *new_element = (struct prime_power *) malloc(sizeof(struct prime_power));
    new_element->prime = prime_divisor;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_element; // <===-- And place the location of new_prime into the next field of the previous insertion --==###
}

void update(struct prime_power **ll_conx, unsigned long new, unsigned long *factor_set) {
    insert_prime_power(ll_conx, new);
    *factor_set = *factor_set / new; }

struct prime_power **prime_factorize(struct prime_power **ll_conx, unsigned long factor_set, int binary_mode, char *name) {
    unsigned long potential_divisor; int read; FILE *table_fs; 
    do {
	if (factor_set == 1) { return ll_conx; }
	// ^^ Base case

	if ( !(table_fs = fopen(name, "r"))) {
	    fprintf(stderr, "Failed to open!\n");
	    return ll_conx; }
	// ^^ Open fs

	while (read = _read_prime(&potential_divisor, table_fs, binary_mode)) {
	    if (potential_divisor * potential_divisor > factor_set) { update(ll_conx, factor_set, &factor_set); break; }
	    else if (factor_set % potential_divisor == 0) { do update(ll_conx, potential_divisor, &factor_set); while (factor_set % potential_divisor == 0); break; } }
	fclose(table_fs);
    } while (read); fprintf(stderr, "Too short\n"); return ll_conx; }

unsigned long combined_factors(struct prime_power *origin) {
    unsigned long ret_val = 1;
    do {
	fprintf(stdout, "%lu", origin->prime);
	ret_val *= origin->prime;
	if (origin->next != NULL)
	    fprintf(stdout, " * ");

	origin = origin->next;
    } while (origin != NULL); return ret_val; }
// ^^ prints and combines the prime factors

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Wrong argument count.\n");
	return -1;
    } unsigned long factor_set = str_to_ul(argv[1]);
    struct prime_power *head;
    if (!(head = (struct prime_power *) disintermediate((void **) prime_factorize((struct prime_power **) phallus(), factor_set, 1, argv[2])))) {
	fprintf(stderr, "Factorization failed because there was a problem accessing the neccessary information; namely the first n primes required for factorizing %lu.\n", factor_set);
	fprintf(stderr, "Where n is from the natural numbers such that:\nn <= %lu^(1/2)\n", factor_set);
	fprintf(stderr, "\nExiting '-3'.\n");
	return -3; } unsigned long resulting_set = combined_factors(head);
    if (resulting_set == factor_set) {
	fprintf(stdout, " = %lu\n", resulting_set);
	fprintf(stdout, "\nPrime factorization succesfull.\n");
	fprintf(stdout, "\nExiting '-0'.\n");
	return 0;
    } else {
	fprintf(stderr, " != %lu\n", factor_set);
	fprintf(stderr, "\nPrime factorization unsuccesfull.\n");
	fprintf(stderr, "\nprime table at specified path \"%s\" must be corrupt.\n", argv[1]);
	fprintf(stderr, "\nExiting '-2'.\n");
	return -2; }
    return 0; }
// ^^ RETURN CODE LEGENDA:
// 0. Prime factorization successfully completed
// -1. Wrong argument count.
// -2. Prime table at specified path \"%s\" must be corrupt:
//     #1 Put all factors of factor_set which are in the specified prime table's list of the potential factors into the linked list.
//     #2 And yet all the prime sloths of the linked list elements multiplied together does not add up to the original factor set again.
//     #3 But 
// -3. Failed because cannot open the prime table or the prime table is too short

