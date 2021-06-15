/* CURRENT PROGRAM AMBITIONS:
 * The "/cryptoworkbench/lists" folder will be used in conjunction with this program to give the cryptoworkbench a form of persistent working memory.
 *
 *
 * The identity element can either be '0' or '1' ==> That is to say that this program generates both additive and multiplicative groups.
 *
 * As with "general_subgroup_generator", the group parameters are defined by argv[1] and argv[2].
 *
 * Think "general_group_generator <group modulus> <group ID>"
 *
 * CURRENT KNOWN ERRORS:
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
// ^^^ LIBRARY INCLUSIONS

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^^ MATHEMATICAL DEFINITIONS

#define INCORRECT_SYNTAX "Incorrect syntax.\n\nProgram usage:\n%s <group modulus> <group identity>\n\n\nExiting '-1'.\n"
char *adjective_to_use = "multiplicative"; // <<< We expect to be using this adjective
const char *alternative_adjective = "additive";
const char *folder = "lists/"; // That is /workbench/lists/
const char *filename_main = "_group_of_integers_modulo_";
// ^^^ STRINGS WE NEED

struct group_prams { unsigned long modulus; unsigned long identity; };
struct group_prams group; // <<< No need for malloc();
FILE *main_fs; // <<< Program will only deal with main_fs
// ^^^ Prepare program variables

int main(int argc, char **argv) {
    switch (argc) {
	case 4: if (streql(argv[3], "--stdout")) main_fs = stdout;
	case 3: group.identity = ul_from_str(argv[2]);
	case 2: group.modulus = ul_from_str(argv[1]); break;
	default: fprintf(stderr, INCORRECT_SYNTAX, argv[0]); return -1;
    }
    // ^^^ Take in supplied variables

    if (3 > argc) { fprintf(stderr, "Group identity not supplied, please provide group ID: "); fscanf(stdin, "%lu", &group.identity); }
    if (2 > argc) { fprintf(stderr, "Group modulus not supplied, please provide group modulus: "); fscanf(stdin, "%lu", &group.modulus); }
    // ^^^ Take in not supplied variables

    if (main_fs != stdout) {
	if (group.identity == ADDITIVE_IDENTITY) adjective_to_use = (char *) alternative_adjective;
	// ^^^ Figure out adjective required for output file name

	char *output_filename = (char *) malloc(sizeof(char) * (strlen(folder) + strlen(adjective_to_use) + strlen(filename_main) + strlen(argv[1]) + 1));
	*copy_over(copy_over(copy_over(copy_over(output_filename, folder), adjective_to_use), filename_main), argv[1]) = 0;
	main_fs = fopen(output_filename, "w"); fprintf(stderr, "Printing to file: \"%s\"\n", output_filename); free(output_filename);
	// ^^^ Open file for list export of elements that belong to the group specified by 'argv[1]' and 'argv[2]'
    }

    for (unsigned long element = group.identity; element < group.modulus; element++)
	if (group.identity == ADDITIVE_IDENTITY || GCD(group.modulus, element) == MULTIPLICATIVE_IDENTITY)
	    fprintf(main_fs, "%lu\n", element);
    // ^^^ Export list of element to external file

    if (main_fs != stdout) fclose(main_fs);
    return 0;
    /* ^^^ Close external filestream (if opened) and return a success code of "0" */ }
