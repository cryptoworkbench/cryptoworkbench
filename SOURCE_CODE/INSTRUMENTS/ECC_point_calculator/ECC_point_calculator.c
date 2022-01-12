/* Here I try to find ECC points.
 *
 * Way from being ready. */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h" // << Needed for "zoom_out()", "initialize_PTR_pair()", and "zoom_in()"
#include "../../libraries/mathematics/universal_group_library.h"

const char *database_incomplete_error = "The datebase file was incomplete. Exiting '-2'.\n";

unsigned long m;

struct square {
    unsigned long index;
    unsigned long first_root;
    unsigned long second_root;
    struct square *next;
};

void add(struct square **iterator, unsigned long perm_length) {
    while (*iterator != NULL && (*iterator)->perm_length.ULONG != perm_length) iterator = &(*iterator)->next;
    if (*iterator == NULL) {
	struct square *new_subgroup_order = (struct square *) malloc(sizeof(struct square)); // Create the new order counter
	// ^^ Create new element

	new_subgroup_order->perm_length.ULONG = perm_length; new_subgroup_order->perm_length.STR = str_from_ul(perm_length, str_len(_perm_length_header));
	// ^^ Set new element's "perm_length" struct

	new_subgroup_order->perm_length_occurences.ULONG = 1;
	// ^^ Set new element's "perm_length_occurences" struct

	new_subgroup_order->next = *iterator; *iterator = new_subgroup_order;
    } // << Do triple ref magic
    else if ((*iterator)->perm_length.ULONG == perm_length) (*iterator)->perm_length_occurences.ULONG++;
} // ^^ Add function from "subgr_examplifier"; needs to be modified to fit my needs

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &m)) { fprintf(stderr, "'%s' is not m!\n", argv[1]); return -1; }
    struct group_STRUCT temp = { MULTIPLICATIVE, m };
    FILE *ELEMENT_database = open_group(argv[0], &temp, argv[1]); unsigned long M_totient = totient(m);
    unsigned long *element_array = (unsigned long *) malloc(sizeof(unsigned long) * M_totient);

    for (unsigned long i = 0; i < M_totient; i++) { if (fscanf(ELEMENT_database, "%lu\n", element_array + i) != 1) { fprintf(stderr, database_incomplete_error); return -2; } }
    close_group(argv[1], operation_symbol_from_ID_Sloth(&temp), ELEMENT_database);

    struct VOID_ptr_ptr_PAIR pair = INITIALIZE_CHANNEL_PTR_pair(); // << Declare a new set of tracers, but this time to create a linked list of generators
    for (unsigned long i = 0; i < M_totient; i++) {
	fprintf(stdout, "%lu: %lu\n", i, element_array[i]);
	add((struct square **) pair.iterator, (element_array[i] * element_array[i]) % m);
    }
    return 0;
}
