#include <stdlib.h> // 'malloc()' for line 5 and 'free()' for line 29 and 30
#include "fermat_factorization.h"

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
    return factors;
}

struct pure_square fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(construct_square(0, 0), construct_square(0, odd_composite)); // the first and second pure_square structs are automatically freed by _fermat_factorize()
}
