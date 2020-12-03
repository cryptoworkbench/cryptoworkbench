/* Workings should be obvious.
 *
 * Ambitions:
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h" // needed to call string_to_unsigned_long()

struct number_pair { // Declare a number_pair struct type
    unsigned long number_one;
    unsigned long number_two;
};

struct number_pair global;

unsigned long lesser_factor() {
    return global.number_one;
}

unsigned long greater_factor() {
    return global.number_two;
}

struct number_pair *pair(unsigned long number_one, unsigned long number_two) { // Declare a function for constructing such struct types
    struct number_pair *constructed_number_pair_struct = malloc(sizeof(struct number_pair));
    constructed_number_pair_struct->number_one = number_one;
    constructed_number_pair_struct->number_two = number_two;
    return constructed_number_pair_struct;
}

void inflate(struct number_pair *square_pair) { // Declare a function for one such useful use of such a struct type; see reference no. xx
    square_pair->number_two += square_pair->number_one;
    square_pair->number_one += 1;
    square_pair->number_two += square_pair->number_one; }

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
    return factors; }

struct number_pair fermat_factorize(unsigned long odd_composite) {
    return _fermat_factorize(pair(0, 0), pair(0, odd_composite)); // the first and second number_pair structs are automatically freed by _fermat_factorize()
}

int main(int argc, char *argv[]) {
    unsigned long *composite = malloc(sizeof(unsigned long));
    if (argc > 1) { *composite = string_to_unsigned_long(argv[1]); }
    else {
	printf("Please put in a composite number: ");
	scanf("%lu", composite);
    }

    global = fermat_factorize(*composite);
    printf("Factor a: %lu\n", lesser_factor());
    printf("Factor b: %lu\n", greater_factor());
    return 0;
}
