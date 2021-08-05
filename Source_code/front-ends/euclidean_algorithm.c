#include <stdio.h>
#include <stdlib.h>
#include "../libraries/mathematics/maths.h"
#include "../libraries/functional/string.h"
#include "../libraries/functional/triple_ref_pointers.h"
const char *insufficient_arguments = "This program takes the union of two factor sets.\n\nUSAGE:\n%s <first factor set denoted as representative composite number> <second factor set denoted as representative composite number>\n\nFor example:\n# %s 1365 15015 770 ===>\n## Factor set #1: 1365\n## Factor set #2: 15015\n## Factor set #3: 770\n##\n## GCD = 35\n\nWrong program usage. Exiting -1.\n";

struct ll {
    unsigned long factor_set;
    struct ll *link;
};

void ll_insert(struct ll **tracer, unsigned long factor_set) {
    struct ll *new_ll = (struct ll *) malloc(sizeof(struct ll)); // Fix existence of new pointer_list element
    new_ll->factor_set = factor_set;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->link;

    *tracer = new_ll; // <===-- And place the location of new_ll into the link field of the previous insertion --==###
}

struct ll *build_HW(struct ll **linked_list_connection, int argc, char **argv) {
    while (argc != 1) {
	ll_insert(linked_list_connection, ul_from_str(argv[argc - 1]));
	argc--; }
    // ^^ Establish lineair linked list containing all group elements using the triple ref technique

    struct ll *last_element, *first_element;
    last_element = first_element = (struct ll *) disintermediate( (void **) linked_list_connection);
    while (last_element->link) {
	last_element = last_element->link;
    } last_element->link = first_element;
    // ^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return first_element; }
// ^^^ Initialize linked list

void print_ll(struct ll *ll) {
    unsigned long counter = 1;
    struct ll *first_HW_step = ll; do {
	fprintf(stdout, "Factor set #%lu: %lu\n", counter, ll->factor_set);
	ll = ll->link; counter++;
    } while (ll != first_HW_step); }
// ^^ Print linked list

void line_out_factor_sets_to_intersect(struct ll *link) {
    while (link->link != link) {
	link->factor_set = GCD(link->factor_set, link->link->factor_set);
	struct ll *to_free = link->link;
	struct ll *new_link = to_free->link;
	free(to_free);
	link->link = new_link; } }
// ^^ Display factor sets whose collective intersection will be taken

int main(int argc, char *argv[]) {
    if (argc <= 2) {
	fprintf(stderr, insufficient_arguments, argv[0], argv[0]);
	return -1; }
    // ^^ Exit when insufficient arguments are supplied

    struct ll *circular_ll = build_HW((struct ll **) sub_ordinator(), argc, argv);
    print_ll(circular_ll);
    line_out_factor_sets_to_intersect(circular_ll);
    fprintf(stdout, "\nGCD: %lu\n", circular_ll->factor_set);

    free(circular_ll); return 0; }
