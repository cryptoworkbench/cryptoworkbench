/* Examplifies additive and multiplicative groups.
 *
 * Works perfectly now. I am very content with it.
 */
#include "subgroup_examplifier.h"

int main(int argc, char **argv) { group_OBJ group; main_fs = stdout;
    if (6 < argc || argc > 1 && match(argv[1], help_queries)) HELP_AND_QUIT(argv[0]); else group = (group_OBJ) malloc(sizeof(group_OBJ));
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_enum_GROUP_IDentity(argv[2], &group->ID)) ID_not_parsable_ERROR(argv[1], argv[2]);
    else group_operation = operation_from_ID(group->ID); // <^^^ Parses and processes everything that has to do with CMD args, also deals with the "help_queries"

    shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) { case 6: main_fs = fopen(argv[5], "w");
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!boolean_from_ID_Sloth(group)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the mod value to shifts when dealing with additive groups (see "MATH_HINT_ONE")
    } // ^ Process offset values.

    unsigned long *generator_array = second_MAIN(element_LL_from_file(argv, group), group); // << Check "subgroup_information.h" for elaboration concerning "second_MAIN()"
    for (unsigned long i = shifts->Y; i < cardinality + shifts->Y; i++) { print_subgroup(i % cardinality); fprintf(main_fs, "\n"); } // << Print table to "main_fs"

    const char *adjective = adjective_from_ID_Sloth(group);
    const char *symbol = operation_symbol_from_ID_Sloth(group);
    if (main_fs != stdout) { fclose(main_fs); main_fs = stdout;
	fprintf(main_fs, "Wrote table for the %s group of integers modulo %s to the external file '%s'\n", adjective, argv[1], argv[5]);
	fprintf(main_fs, "Horizontal offset used: %lu\nVertical offset used: %lu\n", shifts->X, shifts->Y); }
    // ^^^ Only the table is supposed to be written to the external file

    fprintf(main_fs, "\n\u2115%s%s contains %lu elements a.k.a. |\u2115%s%s| = %lu\n\n", argv[1], symbol, cardinality, argv[1], symbol, cardinality);
    // ^^^ Print cardinality information about this group.

    if (generator_array) fprintf(main_fs, "\n\u2191 those are the only %lu generators present in \u2115%s%s \u2191\n", process_generator_array(generator_array, argv[1], symbol), argv[1], symbol);
    else fprintf(main_fs, "This group does not contain any generators.\n");
    // ^^^ Calls the amount of generators to the user and recounts it afterwards, horizontal "shifts->X" is used here, check that out. Also free()'s the array

    for (unsigned long index = 0; index < cardinality; index++) { free(LOOKUP_table[index].permutation); free(LOOKUP_table[index].ASCII); } free(LOOKUP_table);
    // ^^^ Free all of the sloths of memory referred to (in)directly by the table

    return 0;
}

unsigned long index_lookup(unsigned long ul) {
    for (unsigned long index = 0; index < cardinality; index++)
	if (LOOKUP_table[index].ulong == ul) return index;

    return 0;
}

void print_subgroup(unsigned long index) {
    fprintf(main_fs, "<%s> = {", LOOKUP_table[index].ASCII);
    unsigned long i = 0; do {
	fprintf(main_fs, "%s", LOOKUP_table[LOOKUP_table[index].permutation[(i + shifts->X) % LOOKUP_table[index].perm_length]].ASCII); i++;
	if (i == LOOKUP_table[index].perm_length) break;
	else fprintf(main_fs, ", ");
    } while (1); fprintf(main_fs, "}");
}

void insert(struct _general_LL ***tracer_location, unsigned long new_ulong) {
    struct _general_LL *new_LL_element = (struct _general_LL *) malloc(sizeof(struct _general_LL)); // Fix existence of new element
    new_LL_element->element = new_ulong; new_LL_element->next = NULL;
    /* Manifest new element for ulong ^^. */

    while (**tracer_location) *tracer_location = &(***tracer_location).next;
    **tracer_location = new_LL_element;
    /* Add at the end ^^. */
    
    *tracer_location = (struct _general_LL **) **tracer_location;
    /* And move onto this newly added spot ^^. */
}

unsigned long *array_from_LL(struct _general_LL **head_TRACER, unsigned long *required_array_size) {
    struct _general_LL *iter; if (!(iter = (struct _general_LL *) _close_CHANNEL((void **) head_TRACER))) return NULL;
    unsigned long *ulong_array = (unsigned long *) malloc(sizeof(unsigned long) * *required_array_size);
    for (unsigned long i = 0; i < *required_array_size; i++) {
	struct _general_LL *process = iter; ulong_array[i] = process->element;
	iter = process->next; free(process);
    } return ulong_array;
}
unsigned long *yield_subgroup(unsigned long index, group_OBJ group) {
    unsigned long ID = boolean_from_ID_Sloth(group);
    struct VOID_ptr_ptr_PAIR permutation_LL_pair = INITIALIZE_CHANNEL_PTR_pair();
    unsigned long subgroup_card = 0;

    unsigned long generated_element = ID; do {
	insert((struct _general_LL ***) &permutation_LL_pair.iterator, index_lookup(generated_element)); subgroup_card++;
	generated_element = group_operation(generated_element, LOOKUP_table[index].ulong, group->MOD);
    } while (generated_element != ID); LOOKUP_table[index].perm_length = subgroup_card;
    // ^^ First we make a linked list of permutations
    
    return array_from_LL((struct _general_LL **) permutation_LL_pair.head, &subgroup_card);
}

struct VOID_ptr_ptr_PAIR element_LL_from_file(char **argv, group_OBJ group) {
    cardinality = 0;
    FILE *ELEMENT_database = open_group(argv[0], group, argv[1]);
    // ^^^ Open filestream to element database and initialize cardinality counter. ^^

    struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair = INITIALIZE_CHANNEL_PTR_pair();
    // ^^^ Keep an eye of the head of the open linked list that "insert()" will create. ^^

    unsigned long group_ELEMENT; while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { insert((struct _general_LL ***) &element_CHANNEL_PTR_pair.iterator, group_ELEMENT); cardinality++; }
    // ^^^ Manifest open linked list consisting of all this "group"'s elements using "insert()" (this linked list can only be closed performing "circular_LL_from_CHAN(element_CHANNEL_PTR_pair.head)"). ^^

    close_group(argv[1], operation_symbol_from_ID_Sloth(group), ELEMENT_database);
    // ^^^ After successfull interpretation from element_database, notify of the file's parsing in the logbook

    return element_CHANNEL_PTR_pair;
}

unsigned long *second_MAIN(struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair, group_OBJ group) {
    struct _general_LL *LINEAR_element_LL;
    if (!(LINEAR_element_LL = (struct _general_LL *) _close_CHANNEL(element_CHANNEL_PTR_pair.head))) { fprintf(stderr, "Failed to add elements from 'ARCHIVE/' file. Exiting '-11'.\n"); exit(-11); }
    // ^^ No need to circle it by using "circular_LL_from_CHAN()"
    
    unsigned long cell_width = char_in_val(((struct _general_LL *) element_CHANNEL_PTR_pair.iterator)->element); // << Determine required cell width
    LOOKUP_table = (array_piece *) malloc(sizeof(array_piece) * cardinality);
    unsigned long index; for (index = 0; index < cardinality; index++) { // << We use unsigned long "index" twice
	struct _general_LL *process = LINEAR_element_LL;
	LOOKUP_table[index].ulong = process->element;
	LOOKUP_table[index].ASCII = str_from_ul(process->element, cell_width); // << Now with a little less pressure on memory is a good time to add the string representations
	LINEAR_element_LL = process->next; free(process);
    } // << ^ Destroy the linear linked list "LINEAR_element_LL" whilst registering it's values into our "LOOKUP_table"

    struct VOID_ptr_ptr_PAIR generator_LL_pair = INITIALIZE_CHANNEL_PTR_pair(); // << Declare a new set of tracers, but this time to create a linked list of generators
    for (index = 0; index < cardinality; index++) {
	LOOKUP_table[index].permutation = yield_subgroup(index, group); // << Loop over the array one more time
	if (LOOKUP_table[index].perm_length == cardinality) { insert((struct _general_LL ***) &generator_LL_pair.iterator, index); generator_count++; }
    }

    return array_from_LL((struct _general_LL **) generator_LL_pair.head, &generator_count);
}

unsigned long process_generator_array(unsigned long *generator_array, char *modulus, const char *symbol) {
    fprintf(main_fs, "GENERATOR COUNT FOR \u2115%s%s (%lu):\n", modulus, symbol, generator_count);
    unsigned long i = shifts->Y % generator_count; do { print_subgroup(generator_array[i % generator_count]); if (i < (generator_count + shifts->Y)) { fprintf(main_fs, ", and\n"); i++; } else break; } while (1);
    fprintf(main_fs, "\n"); free(generator_array); return generator_count;
}

void ID_not_parsable_ERROR(char *argv_one, char *argv_two) {
    fprintf(stdout, STDOUT_ARGV_ONE_INSTRUCTION, argv_one, argv_one, argv_one, argv_two);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is not in the first list nor in the second. Returning '-2'.\n", argv_two);
    exit(-2);
}

void MOD_not_parsable_ERROR(char *argv_one) {
    fprintf(stdout, STDOUT_ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from ARCHIVE/ the group '\u2115%s*' makes no sense to me. Returning '-1'.\n", argv_one);
    exit(-1);
}

void HELP_AND_QUIT(char *prog_NAME) {
    fprintf(stderr, HELP_INFORMATION, prog_NAME);
    exit(0);
}
/* MATH HINTS (!):
 * "MATH_HINT_ONE":
 * 	For any finite group G, the order (number of elements) of every subgroup of G divides the order of G. This is applicable to additive groups here.
 * 	*/
