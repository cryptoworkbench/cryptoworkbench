/* Development progress:
 * This will be a rewrite of 'DEPRECATED_subgroup_examplifier/subgroup_examplifier.c'
 *
 * So far, so good.
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

char *unparsed_arg_; struct vertibrae *LOOKUP_table; unsigned long group_cardinality_ = 0;
// ^ global variable definitions

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg_); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg_); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }
// ^ error functions

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
    } return ulong_array;
}

void second_MAIN(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair) {
    struct LL_ *LINEAR_element_LL; if (!(LINEAR_element_LL = (struct LL_ *) _close_CHANNEL(element_CHANNEL_PTR_pair.head))) { fprintf(stderr, "Failed to add elements from 'ARCHIVE/' file. Exiting '-11'.\n"); exit(-11); }
    // try to perform '_close_CHANNEL' ^
    
    unsigned long cell_width = char_in_val(((struct LL_ *) element_CHANNEL_PTR_pair.iterator)->e);
    // determine required cell width ^

    LOOKUP_table = (struct vertibrae *) malloc(sizeof(struct vertibrae) * group_cardinality_);
    // allocate lookup table's memory sloth ^

    unsigned long iter;
    // initialize an iterator

    for (iter = 0; iter < group_cardinality_; iter++)
    { struct LL_ *process = LINEAR_element_LL; LOOKUP_table[iter].ulong = process->e; LOOKUP_table[iter].ASCII = str_from_ul(LOOKUP_table[iter].ulong, cell_width); LINEAR_element_LL = process->next; free(process); }
    // destroy the linear linked list 'LINEAR_element_LL' whilst registering its values into LOOKUP_table ^
}

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg_ = argv[1];
    if (!str_represents_ul(unparsed_arg_, mod_)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg_ = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg_))) error_message(arg_error(2), -2); id_ = (unsigned long *) malloc(sizeof(unsigned long)); *id_ = identity_(*SELECTOR);
    struct ordered_pair *offset = (struct ordered_pair *) malloc(sizeof(struct ordered_pair)); offset->a = offset->b = 0; // member a will hold y offset, member b will hold x offset
    if (argc != 3) { switch (argc) {
	    case 5: if (!str_represents_ul(argv[4], &offset->a)) fprintf(stderr, "Failed to interpret vertical table offset.\n");
	    case 4: if (!str_represents_ul(argv[3], &offset->b)) fprintf(stderr, "Failed to interpret horizontal table offset.\n");
	    default: if (*id_ == 0) { offset->a %= *mod_; offset->b %= *mod_; } };
    } // <^ get all information needed ^^

    second_MAIN(group_elements_LL(argv));
    for (int i = 0; i < group_cardinality_; i++) { printf("%s\n", LOOKUP_table[i].ASCII); }
    return 0;
}
