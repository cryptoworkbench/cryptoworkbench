/* This will be an entire rewrite of "subgroup_examplifier".
 *
 * Functional functions and definitions, namely the ones that only pertain to presentation, parsing errors, help message, etc, and not to the underlying mathematics per-se, are now in "ERROR_FUNCTIONS.h"
 * Over at "../subgroup_examplifier/subgroup_examplifier.c" they are in the main file (the file which contains the "main()" function), now I keep them in the before-mentioned library . . . ^^
 *
 * Also now I abstract out the concept of additive and multiplicative group identities using an enum defined over at "../../libraries/mathematics/universal_group_library.h" (enum "GROUP_IDentity").
 */
#include <stdio.h>
#include <stdlib.h>
#include "error_functions.h" // <<< Needed for "HELP_AND_QUIT()" , "MOD_not_parsable_ERROR()", "ID_not_parsable_ERROR"
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

unsigned long read_ul(struct vertibrae *ol) {
    return ol->unit.literal;
}

char *read_numerical(struct vertibrae *ol) {
    return ol->unit.ASCII_numerical;
}

array_piece *table_partition_search(unsigned long ul) {
    for (unsigned long iter = 0; iter < cardinality; iter++)
	if (LOOKUP_table[iter].unit.literal == ul) return &LOOKUP_table[iter];
	// if (LOOKUP_table[iter].unit.literal == ul) return LOOKUP_table + iter;

    return NULL;
}

array_piece *table_partition_search_two(unsigned long ul) {
    void *looper = (void *) LOOKUP_table;

    for (unsigned long i = 0; i < cardinality; i++) {
	if (read_ul( (array_piece *) looper) == ul) return (array_piece *) looper;
	else looper += sizeof(struct vertibrae);
    }
}

/* This function does seem to work
array_piece *table_partition_search_three(unsigned long ul) {
    array_piece *looper = LOOKUP_table;

    unsigned long i = 0;
    for (i = 0; i < cardinality; i++) {
	if (looper->unit.literal == ul) return looper;
	else { looper++; i++; }
    }

    return NULL;
} */

void triple_ref_LL_insert(struct triple_ref_LL **tracer, unsigned long new_ulong) {
    struct triple_ref_LL *new_LL_element = (struct triple_ref_LL *) malloc(sizeof(struct triple_ref_LL)); // Fix existence of new pointer_list element
    new_LL_element->next = NULL;
    new_LL_element->element = new_ulong;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_LL_element; // <===-- And place the location of new_LL_element into the next field of the previous insertion --==###
}

struct triple_ref_LL *establish_LL(char **argv, struct triple_ref_LL **channel, unsigned long *cell_width, group_OBJ group) {
    char *path_to_filename; FILE *ELEMENT_database = open_group(argv[0], group, argv[1], &path_to_filename); cardinality = 0;
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { triple_ref_LL_insert(channel, group_ELEMENT); cardinality++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct triple_ref_LL *last_element, *first_element;
    last_element = first_element = (struct triple_ref_LL *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    *cell_width = char_in_val(last_element->element);
    return last_element->next;
}

void replace_LL_with_table(struct triple_ref_LL *chain, unsigned long cell_width) {
    LOOKUP_table = (array_piece *) malloc(sizeof(array_piece) * cardinality);
    /* ^^ Allocates memory space on the heap for the table. ^^ */

    unsigned long index = 0; struct triple_ref_LL *do_loop_iterator = chain; do {
	struct triple_ref_LL *process = do_loop_iterator;
	LOOKUP_table[index].unit.literal = process->element;
	LOOKUP_table[index].unit.ASCII_numerical = str_from_ul(LOOKUP_table[index].unit.literal, cell_width);
	do_loop_iterator = process->next; free(process); index++;
    } while (do_loop_iterator != chain); /* << Creates the table. ^^ */
}

int main(int argc, char **argv) { group_OBJ group;
    if (5 < argc || argc > 1 && match(argv[1], help_queries)) HELP_AND_QUIT(argv[0]); /* <== Display help if necessary. */ else group = (group_OBJ) malloc(sizeof(group_OBJ));
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]); // << Parse MOD
    if (3 > argc || !STR_could_be_parsed_into_group_OBJ_ID_Sloth(argv[2], group)) ID_not_parsable_ERROR(argv[1], argv[2]); // << Parse ID

    /* Process offset values */
    struct offset_values *shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) {
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!boolean_from_ID_Sloth(group)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the mod value to shifts when dealing with additive groups (see "MATH_HINT_ONE")
    }

    unsigned long cell_width; struct triple_ref_LL *identity_element = establish_LL(argv, (struct triple_ref_LL **) sub_ordinator(), &cell_width, group);
    replace_LL_with_table(identity_element, cell_width);
    
    printf("ID: %lu\n", LOOKUP_table[0].unit.literal);
    printf("Cell width: %lu\n", cell_width);
    printf("Group cardinality: %lu\n\n\n", cardinality);

    for (unsigned long index = 0; index < group->MOD; index++) {
	void *ptr = (void *) table_partition_search(index);
	if (ptr == NULL) fprintf(stdout, "Element %lu not found.\n", index);
	else fprintf(stdout, "Element %lu found: %s, %lu\n", index, read_numerical((struct vertibrae *) ptr), read_ul((struct vertibrae *) ptr));
    }

    return 0;
}

/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. At the very least I know this to be true for additive groups.
 */
