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
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"

struct offset_values { unsigned long Y; unsigned long X; };
// ^^ Not related to groups necessarily, so this is here instead of in "../../libraries/mathematics/universal_group_library.h"

/*
struct vertibrae *build_backbone(char *prog_NAME, struct vertibrae **channel, unsigned long *group_cardinality, struct group_prams *group) {
    char *path_to_filename; char *group_CAP; FILE *ELEMENT_database = open_group(prog_NAME, group, &path_to_filename, &group_CAP);
    // ^^^ Open filestream to element database

    unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { vertibrae_insert(channel, group_ELEMENT); (*group_cardinality)++; }
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    close_group(prog_NAME, group_CAP, symbol_to_use(group->ID), path_to_filename, ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    struct vertibrae *last_element, *first_element;
    last_element = first_element = (struct vertibrae *) disintermediate( (void **) channel);
    while (last_element->next) {
	last_element = last_element->next;
    } last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return last_element;
}
*/

void symbols(group_OBJ group) {
    printf("Numerical denomination as ASCII character: %s\n", numerical_denomination_from_ID_Sloth(group));
    printf("Operation symbol as ASCII character: %s\n", operation_symbol_from_ID_Sloth(group));
    printf("Noun: %s\n", noun_from_ID_Sloth(group));
    printf("Multiple: %s\n", multiple_from_ID_Sloth(group));
    printf("Adjective: %s\n", adjective_from_ID_Sloth(group));
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

    char *filename;
    open_group(argv[0], group, argv[1], &filename);
    printf("Filename: %s\n", filename);

    return 0;
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. At the very least I know this to be true for additive groups.
 */
