// Examplifies additive and multiplicative groups and lists their generators.
//
// New version.
//
// DEV. notes:
// Basically what I want to do here now is make the program display a calculation of the amount of mappings that can be derived for the specified group, per mapping length (a.k.a. per permutation/subgroup length)
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // <<< Needed for "match()", "STR_could_be_parsed_into_UL()", etc
#include "../../libraries/functional/triple_ref_pointers.h" // << Needed for "zoom_out()", "initialize_PTR_pair()", and "zoom_in()"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"
#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDOUT_ARGV_ONE_INSTRUCTION "Okay so the modulus is %s\n\nBut what is this group identity?, what's this group's point of symetry?\n\nIs %s supposed to be the modulus for an additive group?, or is %s supposed to be the modulus for a multiplicative group?\n\n\nTO SPECIFY ADDITIVE (MODULAR) OPERATIONS/ARITHMETIC USE:\n0\n+\naddition\nadditions\nadditive\n\nTO SPECIFY MULTIPLICATIVE (MODULAR) OPERATIONS/ARITHMATIC USE:\n1\n*\nmultiplication\nmultiplications\nmultiplicative\n\n"
#define HELP_INFORMATION "Program usage: %s <CAP> <ID> [horizontal offset] [vertical offset] [output filename]\n\n<MANDATORY ARGUMENTS> are denoted like this. The program won't run without these.\n\n[optional arguments] are denoted like this. They are not very necessary.\n"

struct offset_values { unsigned long Y; unsigned long X; };
struct _general_LL { struct _general_LL *next; unsigned long element; };

struct _order_COUNTER {
    struct _order_COUNTER *next;
    struct { unsigned long ULONG; char *STR; } perm_length;
    struct { unsigned long ULONG; char *STR; } perm_length_occurences;
};

typedef struct vertibrae { char *ASCII; unsigned long ulong; unsigned long *permutation; unsigned long perm_length; } array_piece;
typedef array_piece *table_type; // << Belongs to this one above
// ^^ Declare variable types

unsigned long cardinality, generator_count;
_group_operation group_operation;
table_type LOOKUP_table;
FILE *main_fs;
struct offset_values *shifts;
// ^^ Declare variables

const char *help_queries[] = {"--help", "-h", "help", "instructions", "usage", "--instructions", "--usage", "syntax", "--syntax"};
const char *_perm_length_header = "cardinality:";
const char *_frequency_header = "frequency:";
const char *_percentage_header = "percentage within group:";
// ^^ I think that it is alrigh to put a variable initialization like this in this header file

void HELP_AND_QUIT(char *prog_NAME) {
    fprintf(stderr, HELP_INFORMATION, prog_NAME);
    exit(0);
}

void MOD_not_parsable_ERROR(char *argv_one) {
    fprintf(stdout, STDOUT_ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from ARCHIVE/ the group '\u2115%s*' makes no sense to me. Returning '-1'.\n", argv_one);
    exit(-1);
}

void ID_not_parsable_ERROR(char *argv_one, char *argv_two) {
    fprintf(stdout, STDOUT_ARGV_ONE_INSTRUCTION, argv_one, argv_one, argv_one, argv_two);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is not in the first list nor in the second. Returning '-2'.\n", argv_two);
    exit(-2);
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

void subgroup_insert(struct _order_COUNTER **iterator, unsigned long perm_length) {
    while (*iterator != NULL && (*iterator)->perm_length.ULONG != perm_length) iterator = &(*iterator)->next;
    if (*iterator == NULL) {
	struct _order_COUNTER *new_subgroup_order = (struct _order_COUNTER *) malloc(sizeof(struct _order_COUNTER)); // Create the new order counter
	// ^^ Create new element

	new_subgroup_order->perm_length.ULONG = perm_length; new_subgroup_order->perm_length.STR = str_from_ul(perm_length, str_len(_perm_length_header));
	// ^^ Set new element's "perm_length" struct

	new_subgroup_order->perm_length_occurences.ULONG = 1;
	// ^^ Set new element's "perm_length_occurences" struct

	new_subgroup_order->next = *iterator; *iterator = new_subgroup_order;
    } // << Do triple ref magic
    else if ((*iterator)->perm_length.ULONG == perm_length) (*iterator)->perm_length_occurences.ULONG++;
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

unsigned long index_lookup(unsigned long ul) {
    for (unsigned long index = 0; index < cardinality; index++)
	if (LOOKUP_table[index].ulong == ul) return index;

    return 0;
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

struct _order_COUNTER *second_MAIN(unsigned long **generator_array, struct VOID_ptr_ptr_PAIR element_CHANNEL_PTR_pair, group_OBJ group) {
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

    struct VOID_ptr_ptr_PAIR generator_pair = INITIALIZE_CHANNEL_PTR_pair(); // << Declare a new set of tracers, but this time to create a linked list of generators
    struct VOID_ptr_ptr_PAIR subgroup_pair = INITIALIZE_CHANNEL_PTR_pair(); // << Declare a new set of tracers, but this time to create a linked list of generators
    for (index = 0; index < cardinality; index++) {
	LOOKUP_table[index].permutation = yield_subgroup(index, group); // << Loop over the array one more time
	if (LOOKUP_table[index].perm_length == cardinality) { insert((struct _general_LL ***) &generator_pair.iterator, index); generator_count++; }
	subgroup_insert((struct _order_COUNTER **) subgroup_pair.iterator, LOOKUP_table[index].perm_length);
    }

    *generator_array = array_from_LL((struct _general_LL **) generator_pair.head, &generator_count);
    return ((struct _order_COUNTER *) _close_CHANNEL(subgroup_pair.head));
}

void print_subgroup(unsigned long index) {
    fprintf(main_fs, "<%s> = {", LOOKUP_table[index].ASCII);
    unsigned long i = 0; do {
	fprintf(main_fs, "%s", LOOKUP_table[LOOKUP_table[index].permutation[(i + shifts->X) % LOOKUP_table[index].perm_length]].ASCII); i++;
	if (i == LOOKUP_table[index].perm_length) break;
	else fprintf(main_fs, ", ");
    } while (1); fprintf(main_fs, "}");
}

void interesting_function_one_old(unsigned long *generator_array, struct group_STRUCT *group, unsigned long offset) {
    unsigned long INDEX = offset % generator_count;
    unsigned long factor_accumulator = 1;
    do {unsigned long v = 1; unsigned long additive = 0;
	do {v *= LOOKUP_table[generator_array[INDEX]].ulong; v %= group->MOD; additive++;
	} while (v != LOOKUP_table[generator_array[(INDEX + 1) % generator_count]].ulong);
	printf("%lu^%lu = %lu", LOOKUP_table[generator_array[INDEX]].ulong, additive, LOOKUP_table[generator_array[(INDEX + 1) % generator_count]].ulong);
	factor_accumulator *= additive; factor_accumulator %= totient(group->MOD); INDEX++; INDEX %= generator_count;
	if (factor_accumulator == 1) break;
	else printf("\n");
    } while (1); printf("^1\n"); // replace << using "} while (INDEX != offset % generator_count);" if failure is found
} // ^ Functions perfectly now

void interesting_function_one(unsigned long passed_generator, struct group_STRUCT *group) {
    unsigned long passed_generator_ORDER = cardinality / GCD(cardinality, 1);
    printf("Passed generator: %lu\n", passed_generator);
    printf("Order of passed generator: %lu\n", passed_generator_ORDER);

    unsigned long factor_accumulator = 1;
    unsigned long *array = (unsigned long *) malloc(sizeof(unsigned long) * (cardinality / 2));
    for (unsigned long i = 0; i < cardinality / 2; i++) if (GCD(i + 1, cardinality) == 1) array[i] = 1;
    do {unsigned long v = passed_generator; unsigned long log = 1;
	do {v *= passed_generator; v %= group->MOD; log++;
	} while (cardinality / GCD(cardinality, log) != passed_generator_ORDER);
	printf("%lu^%lu = %lu", passed_generator, log, v);
	passed_generator = v;
	factor_accumulator *= log; factor_accumulator %= cardinality;
	if (factor_accumulator == 1) break;
	else printf("\n");
    } while (1); printf("^1\n");
}

void interesting_function_two(unsigned long *generator_array, struct group_STRUCT *group) {
    unsigned long FOCUS = 1;
    do {unsigned long v = 1; unsigned long additive = 0;
	do {v *= LOOKUP_table[generator_array[0]].ulong; v %= group->MOD; additive++;
	} while (v != LOOKUP_table[generator_array[FOCUS]].ulong);
	printf("%lu^%lu = %lu\n", LOOKUP_table[generator_array[0]].ulong, additive, LOOKUP_table[generator_array[FOCUS]].ulong); FOCUS++;
    } while (FOCUS < generator_count);
}

void group_spitter(unsigned long *generator_array, struct group_STRUCT *group) {
    printf("%lu", LOOKUP_table[generator_array[0]].ulong);
    unsigned long FOCUS = 1;
    do {unsigned long v = 1; unsigned long additive = 0;
	do {v *= LOOKUP_table[generator_array[0]].ulong; v %= group->MOD; additive++;
	} while (v != LOOKUP_table[generator_array[FOCUS]].ulong);
	printf(", %lu", additive); FOCUS++;
    } while (FOCUS < generator_count);
    printf(", %lu", cardinality - 1);
}

int main(int argc, char **argv) { group_OBJ group; main_fs = stdout;
    if (6 < argc || argc > 1 && match(argv[1], help_queries)) HELP_AND_QUIT(argv[0]); else group = (group_OBJ) malloc(sizeof(group_OBJ));
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &group->MOD)) MOD_not_parsable_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_enum_GROUP_IDentity(argv[2], &group->ID)) ID_not_parsable_ERROR(argv[1], argv[2]);
    else group_operation = operation_from_ID(group->ID); // <^^^ Parses and processes everything that has to do with CMD args, also deals with the "help_queries"

    shifts = (struct offset_values *) malloc(sizeof(struct offset_values)); shifts->Y = shifts->X = 0;
    if (argc != 3) { switch (argc) { case 6: main_fs = fopen(argv[5], "w");
	    case 5: if (!STR_could_be_parsed_into_UL(argv[4], &shifts->Y)) fprintf(stderr, STDOUT_VERTICAL_OFFSET_ERROR, argv[4]);
	    case 4: if (!STR_could_be_parsed_into_UL(argv[3], &shifts->X)) fprintf(stderr, STDERR_HORIZONTAL_OFFSET_ERROR, argv[3]);
	    default: if (!boolean_from_ID_Sloth(group)) { shifts->X %= group->MOD; shifts->Y %= group->MOD; } } // << Only applies the modulus value to shifts when dealing with additive groups
    } // ^ Process offset values.

    unsigned long *generator_array;
    struct _order_COUNTER *tree = second_MAIN(&generator_array, element_LL_from_file(argv, group), group); // << Check "subgroup_information.h" for elaboration concerning "second_MAIN()"
    for (unsigned long i = shifts->Y; i < cardinality + shifts->Y; i++) { print_subgroup(i % cardinality); fprintf(main_fs, "\n"); } // << Print table to "main_fs" (whilst applying vertical offset!)

    const char *adjective = adjective_from_ID_Sloth(group);
    const char *symbol = operation_symbol_from_ID_Sloth(group);
    if (main_fs != stdout) { fclose(main_fs); main_fs = stdout;
	fprintf(main_fs, "Wrote table for the %s group of integers modulo %s to the external file '%s'\n", adjective, argv[1], argv[5]);
	fprintf(main_fs, "Horizontal offset used: %lu\nVertical offset used: %lu\n", shifts->X, shifts->Y); }
    // ^^^ Only the table is supposed to be written to the external file

    fprintf(main_fs, "\n| \u2115%s%s's kinds of subgroups:\n| %s | %s | %s\n", argv[1], symbol, _perm_length_header, _percentage_header, _frequency_header);
    float perc; do {
	tree->perm_length_occurences.STR = str_from_ul(tree->perm_length_occurences.ULONG, str_len(_frequency_header) - 3);
	perc = ((float) tree->perm_length_occurences.ULONG / cardinality) * 100;
	fprintf(main_fs, "| %s | %.21f | %lu / %lu", tree->perm_length.STR, perc, tree->perm_length_occurences.ULONG, cardinality);
	tree = tree->next; printf("\n");
    } while (tree);

    fprintf(main_fs, "\nInteresting function #1:\n");
    if (generator_array) {
	interesting_function_one(LOOKUP_table[generator_array[0]].ulong, group); printf("\n");
	unsigned long tot = totient(group->MOD);
	unsigned long *array = (unsigned long *) malloc(sizeof(unsigned long) * (tot / 2));
	for (unsigned long i = 0; i < (tot / 2); i++) if (GCD(i + 1, tot) == 1) array[i] = 1;
	printf("The generators:\n"); unsigned long generator_unit_number = 1;
	for (unsigned long i = 0; i < tot / 2; i++) {
	    if (array[i] == 1) {
		printf("(G_%lu) / 1 = %lu\n", generator_unit_number, FINITE_N_exponentiation(LOOKUP_table[generator_array[0]].ulong, i + 1, group->MOD));
		printf("(G_%lu) \\ 1 = %lu\n", generator_unit_number, FINITE_N_exponentiation(LOOKUP_table[generator_array[0]].ulong, tot - (i + 1), group->MOD)); generator_unit_number++;
	    }
	}
    }

    fprintf(main_fs, "\n"); if (generator_array) {
	fprintf(main_fs, "Generator's in \u2115%s%s:\n", argv[1], symbol);
	unsigned long i = shifts->Y % generator_count; do { print_subgroup(generator_array[i % generator_count]);
	    if (i % generator_count != (shifts->Y - 1) % generator_count) { fprintf(main_fs, ", and\n"); i++; } else break; } while (1); free(generator_array);
    } else fprintf(main_fs, "This group does not contain any generators."); printf("\n");
    // ^^^ Calls the amount of generators to the user and recounts it afterwards, horizontal "shifts->X" is used here, check that out. Also free()'s the array

    for (unsigned long index = 0; index < cardinality; index++) { free(LOOKUP_table[index].permutation); free(LOOKUP_table[index].ASCII); } free(LOOKUP_table);
    // ^^^ Free all of the sloths of memory referred to (in)directly by the table

    return 0;
}
