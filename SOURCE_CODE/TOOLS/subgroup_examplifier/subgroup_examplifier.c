/* Development progress:
 * This will be a rewrite of 'DEPRECATED_subgroup_examplifier/subgroup_examplifier.c'
 *
 * Running with 21 1 will give a "malloc(): invalid_size (unsorted)"
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

struct ordered_pair *offset; char *unparsed_arg_; struct vertibrae *LOOKUP_table; unsigned long group_cardinality_ = 0; unsigned long generator_count = 0; unsigned long index_of_first_gen = 0; // < never true
// ^ global variable definitions

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg_); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg_); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }
// ^ error functions

void print_permutation(unsigned long index) {
    // fprintf(stdout, "(%lu long)", LOOKUP_table[index].perm_length);
    fprintf(stdout, "<%s> = {", LOOKUP_table[index].ASCII);
    unsigned long i = 0; do {
	fprintf(stdout, "%s", LOOKUP_table[LOOKUP_table[index].permutation[(i + offset->b) % LOOKUP_table[index].perm_length]].ASCII); i++;
	if (i == LOOKUP_table[index].perm_length) break;
	else fprintf(stdout, ", ");
    } while (1); fprintf(stdout, "}");
}

unsigned long LOOKUP(unsigned long number) { for (unsigned long index = 0; index < group_cardinality_; index++) if (LOOKUP_table[index].ulong == number) return index; }
// ^ only call for existing elements

unsigned long general_lookup(unsigned long *array, unsigned long array_size, unsigned long number) {
    for (unsigned long i = 0; i < array_size; i++) if (array[i] == number) return i; }
// ^ also only call for existing elements

unsigned long generator_lookup(unsigned long number) {
    for (unsigned long i = 0; i < group_cardinality_; i++) if (LOOKUP_table[LOOKUP_table[index_of_first_gen].permutation[i]].ulong == number) return i;
}

void insert(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv) { FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { insert((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
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
	insert((struct LL_ ***) &permutation_LL_pair.iterator, LOOKUP(generated_element)); subgroup_card++;
	generated_element = GF_combi(generated_element, LOOKUP_table[index].ulong);
    } while (generated_element != *id_); LOOKUP_table[index].perm_length = subgroup_card;
    // ^^ First we make a linked list of permutations
    
    return array_from_LL((struct LL_ **) permutation_LL_pair.head, &subgroup_card);
}

unsigned long *second_MAIN(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair) {
    struct LL_ *LINEAR_element_LL; if (!(LINEAR_element_LL = (struct LL_ *) _close_CHANNEL(element_CHANNEL_PTR_pair.head))) { fprintf(stderr, "Failed to add elements from 'ARCHIVE/' file. Exiting '-11'.\n"); exit(-11); }
    // try to perform '_close_CHANNEL' ^
    
    unsigned long cell_width = char_in_val(((struct LL_ *) element_CHANNEL_PTR_pair.iterator)->e);
    // determine required cell width ^

    LOOKUP_table = (struct vertibrae *) malloc(sizeof(struct vertibrae) * group_cardinality_); 
    // allocate LOOKUP_table's swap of memory ^

    unsigned long iter;
    // initialize the iterator

    for (iter = 0; iter < group_cardinality_; iter++)
    { struct LL_ *process = LINEAR_element_LL; LOOKUP_table[iter].ulong = process->e; LOOKUP_table[iter].ASCII = str_from_ul(LOOKUP_table[iter].ulong, cell_width); LINEAR_element_LL = process->next; free(process); }
    // destroy the linear linked list 'LINEAR_element_LL' whilst registering its values into LOOKUP_table ^

    struct VOID_ptr_ptr_PAIR generator_LL_pair = initialize_CHANNEL_ptr_pair(); // << Declare a new set of tracers, but this time to create a linked list of generators

    iter = 0;
    do {LOOKUP_table[iter].permutation = yield_subgroup(iter);
	if (LOOKUP_table[iter].perm_length == group_cardinality_)
	{ // ^ if the permutation is a long as the group cardinality, we've stumbled upon a generator
	    generator_count++; insert((struct LL_ ***) &generator_LL_pair.iterator, iter);
	    break; // now we can calculate subgroup sizes by using the descrete logarithm of new elements base this generator
	} iter++; // else we continue
    } while (iter < group_cardinality_); if (iter == group_cardinality_ - 1) return NULL; index_of_first_gen = iter;

    // NEXT BLOCK OF CODE
    for (iter++; iter < group_cardinality_; iter++) {
	LOOKUP_table[iter].perm_length = (group_cardinality_ / GCD(generator_lookup(LOOKUP_table[iter].ulong), group_cardinality_));
	LOOKUP_table[iter].permutation = malloc(sizeof(unsigned long) * (LOOKUP_table[iter].perm_length + 1));
	if (LOOKUP_table[iter].perm_length == group_cardinality_) { generator_count++; insert((struct LL_ ***) &generator_LL_pair.iterator, iter); }

	unsigned long j = 0;
	unsigned long generated_element = LOOKUP_table[iter].permutation[j] = LOOKUP(*id_);
	do {j++;
	    LOOKUP_table[iter].permutation[j] = LOOKUP(GF_combi(LOOKUP_table[LOOKUP_table[iter].permutation[j - 1]].ulong, LOOKUP_table[iter].ulong));
	} while (j < LOOKUP_table[iter].perm_length);
    } return array_from_LL((struct LL_ **) generator_LL_pair.head, &generator_count);
}

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg_ = argv[1];
    if (!str_represents_ul(unparsed_arg_, mod_)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg_ = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg_))) error_message(arg_error(2), -2); id_ = (unsigned long *) malloc(sizeof(unsigned long)); *id_ = identity_(*SELECTOR);
    offset = (struct ordered_pair *) malloc(sizeof(struct ordered_pair)); offset->a = offset->b = 0; // member a will hold y offset, member b will hold x offset
    if (argc != 3) { switch (argc) {
	    case 5: if (!str_represents_ul(argv[4], &offset->a)) fprintf(stderr, "Failed to interpret vertical table offset.\n");
	    case 4: if (!str_represents_ul(argv[3], &offset->b)) fprintf(stderr, "Failed to interpret horizontal table offset.\n");
	    default: if (*id_ == 0) { offset->a %= *mod_; offset->b %= *mod_; } };
    } // <^ get all information needed ^^

    unsigned long *generator_array = second_MAIN(group_elements_LL(argv)); int i = 0; 
    for (i = 0; i < group_cardinality_; i++) { print_permutation(i); printf("\n"); }
    printf("\ngenerators (%lu):\n", generator_count);
    for (i = 0; i < generator_count; i++) { print_permutation(generator_array[i]); printf("\n"); }
    return 0;
}
