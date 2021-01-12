#include <stdio.h> // 'fprintf()', 'fopen()' 'fclose()'
#include <stdlib.h> // 'malloc()' for line 5 and 'free()' for line 29 and 30
#include "factorization_engines.h"

struct number_pair *lookup_factorize_wrapper(unsigned long composite) {
    char *prime_table_filename = (char *) malloc(sizeof(char) * 80);
    fprintf(stdout, "Please provide path to prime table lookup file: ");
    fscanf(stdin, "%s", prime_table_filename);
    FILE *prime_table_fs;
    if (!(prime_table_fs = fopen(prime_table_filename, "r")))
	return NULL;
    else {
	fprintf(stdout, "If this prime table a binary prime table? (0/1): ");
	int binary_mode;
	fscanf(stdin, "%i", &binary_mode);
	struct number_pair *factors = (struct number_pair *) malloc(sizeof(struct number_pair));
	factors->number_one = lookup_factorize(composite, binary_mode, prime_table_fs);
	factors->number_two = composite / factors->number_one;
	return factors; }
}

unsigned long classic_shor_find_a(unsigned long previous_a, unsigned long composite) {
    if (GCD(composite, previous_a) != 1) {
	unsigned long current_gcd;
	do {
	    previous_a++;
	    current_gcd = GCD(composite, previous_a);
	} while (current_gcd != 1);
    }

    /* 'previous_a' is now the first a in the infinite open interval with as open minimum endpoint a, and a maximum endpoint infinity. That's [a, infinity) */
    return previous_a;
}

unsigned long classic_shor_find_period(unsigned long a, unsigned long modulus) {
    unsigned long modular_logarithm = ADDITIVE_IDENTITY;
    unsigned long residue = MULTIPLICATIVE_IDENTITY;
    do {
        modular_logarithm++;
        residue = (residue * a ) % modulus;
    } while (residue != MULTIPLICATIVE_IDENTITY); return modular_logarithm;
}

struct number_pair *classic_shor(unsigned long composite_number) {
    unsigned long period;
    unsigned long a = 1;
    do {
        a++;
        a = classic_shor_find_a(a, composite_number);
	period = classic_shor_find_period(a, composite_number);
    } while (period % 2 == 1 || mod_exponentiate(a, period / 2, composite_number) == composite_number - 1);

    unsigned long intermediary = exponentiate(a, period / 2);
    struct number_pair *factors = (struct number_pair *) malloc(sizeof(struct number_pair));
    factors->number_one = GCD(intermediary + 1, composite_number);
    factors->number_two = GCD(intermediary - 1, composite_number);

    return factors; }
/* ##### ^^^^^^^^^^^^^ ##### Functions for shor factorization, call 'classic_shor(unsigned long)'  ##### ^^^^^^^^^^^^^ ##### */

struct number_pair *fermat_factorize_construct_square(unsigned long root, unsigned long square) {
    struct number_pair *constructed_number_pair_struct = (struct number_pair *) malloc(sizeof(struct number_pair));
    constructed_number_pair_struct->number_one = root;
    constructed_number_pair_struct->number_two = square;
    return constructed_number_pair_struct;
}

void _fermat_factorize_inflate(struct number_pair *square_pair) {
    square_pair->number_two += square_pair->number_one;
    square_pair->number_one += 1;
    square_pair->number_two += square_pair->number_one;
}

struct number_pair *_fermat_factorize(struct number_pair *pair_one, struct number_pair *pair_two) {
    while (pair_one->number_two != pair_two->number_two) {
	while (pair_one->number_two < pair_two->number_two)
	    _fermat_factorize_inflate(pair_one);
	while (pair_one->number_two > pair_two->number_two)
	    _fermat_factorize_inflate(pair_two); }
    
    struct number_pair *factors = (struct number_pair *) malloc(sizeof(struct number_pair));
    factors->number_one = pair_one->number_one - pair_two->number_one;
    factors->number_two = pair_one->number_one + pair_two->number_one;

    /* FREE USED STUFF */
    free(pair_one);
    free(pair_two);

    /* RETURN */
    return factors;
}

struct number_pair *fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(fermat_factorize_construct_square(0, 0), fermat_factorize_construct_square(0, odd_composite)); /* the first and second pure_square structs are automatically freed by _fermat_factorize() */ }
/* ##### ^^^^^^^^^^^^^ ##### Functions for fermat factorization, call 'fermat_factorize(unsigned long)'  ##### ^^^^^^^^^^^^^ ##### */
