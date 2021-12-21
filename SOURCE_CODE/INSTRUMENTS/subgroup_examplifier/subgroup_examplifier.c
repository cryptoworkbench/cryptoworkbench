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
FILE *main_fs;
struct offset_values *shifts;

unsigned long index_lookup(unsigned long ul) {
    for (unsigned long index = 0; index < cardinality; index++)
	if (LOOKUP_table[index].unit.literal == ul) return index;

    return 0;
}

struct permutation_piece *permutation_insert(unsigned long unit_identifier, struct permutation_piece *previous_permutation_piece) {
    struct permutation_piece *next_permutation_piece = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Fix existence of new permutation_piece
    next_permutation_piece->unit = &LOOKUP_table[index_lookup(unit_identifier)].unit; // Fix first sloth

    // ###== Insert new linked list element ===>
    next_permutation_piece->next = previous_permutation_piece->next;
    previous_permutation_piece->next = next_permutation_piece;
    return next_permutation_piece; // <=== Shift focus on new element ==###
}

void print_subgroup(struct permutation_piece *link) {
    fprintf(main_fs, "<%s> = {", link->next->unit->ASCII_numerical);
    for (unsigned long i = 0; i < shifts->X; i++) link = link->next;
    // ^^ Prepare the printing of the subgroup's permutation cycle

    struct permutation_piece *do_loop_iterator = link; do {
	fprintf(main_fs, "%s", do_loop_iterator->unit->ASCII_numerical); do_loop_iterator = do_loop_iterator->next;
	if (do_loop_iterator == link) break;
	else fprintf(main_fs, ", ");
    } while (1); fprintf(main_fs, "}");
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

struct triple_ref_LL **establish_LL(char **argv, group_OBJ group, struct triple_ref_LL **element_ll_INSERT_CHANNEL) {
    char *path_to_filename; FILE *ELEMENT_database = open_group(argv[0], group, argv[1], &path_to_filename); cardinality = 0;
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { triple_ref_LL_insert(element_ll_INSERT_CHANNEL, group_ELEMENT); cardinality++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    return element_ll_INSERT_CHANNEL;
}

struct triple_ref_LL *replace_LL_with_table(struct triple_ref_LL **element_ll_INSERT_CHANNEL, group_OBJ group, struct triple_ref_LL **generator_ll_INSERT_CHANNEL) {
    struct triple_ref_LL *iter = zip(element_ll_INSERT_CHANNEL); unsigned long cell_width = char_in_val(iter->element); iter = iter->next;
    // ^^ Determine required cell width for lookup table

    LOOKUP_table = (array_piece *) malloc(sizeof(array_piece) * cardinality);
    // ^^ Allocate memory space on heap for lookup table.

    unsigned long index; // << We will reuse unsigned long index at these 2 for loop's
    for (index = 0; index < cardinality; index++) {
	struct triple_ref_LL *process = iter;
	LOOKUP_table[index].unit.literal = process->element;
	iter = process->next; free(process);
    } // <<< Creates the table and destroys the entire linked list.

    for (index = 0; index < cardinality; index++) { // << Loop over the array one more time
	LOOKUP_table[index].permutation = yield_subgroup(index, group, generator_ll_INSERT_CHANNEL); // << Now "yield_subgroup()" can properly search through the able and count the amount of generators
	LOOKUP_table[index].unit.ASCII_numerical = str_from_ul(LOOKUP_table[index].unit.literal, cell_width); // << Now with a little less pressure on memory is a good time to add the string representations
    } return zip(generator_ll_INSERT_CHANNEL); // << Returns this list at this entry
}

unsigned long process_generator_information(struct triple_ref_LL *list_of_generators) {
    unsigned long generator_count = 0; struct triple_ref_LL *iter = list_of_generators; do {
	struct triple_ref_LL *iter_next = iter->next;
	print_subgroup(LOOKUP_table[index_lookup(iter->element)].permutation);
	free(iter); iter = iter_next; generator_count++;
	if (iter == list_of_generators) break;
	else printf(", and\n");
    } while (1); printf("\n");

    return generator_count;
} // ^ This function also free()'s the entries of the linked list

void free_permutation_pieces(unsigned long index) {
    struct permutation_piece *iter = LOOKUP_table[index].permutation; do {
	struct permutation_piece *iter_next = iter->next;
	free(iter); iter = iter_next;
    } while (iter != LOOKUP_table[index].permutation);
}

void print_table() {
    for (unsigned long i = shifts->Y; i < cardinality + shifts->Y; i++)
    { print_subgroup(LOOKUP_table[i % cardinality].permutation); fprintf(main_fs, "\n"); }
}

int main(int argc, char **argv) { group_OBJ group; main_fs = stdout;
    if (6 < argc || argc > 1 && match(argv[1], help_queries)) HELP_AND_QUIT(argv[0]); else group = (group_OBJ) malloc(sizeof(group_OBJ));
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_group_OBJ_ID_Sloth(argv[2], group)) ID_not_parsable_ERROR(argv[1], argv[2]);
    // ^^^ Parse first two arguments and take care of the case where there are too many arguments.

    shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) { case 6: main_fs = fopen(argv[5], "w");
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!boolean_from_ID_Sloth(group)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the mod value to shifts when dealing with additive groups (see "MATH_HINT_ONE")
    } // ^ Process offset values.

    struct triple_ref_LL *generator_list = replace_LL_with_table(establish_LL(argv, group, (struct triple_ref_LL **) sub_ordinator()), group, (struct triple_ref_LL **) sub_ordinator());
    // ^^^ Substitute this circular linked list of group elements with an array-stored table of elements and free this linked list simultaneously.

    print_table();

    char *adjective = adjective_from_ID_Sloth(group);
    char *symbol = operation_symbol_from_ID_Sloth(group);
    if (main_fs != stdout) { fclose(main_fs); main_fs = stdout;
	fprintf(main_fs, "Wrote table for the %s group of integers modulo %s (\u2115%s%s), with offset values %s and %s, to an external file called '%s'.\n", adjective, argv[1], argv[1], symbol, argv[3], argv[4], argv[5]); }

    fprintf(stdout, "\nExamplified \u2115%s%s; pronunciated 'the %s group of integers modulo %s'.\n", argv[1], symbol, adjective, argv[1]);
    fprintf(stdout, "\n'\u2115%s%s' contains %lu elements. |\u2115%s%s| = %lu\n", argv[1], symbol, cardinality, argv[1], symbol, cardinality);
    // ^^^ Print cardinality information about this group.

    if (generator_list) { /* <<< - If the is a list of generators, >>> - Initialize this list properly --> */ generator_list = generator_list->next;
	fprintf(stdout, "\nGenerator count for \u2115%s%s:\n", argv[1], symbol); unsigned long generator_count = process_generator_information(generator_list);
	fprintf(stdout, "\nThere are %lu. %lu generators are present in \u2115%s%s.\n", generator_count, generator_count, argv[1], symbol);
    } else fprintf(stdout, "\nThis group does not contain any generators.\n");
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
