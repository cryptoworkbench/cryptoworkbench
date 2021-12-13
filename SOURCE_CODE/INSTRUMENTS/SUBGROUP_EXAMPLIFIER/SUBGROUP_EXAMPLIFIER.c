/* This will be an entire rewrite of "subgroup_examplifier".
 *
 * Functional functions and definitions, namely the ones that only pertain to presentation, parsing errors, help message, etc, and not to the underlying mathematics per-se, are now in "ERROR_FUNCTIONS.h"
 * Over at "../subgroup_examplifier/subgroup_examplifier.c" they are in the main file (the file which contains the "main()" function), now I keep them in the before-mentioned library . . . ^^
 *
 * Also now I abstract out the concept of additive and multiplicative group identities using an enum defined over at "../../libraries/mathematics/universal_group_library.h" (enum "GROUP_IDentity").
 */
#include <stdio.h>
#include <stdlib.h>
#include "ERROR_FUNCTIONS.h" // <<< Needed for "HELP_AND_QUIT()" , "MOD_not_parsable_ERROR()", "ID_not_parsable_ERROR"
#include "../../libraries/functional/string.h" // <<< Needed for variadic function "match()"
// #include "../../libraries/functional/LOGBOOK_library.h" // << Needed for the definition of "struct group_prams"
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

int main(int argc, char **argv) { group_OBJ *group; // <<< Declare a pointer variable because we may allocate space to store group variables
    if (5 < argc || argc > 1 && (match(argv[1], 2, "--help", "-h"))) HELP_AND_QUIT(argv[0]); else group = (group_OBJ *) malloc(sizeof(group_OBJ));
    // ^^ Displays help when a wrong argument count was supplied, also when provoked using "-h" or "-help", otherwise allocates memory for MOD and ID struct sloths

    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_ID(argv[2], &group->ID)) ID_not_parsable_ERROR(argv[2]);
    // ^^ Automatically parse arguments that can be parsed, quit with error upon parsing error (/ impossibility)

    fprintf(stdout, "Group modulus: %lu\n", group->MOD);
    // ^^ Check the group modulus

    if (group->ID == ADDITIVE) fprintf(stdout, "0, additive. ENUM as int: %i\n", ID_as_boolean(group->ID));
    else if (group->ID == MULTIPLICATIVE) fprintf(stdout, "1, multiplicative. ENUM as int: %i\n", ID_as_boolean(group->ID));
    // ^^ Check the group ID

    struct offset_values *shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) {
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!ID_as_boolean(group->ID)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the mod value to shifts when dealing with additive groups
    } //    ^^^ << Do you remember Joseph-Louis Lagrange? (see "MATH_HINT_ONE")

    return 0;
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. At the very least I know this to be true for additive groups.
 */
