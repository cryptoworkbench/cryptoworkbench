/* This will be an entire rewrite of "subgroup_examplifier".
 *
 * Functional functions and definitions, namely the ones that only pertain to presentation, parsing errors, help message, etc, and not to the underlying mathematics per-se, are now in "ERROR_FUNCTIONS.h"
 * Over at "../subgroup_examplifier/subgroup_examplifier.c" they are in the main file (the file which contains the "main()" function), now I keep them in the before-mentioned library . . . ^^
 *
 * Also now I abstract out the concept of additive and multiplicative group identities using an enum defined over at "../../libraries/mathematics/universal_group_library.h" (enum "GROUP_IDentity").
 * The N_Combine function does NOT (!) depend on this.
 *
 * ##### === CURRENT STATUS === #####
 * Almost finished rewritting "subgroup_examplifier.c".
 *
 * Now I need to:
 * ~ Make the listing function of generators better. (more streamlined).
 * ~ Free all of the memory used by the various processes of this program.
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
    unsigned long permutation_length;
    struct permutation_piece *permutation;
    struct content unit;
} array_piece; typedef array_piece *table_type;

unsigned long cardinality;
table_type LOOKUP_table;

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

void print_subgroup(struct permutation_piece *generator, unsigned long horizontal_offset) {
    printf("<%s> = {", generator->next->unit->ASCII_numerical);

    struct permutation_piece *starting_point = hor(generator, horizontal_offset);
    struct permutation_piece *do_loop_iterator = starting_point; do {
	printf("%s", do_loop_iterator->unit->ASCII_numerical); do_loop_iterator = do_loop_iterator->next;
	if (do_loop_iterator == starting_point) break;
	else printf(", ");
    } while (1); printf("}\n");
}

// Returns a linked list which is in order of the permutation of the subgroup in question,
// Think of a chain of shackles, this chain is returned at the shackle which points to the identity element unit's struct at a struct vertibrae data type
struct permutation_piece *yield_subgroup(unsigned long start_element, group_OBJ group, unsigned long *generator_count) {
    struct permutation_piece *iterator = (struct permutation_piece *) malloc(sizeof(struct permutation_piece)); // Create element
    iterator->unit = &content_lookup((unsigned long) boolean_from_ID_Sloth(group))->unit; // Set the identity value
    iterator->next = iterator; // Make it circular

    unsigned long subgroup_cardinality = 1; // << For we have already inserted the first element
    for (unsigned long generated_element = start_element; generated_element != boolean_from_ID_Sloth(group); generated_element = N_combine_ABSTR(group->MOD, generated_element, start_element, group->ID)) {
	iterator = permutation_insert(generated_element, iterator); // << Put the current power of g into the permutation data structure
	subgroup_cardinality++;
    }

    content_lookup(start_element)->permutation_length = subgroup_cardinality;
    if (subgroup_cardinality == cardinality) (*generator_count)++;
    return iterator->next;
}

void triple_ref_LL_insert(struct triple_ref_LL **tracer, unsigned long new_ulong) {
    struct triple_ref_LL *new_LL_element = (struct triple_ref_LL *) malloc(sizeof(struct triple_ref_LL)); // Fix existence of new pointer_list element
    new_LL_element->next = NULL;
    new_LL_element->element = new_ulong;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_LL_element; // <===-- And place the location of new_LL_element into the next field of the previous insertion --==###
}

struct triple_ref_LL *circle(struct triple_ref_LL **channel) {
    struct triple_ref_LL *last_element, *first_element;
    last_element = first_element = (struct triple_ref_LL *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
}

struct triple_ref_LL *establish_LL(char **argv, group_OBJ group, struct triple_ref_LL **channel, unsigned long *cell_width) {
    char *path_to_filename; FILE *ELEMENT_database = open_group(argv[0], group, argv[1], &path_to_filename); cardinality = 0;
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { triple_ref_LL_insert(channel, group_ELEMENT); cardinality++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct triple_ref_LL *last_element = circle(channel);
    *cell_width = char_in_val(last_element->element);
    return last_element->next;
}

void replace_LL_with_table(struct triple_ref_LL *chain, unsigned long cell_width, group_OBJ group, unsigned long *generator_count) {
    LOOKUP_table = (array_piece *) malloc(sizeof(array_piece) * cardinality);
    /* ^^ Allocates memory space on the heap for the table. ^^ */

    unsigned long index = 0; struct triple_ref_LL *do_loop_iterator = chain; do {
	struct triple_ref_LL *process = do_loop_iterator;
	LOOKUP_table[index].unit.literal = process->element;
	do_loop_iterator = process->next; free(process); index++;
    } while (do_loop_iterator != chain); /* << Creates the table. ^^ */

    for (index = 0; index < cardinality; index++) {
	LOOKUP_table[index].permutation = yield_subgroup(LOOKUP_table[index].unit.literal, group, generator_count);
	LOOKUP_table[index].unit.ASCII_numerical = str_from_ul(LOOKUP_table[index].unit.literal, cell_width);
    }
}

unsigned long LL_count(struct triple_ref_LL *power) {
    unsigned long LL_count = 1;
    struct triple_ref_LL *iter = power; do {
	iter = iter->next;
	LL_count++;
    } while (iter != power);
    return LL_count;
}

void print_LL(struct triple_ref_LL *power) {
    if (power == NULL) exit(0);
    struct triple_ref_LL *iter = power; do {
	printf("%lu\n", iter->element);
	iter = iter->next;
    } while (iter != power);
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

    unsigned long generator_count = 0; unsigned long cell_width; struct triple_ref_LL *identity_element = establish_LL(argv, group, (struct triple_ref_LL **) sub_ordinator(), &cell_width);
    replace_LL_with_table(identity_element, cell_width, group, &generator_count);

    for (unsigned long i = shifts->Y; i < cardinality + shifts->Y; i++) print_subgroup(LOOKUP_table[i % cardinality].permutation, shifts->X);

    char *adjective = adjective_from_ID_Sloth(group);
    char *symbol = operation_symbol_from_ID_Sloth(group);
    fprintf(stdout, "\nThe %s group of integers modulo %s, which is denoted '\u2115%s%s', contains %lu elements, in standard mathematical notation:\n", adjective, argv[1], argv[1], symbol, cardinality);
    fprintf(stdout, "|\u2115%s%s| = %lu\n", argv[1], symbol, cardinality);
    // ^^^ Print cardinality information about this group

    struct triple_ref_LL **channel = (struct triple_ref_LL **) sub_ordinator();
    for (unsigned long i = 0; i < cardinality; i++) if (LOOKUP_table[i].permutation_length == cardinality) triple_ref_LL_insert(channel, LOOKUP_table[i].unit.literal);
    struct triple_ref_LL *link; if (generator_count > 0) link = circle(channel)->next;

    // generator_count = LL_count(link);
    if (!generator_count) {
	fprintf(stdout, "\nThis group contains 0 generators.\n");
    } else {
	fprintf(stdout, "\nThis group contains %lu generators:\n", generator_count);
	print_LL(link);
    }

    return 0;
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. At the very least I know this to be true for additive groups.
 */
