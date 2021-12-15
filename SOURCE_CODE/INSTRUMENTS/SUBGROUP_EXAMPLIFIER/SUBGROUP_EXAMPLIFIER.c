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

struct vertibrae {
    unsigned long permutation_length;
    struct permutation_piece *permutation;
    struct content unit;
};

void triple_ref_LL_insert(struct triple_ref_LL **tracer, unsigned long new_ulong) {
    struct triple_ref_LL *new_vertibrae = (struct triple_ref_LL *) malloc(sizeof(struct triple_ref_LL)); // Fix existence of new pointer_list element
    new_vertibrae->next = NULL;
    new_vertibrae->element = new_ulong;

    while (*tracer) // ###==-- Find last insertion --===>
	tracer = &(*tracer)->next;

    *tracer = new_vertibrae; // <===-- And place the location of new_vertibrae into the next field of the previous insertion --==###
}

struct triple_ref_LL *set_cardinality(char **argv, struct triple_ref_LL **channel, unsigned long *group_cardinality, group_OBJ group) {
    char *path_to_filename; FILE *ELEMENT_database = open_group(argv[0], group, argv[1], &path_to_filename);
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { triple_ref_LL_insert(channel, group_ELEMENT); (*group_cardinality)++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct triple_ref_LL *last_element, *first_element;
    last_element = first_element = (struct triple_ref_LL *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
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

    unsigned long cell_width; unsigned long group_cardinality = 0;
    struct triple_ref_LL *last_element = set_cardinality(argv, (struct triple_ref_LL **) sub_ordinator(), &group_cardinality, group);
    cell_width = char_in_val(last_element->element);
    struct triple_ref_LL *identity_element = last_element->next;

    printf("Id: %lu\n", identity_element->element);
    printf("Cell width: %lu\n", cell_width);
    printf("group cardinality: %lu\n", group_cardinality);

    struct vertibrae *array = (struct vertibrae *) malloc(sizeof(struct vertibrae) * group_cardinality);

    unsigned long index = 0; struct triple_ref_LL *do_loop_iterator = identity_element; do {
	array[index].unit.literal = do_loop_iterator->element;
	array[index].unit.ASCII_numerical = str_from_ul(array[index].unit.literal, cell_width);
	do_loop_iterator = do_loop_iterator->next; index++;
    } while (do_loop_iterator != identity_element);
    /* ^^^ Make an array of the required size. ^^^ */

    for (index = 0; index < group_cardinality; index++) fprintf(stdout, "Element: %s\n", array[index].unit.ASCII_numerical);

    return 0;
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. At the very least I know this to be true for additive groups.
 */
