/* Intented program operation:
 * ~ Interprets list of group elements from file in workbench/lists/ named multiplicative_group_of_integers_modulo_group_modulus
 * ~ Find first generator
 *
 * Ps.
 * Upon execution failure, check a multiplicative group of integers was generated to a file in workbench/lists/
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
// ^^^ LIBRARY INCLUSIONS

#define MULTIPLICATIVE_IDENTITY 1
// ^^^ MATHEMATICAL DEFINITIONS

const char *folder_name = "lists/";
const char *multiplicative_group_generator = "multiplicative_group_generator";
const char *name = "multiplicative_group_of_integers_modulo_";
const char *base_question = "Please pick an element from this group to use as base (generator): ";
// ^^^ NECESSARY DATA

struct group_element { unsigned long value; struct group_element *next; }; // <<< For use with triple ref pointers
unsigned long group_modulus, group_cardinality;
// ^^^ PROGRAM VARIABLES

void insert(struct group_element **channel, unsigned long group_element) {
    struct group_element *new_element = (struct group_element *) malloc(sizeof(struct group_element));
    new_element->value = group_element;

    while (*channel) // <<< Find the last insertion
	channel = &(*channel)->next;

    *channel = new_element; // <<< Place new element in 'next' field of the last insertion
}

struct group_element *ll_from_file(struct group_element **channel, FILE *input_file) {
    unsigned long group_element;
    while (fscanf(input_file, "%lu\n", &group_element) == 1) { insert(channel, group_element); group_cardinality++; }
    fclose(input_file);
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    struct group_element *last_element, *first_element;
    last_element = first_element = (struct group_element *) disintermediate( (void **) channel);
    while (last_element->next) last_element = last_element->next;
    last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return first_element;
}

unsigned long length(unsigned long element) {
    unsigned long sub_order = MULTIPLICATIVE_IDENTITY;
    for (unsigned long iter = element; iter != MULTIPLICATIVE_IDENTITY; iter = (iter * element) % group_modulus)
	sub_order++;

    return sub_order;
}

unsigned long present(struct group_element *ll, unsigned long element) {
    struct group_element *iter = ll; do {
	if (element == iter->value)
	    return element;
	iter = iter->next;
    } while (iter != ll);

    return 0;
}

int main(int argc, char **argv) {
    if (argc == 2) { group_modulus = ul_from_str(argv[1]); }
    // ^^^ Interpret group modulus from the first terminal argument
    
    else { fprintf(stderr, "Wrong argument count.\n\nExiting '-1'.\n"); return -1; }
    // ^^^ Or exit upon wrong argument count.

    char *file_to_open = (char *) malloc(sizeof(char) * (strlen(folder_name) + strlen(name) + strlen(argv[1]) + 1) ); // << + 1 for the string terminator
    *copy_over(copy_over(copy_over(file_to_open, folder_name), name), argv[1]) = 0; // << Setting everyting at once, including the terminating 0 byte
    // ^^^ Prepare path to pass on to "fopen()"

    FILE *input_file;
    if (!(input_file = fopen(file_to_open, "r"))) {
	fprintf(stderr, "No such file \"%s\".\n\nRunning \"%s\".\n", file_to_open, multiplicative_group_generator);
	char *command = (char *) malloc(sizeof(char) * (strlen(multiplicative_group_generator) + 1 + strlen(argv[1]) + 1));
	*copy_over(copy_over(copy_over(command, multiplicative_group_generator), " "), argv[1]) = 0;
	system(command); free(command);

	if (!(input_file = fopen(file_to_open, "r")))
	{ fprintf(stderr, "Failed to create file using %s.\n\n\nExiting '-3'.\n", multiplicative_group_generator); return -3; } }
    else fprintf(stdout, "Successfully opened the file \"%s\".\n\n", file_to_open);
    // ^^^ Prepare filestream

    struct group_element *group_ll = ll_from_file((struct group_element **) sub_ordinator(), input_file);
    // ^^^ Get group from file

    fprintf(stdout, "Group interpreted from file \"%s\":\n", file_to_open); free(file_to_open);
    struct group_element *iter = group_ll; do {
	unsigned long order = length(iter->value);
	fprintf(stdout, "|<%lu>| = %lu\n", iter->value, order);
	iter = iter->next;
    } while (iter != group_ll);
    // ^^^ Display group in stdout

    fprintf(stdout, "\nGroup contains %lu elements.\n\n\n", group_cardinality);

    unsigned long base = 0; while (!base) {
	fprintf(stdout, "Please pick an element from this group to use as base (generator): ");
	fscanf(stdin, "%lu", &base);
	base = present(group_ll, base); }
    // ^^^ Determine base number

    fprintf(stdout, "\n");
    unsigned long private_alice = 0; while (!private_alice) {
	fprintf(stdout, "Generator: %lu\n", base);
	fprintf(stdout, "Alice's private exponent: ");
	fscanf(stdin, "%lu", &private_alice);
	private_alice = present(group_ll, private_alice); }
    // ^^^ Determine private_alice

    fprintf(stdout, "\n");
    unsigned long private_bob = 0; while (!private_bob) {
	fprintf(stdout, "Generator: %lu\n", base);
	fprintf(stdout, "Alice's secret exponent: %lu\n", private_alice);
	fprintf(stdout, "Bob's private exponent: ");
	fscanf(stdin, "%lu", &private_bob);
	private_bob = present(group_ll, private_bob); }
    // ^^^ Determine private_bob

    fprintf(stdout, "\n\n# PUBLICLY AGREED-UPON VARIABLES:\n# ~ Multiplicative group: <\u2124/%lu\u2124, *>\n# ~ Base number (generator): %lu\n", group_modulus, base);
    fprintf(stdout, "#\n# SECRET VARIABLES:\n# ~ Alice's secret exponent: %lu\n# ~ Bob's secret exponent: %lu", private_alice, private_bob);
    // ^^^ Display selected variables

    fprintf(stdout, "\n#\n# Calculation Alice makes before communication:\n");
    unsigned long public_alice = mod_exponentiate(base, private_alice, group_modulus);
    fprintf(stdout, "# ~ %lu^%lu \u2261 %lu (%% %lu)\n", base, private_alice, public_alice, group_modulus);
    // ^^^ Display calculation on Alice's side

    fprintf(stdout, "#\n# Calculation Bob makes before communication:\n");
    unsigned long public_bob = mod_exponentiate(base, private_bob, group_modulus);
    fprintf(stdout, "# ~ %lu^%lu \u2261 %lu (%% %lu)", base, private_bob, public_bob, group_modulus);
    // ^^^ Display calculation on Bob's side

    fprintf(stdout, "\n#\n# INFORMATION COMMUNICATED OVER OPEN CHANNEL:\n# ~ Information from Alice to Bob: '%lu'\n# ~ Information from Bob to Alice: '%lu'\n", public_alice, public_bob);
    // ^^^ Simulate open channel communication

    fprintf(stdout, "#\n# Calculation Alice makes after communication with Bob:\n");
    unsigned long mutual_alice = mod_exponentiate(public_bob, private_alice, group_modulus);
    fprintf(stdout, "# ~ %lu^%lu \u2261 %lu (%% %lu)", public_bob, private_alice, mutual_alice, group_modulus);

    fprintf(stdout, "\n#\n# Calculation Bob makes after communication with Alice:\n");
    unsigned long mutual_bob = mod_exponentiate(public_alice, private_bob, group_modulus);
    fprintf(stdout, "# ~ %lu^%lu \u2261 %lu (%% %lu)", public_alice, private_bob, mutual_bob, group_modulus);

    if (mutual_bob == mutual_alice) {
	fprintf(stdout, "\n#\n##### KEY-AGREEMENT SUCCESSFULL ! =====>\n#####\n##### Alice and Bob mutually arrived at the shared secret '%lu' <=====", mutual_bob);
	fprintf(stdout, "\n###\n### Try to figure out '%lu' with the information below!\n###\n## INFORMATION KNOWN TO EVE WHO'S BEEN LISTING ON THE OPEN COMMUNICATION CHANNEL ALL ALONG:", mutual_bob);
	fprintf(stdout, "\n## ~ Multiplicative group of integers used: <\u2124/%lu\u2124>", group_modulus);
	fprintf(stdout, "\n## ~ Base number (generator): %lu", base);
	fprintf(stdout, "\n## ~ %lu as %lu^x \u2261 %lu (for some element x in <\u2124/%lu\u2124, *>)", public_alice, base, public_alice, group_modulus);
	fprintf(stdout, "\n## ~ %lu as %lu^y \u2261 %lu (for some element y in <\u2124/%lu\u2124, *>)\n", public_bob, base, public_bob, group_modulus);
	return 0;
    } else {
	fprintf(stdout, "\n#\n##### Calculation unsuccessfull, unknown error occured.\n#\n#Exiting '-3'.\n");
	return -3;
    } }
