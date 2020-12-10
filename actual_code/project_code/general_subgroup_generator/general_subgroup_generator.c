#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/mathematics/maths.h"
#include "../../../libraries/functional/string.h"
#define ADDITIVE_IDENTITY 0

unsigned long _the_unary_operator_addition_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus) {
    unsigned long return_value = (generated_element + generating_element) % group_modulus;
    return return_value; // Group operation for addition under modular arithmetic
}

unsigned long _the_unary_operator_multiplication_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus) {
    unsigned long return_value = (generated_element * generating_element) % group_modulus;
    return return_value; // Group operation for multiplication under modular arithmetic
}

struct unit {
    unsigned long number;
    char *ascii;
};

struct permutation_piece {
    struct permutation_piece *next;
    struct unit *unit;
};

struct vertibrae {
    struct vertibrae *next;
    struct unit unit;
    struct permutation_piece *permutation;
};

struct set_of_table_properties {
    unsigned long vertical_offset;
    unsigned long horizontal_offset;
};

struct set_of_group_parameters {
    unsigned long modulus;
    unsigned long identity;
};

void **phallus() {
    void ***link;
    *(*(link = (void ***) malloc(sizeof(void *))) = (void **) malloc(sizeof(void *))) = NULL;
    void **source = *link;
    free(link);
    return source;
} FILE *fs = NULL;

unsigned long GCD(unsigned long big, unsigned long small) { // Calculates the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm
    if (big % small == 0)
        return small;
    return GCD(small, big % small);
}

unsigned int coprime(unsigned long greatest_common_divisor) // Call as coprime(GCD(big, small)) ===>
  { return (greatest_common_divisor == 1) ? 1 : 0; } // <=== If the Greatest Common Divisor of the unsigned long variables 'big' and 'small' in GCD(big, small) = 1, big & small are coprime

struct unit *lookup_unit(struct vertibrae *upstream_link, unsigned long number) {
    struct vertibrae *iterator = upstream_link;
    do {
	if (iterator->unit.number == number)
	    return &iterator->unit;
	else
	    iterator = iterator->next;
    } while (iterator != upstream_link);
}

void vertibrae_insert(struct vertibrae **tracer, unsigned long new_ulong) {
    struct vertibrae *new_vertibrae = (struct vertibrae *) malloc(sizeof(struct vertibrae)); // Fix existence of new pointer_list element
    new_vertibrae->next = NULL;
    new_vertibrae->unit.number = new_ulong;
    new_vertibrae->unit.ascii = NULL;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_vertibrae; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

struct permutation_piece *permutation_insert(struct vertibrae *upstream_l, unsigned long unit_identifier, struct permutation_piece *previous_permutation_piece) {
    struct permutation_piece *next_permutation_piece = malloc(sizeof(struct permutation_piece)); // Fix existence of new pointer_list element
    next_permutation_piece->unit = lookup_unit(upstream_l, unit_identifier); // Fix first sloth

    // ###== Insert new linked list element ===>
    next_permutation_piece->next = previous_permutation_piece->next;
    previous_permutation_piece->next = next_permutation_piece;
    return next_permutation_piece; // <=== Shift focus on new element ==###
}

/* Returns a linked list which is in order of the permutation of the subgroup in question,
 * Think of a chain of shackles, this chain is returned at the shackle which points to the identity element unit's struct at a struct vertibrae data type
 * */
struct permutation_piece *yield_subgroup(struct vertibrae *upstream_l, struct set_of_group_parameters *group_parameters) {
    struct permutation_piece *iterator = malloc(sizeof(struct permutation_piece)); // Create element
    iterator->unit = lookup_unit(upstream_l, group_parameters->identity); // Set the identity value
    iterator->next = iterator; // Make it circular

    unsigned long (*group_operation) (unsigned long, unsigned long, unsigned long) = _the_unary_operator_addition_under_modular_arithmatic;

    if (group_parameters->identity)
	group_operation = _the_unary_operator_multiplication_under_modular_arithmatic;

    for (unsigned long generated_element = upstream_l->unit.number; generated_element != group_parameters->identity; generated_element = group_operation(generated_element, upstream_l->unit.number, group_parameters->modulus))
	iterator = permutation_insert(upstream_l, generated_element, iterator); /* Put the current power of g into the permutation data structure */

    /* unsigned long generated_element = upstream_l->unit.number; do {
	permutation_insert(source, upstream_l, generated_element);
	generated_element = group_operation(generated_element, upstream_l->unit.number, group_parameters->modulus);
    } while (generated_element != upstream_l->unit.number); */

    return iterator->next;
}

struct permutation_piece *move_along_horizontally(struct permutation_piece *link, unsigned long horizontal_offset) {
    for (unsigned long i = 0; i < horizontal_offset; link = link->next, i++) {}
    return link;
}

void print_row(struct permutation_piece *identifier_shackle, unsigned long horizontal_offset) {
    /* ### Always display first the generator ### */
    fprintf(fs, "<%s> = {", identifier_shackle->next->unit->ascii);

    /* ### Move along the horizontal axis ### */
    struct permutation_piece *first_to_print = move_along_horizontally(identifier_shackle, horizontal_offset);

    /* ### Start the subgroup printing do loop ### */
    struct permutation_piece *do_loop_iterator = first_to_print; do {
	fprintf(fs, "%s", do_loop_iterator->unit->ascii);
	do_loop_iterator = do_loop_iterator->next;
	
	if (do_loop_iterator == first_to_print)
	    break;
	else
	    fprintf(fs, ", ");
    } while (1); fprintf(fs, "}\n");
}

void table_effect(unsigned long cardinality, unsigned long cell_width) {
    printf(" ==    ");
    for (unsigned long i = 0; i < cardinality; i++) {
	printf(" ");
	for (unsigned long j = 0; j < cell_width; j++)
	    printf("=");
	printf(" ");
    }
    printf("\n");
}

struct vertibrae *print_table(struct vertibrae *initial_row, struct set_of_table_properties *table_properties, unsigned long *group_cardinality) {
    for (unsigned long i = 0; i < table_properties->vertical_offset; initial_row = initial_row->next, i++) {} // Move along the vertical axis

    struct vertibrae *current_row = initial_row; do {
	print_row(current_row->permutation, table_properties->horizontal_offset);
	(*group_cardinality)++;
	current_row = current_row->next;
    } while (current_row != initial_row);
    return initial_row;
}

void free_substrate(struct permutation_piece *substrate) {
    struct permutation_piece *iterator = substrate; do {
	struct permutation_piece *permutation_piece_to_suspend = iterator;

	iterator = iterator->next; // Dodge own free
	free(permutation_piece_to_suspend);
    } while (iterator != substrate);
}

void free_table(struct vertibrae *link) {
    struct vertibrae *iterator = link; do {
	free(iterator->unit.ascii);
	free_substrate(iterator->permutation);

	struct vertibrae *suspend = iterator;
	iterator = iterator->next;
	free(suspend);
    } while (iterator != link);
}
struct vertibrae *setup_table(struct vertibrae *last_element, struct set_of_group_parameters *group_parameters) {
    unsigned long cell_width = char_in_val(last_element->unit.number);
    struct vertibrae *identity_element = last_element->next;

    struct vertibrae *do_loop_iterator = identity_element; do {
	do_loop_iterator->permutation = yield_subgroup(do_loop_iterator, group_parameters); // Generate subgroup in memory
	do_loop_iterator->unit.ascii = ul_to_str(do_loop_iterator->unit.number, cell_width);
	do_loop_iterator = do_loop_iterator->next;
    } while (do_loop_iterator != identity_element); // ### Return linked list at identity element
    return identity_element;
}

void *disintermediate(void **to_be_dereferenced) {
    void *return_value = *to_be_dereferenced; free(to_be_dereferenced);
    return return_value;
}

struct vertibrae *build_backbone(struct vertibrae **linked_list_connection, struct set_of_group_parameters *group) {
    // ### Establish lineair linked list containing all group elements using the triple ref technique
    for (unsigned long element = group->identity; element < group->modulus; element++)
	if (group->identity == ADDITIVE_IDENTITY || coprime(GCD(group->modulus, element)))
	    vertibrae_insert(linked_list_connection, element);

    // ## Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used
    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate( (void **) linked_list_connection);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;

    return last_element;
}

int main(int argc, char **argv) {
    struct set_of_table_properties *table_properties = (struct set_of_table_properties *) malloc(sizeof(struct set_of_table_properties));
    struct set_of_group_parameters *group_properties = (struct set_of_group_parameters *) malloc(sizeof(struct set_of_group_parameters));
    switch (argc) {
	case 6: // When a fifth argument is supplied, output calculations to this file
	    fs = fopen(argv[5], "w");
	case 5:
	    table_properties->horizontal_offset = string_to_unsigned_long(argv[4]);
	case 4:
	    table_properties->vertical_offset = string_to_unsigned_long(argv[3]);
	case 3:
	    group_properties->identity = string_to_unsigned_long(argv[2]);
	case 2:
	    group_properties->modulus = string_to_unsigned_long(argv[1]);
    }

    if (6 > argc) { // When a fifth argument was not supplied, output to stdout
	fs = stdout; }

    if (5 > argc) {
	fprintf(stdout, "Horizontal offset: ");
	fscanf(stdin, "%lu", &table_properties->horizontal_offset); }

    if (4 > argc) {
	fprintf(stdout, "Vertical offset: ");
	fscanf(stdin, "%lu", &table_properties->vertical_offset); }

    if (3 > argc) { // If the group identity was not supplied.
	fprintf(stdout, "Group identity_element: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group_properties->identity); } // Take in the group identity.

    if (2 > argc) { // If the group modulus also was not supplied.
	fprintf(stdout, "Group modulus: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group_properties->modulus); // Take in the group modulus.
    } table_properties->horizontal_offset %= group_properties->modulus;

    unsigned long cell_width;
    unsigned long group_cardinality = 0;

    free_table(
	print_table(
	    setup_table(
		build_backbone(
		    (struct vertibrae **) phallus(),
		    group_properties),
		group_properties),
	    table_properties,
	    &group_cardinality)
	); fprintf(fs, "\n");

    if (group_properties->identity) { // Display cardinality of multiplicative group of integers
	fprintf(fs, "|<\u2124/%lu\u2124, *>| = %lu", group_properties->modulus, group_cardinality);
    } else { // Display cardinality of additive group of integers
	fprintf(fs, "|<\u2124/%lu\u2124, +>| = %lu", group_properties->modulus, group_cardinality);
    } fprintf(fs, "\n");

    fprintf(fs, "\nQuotient groups:\n");
    for (unsigned long i = 0; i < group_properties->modulus; i++) {
	fprintf(fs, "%lu\u2124 + %lu = {... , ", group_properties->modulus, i);
	for (long multiplier = -3; multiplier < 4; multiplier++) {
	    fprintf(fs, "%li, ", i * multiplier);
	} fprintf(fs, "... }\n");
	    
    }

    /* ### Free stuff ### */
    free(group_properties);
    free(table_properties);

    if (fs != stdout)
	fclose(fs);

    return 0; }
