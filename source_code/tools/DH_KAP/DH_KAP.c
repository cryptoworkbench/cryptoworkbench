/* Current program operations:
 * Takes a file from ~/crypto_lab/registry/ specified by argv[1]
 *
 * If the appropiate file is not present in "./../registry/", generates this file using "~/crypto_lab/instruments/group_examplifier argv[1] > ./../registry" (handled by registry_functions)
 *
 * Opens this file anyway.
 *
 * Proceeds to calculate and list all subgroup cardinalities. Then asks user for private exponents of Bob and Alice from specified group.
 *
 * Proceeds on to perform an example Diffie-Hellman key-agreement.
 *
 * INTENTED PROGRAM OPERATIONS:
 * Takes a file from ~/crypto_lab/registry/ specified by argv[1]
 *
 * If the appropiate file is not present in "./../registry/", generates this file using "~/crypto_lab/instruments/group_examplifier argv[1] > ./../registry" (handled by registry_functions)
 *
 * Opens this file anyway.
 *
 * Tries to interpret argv[1] (if specified) as an appropiate generator for example.
 *
 * If argv[1] is within the group, good, proceed.
 *
 * If argv[1] is not within the group, notify, and allow to correct
 *
 * Proceeds to calculate and list all subgroup cardinalities. Then asks user for private exponents of Bob and Alice from specified group.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/functional/logbook_functions.h"
// ^^ LIBRARY INCLUSIONS

#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^ MATHEMATICAL DEFINITIONS

const char *name = "multiplicative_group_of_integers_modulo_";
const char *base_question = "Please pick an element from this group to use as base (generator): ";
// ^^ NECESSARY DATA

struct group_element { unsigned long value; struct group_element *next; }; // <<< For use with triple ref pointers
unsigned long group_modulus;
// ^^ PROGRAM VARIABLES

void insert(struct group_element **channel, unsigned long group_element) {
    struct group_element *new_element = (struct group_element *) malloc(sizeof(struct group_element));
    new_element->value = group_element;

    while (*channel) // <<< Find the last insertion
	channel = &(*channel)->next;

    *channel = new_element; // <<< Place new element in 'next' field of the last insertion
}

struct group_element *ll_from_file(FILE *input_file, struct group_element **channel) {
    unsigned long group_element;
    while (fscanf(input_file, "%lu\n", &group_element) == 1) 
	insert(channel, group_element);
    // ^^^ Establish lineair linked list containing all group elements using the triple ref technique

    struct group_element *last_element, *first_element;
    last_element = first_element = (struct group_element *) disintermediate( (void **) channel);
    while (last_element->next) last_element = last_element->next;
    last_element->next = first_element;
    // ^^^ Take out of the end product a singly-linked list that is circular and destroy any intermediary memory used

    return first_element;
}

unsigned long length(unsigned long element) {
    unsigned long sub_order = ADDITIVE_IDENTITY;
    unsigned long iter = MULTIPLICATIVE_IDENTITY;
    do {iter = (iter * element) % group_modulus;
	sub_order++;
    } while (iter != MULTIPLICATIVE_IDENTITY); 

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

    char *filename; FILE *input_file = open_modular_group(argv[0], (struct group_prams) {group_modulus, MULTIPLICATIVE_IDENTITY}, &filename);
    struct group_element *group_ll = ll_from_file(input_file, (struct group_element **) sub_ordinator());
    // ^^ Get group from file

    char *BUFFER = BUFFER_OF_SIZE(200);
    sprintf(BUFFER, "Sourced <\u2124/%lu\u2124, *> successfully from filestream\n", group_modulus, filename); FLUSH_TO_FS(argv[0], BUFFER);
    sprintf(BUFFER, "Closed the filestream sourced by '%s'\n", filename); free(filename); FLUSH_TO_FS(argv[0], BUFFER); free(BUFFER);
    // ^^^ Notify logbook we got group from file

    struct group_element *iter = group_ll; do {
	unsigned long order = length(iter->value);
	fprintf(stdout, "|<%lu>| = %lu\n", iter->value, order);
	iter = iter->next;
    } while (iter != group_ll);
    // ^^^ Display group in stdout

    unsigned long base = 0; while (!base) {
	fprintf(stdout, "\nPlease pick an element from this group to use as a base number: ");
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

    fprintf(stdout, "\n# PUBLICLY AGREED-UPON VARIABLES:\n# ~ Multiplicative group: <\u2124/%lu\u2124, *>\n# ~ Base number: %lu\n", group_modulus, base);
    fprintf(stdout, "#\n# SECRET VARIABLES:\n# ~ Alice's secret exponent: %lu\n# ~ Bob's secret exponent: %lu\n", private_alice, private_bob);
    // ^^^ Display selected variables

    fprintf(stdout, "#\n# Calculation Alice makes before communication:\n");
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
	fprintf(stdout, "\n#\n##### KEY AGREEMENT SUCCESSFULL ! =====>\n#####\n##### Alice and Bob mutually arrived at the shared secret '%lu' <=====", mutual_bob);
	fprintf(stdout, "\n###\n### Try to figure out '%lu' with the information below!\n###\n## INFORMATION KNOWN TO EVE WHO'S BEEN LISTING ON THE OPEN COMMUNICATION CHANNEL ALL ALONG:", mutual_bob);
	fprintf(stdout, "\n## ~ Multiplicative group of integers used: <\u2124/%lu\u2124>", group_modulus);
	fprintf(stdout, "\n## ~ Base number (generator): %lu", base);
	fprintf(stdout, "\n## ~ \u2203 x \u2208 <\u2124/%lu\u2124, *> : %lu^x \u2261 %lu (%% %lu)", group_modulus, base, public_alice, group_modulus);
	fprintf(stdout, "\n## ~ \u2203 y \u2208 <\u2124/%lu\u2124, *> : %lu^y \u2261 %lu (%% %lu)", group_modulus, base, public_bob, group_modulus);
	fprintf(stdout, "\n##");
	fprintf(stdout, "\n## NOTICE HOW EVE IS UNABLE TO FIGURE OUT '%lu' WITHOUT THE SECRET VALUES 'x' and 'y'\n", mutual_bob);
	return 0;
    } else {
	fprintf(stderr, "\n#\n##### Calculation unsuccessfull, unknown error occured.\n#\n#Exiting '-3'.\n");
	return -3;
    } }
