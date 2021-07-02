#include "shared_information.h"
#include "../../libraries/mathematics/maths.h"

unsigned long base_number, Public_Result_Alice;

int main(int argc, char **argv) { if (argc == 4) { cap = ul_from_str(argv[1]); base_number = ul_from_str(argv[2]); Public_Result_Alice = ul_from_str(argv[3]); }
    fprintf(stderr, "Arrived on Bob's computer\n");
    if (argc != 4) { fprintf(stderr, "Insufficient arguments.\n"); return -2; }

    char *opened_file; FILE *input_file = open_modular_group(fopen("/dev/null", "a"), argv[0], cap, MULTIPLICATIVE_IDENTITY, &opened_file); free(opened_file);
    struct group_element *group_ll = group_elements_in_file((struct group_element **) sub_ordinator(), input_file);

    fprintf(stdout, "\n"); unsigned long Bob_private_exponent = 0;
    while (!Bob_private_exponent) {
	fprintf(stdout, "Base number: %lu\n", base_number);
	fprintf(stdout, "Modulus: %lu\n", cap);
	fprintf(stdout, "Alice's public result: %lu\n", Public_Result_Alice);
	fprintf(stdout, "Bob's private exponent: ");
	fscanf(stdin, "%lu", &Bob_private_exponent);
	Bob_private_exponent = present(group_ll, Bob_private_exponent); }

    execlp(ENDPOINT_ALICE, argv[0], argv[1], argv[2], str_from_ul(mod_exponentiate(base_number, Bob_private_exponent, cap), 0), NULL);
}
