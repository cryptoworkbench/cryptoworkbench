/* ABSTRACT:
 * This program outputs a list of elements that belong to the specified modular group like so:
 * ./argv_one <group modulus> <group identity>
 * END ABSTRACT. */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
// ^^^ LIBRARY INCLUSIONS

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^^ MATHEMATICAL DEFINITIONS

#define INCORRECT_SYNTAX "Incorrect syntax.\n\nProgram usage:\n%s <group modulus> <group identity>\n\n\nExiting '-1'.\n"

struct group_prams { unsigned long modulus; unsigned long identity; };
struct group_prams group; // <<< No need for malloc();
FILE *main_fs; // <<< Program will only deal with main_fs
// ^^^ Prepare program variables

int main(int argc, char **argv) {
    switch (argc) {
	case 3: group.identity = ul_from_str(argv[2]);
	case 2: group.modulus = ul_from_str(argv[1]); break;
	default: fprintf(stderr, INCORRECT_SYNTAX, argv[0]); return -1; }
    // ^^^ Take in supplied variables

    if (3 > argc) { fprintf(stderr, "Group identity not supplied, please provide group ID: "); fscanf(stdin, "%lu", &group.identity); }
    if (2 > argc) { fprintf(stderr, "Group modulus not supplied, please provide group modulus: "); fscanf(stdin, "%lu", &group.modulus); }
    // ^^^ Take in not supplied variables

    for (unsigned long element = group.identity; element < group.modulus; element++)
	if (group.identity == ADDITIVE_IDENTITY || GCD(group.modulus, element) == MULTIPLICATIVE_IDENTITY)
	    fprintf(stdout, "%lu\n", element);
    // ^^^ fprintf() the list of elements to external file

    return 0;
}
