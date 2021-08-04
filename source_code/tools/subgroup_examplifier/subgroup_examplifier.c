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
#include "../../libraries/functional/LOGBOOK_library.h" // << Needed for the definition of "struct group_prams"
#include "../../libraries/mathematics/group_operations.h"
// ^^^ PERSONAL LIBRARY INCLUSIONS

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define STDOUT_ARGV_ONE_INSTRUCTION "Please provide as second argument '0' for the ADDITIVE IDENTITY or '1' for the MULTIPLICATIVE IDENTITY.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define HELP_INFORMATION "Program usage: %s <CAP> <ID> [horizontal offset] [vertical offset] [output filename]\n\n<MANDATORY ARGUMENTS> are denoted like this. The program won't run without these.\n\n[optional arguments] are denoted like this. They are not very necessary.\n"
// ^^^ (MATHEMATICAL) DEFINITIONS

FILE *main_fs; // <<< ALL calls to "fprintf()" use main_fs

struct content {
    unsigned long number;
    char *str;
};

struct permutation_piece {
    struct permutation_piece *next;
    struct content *unit;
};

struct vertibrae {
    struct vertibrae *next;
    struct content unit;
    struct permutation_piece *permutation;
    unsigned long permutation_length;
};

struct offset_values {
    unsigned long Y;
    unsigned long X;
};

unsigned int coprime(unsigned long greatest_common_divisor) // Call as coprime(GCD(big, small)) ===>
  { return (greatest_common_divisor == 1) ? 1 : 0; } // <=== If the Greatest Common Divisor of the unsigned long variables 'big' and 'small' in GCD(big, small) = 1, big & small are coprime

struct content *content_lookup(struct vertibrae *UPSTREAM, unsigned long number) {
    struct vertibrae *iterator = UPSTREAM;
    do {
	if (iterator->unit.number == number)
	    return &iterator->unit;
	else
	    iterator = iterator->next;
    } while (iterator != UPSTREAM);
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

struct permutation_piece *permutation_insert(struct vertibrae *UPSTREAM, unsigned long unit_identifier, struct permutation_piece *previous_permutation_piece) {
    struct permutation_piece *next_permutation_piece = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Fix existence of new permutation_piece
    next_permutation_piece->unit = content_lookup(UPSTREAM, unit_identifier); // Fix first sloth

    // ###== Insert new linked list element ===>
    next_permutation_piece->next = previous_permutation_piece->next;
    previous_permutation_piece->next = next_permutation_piece;
    return next_permutation_piece; // <=== Shift focus on new element ==###
}

/* Returns a linked list which is in order of the permutation of the subgroup in question,
 * Think of a chain of shackles, this chain is returned at the shackle which points to the identity element unit's struct at a struct vertibrae data type
 * */
struct permutation_piece *yield_subgroup(struct vertibrae *UPSTREAM, struct group_prams *group) {
    struct permutation_piece *iterator = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Create element
    iterator->unit = content_lookup(UPSTREAM, group->ID); // Set the identity value
    iterator->next = iterator; // Make it circular

    unsigned long subgroup_cardinality = 1; // <<< For we already have the identity element (see code above)
    for (unsigned long generated_element = UPSTREAM->unit.number; generated_element != group->ID; generated_element = N_field_combine(group->CAP, generated_element, UPSTREAM->unit.number, group->ID)) {
	iterator = permutation_insert(UPSTREAM, generated_element, iterator); /* Put the current power of g into the permutation data structure */
	subgroup_cardinality++;
    }

    UPSTREAM->permutation_length = subgroup_cardinality;
    return iterator->next;
}

struct permutation_piece *move_along_horizontally(struct permutation_piece *link, unsigned long horizontal) {
    for (unsigned long i = 0; i < horizontal; link = link->next, i++) {}
    return link;
}

void print_row(struct permutation_piece *identifier_shackle, unsigned long horizontal) {
    /* ### Always display first the generator ### */
    fprintf(main_fs, "<%s> = {", identifier_shackle->next->unit->str);

    /* ### Move along the horizontal axis ### */
    struct permutation_piece *first_to_print = move_along_horizontally(identifier_shackle, horizontal);

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

struct vertibrae *print_table(struct vertibrae *initial_row, struct offset_values *shifts) {
    for (unsigned long i = 0; i < shifts->Y; initial_row = initial_row->next, i++) {}
    // ^^^ Move along the Y axis

    struct vertibrae *current_row = initial_row; do {
	print_row(current_row->permutation, shifts->X);
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

void print_generators(struct vertibrae *identity_element, unsigned long group_cardinality) {
    struct vertibrae *current_element = identity_element->next; do {
	if (current_element->permutation_length == group_cardinality) fprintf(stdout, "%s\n", current_element->unit.str);
	current_element = current_element->next;
    } while (current_element != identity_element);
}

/* ### put generator count ### */
void put_generator_count(struct vertibrae *identity_element, unsigned long group_cardinality) {
    unsigned long generator_count = 0;
    struct vertibrae *current_element = identity_element->next; do {
	if (current_element->permutation_length == group_cardinality) generator_count++;
	current_element = current_element->next;
    } while (current_element != identity_element);
    identity_element->permutation_length = generator_count;
}

struct vertibrae *setup_table(struct vertibrae *last_element, struct group_prams *group) {
    unsigned long cell_width = char_in_val(last_element->unit.number);
    struct vertibrae *identity_element = last_element->next;

    unsigned long subgroup_size;
    struct vertibrae *do_loop_iterator = identity_element; do {
	do_loop_iterator->permutation = yield_subgroup(do_loop_iterator, group); // Generate subgroup in memory
	do_loop_iterator->unit.str = str_from_ul(do_loop_iterator->unit.number, cell_width);
	do_loop_iterator = do_loop_iterator->next;
    } while (do_loop_iterator != identity_element); // << Return linked list at identity element
    return do_loop_iterator; // <<< Returns linked list at identity element
}

struct vertibrae *build_backbone(char *prog_NAME, struct vertibrae **channel,unsigned long *group_cardinality, struct group_prams *group) {
    char *filename; FILE *element_database = open_group_as_(group, prog_NAME, &filename);
    // ^^^ Open filestream to element database

    unsigned long group_element;
    while (fscanf(element_database, "%lu\n", &group_element) == 1) { vertibrae_insert(channel, group_element); (*group_cardinality)++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    char *symbol = symbol_to_use(group->ID);
    char *BUFFER = BUFFER_OF_SIZE(200);
    sprintf(BUFFER, "Sourced <\u2124/%lu\u2124, %s> successfully from the filestream", group->CAP, symbol); flush_to_LOGBOOK(prog_NAME, BUFFER); fclose(element_database);
    sprintf(BUFFER, "Closed the filestream sourced by '%s'", filename); free(filename); flush_to_LOGBOOK(prog_NAME, BUFFER); free(BUFFER);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
}

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stdout, STDOUT_ARGV_ONE_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is neither '0' nor '1'. Returning '-2'.\n", argv_two);
    exit(-2);
}

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stdout, STDOUT_ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from REGISTRY/ the group '<\u2124/%s\u2124>' makes no sense to me. Returning '-1'.\n", argv_one);
    exit(-1);
}

void HELP_AND_QUIT(char *argv_zero) { fprintf(stderr, HELP_INFORMATION, argv_zero); exit(0); }
int main(int argc, char **argv) { struct group_prams *group; main_fs = stdout; // <<< Preliminary pointers
    if (6 < argc || argc > 1 && (streql(argv[1], "--help") || streql(argv[1], "-h"))) HELP_AND_QUIT(argv[0]); else group = (struct group_prams *) malloc(sizeof(struct group_prams));
    // ^^^ Allocate memory for CAP and ID values if necessary

    if (2 > argc || !(ul_ptr_from_str(&group->CAP, argv[1]))) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    else if (3 > argc || !(ul_ptr_from_str(&group->ID, argv[2]))) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    // ^^^ Collect CAP and ID values from mandatory arguments, quit with appropiate error message upon failure

    struct offset_values *shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) { case 6: main_fs = fopen(argv[5], "w");
	    case 5: if (!(ul_ptr_from_str(&shifts->Y, argv[4]))) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!(ul_ptr_from_str(&shifts->X, argv[3]))) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!(group->ID)) { shifts->X %= group->CAP; shifts->Y %= group->CAP; } }
    } // <<< Do you remember Joseph-Louis Lagrange? (see "MATH_HINT_ONE")
    // ^^^ HANDLE the parsing of POTENTIAL ARGUMENTS (vertical and horizontal offset values default to 0 since their respective arguments are "[optional]")

    unsigned long cell_width; unsigned long group_cardinality = 0;
    struct vertibrae *table = setup_table(build_backbone(argv[0], (struct vertibrae **) sub_ordinator(), &group_cardinality, group), group);
    print_table(table, shifts);

    if (main_fs != stdout)
    { fclose(main_fs); main_fs = stdout; }
    else
	fprintf(stdout, "\n");
    // ^^^ We are done creating the table so stop writting externally

    char *adjective = adjective_to_use(group->ID);
    char *symbol = symbol_to_use(group->ID);
    fprintf(main_fs, "The %s group of integers modulo %lu, expressed by the notations below:\n	<\u2124/%lu\u2124, %s>\nOr	\u2124%lu%s\n\ncontains %lu elements. That is to say that the cardinality of the %s group of integers modulo %lu is %lu \u21D2\n", adjective, group->CAP, group->CAP, symbol, group->CAP, symbol, group_cardinality, adjective, group->CAP, group_cardinality);

    fprintf(main_fs, "	|<\u2124/%lu\u2124, %s>| = %lu\n", group->CAP, symbol, group_cardinality);
    fprintf(main_fs, "Or 	|\u2124%lu%s| = %lu\n", group->CAP, symbol, group_cardinality);
    // ^^^ Print cardinality information about this group

    put_generator_count(table, group_cardinality);
    if (table->permutation_length > 0) {
	fprintf(stdout, "\nThe group denoted \"<\u2124/%lu\u2124, %s>\" or alternatively \"\u2124%lu%s\" contains only the following %lu generators:\n", group->CAP, symbol, group->CAP, symbol, table->permutation_length);
	print_generators(table, group_cardinality);
    } else
	fprintf(stdout, "\nThis group does not have any generators.\n");
    // ^^^ Print generator information about this group

    /* ### Gotta exit cleanly ### */
    free_table(table);
    free(group);
    free(shifts);
    exit(0);
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G.
 */
