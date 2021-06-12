/* Intented program operations:
 * This program creates a lists of all distinct elements that belong to a particular multiplicative group of integers defined by passing on the group modulus to argv[0]
 *
 * Currently saves to lists/multiplicative_group_of_integers_modulo_<group modulus>
 *
 * Segment error occurs when folder "lists" is not in the working directory.
 *
 * It guarenteed to work perfectly only when executed on the workbench.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#define MULTIPLICATIVE_IDENTITY 1
const char *folder_name = "lists"; // That is /workbench/lists/ (the last '/' is added by the copy_over function on line
const char *name_prefix = "multiplicative_group_of_integers_modulo_";

typedef struct _ll {
    unsigned long member;
    struct _ll *next;
} ll;

int main(int argc, char **argv) {
    fprintf(stdout, "I am used to export a list of all of the distinct elements that are in a multiplicative group of integers.\n\n");

    unsigned long number;
    if (argc > 2)
    {   fprintf(stderr, "Error\n\nWrong input syntax.\n\nPlease use less arguments.\n\n\nReturning -1.\n");
	return -1; }
    else if (argc == 2)
    {   number = ul_from_str(argv[1]); }
    else
    {   fprintf(stdout, "Number to begin with: ");
	fscanf(stdin, "%lu", &number); }

    fprintf(stdout, "\nThese are the members of \u2124_%lu*\n", number);

    char *potential_argv_1_copy = str_from_ul(number, 0); // <<< For temporary storage in string form of <group modulus> if <group modulus> was not interpreted from argv[1]
    char *output_filename = (char *) malloc(sizeof(char) * (strlen(folder_name) + 1 + strlen(name_prefix) + strlen(potential_argv_1_copy) + 1)); // << + 1 for string terminating 0 byte
    *copy_over(copy_over(copy_over(copy_over(output_filename, folder_name), "/"), name_prefix), potential_argv_1_copy) = 0; free(potential_argv_1_copy);
    // *copy_over(copy_over(output_filename, name_prefix), potential_argv_1_copy) = 0; free(potential_argv_1_copy);
    /* Prepare output filename */

    FILE *out = fopen(output_filename, "w");
    /* Open filestream to output file */

    for (unsigned long iter = 1; iter < number; iter++)
	if (GCD(number, iter) == MULTIPLICATIVE_IDENTITY)
	{   fprintf(stdout, "\n%lu", iter);
	    fprintf(out, "%lu\n", iter); }
    /* fprintf to stdout and output file */

    char yes_no; do { // I do not get why it repeats the below sentence upon entering the wrong character (not 'Y' or 'y' or 'N' or 'n')
	fprintf(stdout, "\n\nWrite data to output file (y/n) ?: ");
	fscanf(stdin, "%c", &yes_no);
    } while (!(yes_no == 'Y' || yes_no == 'y') && !(yes_no == 'N' || yes_no == 'n') );
    if (yes_no == 'Y' || yes_no == 'y') {
	fprintf(stdout, "Written data to output file %s\n", output_filename);
    } else {
	fprintf(stdout, "Bye bye\n");
    } return 0; }
