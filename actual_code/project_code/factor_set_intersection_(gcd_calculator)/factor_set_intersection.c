#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"

/* The simplest implementation of the euclidean algorithm I could think of, which happens to be recursive. */
unsigned long euclidean_algorithm(unsigned long big, unsigned long small) {
    if (big % small == 0)
	return small;

    return euclidean_algorithm(small, big % small);
}

int main(int argc, char *argv[]) {
    unsigned long *small_factor_set = malloc(sizeof(unsigned long));
    unsigned long *big_factor_set = malloc(sizeof(unsigned long));

    /* ## Take in supplied variables ## */
    switch (argc) {
	case 3:
	    string_to_unsigned_long(argv[2], small_factor_set);
	case 2:
	    string_to_unsigned_long(argv[1], big_factor_set);
	    break;
	default:
	    printf("Program takes the union of factor sets %s <first factor set denoted as representative composite number> <second factor set denoted as representative composite number>\n", argv[0]);
	    printf("\nWrong program usage.\n\n\nExiting -1\n");
	    return -1;
    }

    /* ## Attempt to process not supplied variables (and print supplied) ## */
    printf("First factor set denoted as representative composite number  :  ");
    if (3 > argc) // If small_factor_set was not processed,
	scanf("%lu", small_factor_set); // process small_factor_set
    else /* Or print the already supplied factor set */ printf("%lu\n", *small_factor_set);

    printf("Second factor set denoted as representative composite number :  ");
    if (2 > argc) // If big_factor_set was not processed,
	scanf("%lu", big_factor_set); // process big_factor_set
    else /* Or print the already supplied factor set */ printf("%lu\n", *big_factor_set);

    if (!(*small_factor_set <= *big_factor_set)) { // If small_factor_set is greater than big_factor_set,
	unsigned long *temp = big_factor_set; // Prepare temp pointer
	big_factor_set = small_factor_set; small_factor_set = temp; // Switch pointers pointing to big_factor_set and small_factor_set
    }

    unsigned long itersection_of_small_factor_set_and_big_factor_set = euclidean_algorithm(*big_factor_set, *small_factor_set);
    printf("Intersection of first and second factor set                  :  %lu\n", itersection_of_small_factor_set_and_big_factor_set);

    printf("\nSymbolically represented:\n%lu \u2229 %lu = %lu\n", *big_factor_set, *small_factor_set, euclidean_algorithm(*big_factor_set, *small_factor_set));
    free(small_factor_set); free(big_factor_set); return 0;
}
