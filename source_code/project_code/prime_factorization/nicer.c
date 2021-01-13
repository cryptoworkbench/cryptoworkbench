/* DESCRIPTION:
 * Works neatly. Happens to open and close prime_table_fs constantly in order to start reading from the beginning again. I do not know if this is neccesary.
 *
 * prime_factorization.c hsa formed the basis of this code.
 *
 * For the life of me I do not know what malfunctions, so I'll have to use a debugger. */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"

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

void update(struct prime_power **ll_conx, unsigned long new, unsigned long *factor_set, unsigned long *prime_divisors) {
    insert_prime_power(ll_conx, new);
    *factor_set = *factor_set / new;
    *prime_divisors += 1; }

unsigned long prime_factorize(struct prime_power **ll_conx, unsigned long factor_set, int binary_mode, char *name) {
    unsigned long potential_divisor; int read; FILE *table_fs; 
    unsigned long prime_divisors = 0; do {
	if (factor_set == 1) { return prime_divisors; }
	// ^^ Base case

	if ( !(table_fs = fopen(name, "r"))) {
	    fprintf(stderr, "Failed to open!\n");
	    return prime_divisors; }
	// ^^ Open fs

	while (read = _read_prime(&potential_divisor, table_fs, binary_mode)) {
	    if (potential_divisor * potential_divisor > factor_set) { update(ll_conx, factor_set, &factor_set, &prime_divisors); break; }
	    else if (factor_set % potential_divisor == 0) {
		do update(ll_conx, potential_divisor, &factor_set, &prime_divisors);
		while (factor_set % potential_divisor == 0); break; } }
	fclose(table_fs);
    } while (read); fprintf(stderr, "Too short\n"); return prime_divisors; }

unsigned long combined_factors(struct prime_power *origin) {
    unsigned long ret_val = 1;
    do {
	fprintf(stdout, "%lu", origin->prime);
	if (origin->next != NULL)
	    fprintf(stdout, " * ");

	ret_val *= origin->prime;
	origin = origin->next;
    } while (origin != NULL); return ret_val; }
// ^^ prints and combines the prime factors

void free_set(struct prime_power *origin) {
    do {struct prime_power *link = origin->next;
	free(origin); origin = link;
    } while (origin != NULL); }

int main(int argc, char **argv) {
    if (argc != 2) {
	fprintf(stderr, "Wrong argument count.\n");
	return -1; }
    // ^^ Check number of arguments

    for (unsigned long factor_set = 2; factor_set < 100; factor_set++) {
	struct prime_power ***link;
	*(*(link = (struct prime_power ***) malloc(sizeof(struct prime_power *))) = (struct prime_power **) malloc(sizeof(struct prime_power *))) = NULL;
	struct prime_power **head = *link; free(link);

	// printf("hang\n");
	unsigned long result = prime_factorize(head, factor_set, 1, argv[1]);
	// printf("hang\n");
	fprintf(stdout, "Factor set: %lu | ", factor_set);
	fprintf(stdout, "Result: %lu | ", result);

	struct prime_power *ll = *head; free(head);
	if (combined_factors(ll) == factor_set)
	    fprintf(stdout, " = %lu\n", factor_set);
	else
	    fprintf(stderr, " != %lu\n", factor_set);

	free_set(ll);
    } return 0; }
// ^^ RETURN CODE LEGENDA:
// 0. Prime factorization successfully completed
// -1. Wrong argument count.
// -2. Prime table at specified path \"%s\" must be corrupt:
//     #1 Put all factors of factor_set which are in the specified prime table's list of the potential factors into the linked list.
//     #2 And yet all the prime sloths of the linked list elements multiplied together does not add up to the original factor set again.
//     #3 But 
// -3. Failed because cannot open the prime table or the prime table is too short
