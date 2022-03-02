/* Program description:
 * Examplifies subgroups. Feed it a modulus and a group identity as command-line arguments and it will examplify all subgroups within specified group. It also lists the generators that are within the group.
 *
 * DEVELOPERS NOTES:
 * When you put it with 2 1 it says there are no generators there.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/group_library.h"
// ^ library inclusions

struct LL_ { struct LL_ *next; unsigned long e; };
struct crux { unsigned long *base_permutation; char **ASCII; unsigned long **permutation; unsigned long *perm_length; };
// ^^ type definitions

struct crux *lookup_table; unsigned long group_cardinality_ = 0; unsigned long *permutation_of_FIRST_GEN; field_operation combine; unsigned long horizontal_offset;
//           ^ global variables          ^                                      ^                                         ^                      ^

void INSERT(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

void print_permutation(unsigned long index) {
    fprintf(stdout, "<%s> = {", lookup_table->ASCII[index]);
    unsigned long i = 0; do {
	fprintf(stdout, "%s", lookup_table->ASCII[lookup_table->permutation[index][(horizontal_offset + i) % lookup_table->perm_length[index]]]); i++;
	if (i == lookup_table->perm_length[index]) break;
	else fprintf(stdout, ", ");
    } while (1); fprintf(stdout, "}\n");
}

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv)
{ FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { INSERT((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
    return element_CHANNEL_ptr_pair; }

unsigned long *array_from_LL(struct LL_ **head_TRACER, unsigned long *required_array_size) {
    struct LL_ *iter; if (!(iter = (struct LL_ *) _close_CHANNEL((void **) head_TRACER))) return NULL; unsigned long *ulong_array = (unsigned long *) malloc(sizeof(unsigned long) * *required_array_size);
    for (unsigned long i = 0; i < *required_array_size; i++) { struct LL_ *process = iter; ulong_array[i] = process->e; iter = process->next; free(process); } return ulong_array;
}

unsigned long count_of_GENERATED_subgroup_elements(unsigned long index) { unsigned long ret_val = 0;
    struct VOID_ptr_ptr_PAIR permutation_LL_pair = initialize_CHANNEL_ptr_pair();
    unsigned long generated_element = *id_; do {
	INSERT((struct LL_ ***) &permutation_LL_pair.iterator, INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, generated_element)); ret_val++;
	generated_element = combine(generated_element, lookup_table->base_permutation[index]);
    } while (generated_element != *id_);
    lookup_table->permutation[index] = array_from_LL((struct LL_ **) permutation_LL_pair.head, &ret_val);
    return ret_val;
}

unsigned long finish(unsigned long index) { unsigned long generator_count = 1;
    for (index; index < group_cardinality_; index++) {
	unsigned long discrete_log = INDEX_within_UL_array(permutation_of_FIRST_GEN, group_cardinality_, INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, lookup_table->base_permutation[index]));
	lookup_table->perm_length[index] = (group_cardinality_ / GCD(discrete_log, group_cardinality_)); if (lookup_table->perm_length[index] == group_cardinality_) generator_count++;
	lookup_table->permutation[index] = malloc(sizeof(unsigned long) * lookup_table->perm_length[index]);
	unsigned long j = 0; lookup_table->permutation[index][j] = INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, lookup_table->base_permutation[0]);
	for (; j + 1 < lookup_table->perm_length[index]; j++) lookup_table->permutation[index][j + 1]
	    = INDEX_within_UL_array(lookup_table->base_permutation, group_cardinality_, combine(lookup_table->base_permutation[index], lookup_table->base_permutation[lookup_table->permutation[index][j]]));
    } return generator_count;
}

unsigned long found_generators(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair) { unsigned long cell_width = char_in_val(((struct LL_ *) element_CHANNEL_PTR_pair.iterator)->e);
    lookup_table = (struct crux *) malloc(sizeof(struct crux)); permutation_of_FIRST_GEN = lookup_table->base_permutation = array_from_LL((struct LL_ **) element_CHANNEL_PTR_pair.head, &group_cardinality_);
    lookup_table->permutation = (unsigned long **) malloc(sizeof(unsigned long *) * group_cardinality_); lookup_table->perm_length = (unsigned long *) malloc(sizeof(unsigned long) * group_cardinality_);
    lookup_table->perm_length[0] = 1; *(lookup_table->permutation[0] = malloc(sizeof(unsigned long *))) = 0; lookup_table->ASCII = (char **) malloc(sizeof(char *) * group_cardinality_); unsigned long index;
    for (index = 0; index < group_cardinality_; index++) lookup_table->ASCII[index] = str_from_ul(lookup_table->base_permutation[index], cell_width);
    if (*id_) { for (index = 1; index < group_cardinality_; index++) if ((lookup_table->perm_length[index] = count_of_GENERATED_subgroup_elements(index)) == group_cardinality_) break;
	if (index == group_cardinality_) return 0; permutation_of_FIRST_GEN = lookup_table->permutation[index]; return finish(index + 1); }
    lookup_table->perm_length[1] = group_cardinality_; lookup_table->permutation[1] = lookup_table->base_permutation; return finish(2);
}

void horizontal_offset_failed_to_parse() { fprintf(stderr, "Failed to interpret horizontal table offset! --- ^"); }
void __vertical_offset_failed_to_parse() { fprintf(stderr, "Failed to interpret vertical table offset! -- -- ^"); }
void invalid_group_parameters()
{
    fprintf(stderr, "\nInvalid group parameters: ");
    if (!(*mod_)) fprintf(stderr, "the modulus cannot be 0!");
    else fprintf(stderr, "for multiplicative groups the modulus needs to be at least 2! (since multiplicative groups do not include the element '0')");
}

void mod_error() { fprintf(stderr, "Please supply as first argument the modulus of the group whose subgroups to examplify"); }
// error functions ^ (function header format fits typedef '_error_message')

int main(int argc, char **argv) { argv_location = &argv;
    unsigned long mod; mod_ = &mod;conditional_goodbye(n(n(error_specification(mod_error, n(ul_parse_str(argv[1], mod_, -1))))));
    int id; id_ = &id;             conditional_goodbye(n(n(error_specification(identity_error_elaboration, n(identity_parse_str(&id, argv[2], -2))))));
    if (!mod || !(mod - 1) && id)  conditional_goodbye(n(n(error_message(invalid_group_parameters, -3))));
    // process mandatory terminal arguments (mod and group identity) ^ 

                  horizontal_offset = 0; n(n(error_specification(horizontal_offset_failed_to_parse, 3 < argc && ul_parse_str(argv[3], &horizontal_offset, 1))));
    unsigned long __vertical_offset = 0; n(n(error_specification(__vertical_offset_failed_to_parse, 4 < argc && ul_parse_str(argv[4], &__vertical_offset, 1))));
    // process optional terminal arguments ^

    combine = id_field_operation(); unsigned long generator_count = found_generators(group_elements_LL(argv));
    unsigned long index = __vertical_offset; do { print_permutation(index); index = _add(index, 1, group_cardinality_); } while (index != __vertical_offset); fprintf(stdout, "\n");
    //   examplify subgroups ^

    if (generator_count) {
	fprintf(stdout, "%lu generators are present within \u2115/\u2115%s%s:\n", generator_count, argv[1], id_as_operation_symbol());
	for (unsigned long printed_gens = 0, index = __vertical_offset; printed_gens < generator_count; index = _add(index, 1, group_cardinality_))
	{ while (lookup_table->perm_length[index] != group_cardinality_) index = _add(index, 1, group_cardinality_); print_permutation(index); printed_gens++; }
    } else fprintf(stdout, "There are no generators in this group.\n");
    //   list generators afterwards ^

    for (unsigned long i = 0; i < group_cardinality_; i++) { free(lookup_table->permutation[i]); free(lookup_table->ASCII[i]); } free(lookup_table->perm_length);
    if (id) free(lookup_table->base_permutation); free(lookup_table); return 0;
} // * = 'member a will hold y offset, member b will hold x offset'
