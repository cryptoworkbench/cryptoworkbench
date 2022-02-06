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


struct LL_ { struct LL_ *next; unsigned long a; };
// ^^ type definitions

void subgroup(unsigned long generator); _error_selector arg_error(); void identity_error(); void mod_error();
struct LL_ *group_elements_LL(char **argv);
// ^^^^ function headers

char *unparsed_arg;
// ^ global variable definitions

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, mod_)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg))) error_message(arg_error(2), -2); id_ = (unsigned long *) malloc(sizeof(unsigned long)); *id_ = identity_(*SELECTOR);
    struct ordered_pair *offset = (struct ordered_pair *) malloc(sizeof(struct ordered_pair)); offset->a = offset->b = 0; // member a will hold y offset, member b will hold x offset
    if (argc != 3) { switch (argc) {
	    case 5: if (!str_represents_ul(argv[4], &offset->a)) fprintf(stderr, "Failed to interpret vertical table offset.\n");
	    case 4: if (!str_represents_ul(argv[3], &offset->b)) fprintf(stderr, "Failed to interpret horizontal table offset.\n");
	    default: if (*id_ == 0) { offset->a %= *mod_; offset->b %= *mod_; } };
    } // <^ get all information needed ^^

    // LL LL = group_elements_LL(argv);

    for (struct LL_ *LL = group_elements_LL(argv); LL; LL = LL->next)
	printf("%lu\n", LL->a);
    // for (int i = *id_; i < *mod_; i++) if (*id_ == ADDITIVE_IDENTITY || GCD(i, *mod_) == 1) subgroup(i);
    return 0;
}

void insert(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); // < create new element
    new_LL_element->a = new_ulong; new_LL_element->next = NULL; // < initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // < add at the end
    *tracer_location = (struct LL_ **) **tracer_location; // < move tracer into/onto the new spot
}

struct LL_ *group_elements_LL(char **argv) { ul cardinality = 0;
    FILE *ELEMENT_database = open_group(argv);
    struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair();
    unsigned long group_ELEMENT; while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { insert((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); cardinality++; }

    /*
    for (; element_CHANNEL_ptr_pair.iterator; element_CHANNEL_ptr_pair.iterator = (void ***) element_CHANNEL_ptr_pair.iterator.next) {
	printf("%lu\n", element_CHANNEL_ptr_pair.iterator->a);
    } */

    // close_group(argv[1], operation_symbol_from_ID_Sloth(group), ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    return (struct LL_ *) element_CHANNEL_ptr_pair.head;

}

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }
// ^^^ error functionalities
