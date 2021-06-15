/* Program operations:
 * Examplifies subgroups.
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
// ^^^ MATHEMATICAL DEFINITIONS

#define INCORRECT_SYNTAX "Incorrect syntax.\n\nProgram usage:\n%s <group modulus> <group identity>\n\n\nExiting '-1'.\n"
char *adjective_to_use = "multiplicative"; // <<< We expect to be using this adjective
const char *alternative_adjective = "additive";
const char *folder = "lists/"; // That is /workbench/lists/
const char *filename_main = "_group_of_integers_modulo_";
const char *required_program = "group_generator";
const char *stderr_redirect = " 2> /dev/null";
// ^^^ STRINGS WE NEED

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

struct set_of_table_properties {
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

struct vertibrae *print_table(struct vertibrae *initial_row, struct set_of_table_properties *table_properties, unsigned long *group_cardinality) {
    for (unsigned long i = 0; i < table_properties->vertical_offset; initial_row = initial_row->next, i++) {}
    // ^^^ Move along the vertical axis

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

struct vertibrae *build_backbone(FILE *logbook, char *argv_zero, struct vertibrae **channel, struct group_prams *group) {
    if (group->identity == ADDITIVE_IDENTITY) adjective_to_use = (char *) alternative_adjective;
    // ^^^ Figure out adjective required to open the correct file

    char *argv_one = str_from_ul(group->modulus, 0);
    char *input_filename = (char *) malloc(sizeof(char) * (strlen(folder) + strlen(adjective_to_use) + strlen(filename_main) + strlen(argv_one) + 1));
    *copy_over(copy_over(copy_over(copy_over(input_filename, folder), adjective_to_use), filename_main), argv_one) = 0;
    // ^^^ Put this together with the group modulus (in string form as *argv_one) and a string terminating 0 byte

    // ### Try to open this file
    FILE *element_database = NULL;
    if (!(element_database = fopen(input_filename, "r"))) {
	fprintf(logbook, LOGBOOK_FORMULA "No file named \"%s\"\n", argv_zero, input_filename); // <<< Log error to logbook
	char *required_command = (char *) malloc(sizeof(char) * (strlen(required_program) + 1 + strlen(argv_one) + 3 + strlen(stderr_redirect) + 1));
	char *freeze = copy_over(copy_over(copy_over(copy_over(required_command, required_program), " "), argv_one), " "); free(argv_one);
	if (group->identity == ADDITIVE_IDENTITY) *copy_over(copy_over(freeze, "0"), stderr_redirect) = 0;
	else if (group->identity == MULTIPLICATIVE_IDENTITY) *copy_over(copy_over(freeze, "1"), stderr_redirect) = 0;
	// ^^^ Prepare required command

	fprintf(logbook, LOGBOOK_FORMULA "Running command \"%s\"\n", argv_zero, required_command);
	system(required_command); free(required_command);
	// ^^^ Execute required command

	if (!(element_database = fopen(input_filename, "r")))
	    fprintf(logbook, LOGBOOK_FORMULA "Error: failed to create file using %s\n", argv_zero, required_program);
    } if (element_database != NULL) fprintf(logbook, LOGBOOK_FORMULA "Successfully opened file \"%s\".\n", argv_zero, input_filename);
    // ^^^ Open this file

    unsigned long group_element;
    while (fscanf(element_database, "%lu\n", &group_element) == 1) {
	vertibrae_insert(channel, group_element); } fclose(element_database); // << And close element database connection
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    if (group->identity == ADDITIVE_IDENTITY)
	fprintf(logbook, LOGBOOK_FORMULA "Additive", argv_zero);
    else if (group->identity == MULTIPLICATIVE_IDENTITY) {
	fprintf(logbook, LOGBOOK_FORMULA "Multiplicative", argv_zero);
    } fprintf(logbook, " group interpreted from file \"%s\"\n", input_filename); free(input_filename); close_logbook(logbook);
    // ^^^ Notify user of successfully loading list into memory

    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
}

int main(int argc, char **argv) {
    struct set_of_table_properties *table_properties = (struct set_of_table_properties *) malloc(sizeof(struct set_of_table_properties));
    struct group_prams *group = (struct group_prams *) malloc(sizeof(struct group_prams));
    // ^^^ Pre-allocate some memory for program variables

    switch (argc) {
	case 6: main_fs = fopen(argv[5], "w"); // main_fs is the main filestream
	case 5: table_properties->vertical_offset = ul_from_str(argv[4]); // y coordinate
	case 4: table_properties->horizontal_offset = ul_from_str(argv[3]); // x coordinate
	case 3: group->identity = ul_from_str(argv[2]);
	case 2: group->modulus = ul_from_str(argv[1]); }
    // ^^^ Process supplied variables

    if (6 > argc) { // When a fifth argument was not supplied, output to stdout
	main_fs = stdout; }
    if (5 > argc) { // When the y coordinate (vertical offset) was not supplied, ask for it
	fprintf(stdout, "Vertical offset: ");
	fscanf(stdin, "%lu", &table_properties->vertical_offset); }
    if (4 > argc) { // When the x coordinate (horizontal offset) was not supplied, ask for it
	fprintf(stdout, "Horizontal offset: ");
	fscanf(stdin, "%lu", &table_properties->horizontal_offset); }
    if (3 > argc) { // If the group identity was not supplied, ask what it should be
	fprintf(stdout, "Group identity_element: ");
	fscanf(stdin, "%lu", &group->identity); }
    if (2 > argc) { // If the group modulus also was not supplied, ask what it should be
	fprintf(stdout, "Group modulus: ");
	fscanf(stdin, "%lu", &group->modulus); }
    // ^^^ Process lacking variables
    
    table_properties->horizontal_offset %= group->modulus;

    unsigned long cell_width;
    unsigned long group_cardinality = 0;

    struct vertibrae *table = setup_table(build_backbone(open_logbook(), argv[0], (struct vertibrae **) sub_ordinator(), group), group);
    print_table(table, table_properties, &group_cardinality);
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

    /* ### Free stuff ### */
    free(group);
    free(table_properties);

    return 0; }
