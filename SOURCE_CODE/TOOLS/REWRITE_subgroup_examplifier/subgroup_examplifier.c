#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/universal_group_library.h"
// ^ library inclusions

struct LL_ { struct LL_ *next; unsigned long e; };
struct crux { unsigned long *base_permutation; char **ASCII; unsigned long **permutation; unsigned long *perm_length; };
// ^^ type definitions

struct ordered_pair *offset; char *unparsed_arg_; struct crux *lookup_table; unsigned long group_cardinality_ = 0; unsigned long generator_count = 0; unsigned long FIRST_GEN; unsigned long *permutation_of_FIRST_GEN;
//     ^ global variables          ^                           ^                           ^                                     ^                                  ^

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg_); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg_); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }
// ^^^ error functions

void INSERT(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

void print_permutation(unsigned long *permutation, unsigned long size) {
    fprintf(stdout, "<%s> = {", lookup_table->ASCII[permutation[1]]);
    unsigned long i = 0; do {
	fprintf(stdout, "%s", lookup_table->ASCII[permutation[i]]); i++;
	if (i == size) break;
	else fprintf(stdout, ", ");
    } while (1); fprintf(stdout, "}\n");
}

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv) { FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { INSERT((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
    return element_CHANNEL_ptr_pair;
}

unsigned long *array_from_LL(struct LL_ **head_TRACER, unsigned long *required_array_size) {
    struct LL_ *iter; if (!(iter = (struct LL_ *) _close_CHANNEL((void **) head_TRACER))) return NULL; unsigned long *ulong_array = (unsigned long *) malloc(sizeof(unsigned long) * *required_array_size);
    for (unsigned long i = 0; i < *required_array_size; i++) { struct LL_ *process = iter; ulong_array[i] = process->e; iter = process->next; free(process); } return ulong_array;
}

unsigned long *yield_subgroup(unsigned long index) {
    struct VOID_ptr_ptr_PAIR permutation_LL_pair = initialize_CHANNEL_ptr_pair();
    lookup_table->perm_length[index] = 0;

    unsigned long generated_element = *id_; do {
	unsigned long SPECIFIC_INDEX = INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, generated_element);
	INSERT((struct LL_ ***) &permutation_LL_pair.iterator, SPECIFIC_INDEX); lookup_table->perm_length[index]++;
	generated_element = GF_combi(generated_element, lookup_table->base_permutation[index]);
    } while (generated_element != *id_);
    return array_from_LL((struct LL_ **) permutation_LL_pair.head, &lookup_table->perm_length[index]);
}

unsigned long finish(unsigned long index) { unsigned long ret_val = 1;
    for (index; index < group_cardinality_; index++) {
	unsigned long discrete_log = INDEX_within_UL_array(permutation_of_FIRST_GEN, group_cardinality_, INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, lookup_table->base_permutation[index]));
	lookup_table->perm_length[index] = (group_cardinality_ / GCD(discrete_log, group_cardinality_)); if (lookup_table->perm_length[index] == group_cardinality_) ret_val++;
	lookup_table->permutation[index] = malloc(sizeof(unsigned long) * lookup_table->perm_length[index]);
	unsigned long j = 0; lookup_table->permutation[index][j] = INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, lookup_table->base_permutation[0]);
	for (; j + 1 < lookup_table->perm_length[index]; j++) lookup_table->permutation[index][j + 1]
	    = INDEX_within_UL_array( lookup_table->base_permutation, group_cardinality_, GF_combi(lookup_table->base_permutation[index], lookup_table->base_permutation[lookup_table->permutation[index][j]]));
    } return ret_val;
}

unsigned long second_MAIN(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair) { unsigned long ret_val = 0; unsigned long cell_width = char_in_val(((struct LL_ *) element_CHANNEL_PTR_pair.iterator)->e);
    lookup_table = (struct crux *) malloc(sizeof(struct crux)); permutation_of_FIRST_GEN = lookup_table->base_permutation = array_from_LL((struct LL_ **) element_CHANNEL_PTR_pair.head, &group_cardinality_);
    lookup_table->permutation = (unsigned long **) malloc(sizeof(unsigned long *) * group_cardinality_); lookup_table->perm_length = (unsigned long *) malloc(sizeof(unsigned long) * group_cardinality_);
    lookup_table->ASCII = (char **) malloc(sizeof(char *) * group_cardinality_); unsigned long index = 0;
    for (; index < group_cardinality_; index++) lookup_table->ASCII[index] = str_from_ul(lookup_table->base_permutation[index], cell_width);
    // initialize everything ^^

    if (*id_) { index = 0; do { lookup_table->permutation[index] = yield_subgroup(index); if (lookup_table->perm_length[index] == group_cardinality_) { ret_val++; break; } index++; } while (index < group_cardinality_);
	if (index == group_cardinality_) return ret_val; permutation_of_FIRST_GEN = lookup_table->permutation[index]; return finish(index + 1); }
    else {
	lookup_table->perm_length[0] = 1; *(lookup_table->permutation[0] = malloc(sizeof(unsigned long *))) = lookup_table->base_permutation[0]; // set the perm identity (element's) permutation <
	lookup_table->perm_length[1] = group_cardinality_; lookup_table->permutation[1] = lookup_table->base_permutation;
	return finish(2);
    }
}

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg_ = argv[1];
    if (!str_represents_ul(unparsed_arg_, mod_)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg_ = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg_))) error_message(arg_error(2), -2); id_ = (unsigned long *) malloc(sizeof(unsigned long)); *id_ = identity_(*SELECTOR); free(SELECTOR);
    offset = (struct ordered_pair *) malloc(sizeof(struct ordered_pair)); offset->a = offset->b = 0; // member a will hold y offset, member b will hold x offset
    if (argc != 3) { switch (argc) {
	    case 5: if (!str_represents_ul(argv[4], &offset->a)) fprintf(stderr, "Failed to interpret vertical table offset. Defaulting to not using any.\n");
	    case 4: if (!str_represents_ul(argv[3], &offset->b)) fprintf(stderr, "Failed to interpret horizontal table offset. Defaulting to not using any.\n");
	    default: if (!(*id_)) { offset->a %= *mod_; offset->b %= *mod_; } };
    } // process terminal arguments ^

    unsigned long generator_count = second_MAIN(group_elements_LL(argv));
    for (unsigned long index = 0; index < group_cardinality_; index++) print_permutation(lookup_table->permutation[index], lookup_table->perm_length[index]);
    if (generator_count) fprintf(stdout, "\nGenerators (%lu):\n", generator_count); else fprintf(stdout, "\nNo generators are presents in this group.\n");
    for (unsigned long printed_gens = 0, index = offset->a; printed_gens < generator_count; index = _add(index, 1, group_cardinality_)) { 
	while (lookup_table->perm_length[index] != group_cardinality_) index = _add(index, 1, group_cardinality_);
	print_permutation(lookup_table->permutation[index], lookup_table->perm_length[index]); printed_gens++;
    } return 0;
}
