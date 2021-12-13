/* Entire rewrite of "subgroup_examplifier".
 */
#include <stdio.h>
#include <stdlib.h>
#include "ERROR_FUNCTIONS.h" // <<< Needed for "HELP_AND_QUIT()" , "MOD_not_parsable_ERROR()", "ID_not_parsable_ERROR"
#include "../../libraries/functional/string.h" // <<< Needed for variadic function "match()"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"

struct offset_values {
    unsigned long Y;
    unsigned long X;
};

int main(int argc, char **argv) { group_OBJ *group; // <<< Declare a pointer variable because we may allocate space to store group variables
    if (5 < argc || argc > 1 && (match(argv[1], 2, "--help", "-h"))) HELP_AND_QUIT(argv[0]); else group = (group_OBJ *) malloc(sizeof(group_OBJ));
    // ^^ Allocate memory for MOD and ID values when required, otherwise displays help 

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
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G.
 */
