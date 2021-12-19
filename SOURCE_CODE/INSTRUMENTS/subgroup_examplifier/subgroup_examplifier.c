/* Examplifies additive and multiplicative groups.
 *
 * Next thing on the list is to make it export to external table files again.
 */
#include <stdio.h>
#include <stdlib.h>
#include "error_functions.h" // <<< Needed for "HELP_AND_QUIT()" , "MOD_not_parsable_ERROR()", "ID_not_parsable_ERROR"
#include "../../libraries/mathematics/maths.h" // <<< Needed for "N_Combine"
#include "../../libraries/functional/string.h" // <<< Needed for variadic function "match()"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"

struct offset_values { unsigned long Y; unsigned long X; };
// ^^ Not related to groups necessarily, so this is here instead of in "../../libraries/mathematics/universal_group_library.h"

struct triple_ref_LL {
    struct triple_ref_LL *next;
    unsigned long element;
};

struct content {
    unsigned long literal;
    char *ASCII_numerical;
};

struct permutation_piece {
    struct permutation_piece *next;
    struct content *unit;
};

typedef struct vertibrae {
    struct permutation_piece *permutation;
    struct content unit;
} array_piece; typedef array_piece *table_type;

unsigned long cardinality;
table_type LOOKUP_table;
FILE *main_fs; // << Next point of attention right here

array_piece *content_lookup(unsigned long ul) {
    for (unsigned long iter = 0; iter < cardinality; iter++) if (LOOKUP_table[iter].unit.literal == ul) return LOOKUP_table + iter;
    return NULL;
}

struct permutation_piece *permutation_insert(unsigned long unit_identifier, struct permutation_piece *previous_permutation_piece) {
    struct permutation_piece *next_permutation_piece = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Fix existence of new permutation_piece
    next_permutation_piece->unit = &content_lookup(unit_identifier)->unit; // Fix first sloth

    // ###== Insert new linked list element ===>
    next_permutation_piece->next = previous_permutation_piece->next;
    previous_permutation_piece->next = next_permutation_piece;
    return next_permutation_piece; // <=== Shift focus on new element ==###
}

struct permutation_piece *hor(struct permutation_piece *start, unsigned long skips) {
    for (unsigned long i = 0; i < skips; i++) {start = start->next; }
    return start;
}

void print_subgroup(struct permutation_piece *generator, unsigned long *generator_count, unsigned long horizontal_offset) {
    printf("<%s> = {", generator->next->unit->ASCII_numerical);
    struct permutation_piece *starting_point = hor(generator, horizontal_offset);
    struct permutation_piece *do_loop_iterator = starting_point; unsigned long index = 0; do {
	printf("%s", do_loop_iterator->unit->ASCII_numerical); do_loop_iterator = do_loop_iterator->next; index++;
	if (do_loop_iterator == starting_point) break;
	else printf(", ");
    } while (1); printf("}\n");
    if (index == cardinality) (*generator_count)++;
}

void triple_ref_LL_insert(struct triple_ref_LL **tracer, unsigned long new_ulong) {
    struct triple_ref_LL *new_LL_element = (struct triple_ref_LL *) malloc(sizeof(struct triple_ref_LL)); // Fix existence of new pointer_list element
    new_LL_element->next = NULL;
    new_LL_element->element = new_ulong;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_LL_element; // <===-- And place the location of new_LL_element into the next field of the previous insertion --==###
}

// Returns a linked list which is in order of the permutation of the subgroup in question,
// Think of a chain of shackles, this chain is returned at the shackle which points to the identity element unit's struct at a struct vertibrae data type
struct permutation_piece *yield_subgroup(unsigned long index, group_OBJ group, struct triple_ref_LL **generator_channel) {
    unsigned long start_element = LOOKUP_table[index].unit.literal;
    struct permutation_piece *iterator = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Create element
    iterator->unit = &LOOKUP_table[0].unit; // The identity value is always at the start of the lookup table
    iterator->next = iterator; // Make it circular

    unsigned long subgroup_cardinality = 1; // << For we have already inserted the first element
    for (unsigned long generated_element = start_element; generated_element != boolean_from_ID_Sloth(group); generated_element = N_combine_ABSTR(group->MOD, generated_element, start_element, group->ID)) {
	iterator = permutation_insert(generated_element, iterator); // << Put the current power of g into the permutation data structure
	subgroup_cardinality++; }

    if (subgroup_cardinality == cardinality) triple_ref_LL_insert(generator_channel, LOOKUP_table[index].unit.literal);
    return iterator->next;
}

struct triple_ref_LL *zip(struct triple_ref_LL **channel) {
    struct triple_ref_LL *last_shackle, *first_shackle; if (!(last_shackle = first_shackle = (struct triple_ref_LL *) disintermediate((void **) channel))) return NULL;
    while (last_shackle->next) last_shackle = last_shackle->next; last_shackle->next = first_shackle;
    return last_shackle;
}

struct triple_ref_LL *establish_LL(char **argv, group_OBJ group, struct triple_ref_LL **channel, unsigned long *cell_width) {
    char *path_to_filename; FILE *ELEMENT_database = open_group(argv[0], group, argv[1], &path_to_filename); cardinality = 0;
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { triple_ref_LL_insert(channel, group_ELEMENT); cardinality++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct triple_ref_LL *last_element = zip(channel);
    *cell_width = char_in_val(last_element->element);
    return last_element->next;
}

struct triple_ref_LL *replace_LL_with_table(struct triple_ref_LL *element_ring, unsigned long cell_width, group_OBJ group, struct triple_ref_LL **generator_list) {
    LOOKUP_table = (array_piece *) malloc(sizeof(array_piece) * cardinality); // << Allocates memory space on the heap for the table.
    unsigned long index; struct triple_ref_LL *iter = element_ring;
    for (index = 0; index < cardinality; index++) {
	struct triple_ref_LL *process = iter;
	LOOKUP_table[index].unit.literal = process->element;
	iter = process->next; free(process);
    } // <<< Creates the table and destroys the entire linked list.

    for (index = 0; index < cardinality; index++) { // << Loop over the array one more time
	LOOKUP_table[index].permutation = yield_subgroup(index, group, generator_list); // << Now "yield_subgroup()" can properly search through the able and count the amount of generators
	LOOKUP_table[index].unit.ASCII_numerical = str_from_ul(LOOKUP_table[index].unit.literal, cell_width); // << Now with a little less pressure on memory is a good time to add the string representations
    } return zip(generator_list); // << Returns this list at this entry
}

void process_generator_information(unsigned long *generator_count, struct triple_ref_LL *list_of_generators) {
    fprintf(stdout, "\nThis group contains these %lu generators:\n", *generator_count);
    struct triple_ref_LL *iter = list_of_generators; do {
	struct triple_ref_LL *iter_next = iter->next; printf("<%lu>", iter->element); free(iter); iter = iter_next;
	if (iter == list_of_generators) break;
	else printf(", and\n");
    } while (1); printf("\n");
} // ^ This function also free()'s the entries of the linked list

void free_permutation_pieces(unsigned long index) {
    struct permutation_piece *iter = LOOKUP_table[index].permutation; do {
	struct permutation_piece *iter_next = iter->next;
	free(iter); iter = iter_next;
    } while (iter != LOOKUP_table[index].permutation);
}

int main(int argc, char **argv) { group_OBJ group;
    if (5 < argc || argc > 1 && match(argv[1], help_queries)) HELP_AND_QUIT(argv[0]); else group = (group_OBJ) malloc(sizeof(group_OBJ));
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_group_OBJ_ID_Sloth(argv[2], group)) ID_not_parsable_ERROR(argv[1], argv[2]);
    // ^^^ Parse first two arguments and take care of the case where there are too many arguments.

    struct offset_values *shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) {
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!boolean_from_ID_Sloth(group)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the mod value to shifts when dealing with additive groups (see "MATH_HINT_ONE")
    } // ^ Process offset values.

    unsigned long cell_width; struct triple_ref_LL *identity_element = establish_LL(argv, group, (struct triple_ref_LL **) sub_ordinator(), &cell_width);
    // ^^^ Establish a circular linked list of group elements.

    struct triple_ref_LL *generator_list = replace_LL_with_table(identity_element, cell_width, group, (struct triple_ref_LL **) sub_ordinator());
    // ^^^ Substitute this circular linked list of group elements with an array-stored table of elements and free this linked list simultaneously.

    unsigned long *generator_count; *(generator_count = (unsigned long *) malloc(sizeof(unsigned long))) = 0;
    for (unsigned long i = shifts->Y; i < cardinality + shifts->Y; i++) print_subgroup(LOOKUP_table[i % cardinality].permutation, generator_count, shifts->X);
    // ^^^ Print all of the subgroups with horizontal and vertical shifts applied. (Could also count generators here).

    char *symbol = operation_symbol_from_ID_Sloth(group);
    fprintf(stdout, "\nThe %s group of integers modulo %s, which is denoted '\u2115%s%s', contains %lu elements, in standard mathematical notation:\n", adjective_from_ID_Sloth(group), argv[1], argv[1], symbol, cardinality);
    fprintf(stdout, "|\u2115%s%s| = %lu\n", argv[1], symbol, cardinality);
    // ^^^ Print cardinality information about this group.

    if (generator_list) process_generator_information(generator_count, generator_list->next); else fprintf(stdout, "\nThis group does not contain any generators.\n"); free(generator_count);
    // ^^^ Print information about the generators and entirely free the linked list holding this information.

    for (unsigned long index = 0; index < cardinality; index++) { free_permutation_pieces(index); free(LOOKUP_table[index].unit.ASCII_numerical); }
    // ^^^ Free all of the sloths of memory referred to (in)directly by the table

    free(LOOKUP_table);
    // ^^^ Free this table

    return 0;
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. This is applicable to additive groups here.
 * 	*/
