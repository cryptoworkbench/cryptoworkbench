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

struct set_of_table_parameters {
    unsigned long vertical_offset;
    unsigned long horizontal_offset;
};

struct set_of_group_parameters {
    unsigned long modulus;
    unsigned long identity_element;
};

void *disintermediate(void **to_be_disintermediated) {
    void *return_value = *to_be_disintermediated; free(to_be_disintermediated);
    return return_value;
}

struct permutation_piece **permutation_needle_insert() {
    struct permutation_piece ***link;
    *(*(link = (struct permutation_piece ***) malloc(sizeof(void *))) = (struct permutation_piece **) malloc(sizeof(void *))) = NULL;
    struct permutation_piece **source = *link;
    free(link);
    return source;
}

struct vertibrae **vertibrae_needle_insert() {
    struct vertibrae ***link;
    *(*(link = (struct vertibrae ***) malloc(sizeof(void *))) = (struct vertibrae **) malloc(sizeof(void *))) = NULL;
    struct vertibrae **source = *link;
    free(link);
    return source;
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

void vertibrae_insert(struct vertibrae **tracer, unsigned long new_ulong) {
    struct vertibrae *new_vertibrae = malloc(sizeof(struct vertibrae)); // Fix existence of new pointer_list element
    new_vertibrae->next = *tracer;
    new_vertibrae->unit.number = new_ulong;
    *tracer = new_vertibrae; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

void permutation_insert(struct vertibrae *upstream_l, struct permutation_piece **tracer, unsigned long unit_identifier) {
    struct permutation_piece *new_permutation_piece = malloc(sizeof(struct permutation_piece)); // Fix existence of new pointer_list element
    new_permutation_piece->unit = lookup_unit(upstream_l, unit_identifier); // Fix first sloth
    new_permutation_piece->next = *tracer;
    *tracer = new_permutation_piece; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

struct permutation_piece *yield_subgroup(struct vertibrae *upstream_link, struct permutation_piece **tracer, struct set_of_group_parameters *group) {
    /* ### Determine group operation ### */
    unsigned long (*group_operation) (unsigned long, unsigned long, unsigned long) = _the_unary_operator_addition_under_modular_arithmatic;
    if (group->identity_element)
	group_operation = _the_unary_operator_multiplication_under_modular_arithmatic;

    /* ### Insert subgroup elements ### */
    unsigned long generated_element = group->identity_element; do {
	permutation_insert(upstream_link, tracer, generated_element);
	generated_element = group_operation(generated_element, upstream_link->unit.number, group->modulus);
    } while (generated_element != group->identity_element);

    /* ### Make circular ### */
    struct permutation_piece *last_element, *first_element;
    last_element = first_element = (struct permutation_piece *) disintermediate(tracer);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    return first_element; // <=== Return the identity element
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

struct vertibrae *print_table(unsigned long *group_cardinality, struct vertibrae *initial_row, struct set_of_table_parameters *table_parameters) {
    for (unsigned long i = 0; i < table_parameters->vertical_offset; initial_row = initial_row->next, i++) {} // Move along the vertical axis

    struct vertibrae *current_row = initial_row; do {
	print_row(current_row->permutation, table_parameters->horizontal_offset);
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
    unsigned long cell_width = char_in_val(last_element->unit.number); // Catch cell_width
    last_element = last_element->next; // Set 'last_element' to the identity element

    struct vertibrae *identity_element = last_element; do {
	identity_element->permutation = yield_subgroup(identity_element, permutation_needle_insert(), group_parameters);
	identity_element->unit.ascii = ul_to_str(identity_element->unit.number, cell_width);
	identity_element = identity_element->next;
    } while (identity_element != last_element);
    return identity_element; // <=== Return linked list at the identity element =====###
}

struct vertibrae *build_backbone(struct vertibrae **tracer, struct set_of_group_parameters *group) {
    /* ### Create table ### */
    unsigned long element = group->modulus; do {
	element--;
	if (group->identity_element == ADDITIVE_IDENTITY || coprime(GCD(group->modulus, element)))
	    vertibrae_insert(tracer, element);
    } while (element != group->identity_element);

    /* ### Make circular ### */
    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate(tracer);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    return last_element; // ### Return to setup_table the element first inserted, the element with the greatest value
}

int main(int argc, char **argv) {
    struct set_of_table_parameters *table_parameters = malloc(sizeof(struct set_of_table_parameters));
    struct set_of_group_parameters *group_parameters = malloc(sizeof(struct set_of_group_parameters));
    switch (argc) {
	case 6:
	    fs = fopen(argv[5], "w");
	case 5:
	    table_parameters->horizontal_offset = string_to_unsigned_long(argv[4]);
	case 4:
	    table_parameters->vertical_offset = string_to_unsigned_long(argv[3]);
	case 3:
	    group_parameters->identity_element = string_to_unsigned_long(argv[2]);
	case 2:
	    group_parameters->modulus = string_to_unsigned_long(argv[1]);
    }

    if (6 > argc) {
	fs = stdout; }

    if (5 > argc) {
	fprintf(stdout, "Horizontal offset: ");
	fscanf(stdin, "%lu", &table_parameters->horizontal_offset); }

    if (4 > argc) {
	fprintf(stdout, "Vertical offset: ");
	fscanf(stdin, "%lu", &table_parameters->vertical_offset); }

    if (3 > argc) { // If the group identity was not supplied.
	fprintf(stdout, "Group identity_element: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group_parameters->identity_element); } // Take in the group identity.

    if (2 > argc) { // If the group modulus also was not supplied.
	fprintf(stdout, "Group modulus: "); // Kindly emphasize the issue, and;
	fscanf(stdin, "%lu", &group_parameters->modulus); // Take in the group modulus.
    } table_parameters->horizontal_offset %= group_parameters->modulus;

    unsigned long cell_width;
    unsigned long group_cardinality = 0;

    free_table(
	print_table(
	    &group_cardinality,
	    setup_table(
		build_backbone(
		    vertibrae_needle_insert(),
		    group_parameters),
		group_parameters
		),
	    table_parameters
	    )
	); fprintf(fs, "\n");

    if (group_parameters->identity_element) { // Display cardinality of multiplicative group of integers
	fprintf(fs, "|<\u2124_%lu, *>| = %lu", group_parameters->modulus, group_cardinality);
    } else { // Display cardinality of additive group of integers
	fprintf(fs, "|<\u2124_%lu, +>| = %lu", group_parameters->modulus, group_cardinality);
    } fprintf(fs, "\n");

    /* ### Free stuff ### */
    free(group_parameters);
    free(table_parameters);

    if (fs != stdout)
	fclose(fs);

    return 0; }
