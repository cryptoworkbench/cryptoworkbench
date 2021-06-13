/* Cayley table generator:
 * This application generates cayley tables for the groups of modular arithmatics.
 *
 * This means additive groups under an integer modulus and multiplicative groups under an integer modulus.
 *
 * ABSTRACT:
 * First this program determines all of the group's elements and puts them into a linked list (non-circular and singly-linked).
 *
 * Then this program creates a linked list of possible combinations and their outcome (again non-circular and singly-linked).
 *
 * Then this code looks up every outcome for every combination from this linked list in order to fill out a cayley table.
 *
 * Results of unary operations are never calculated twice.
 *
 *
 * DEVELOPERS NOTES:
 * - Start all over again and do it right.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/group_operations.h"
// Mathematical definitions
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

// Colour definitions
#define RESET "\033[0m"
#define RED "\033[31m"
#define UNDERLINE "\e[4m"
FILE *fs; // the line where main starts sets this to stdout  

const char *Error_one = "Program usage:\n";
const char *Error_two = " <group modulus> <group identity>\n";
const char *prepend = "cayley_table_for_the_";
const char *multiplicative_adjective = "multiplicative";
const char *additive_adjective = "additive";
const char *middle = "_group_of_integers_under_modulo_";
const char *end = "_arithmatic";

// Set global variable for this shit
unsigned long (*group_operation) (unsigned long, unsigned long, unsigned long);

struct group_meta {
    unsigned long modulus;
    unsigned long identity;
    unsigned long order;
    unsigned long cell_width;
    struct element *ll;
};

struct element {
    struct element *next;
    unsigned long number;
    char *ascii;
};

struct combination {
    struct element *first;
    struct element *second;
    struct element *outcome;
    struct combination *next;
};

struct combination *combination_ll;

unsigned int coprime(unsigned long greatest_common_divisor) // Call as coprime(GCD(big, small)) ===>
  { return (greatest_common_divisor == 1) ? 1 : 0; } // <=== If the Greatest Common Divisor of the unsigned long variables 'big' and 'small' in GCD(big, small) = 1, big & small are coprime

void spawn_element(struct element **tracer, unsigned long new_ulong) {
    struct element *new_element = (struct element *) malloc(sizeof(struct element)); // Fix existence of new element
    new_element->next = NULL;
    new_element->number = new_ulong;
    new_element->ascii = NULL;

    while (*tracer) // ### Find last insertion
	tracer = &(*tracer)->next;

    *tracer = new_element; // ## And place the location of new_element into the next field of this last insertion
}

struct element *setup_group(struct element **linked_list_connection, struct group_meta *group) {
    // ### Establish lineair linked list containing all group elements using the triple ref technique
    for (unsigned long element = group->identity; element < group->modulus; element++)
	if (group->identity == ADDITIVE_IDENTITY || coprime(GCD(group->modulus, element))) {
	    spawn_element(linked_list_connection, element);
	    group->order++; }

    // ## Take out of the end product a singly-linked list and destroy any intermediary memory used
    struct element *iterator, *identity;
    iterator = identity = (struct element *) disintermediate( (void **) linked_list_connection);
    while (iterator->next) {
	iterator = iterator->next;
    } group->cell_width = char_in_val(iterator->number);
    iterator = identity; // RESET
    
    // And write ASCII codes into group information
    while (iterator) {
	iterator->ascii = str_from_ul(iterator->number, group->cell_width);
	iterator = iterator->next; }

    // Finalize work
    return identity;
}

void print(struct group_meta *group) {
    struct element *element = group->ll;
    for (unsigned long counter = 1; counter < group->order; counter++) {
	fprintf(fs, "%s, ", element->ascii);
	element = element->next;
    } fprintf(fs, "%s", element->ascii);
}

struct element *lookup(unsigned long mark, struct group_meta *group) {
    struct element *element = group->ll;
    while (element) {
	if (element->number == mark)
	    return element;
	else
	    element = element->next;
    }
}

void spawn_association(struct combination **tracer, struct element *unary_head, struct element *unary_tail, struct element *outcome) {
    // Then we create the rest
    struct combination *new_combi = (struct combination *) malloc(sizeof(struct combination)); // Fix existence of new combination
    new_combi->first = unary_head;
    new_combi->second = unary_tail;
    new_combi->outcome = outcome;

    while (*tracer) // ### Find last insertion
	tracer = &(*tracer)->next;

    *tracer = new_combi; // ## And place the location of new_combi into the next field of this last insertion
}

struct combination *combine(struct combination **source, struct group_meta *group) { 
    // First we determine the group operation
    if (group->identity)
	group_operation = _the_unary_operator_multiplication_under_modular_arithmatic;
    else
	group_operation = _the_unary_operator_addition_under_modular_arithmatic;

    // Prepare variables for function
    struct element *unary_head = group->ll;

    // Perform loop
    for (unsigned long round_no = ADDITIVE_IDENTITY; round_no < group->order; round_no++, unary_head = unary_head->next) {
	struct element *unary_tail = unary_head; // Start combining
	do {// Lookup the adress of the element that results from performing the group operation using the selected unary_head and unary_tail
	    struct element *outcome = lookup(
		    group_operation( // <-- Performs the group operation and sends the outcome along with the linked list connection to the lookup function
			unary_head->number,
			unary_tail->number,
			group->modulus),
		    group
		    );

	    // Spawn the new association into memory
	    spawn_association(
		    source,
		    unary_head,
		    unary_tail,
		    outcome
		    );

	    // Move along the vertical axis (y)
	    unary_tail = unary_tail->next;
	} while (unary_tail); }
    return (struct combination *) disintermediate( (void **) source); }

void bar(unsigned long spaces) {
    for (unsigned long iter = 0; iter < spaces; iter++)
	fprintf(fs, " ");
}

struct element *lookup_combination(struct combination *ll, unsigned long outer, unsigned long inner) {
    struct combination *iter = ll;
    while (iter &&
	    (
		!( iter->first->number == outer && iter->second->number == inner ) &&
		!( iter->first->number == inner && iter->second->number == outer ) )
	  )
	iter = iter->next;
    return iter->outcome;
}

struct element *lookup_el(struct group_meta *group, unsigned long number) {
    struct element *iter = group->ll;
    for (unsigned long i = 0; i < number; i++) {
	iter = iter->next;
    } return iter;
}

int main(int argc, char **argv) { fs = stdout;
    if (4 < argc) { // <-- Check argument count
	fprintf(stderr, "%s%s%s", Error_one, argv[0], Error_two);
	return -1; }

    // Start program
    struct group_meta *group = (struct group_meta *) malloc(sizeof(struct group_meta));
    char *output_filename = NULL; unsigned long filename_length = 0;
    switch (argc) { // Process supplied variables 
	case 3:
	    group->identity = ul_from_str(argv[2]);
	case 2:
	    group->modulus = ul_from_str(argv[1]);

	    if (3 < argc /* a.k.a. argc == 4 */) {

	    }
	    // Determine filename length
	    filename_length += strlen(prepend);

	    if (group->identity)
		filename_length += strlen(multiplicative_adjective);
	    else
		filename_length += strlen(additive_adjective);
	    
	    filename_length += strlen(middle);
	    filename_length += char_in_val(group->modulus);
	    filename_length += strlen(end);

	    // Allocate memory
	    output_filename = (char *) malloc(sizeof(char) * (filename_length + 1));

	    // Start creation
	    char *filename_iterator = output_filename;
	    filename_iterator = copy_over(output_filename, prepend);
	    if (group->identity)
		filename_iterator = copy_over(filename_iterator, multiplicative_adjective);
	    else
		filename_iterator = copy_over(filename_iterator, additive_adjective);

	    sprintf(filename_iterator, "%s%s%s", middle, argv[1], end);
	    // ^^ The only thing I might overlook here is setting the string terminating character in the filename
	    fs = fopen(output_filename, "w");
	    fprintf(stdout, "Generated to file:\n");
	    fprintf(stdout, "	\"%s\"\n", output_filename);
	    fprintf(stdout, "\n\nA cayley table for the ");
	    if (group->identity)
		fprintf(stdout, "%s", multiplicative_adjective);
	    else
		fprintf(stdout, "%s", additive_adjective);

	    fprintf(stdout, " group of integers under modulus %lu arithmatic.", group->modulus);
	    break;
	case 1:
	    fprintf(stderr, "Program usage:\n");
	    fprintf(stderr, "%s <group modulus> <group identity>\n", argv[0]);
    }

    // If neccesary, ask for the group identity
    if (3 > argc) {
	fprintf(stdout, "Group identity: "); 
	fscanf(stdin, "%lu", &group->identity); }

    // If neccesary, ask for the group modulus
    if (2 > argc) {
	fprintf(stdout, "Group modulus: ");
	fscanf(stdin, "%lu", &group->modulus); }

    if (4 > argc) {
    } else if (!streql(argv[3], "stdout")) {
	fs = fopen(argv[3], "w");
	printf("Filestream opened to %s\n", argv[3]);
    } else
	printf("%s\n", argv[3]);

    // Initialize group
    group->ll = setup_group((struct element **) sub_ordinator(), group);

    // Initialize combination ll
    combination_ll = combine((struct combination **) sub_ordinator(), group);

    // Print first table row
    fprintf(stdout, UNDERLINE); fprintf(fs, " "); fprintf(stdout, RED);
    if (group->identity)
	fprintf(fs, "*");
    else
	fprintf(fs, "+");

    bar(group->cell_width - 1); fprintf(stdout, RESET UNDERLINE);
    struct element *element = group->ll;
    for (unsigned long counter = 0; counter < group->order; counter++) {
	fprintf(fs, " | ");
	fprintf(stdout, RED);
	fprintf(fs, "%s", element->ascii);
	fprintf(stdout, RESET UNDERLINE);
	element = element->next; }
    fprintf(fs, " \n");

    // Start rest of table
    struct combination *iterator = combination_ll;
    for (unsigned long outer = 0; outer < group->order; outer++) {
	// fprintf(fs, " " RED "%s" RESET UNDERLINE, lookup_el(group, outer)->ascii);
	fprintf(fs, " ");
	fprintf(stdout, RED);
        fprintf(fs, "%s", lookup_el(group, outer)->ascii);
	fprintf(stdout, RESET UNDERLINE);
	for (unsigned long inner = 0; inner < group->order; inner++) {
	    fprintf(fs, " | %s", lookup_combination(combination_ll, lookup_el(group, outer)->number, lookup_el(group, inner)->number )->ascii);
	} fprintf(fs, " \n");
    } fprintf(stdout, RESET "\n");
    
    fprintf(stdout, "\nThis group contains %lu elements and the cell width is %lu characters.\n", group->order, group->cell_width + 2);
    return 0;
}
