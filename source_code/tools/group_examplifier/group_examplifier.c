/* ABSTRACT:
 * This program outputs a list of elements that belong to the specified modular group like so:
 * ./argv_one <group modulus> <group identity>
 * END ABSTRACT. */
#include <stdio.h>
#include "../../libraries/mathematics/maths.h" // <<< Needed for "GCD()"
#include "../../libraries/functional/string.h" // <<< Needed for "ul_ptr_from_str()"
// ^^^ LIBRARY INCLUSIONS

#define ARGV_TWO_INSTRUCTION "Please provide as second argument '0' for the additive identity,\nOr '1' for the multiplicative identity.\n"
#define ARGV_ONE_INSTRUCTION "Please provide as first argument the modulus of the group (in decimal notation).\n"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^^ MATHEMATICAL DEFINITIONS

#define INCORRECT_SYNTAX "Incorrect syntax.\n\nProgram usage:\n%s <group modulus> <group identity>\n\n\nExiting '-1'.\n"

struct group_prams { unsigned long id; unsigned long cap; };
struct group_prams group; // <<< No need for malloc();
FILE *main_fs; // <<< Program will only deal with main_fs
// ^^^ Prepare program variables

int QUIT_ON_ARGV_TWO_ERROR() {
    fprintf(stderr, ARGV_TWO_INSTRUCTION);
    return -3;
}

int QUIT_ON_ARGV_ONE_ERROR() {
    fprintf(stderr, ARGV_ONE_INSTRUCTION);
    return -2;
}

int main(int argc, char **argv) {
    switch (argc) {
	case 3: if (! (ul_ptr_from_str(&group.id, argv[2]))) return QUIT_ON_ARGV_TWO_ERROR();
	case 2: if (! (ul_ptr_from_str(&group.cap, argv[1]))) return QUIT_ON_ARGV_ONE_ERROR(); break;
	default: fprintf(stderr, INCORRECT_SYNTAX, argv[0]); return -1; }
    // ^^^ Give error when supplied terminal arguments were invalid or else parse them correctly

    if (3 > argc) return QUIT_ON_ARGV_TWO_ERROR();
    if (2 > argc) return QUIT_ON_ARGV_ONE_ERROR();
    // ^^^ Give error on missing ones

    for (unsigned long element = group.id; element < group.cap; element++)
	if (group.id == ADDITIVE_IDENTITY || GCD(group.cap, element) == MULTIPLICATIVE_IDENTITY)
	    fprintf(stdout, "%lu\n", element);
    // ^^^ fprintf() the list of elements to stdout (which can be redirected by the shell using '>')

    return 0;
}
