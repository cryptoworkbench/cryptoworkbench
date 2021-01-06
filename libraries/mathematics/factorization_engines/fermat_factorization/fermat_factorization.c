#include <stdlib.h> // 'malloc()' for line 5 and 'free()' for line 29 and 30
#include "fermat_factorization.h"

struct number_pair *construct_square(unsigned long root, unsigned long square) {
    struct number_pair *constructed_number_pair_struct = (struct number_pair *) malloc(sizeof(struct number_pair));
    constructed_number_pair_struct->number_one = root;
    constructed_number_pair_struct->number_two = square;
    return constructed_number_pair_struct;
}

void inflate(struct number_pair *square_pair) {
    square_pair->number_two += square_pair->number_one;
    square_pair->number_one += 1;
    square_pair->number_two += square_pair->number_one;
}

struct number_pair _fermat_factorize(struct number_pair *pair_one, struct number_pair *pair_two) {
    while (pair_one->number_two != pair_two->number_two) {
	while (pair_one->number_two < pair_two->number_two)
	    inflate(pair_one);
	while (pair_one->number_two > pair_two->number_two)
	    inflate(pair_two); }
    
    struct number_pair factors = {
	pair_one->number_one - pair_two->number_one,
	pair_one->number_one + pair_two->number_one };

    /* FREE USED STUFF */
    free(pair_one);
    free(pair_two);

    /* RETURN */
    return factors;
}

struct number_pair fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(construct_square(0, 0), construct_square(0, odd_composite)); // the first and second pure_square structs are automatically freed by _fermat_factorize()
}
