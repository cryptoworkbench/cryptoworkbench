/* This was my attempt at making a doubly linked list */
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
    struct vertibrae *previous;
    struct unit unit;
    struct permutation_piece *permutation;
};

struct table_properties {
    unsigned long vertical_offset;
    unsigned long horizontal_offset;
};

struct group_properties {
    unsigned long modulus;
    unsigned long identity;
};

void *close_source(void **to_be_disintermediated) {
    void *return_value = *to_be_disintermediated; free(to_be_disintermediated);
    return return_value;
}

void **open_source() {
    void ***address_where_the_location_of_the_pointer_is_stored;
    *(*(address_where_the_location_of_the_pointer_is_stored = (void ***) malloc(sizeof(void *))) = (void **) malloc(sizeof(void *))) = NULL;
    void **location_of_pointer = *address_where_the_location_of_the_pointer_is_stored;
    free(address_where_the_location_of_the_pointer_is_stored);
    return location_of_pointer;
}
FILE *fs = NULL;

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

void vertibrae_prepend(struct vertibrae **tracer, unsigned long new_ulong, unsigned cell_width) {
    struct vertibrae *new_vertibrae = malloc(sizeof(struct vertibrae)); // Fix existence of new pointer_list element
    new_vertibrae->unit.number = new_ulong;
    new_vertibrae->unit.ascii = ul_to_str(new_ulong, cell_width);

    new_vertibrae->next = *tracer;
    *tracer = new_vertibrae; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

void permutation_insert(struct vertibrae *upstream_l, struct permutation_piece **tracer, unsigned long unit_identifier) {
    struct permutation_piece *new_permutation_piece = malloc(sizeof(struct permutation_piece)); // Fix existence of new pointer_list element
    new_permutation_piece->unit = lookup_unit(upstream_l, unit_identifier); // Fix first sloth
    new_permutation_piece->next = *tracer;
    *tracer = new_permutation_piece; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

struct permutation_piece *yield_subgroup(struct vertibrae *upstream_link, struct permutation_piece **source, struct group_properties *group) {
    /* ### Determine group operation ### */
    unsigned long (*group_operation) (unsigned long, unsigned long, unsigned long) = _the_unary_operator_addition_under_modular_arithmatic;
    if (group->identity)
	group_operation = _the_unary_operator_multiplication_under_modular_arithmatic;

    /* ### Insert subgroup elements ### */
    unsigned long generated_element = group->identity; do {
	permutation_insert(upstream_link, source, generated_element);
	generated_element = group_operation(generated_element, upstream_link->unit.number, group->modulus);
    } while (generated_element != group->identity);

    /* ### Make circular ### */
    struct permutation_piece *last_element, *first_element;
    last_element = first_element = (struct permutation_piece *) close_source((void **) source);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    return last_element; // <=== Return the identity element
}

struct permutation_piece *move_along_horizontally(struct permutation_piece *link, unsigned long horizontal_offset) {
    for (unsigned long i = 0; i < horizontal_offset; link = link->next, i++) {}
    return link;
}

void print_row(struct permutation_piece *identifier_shackle, unsigned long horizontal_offset) {
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
    } while (1);
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

struct vertibrae *print_table(struct vertibrae *initial_row, struct table_properties *table_properties) {
    for (unsigned long i = 0; i < table_properties->vertical_offset; initial_row = initial_row->next, i++) {} // Move along the vertical axis

    struct vertibrae *do_loop_iterator = initial_row; do {
	printf("<%s^(-1)> = <%s> = {", do_loop_iterator->unit.ascii, do_loop_iterator->permutation->next->unit->ascii);
	print_row(do_loop_iterator->permutation, table_properties->horizontal_offset); printf("}\n");
	do_loop_iterator = do_loop_iterator->next;
    } while (do_loop_iterator != initial_row);
}

struct vertibrae *setup_table(struct vertibrae *identity_element, struct group_properties *group, unsigned long *cardinality) {
    struct vertibrae *do_loop_iterator = identity_element; do {
	do_loop_iterator->permutation = yield_subgroup(do_loop_iterator, (struct permutation_piece **) open_source(), group);
	(*cardinality)++;
	do_loop_iterator = do_loop_iterator->next;
    } while (do_loop_iterator != identity_element);
    return identity_element; // <=== Return linked list at the identity element =====###
}

void zip_backbone(struct vertibrae **tracer) {
    struct vertibrae *first = *tracer; free(tracer);
    do {
	(*tracer)->next->previous = *tracer;
	tracer = &(*tracer)->next;
    } while (*tracer != first);
}

struct vertibrae *build_backbone(struct vertibrae **source, struct group_properties *group) {
    /* ### Create table ### */
    unsigned long element = group->modulus;
    unsigned long cell_width = char_in_val(element - 1);
    do {
	element--;
	if (group->identity == ADDITIVE_IDENTITY || coprime(GCD(group->modulus, element)))
	    vertibrae_prepend(source, element, cell_width);
    } while (element != group->identity);

    /* ### Make circular ### */
    struct vertibrae *last_element, *first_element;
    last_element = first_element = *source; // (struct vertibrae *) close_source((void **) source);
    while (last_element->next) {
	// printf("%s\n", last_element->unit.ascii);
	last_element = last_element->next;
    } last_element->next = first_element;

    zip_backbone(source);
    return first_element; // ### Return to setup_table the element first inserted, the element with the greatest value
}

int main(int argc, char **argv) {
    struct table_properties *table_properties = malloc(sizeof(struct table_properties));
    struct group_properties *group = malloc(sizeof(struct group_properties));
    switch (argc) {
	case 6:
	    fs = fopen(argv[5], "w");
	case 5:
	    table_properties->horizontal_offset = string_to_unsigned_long(argv[4]);
	case 4:
	    table_properties->vertical_offset = string_to_unsigned_long(argv[3]);
	case 3:
	    group->identity = string_to_unsigned_long(argv[2]);
	case 2:
	    group->modulus = string_to_unsigned_long(argv[1]);
    }

    if (6 > argc) {
	fs = stdout; }

    if (5 > argc) {
	fprintf(stdout, "Horizontal offset: ");
	fscanf(stdin, "%lu", &table_properties->horizontal_offset); }

    if (4 > argc) {
	fprintf(stdout, "Vertical offset: ");
	fscanf(stdin, "%lu", &table_properties->vertical_offset); }

    if (3 > argc) { // If the group identity was not supplied.
	fprintf(stdout, "Group identity: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group->identity); } // Take in the group identity.

    if (2 > argc) { // If the group modulus also was not supplied.
	fprintf(stdout, "Group modulus: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group->modulus); // Take in the group modulus.
    } table_properties->horizontal_offset %= group->modulus;

    unsigned long cell_width;
    unsigned long cardinality = 0;
    struct vertibrae *pt = setup_table(build_backbone((struct vertibrae **) open_source(), group), group, &cardinality);
    print_table(pt, table_properties);
    free_table(pt);
    fprintf(fs, "\n");

    if (group->identity) { // Display cardinality of multiplicative group of integers
	fprintf(fs, "|<\u2124_%lu, *>| = %lu", group->modulus, cardinality);
    } else { // Display cardinality of additive group of integers
	fprintf(fs, "|<\u2124_%lu, +>| = %lu", group->modulus, cardinality);
    } fprintf(fs, "\n");

    /* ### Free stuff ### */
    free(group);
    free(table_properties);

    if (fs != stdout)
	fclose(fs);

    return 0; }
