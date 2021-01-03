/* Workings should be obvious. */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h" // needed to call string_to_unsigned_long()

struct pure_square { unsigned long root; unsigned long square; };

struct pure_square *construct_square(unsigned long root, unsigned long square) {
    struct pure_square *constructed_number_pair_struct = (struct pure_square *) malloc(sizeof(struct pure_square));
    constructed_number_pair_struct->root = root;
    constructed_number_pair_struct->square = square;
    return constructed_number_pair_struct;
}

void inflate(struct pure_square *square_pair) {
    square_pair->square += square_pair->root;
    square_pair->root += 1;
    square_pair->square += square_pair->root;
}

struct pure_square _fermat_factorize(struct pure_square *pair_one, struct pure_square *pair_two) {
    while (pair_one->square != pair_two->square) {
	while (pair_one->square < pair_two->square)
	    inflate(pair_one);
	while (pair_one->square > pair_two->square)
	    inflate(pair_two); }
    
    struct pure_square factors = {
	pair_one->root - pair_two->root,
	pair_one->root + pair_two->root };

    /* FREE USED STUFF */
    free(pair_one);
    free(pair_two);

    /* RETURN */
    return factors; }

struct pure_square fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(construct_square(0, 0), construct_square(0, odd_composite)); // the first and second pure_square structs are automatically freed by _fermat_factorize()
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "%s <factor set to dissect denoted as composite number>\n", argv[0]);
	fprintf(stderr, "\n\nWrong program usage.\n\nExiting with '-1'.\n");
	return -1;
    } unsigned long factor_set = string_to_unsigned_long(argv[1]);
    printf("Multiplicative factor set to dissect :  '%lu'\n", factor_set);

    struct pure_square suspected_composite_factors = fermat_factorize(factor_set);
    printf("Suspected subset a                   :  '%lu'\n", suspected_composite_factors.root);
    printf("Suspected subset b                   :  '%lu'\n", suspected_composite_factors.square);

    unsigned long supposed_factor_set = suspected_composite_factors.root * suspected_composite_factors.square;
    if (supposed_factor_set == factor_set) {
	printf("%lu * %lu = %lu\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation successful.\n\nExiting '0'.\n");
	return 0;
    } else {
	printf("%lu * %lu != %lu\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation unsuccessful.\n\nExiting '-2'.\n");
	return -1;
    }
}
