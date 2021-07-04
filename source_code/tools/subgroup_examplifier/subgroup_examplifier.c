/* Program operations:
 * Examplifies subgroups.
 *
 * DEVELOPERS NOTE:
 * The construction in main()
 */
#include <stdio.h>
#include <stdlib.h>
// ^^^ STANDARD LIBRARY INCLUSIONS

#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/functional/logbook_functions.h"
#include "../../libraries/mathematics/group_operations.h"
// ^^^ PERSONAL LIBRARY INCLUSIONS

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define STDOUT_ARGV_ONE_INSTRUCTION "Please provide as second argument '0' for the ADDITIVE IDENTITY or '1' for the MULTIPLICATIVE IDENTITY.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define HELP_INFORMATION "Program usage: %s <group MOD> <group ID> [horizontal offset] [vertical offset] [output filename]\n\nOptions in between '<' & '>' symbols are mandatory.\n\nOptions between '[' & ']' are optional.\n"
// ^^^ (MATHEMATICAL) DEFINITIONS

FILE *main_fs; // <<< ALL calls to "fprintf()" use main_fs

struct unit {
    unsigned long number;
    char *str;
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

struct coordinates {
    unsigned long vertical_offset;
    unsigned long horizontal_offset;
};

struct group_prams {
    unsigned long modulus;
    unsigned long identity;
};

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
    new_vertibrae->unit.str = NULL;

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
struct permutation_piece *yield_subgroup(struct vertibrae *upstream_l, struct group_prams *group_parameters) {
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
    fprintf(main_fs, "<%s> = {", identifier_shackle->next->unit->str);

    /* ### Move along the horizontal axis ### */
    struct permutation_piece *first_to_print = move_along_horizontally(identifier_shackle, horizontal_offset);

    /* ### Start the subgroup printing do loop ### */
    struct permutation_piece *do_loop_iterator = first_to_print; do {
	fprintf(main_fs, "%s", do_loop_iterator->unit->str);
	do_loop_iterator = do_loop_iterator->next;
	
	if (do_loop_iterator == first_to_print)
	    break;
	else
	    fprintf(main_fs, ", ");
    } while (1); fprintf(main_fs, "}\n");
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

struct vertibrae *print_table(struct vertibrae *initial_row, struct coordinates *table_coordinates, unsigned long *group_cardinality) {
    for (unsigned long i = 0; i < table_coordinates->vertical_offset; initial_row = initial_row->next, i++) {}
    // ^^^ Move along the vertical axis

    struct vertibrae *current_row = initial_row; do {
	print_row(current_row->permutation, table_coordinates->horizontal_offset);
	(*group_cardinality)++;
	current_row = current_row->next;
    } while (current_row != initial_row);
    return initial_row;
}

void free_substrate(struct permutation_piece *substrate) {
    struct permutation_piece *iterator = substrate; do {
	struct permutation_piece *permutation_piece_to_suspend = iterator;

	iterator = iterator->next; // Dodge one free
	free(permutation_piece_to_suspend);
    } while (iterator != substrate);
}

void free_table(struct vertibrae *link) {
    struct vertibrae *iterator = link; do {
	free(iterator->unit.str);
	free_substrate(iterator->permutation);

	struct vertibrae *suspend = iterator;
	iterator = iterator->next;
	free(suspend);
    } while (iterator != link);
}

struct vertibrae *setup_table(struct vertibrae *last_element, struct group_prams *group_parameters) {
    unsigned long cell_width = char_in_val(last_element->unit.number);
    struct vertibrae *identity_element = last_element->next;

    struct vertibrae *do_loop_iterator = identity_element; do {
	do_loop_iterator->permutation = yield_subgroup(do_loop_iterator, group_parameters); // Generate subgroup in memory
	do_loop_iterator->unit.str = str_from_ul(do_loop_iterator->unit.number, cell_width);
	do_loop_iterator = do_loop_iterator->next;
    } while (do_loop_iterator != identity_element); // << Return linked list at identity element
    return do_loop_iterator; // <<< Returns linked list at identity element
}

struct vertibrae *build_backbone(char *argv_zero, struct vertibrae **channel, struct group_prams *group) {
    char *input_filename; FILE *element_database = open_modular_group(open_logbook(), argv_zero, group->modulus, group->identity, &input_filename);
    // ^^^ Open filestream to element database

    unsigned long group_element;
    while (fscanf(element_database, "%lu\n", &group_element) == 1) {
	vertibrae_insert(channel, group_element); } fclose(element_database); // << And close element database connection
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
}

int QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stdout, STDOUT_ARGV_ONE_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is neither '0' nor '1'. Returning -2.\n", argv_two); return -2; }

int QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stdout, STDOUT_ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group MOD: to attempt to open from registry the group '<\u2124/%s\u2124>' makes no sense to me. Returning -1.\n", argv_one); return -1;
}

int HELP_AND_QUIT(char *argv_zero) {
    fprintf(stderr, HELP_INFORMATION, argv_zero);
    return 0;
}

int main(int argc, char **argv) {
    struct group_prams *group; struct coordinates *table_coordinates; // <<< Declare STRUCT pointers for program variables
    group = (struct group_prams *) malloc(sizeof(struct group_prams)); // <<< Allocate one of the STRUCTs already
    main_fs = stdout;

    if (argv[1] && (streql(argv[1], "--help") || streql(argv[1], "-h")))
    {  return HELP_AND_QUIT(argv[0]); // <<< HANDLES WHEN THIS PROGRAM IS RAN WITH THE "--help" OPTION
    }

    else if (! (ul_ptr_from_str(&group->modulus, argv[1])))
    {  return QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    }

    else if (! (ul_ptr_from_str(&group->identity, argv[2])))
    { return QUIT_ON_ARGV_TWO_ERROR(argv[2]); }

    else
    {   table_coordinates = (struct coordinates *) malloc(sizeof(struct coordinates)); // <<< ^^^ IF WE HAVE A GROUP MODULUS AND A GROUP IDENTITY
	table_coordinates->vertical_offset = table_coordinates->horizontal_offset = 0;
	if (argc == 6) main_fs = fopen(argv[5], "w");
	switch (argc) {
	    case 6: main_fs = fopen(argv[5], "w");
	    case 5: if (!(ul_ptr_from_str(&table_coordinates->vertical_offset, argv[4]))) { fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]); }
	    case 4: if (!(ul_ptr_from_str(&table_coordinates->horizontal_offset, argv[3]))) { fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]); }
	    case 3: case 2: break; // <<< For these cases have already been filtered out
/*case>=7:*/default: HELP_AND_QUIT(argv[0]); break; }
    }
    // ^^^ HANDLES ALL POSSIBLE INPUT CASE SCENARIOS EXCEPT THE TWO SCENARIOS THAT ARE HANDLED BY THE FOLLOWING TWO LINES


    table_coordinates->horizontal_offset %= group->modulus;

    unsigned long cell_width;
    unsigned long group_cardinality = 0;

    struct vertibrae *table = setup_table(build_backbone(argv[0], (struct vertibrae **) sub_ordinator(), group), group);
    print_table(table, table_coordinates, &group_cardinality);
    free_table(table);

    if (main_fs != stdout)
    { fclose(main_fs); main_fs = stdout; }
    else
	fprintf(stdout, "\n");
    // ^^^ We are done creating the table so stop writting externally

    if (group->identity == MULTIPLICATIVE_IDENTITY) { // <<< Display cardinality information on the multiplicative group of integers
	fprintf(main_fs, "The multiplicative group of integers modulo %lu, expressed by the notations below:\n	\u2124%lu*\nOr	<\u2124/%lu\u2124, *>\n\ncontains %lu elements. That is to say that the cardinality of the multiplicative group of integers modulo %lu is %lu \u21D2\n", group->modulus, group->modulus, group->modulus, group_cardinality, group->modulus, group_cardinality);
	fprintf(main_fs, " 	|\u2124%lu*| = %lu\n", group->modulus, group_cardinality);
	fprintf(main_fs, "Or	|<\u2124/%lu\u2124*>| = %lu\n", group->modulus, group_cardinality); }
    
    else if (group->identity == ADDITIVE_IDENTITY) { // <<< Display cardinality information on the additive group of integers
	fprintf(main_fs, "The additive group of integers modulo %lu, expressed by the notations below:\n	\u2124%lu+\nOr	<\u2124/%lu\u2124, +>\n\ncontains %lu elements. That is to say that the cardinality of the additive group of integers modulo %lu is %lu \u21D2\n", group->modulus, group->modulus, group->modulus, group_cardinality, group->modulus, group_cardinality);
	fprintf(main_fs, "   	|\u2124%lu+| = %lu\n", group->modulus, group_cardinality);
	fprintf(main_fs, "Or 	|<\u2124/%lu\u2124>+| = %lu\n", group->modulus, group_cardinality); }

    /* ### Free remaining stuff ### */
    free(group);
    free(table_coordinates);

    return 0; }
