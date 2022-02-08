/* CHANGES TO BE MADE:
 * ~ 'second_MAIN' should calculate amount of generators
 *
 * DEVELOPER NOTES ->
 * There are 3 ways of knowing if any generators were found:
 * index_of_FIRST_GEN is set at 0 (which is an obvious fallacy, the first sloth of LOGBOOK is always supposed to be the identity element)
 * the pointer generator_array is set at NULL
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/universal_group_library.h"
// ^ library inclusions

struct LL_ { struct LL_ *next; unsigned long e; };
struct vertibrae { char *ASCII; unsigned long ulong; unsigned long perm_length; unsigned long *permutation; };
// ^^ type definitions

struct ordered_pair *offset; char *unparsed_arg_; struct vertibrae *LOOKUP_table; unsigned long group_cardinality_ = 0; unsigned long generator_count = 0; unsigned long index_of_FIRST_GEN;
struct VOID_ptr_ptr_PAIR generator_LL_pair;
// ^ global variable definitions

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg_); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg_); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }
// ^ error functions

void print_permutation(unsigned long index) {
    fprintf(stdout, "<%s> = {", LOOKUP_table[index].ASCII);
    unsigned long i = 0; do {
	fprintf(stdout, "%s", LOOKUP_table[LOOKUP_table[index].permutation[(i + offset->b) % LOOKUP_table[index].perm_length]].ASCII); i++;
	if (i == LOOKUP_table[index].perm_length) break;
	else fprintf(stdout, ", ");
    } while (1); fprintf(stdout, "}\n");
}

unsigned long index_within_LOOKUP_TABLE(unsigned long number) { for (unsigned long index = 0; index < group_cardinality_; index++) if (LOOKUP_table[index].ulong == number) return index; }
// ^ only call for existing elements

unsigned long base_FIRST_GEN_descrete_log_of_(unsigned long number) { for (unsigned long i = 0; i < group_cardinality_; i++) if (LOOKUP_table[LOOKUP_table[index_of_FIRST_GEN].permutation[i]].ulong == number) return i; }

void INSERT(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

void INSERT_generator(unsigned long number) { INSERT((struct LL_ ***) &generator_LL_pair.iterator, number); generator_count++; }

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv) { FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { INSERT((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
    return element_CHANNEL_ptr_pair;
}

unsigned long *array_from_LL(struct LL_ **head_TRACER, unsigned long *required_array_size) {
    struct LL_ *iter; if (!(iter = (struct LL_ *) _close_CHANNEL((void **) head_TRACER))) return NULL;
    unsigned long *ulong_array = (unsigned long *) malloc(sizeof(unsigned long) * *required_array_size);

    for (unsigned long i = 0; i < *required_array_size; i++) {
	struct LL_ *process = iter; ulong_array[i] = process->e;
	iter = process->next; free(process);
    }

    return ulong_array;
}

unsigned long *yield_subgroup(unsigned long index) {
    struct VOID_ptr_ptr_PAIR permutation_LL_pair = initialize_CHANNEL_ptr_pair();
    unsigned long subgroup_card = 0;

    unsigned long generated_element = *id_; do {
	INSERT((struct LL_ ***) &permutation_LL_pair.iterator, index_within_LOOKUP_TABLE(generated_element)); subgroup_card++;
	generated_element = GF_combi(generated_element, LOOKUP_table[index].ulong);
    } while (generated_element != *id_); LOOKUP_table[index].perm_length = subgroup_card;
    // ^^ First we make a linked list of permutations
    
    return array_from_LL((struct LL_ **) permutation_LL_pair.head, &subgroup_card);
}

unsigned long second_MAIN(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair) { unsigned long ret_val = 0;
    struct LL_ *LINEAR_element_LL; if (!(LINEAR_element_LL = (struct LL_ *) _close_CHANNEL(element_CHANNEL_PTR_pair.head))) { fprintf(stderr, "Failed to add elements from 'ARCHIVE/' file. Exiting '-11'.\n"); exit(-11); }
    // try to perform '_close_CHANNEL' ^
    
    unsigned long cell_width = char_in_val(((struct LL_ *) element_CHANNEL_PTR_pair.iterator)->e);
    // determine required cell width ^

    LOOKUP_table = (struct vertibrae *) malloc(sizeof(struct vertibrae) * group_cardinality_); 
    // allocate LOOKUP_table's swap of memory ^

    unsigned long index;
    // initialize the iterator

    for (index = 0; index < group_cardinality_; index++)
    { struct LL_ *process = LINEAR_element_LL; LOOKUP_table[index].ulong = process->e; LOOKUP_table[index].ASCII = str_from_ul(LOOKUP_table[index].ulong, cell_width); LINEAR_element_LL = process->next; free(process); }
    // destroy the linear linked list 'LINEAR_element_LL' whilst registering its values into LOOKUP_table ^

    index = 0; do { LOOKUP_table[index].permutation = yield_subgroup(index); if (LOOKUP_table[index].perm_length == group_cardinality_) break; index++; } while (index < group_cardinality_);
    if (index == group_cardinality_) return ret_val;
    
    ret_val++; index_of_FIRST_GEN = index;
    for (index = index_of_FIRST_GEN + 1; index < group_cardinality_; index++) {
	LOOKUP_table[index].perm_length = (group_cardinality_ / GCD(base_FIRST_GEN_descrete_log_of_(LOOKUP_table[index].ulong), group_cardinality_));
	if (LOOKUP_table[index].perm_length == group_cardinality_) ret_val++;
	LOOKUP_table[index].permutation = malloc(sizeof(unsigned long) * (LOOKUP_table[index].perm_length + 1));
	unsigned long j = 0; LOOKUP_table[index].permutation[j] = index_within_LOOKUP_TABLE(*id_);
	for (; j + 1 < LOOKUP_table[index].perm_length; j++) LOOKUP_table[index].permutation[j + 1] = index_within_LOOKUP_TABLE(GF_combi(LOOKUP_table[LOOKUP_table[index].permutation[j]].ulong, LOOKUP_table[index].ulong));
    }

    return ret_val;
}

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg_ = argv[1];
    if (!str_represents_ul(unparsed_arg_, mod_)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg_ = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg_))) error_message(arg_error(2), -2); id_ = (unsigned long *) malloc(sizeof(unsigned long)); *id_ = identity_(*SELECTOR); free(SELECTOR);
    offset = (struct ordered_pair *) malloc(sizeof(struct ordered_pair)); offset->a = offset->b = 0; // member a will hold y offset, member b will hold x offset
    if (argc != 3) { switch (argc) {
	    case 5: if (!str_represents_ul(argv[4], &offset->a)) fprintf(stderr, "Failed to interpret vertical table offset. Defaulting to not using any.\n");
	    case 4: if (!str_represents_ul(argv[3], &offset->b)) fprintf(stderr, "Failed to interpret horizontal table offset. Defaulting to not using any.\n");
	    default: if (!(*id_)) { offset->a %= *mod_; offset->b %= *mod_; } };
    } // <^ get all information needed ^^

    unsigned long generator_count = second_MAIN(group_elements_LL(argv));
    unsigned long i = offset->a; do { print_permutation(i); i = _add(i, 1, group_cardinality_); } while (i != offset->a);
    if (generator_count) {
	fprintf(stdout, "\nGenerators (%lu):\n", generator_count);
	for (unsigned long printed_gens = 0, i = offset->a; printed_gens < generator_count; i++) {
	    while (LOOKUP_table[i].perm_length != group_cardinality_) i = _add(i, 1, group_cardinality_);
	    print_permutation(i); printed_gens++;
	}
    } else fprintf(stdout, "\nNo generators are presents in this group.\n");
    return 0;
}
