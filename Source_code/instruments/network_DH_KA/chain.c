/* Do this:
 * make chain
 * cd ~/crypto_lab/tools
 * watch -n 1 cat temp
 * chain 2> temp
 */
#include "shared_information.h"

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

int main(int argc, char **argv) { if (argc == 2) { cap = ul_from_str(argv[1]); }
    fprintf(stderr, "Agreeing on public variables . . .\n");
    if (argc != 2)  { fprintf(stdout, "Insufficient arguments.\n"); return -1; }

    char *opened_file; FILE *input_file = open_modular_group(open_logbook(), argv[0], cap, MULTIPLICATIVE_IDENTITY, &opened_file); free(opened_file);
    struct group_element *group_ll = group_elements_in_file((struct group_element **) sub_ordinator(), input_file);

    struct group_element *iter = group_ll; do {
	unsigned long order = length(iter->value);
	fprintf(stdout, "|<%lu>| = %lu\n", iter->value, order);
	iter = iter->next;
    } while (iter != group_ll);
    // ^^^ Display group in stdout

    unsigned long base_number; do {
	fprintf(stdout, "\nPlease pick an element from this group to use as a base number: ");
	fscanf(stdin, "%lu", &base_number);
	base_number = present(group_ll, base_number);
    } while (base_number == 0);
    // ^^^ Determine base number

    /* ### NOW WE HAVE TO WRITE THE MULTIPLICATIVE GROUP'S MODULUS AND THE BASE NUMBER WITHIN THIS GROUP TO AN EXTERNAL FILE ### */
    execlp(ENDPOINT_ALICE, argv[0], argv[1], str_from_ul(base_number, 0), NULL); }
// ^^^ Incarnate current operation name into next phase
