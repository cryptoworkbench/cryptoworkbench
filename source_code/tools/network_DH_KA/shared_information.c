#include "shared_information.h"

void insert(struct group_element **channel, unsigned long group_element) {
    struct group_element *new_element = (struct group_element *) malloc(sizeof(struct group_element));
    new_element->value = group_element;

    while (*channel) // <<< Find the last insertion
	channel = &(*channel)->next;

    *channel = new_element; // <<< Place new element in 'next' field of the last insertion
}

struct group_element *group_elements_in_file(struct group_element **channel, FILE *input_file) {
    unsigned long group_element; while (fscanf(input_file, "%lu\n", &group_element) == 1) { insert(channel, group_element); } fclose(input_file);
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    struct group_element *last_element, *first_element;
    last_element = first_element = (struct group_element *) disintermediate( (void **) channel);
    while (last_element->next) { last_element = last_element->next; } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used
    return first_element; }
// ^^^ Function to get a linked list from the filestream supplied by "open_modular_group()", automatically closes input_file

unsigned long length(unsigned long element) {
    unsigned long sub_order = ADDITIVE_IDENTITY; unsigned long iter = MULTIPLICATIVE_IDENTITY;
    do { iter = (iter * element) % cap; sub_order++; }
    while (iter != MULTIPLICATIVE_IDENTITY); 
    return sub_order; }
// ^^^ Function to get the order of an element in a multiplicative group

unsigned long present(struct group_element *ll, unsigned long element) {
    struct group_element *iter = ll; do {
	if (element == iter->value) return element;
	else iter = iter->next;
    } while (iter != ll); return 0; }
// ^^^ Function to check if "element" is present in linked list "ll"
