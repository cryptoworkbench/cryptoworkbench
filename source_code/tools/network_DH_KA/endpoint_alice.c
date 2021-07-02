/* ABSTRACT:
 * This program is supposed to simulate Alice's computer.
 */
#include "shared_information.h"

int main(int argc, char **argv) {
    if (argc == 3) { // <<< First run point
	unsigned long cap = ul_from_str(argv[1]); // << Cap is defined in the header file ^^
	unsigned long base_number = ul_from_str(argv[2]);
	char *opened_file; FILE *input_file = open_modular_group(fopen("/dev/null", "a"), argv[0], cap, MULTIPLICATIVE_IDENTITY, &opened_file); free(opened_file);
	struct group_element *group_ll = group_elements_in_file((struct group_element **) sub_ordinator(), input_file);

	unsigned long Alice_private_exponent; do {
	    fprintf(stdout, "\nBase number: %lu\n", base_number);
	    fprintf(stdout, "Modulus: %lu\n", cap);
	    fprintf(stdout, "Alice's private exponent: ");
	    fscanf(stdin, "%lu", &Alice_private_exponent);
	    Alice_private_exponent = present(group_ll, Alice_private_exponent);
	} while (Alice_private_exponent == 0);

	execlp(ENDPOINT_BOB, argv[0], argv[1], argv[2], str_from_ul(mod_exponentiate(base_number, Alice_private_exponent, cap), 0), NULL);
    } else if (argc == 4) { // <<< Second run point
	unsigned long cap = ul_from_str(argv[1]); // << Cap is defined in the header file ^^
	unsigned long base_number = ul_from_str(argv[2]);

	char *opened_file; FILE *input_file = open_modular_group(fopen("/dev/null", "a"), argv[0], cap, MULTIPLICATIVE_IDENTITY, &opened_file); free(opened_file);
	struct group_element *group_ll = group_elements_in_file((struct group_element **) sub_ordinator(), input_file);
    } else
    {   fprintf(stderr, "Insufficient arguments!\n");
	return -1; }
}
