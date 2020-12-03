/* This program calculates factors using the most efficient implementation of Fermat's factorization algorithm I can think of.
 *
 * Try factorizing '2027651281'
 * Or '4849845'
 *
 * Crashes on 625
 *
 * Try swapping not_prime and _not_prime
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

FILE *prime_table;

typedef struct _bisection { // Simple struct used to temporarily store the result of a single factorization
    unsigned long factor_a;
    unsigned long factor_b;
} bisection;

typedef struct _factor_set_element {
    unsigned long factor;
    unsigned long exponent;
    struct _factor_set_element *next;
} element;

typedef element *element_ptr;

/* ### BEGIN PROGRAM ### */
unsigned int _not_prime(unsigned long potential_prime) {
    for (unsigned long i = 2; i <= (potential_prime - (potential_prime % 2)) / 2; i++)
	if (potential_prime % i == 0)
	    return 1;
    return 0;
}

unsigned int search(unsigned long potential_prime) {
    unsigned long prime_in_table; // Set prime_in_table to 0 so that the second sub clause in the while loop always equates to true for the first iteration

    while (fscanf(prime_table, "%lu\n", &prime_in_table)) {
	if (potential_prime == prime_in_table)
	    return 0;

	if (prime_in_table > potential_prime)
	    return 1;
    }
}

unsigned int not_prime(unsigned long potential_prime) {
    prime_table;
    if (!(prime_table = fopen("prime_table", "r")))
	    printf("Couldn't open ma file\n");
    else
	printf("Successfully opened file\n");

    unsigned int ret_value = search(potential_prime);
    printf("\nValue of ret_val: %d\n\n", ret_value);

    if (fclose(prime_table) == 0) {
	printf("Succesfully closed prime_table filestream.\n");
    } else {
	printf("Did not succesfully close filestream.\n");
    }

    return ret_value;
}

unsigned long inflate_square(unsigned long *root, unsigned long *square, unsigned long match_up) {
    *square += *root;
    *root += MULTIPLICATIVE_IDENTITY;
    *square += *root;

    if (!(*square > match_up)) { /* For as long as the square is not bigger than match_up */
	inflate_square(root, square, match_up);
    } else if (*square > match_up) {
	*square -= *root;
	*root -= MULTIPLICATIVE_IDENTITY;
	*square -= *root;
	return *square; }
}

struct _bisection fermat_factorize(unsigned long *big_rt, unsigned long *big_sq, unsigned long small_rt, unsigned long whole) {
    printf("Problem.\n");
    if (whole == inflate_square(big_rt, big_sq, whole)) {
	free(big_sq); bisection return_value = {*big_rt - small_rt, *big_rt + small_rt}; free(big_rt);
	return return_value; /* There is no need to free small_rt because it was not received as a pointer to an unsigned long */
    } else fermat_factorize(big_rt, big_sq, MULTIPLICATIVE_IDENTITY + small_rt, MULTIPLICATIVE_IDENTITY + (small_rt * 2) + whole);
}

void print_linked_list(element_ptr head_of_linked_list) {
    element_ptr iterator = head_of_linked_list;
    for (; iterator->next != head_of_linked_list; iterator = iterator->next) {
	printf("%lu^%lu * ", iterator->factor, iterator->exponent);
    } /* Now we have turned around the circle */ printf("%lu^%lu", iterator->factor, iterator->exponent);
}

element_ptr set_dissector(element initial_set) {
    element_ptr head_of_linked_list = malloc(sizeof(element));
    head_of_linked_list->factor = initial_set.factor;
    head_of_linked_list->exponent = initial_set.exponent;
    head_of_linked_list->next = head_of_linked_list;

    element_ptr current_element = head_of_linked_list;
    do {
	while (not_prime(current_element->factor) == 1) {
	    printf("Factorize composite %lu:\n", current_element->factor);
	    struct _bisection factorization_solution = fermat_factorize(malloc(sizeof(unsigned long)), malloc(sizeof(unsigned long)), ADDITIVE_IDENTITY, current_element->factor);
	    current_element->factor = factorization_solution.factor_a;

	    if (factorization_solution.factor_b == factorization_solution.factor_a) {
		current_element->exponent = current_element->exponent * 2; // Double the exponent
	    } else if (factorization_solution.factor_b != factorization_solution.factor_a) {
		element_ptr old_next = current_element->next; // First we need to save the old next value

		current_element->next = malloc(sizeof(element)); /* CREATE A NEW ELEMENT: */
		current_element->next->factor = factorization_solution.factor_b; // Register b factor in new element
		current_element->next->exponent = current_element->exponent; // Register exponent in new element
		current_element->next->next = old_next; // Register old next in newly appended (inserted) linked list element (so as to keep the tie back to head)
	    } print_linked_list(head_of_linked_list); printf("\n\n");
	} current_element = current_element->next;
    } while (current_element != head_of_linked_list);
    return head_of_linked_list;
}

void print_prime_factors(element a) {
    printf("How to derive the prime factorization of %lu", a.factor);
    if (a.exponent > MULTIPLICATIVE_IDENTITY) {
	printf("^%lu", a.exponent);
    } printf(" ...\n\n");

    /* Print all set elements ((prime) factors) in a orderly fasion */
    element_ptr solution = set_dissector(a);
    printf("Solution:\n");
    printf("%lu = ", a.factor);
    print_linked_list(solution);
    if (a.exponent > MULTIPLICATIVE_IDENTITY) {
	printf("^%lu", a.exponent);
    } printf("\n");
}

int main(int argc, char *argv[]) {
    prime_table = fopen("prime_table", "r");
    if (prime_table == NULL) {
	printf("Program requires a prime table called prime_table.\n\nExiting -1.\n");
	return -1;
    } fclose(prime_table);

    unsigned long *composite = malloc(sizeof(unsigned long)); // Define initial set container
    if (argc > 1) { *composite = string_to_unsigned_long(argv[1]); } // Take in set
    else {
	printf("Please put in a composite number: ");
	scanf("%lu", composite);
    } element a = {*composite, 1, NULL};

    print_prime_factors(a);
    return 0;
}
