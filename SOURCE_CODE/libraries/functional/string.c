/* This library contains all of the string functions.
 *
 * See the header file for function descriptions. */
#include "string.h"

/* Returns an unsigned long containing the number of characters in the string pointed at by the constant char pointer 'string_pointer' */
unsigned long str_len(const char *string_pointer) {
    unsigned long index = 0;
    for (; string_pointer[index] != STRING_TERMINATING_CHARACTER; index++) {}
    return index;
}

int match(char *INPUT, int number_of_comparisons, ...) {
    va_list ap;
    va_start(ap, number_of_comparisons);

    for (int i = 0; i < number_of_comparisons; i++) if (strcmp(INPUT, va_arg(ap, char *)) == 0) return 1;

    /* End function */
    va_end(ap); return 0;
}

int match_against_list(char *INPUT, char *char_PTR_array[]) {
    int length = 0; do {
	if (strcmp(char_PTR_array[length], INPUT) == 0) return 1;
	else length++;
    } while (char_PTR_array[length] != 0);

    printf("Length of the list: %i\n", length);
    return 0;
}

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int str_len_int(char *string_pointer) {
    int index = 0;
    for (; string_pointer[index] != STRING_TERMINATING_CHARACTER; index++) {}
    return index;
}

char *copy_over(char *recipient_adress, const char *source_adress) {
    while (*source_adress != 0) {
	*recipient_adress = *source_adress;
	source_adress++; recipient_adress++;
    } return recipient_adress;
}

unsigned long ul_from_str(char *string) {
    unsigned long iteration_count, string_as_integer, length_of_string; // Declare needed variables
    iteration_count = string_as_integer = 0; length_of_string = str_len(string); // Initialize variables

    char *current_character = (string + (length_of_string - 1));
    while (current_character != string) {
	string_as_integer += (*current_character - ASCII_BASE) * N_exponentiation(NUMERIC_BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * (N_exponentiation(NUMERIC_BASE, length_of_string - 1));
    return string_as_integer;
}

int string_to_int(char *string) {
    int iteration_count, string_as_integer, length_of_string; // Declare needed variables
    iteration_count = string_as_integer = 0; length_of_string = str_len_int(string); // Initialize variables

    char *current_character = (string + (length_of_string - 1));
    while (current_character != string) {
	string_as_integer += (*current_character - ASCII_BASE) * N_exponentiation(NUMERIC_BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * (N_exponentiation(NUMERIC_BASE, length_of_string - 1));
    return string_as_integer;
}

unsigned long char_in_val(unsigned long a) {
    if (a == 0)
	return 1;

    unsigned long char_index, intermediate_value;
    char_index = 0; intermediate_value = N_exponentiation(NUMERIC_BASE, char_index);

    while (!(intermediate_value >= a)) /* Calculate the first power of NUMERIC_BASE which is greater than or equal to a */
    { char_index++; intermediate_value = N_exponentiation(NUMERIC_BASE, char_index); }

    if (intermediate_value == a)
	char_index++;

    return char_index;
}

char *str_from_ul(unsigned long a, unsigned long min_out_length) { // Works!
    unsigned long char_index = char_in_val(a);
    unsigned long number_of_heading_zeros = 0; // Start off assuming there is no need for heading zeros
    if (min_out_length > char_index) // Check to see if there is any need for heading zeros
	number_of_heading_zeros = min_out_length - char_index; // If there is need for heading zeros, the number of heading zeros that are needed is the difference calculation

    /* Assign the space needed */
    char *unsigned_long_as_string = (char *) malloc(sizeof(char) * (char_index + number_of_heading_zeros + 1)); // + 1 for the string terminating NULL character
    unsigned_long_as_string[number_of_heading_zeros + char_index] = 0; // Set this string terminating NULL character

    for (unsigned long iter = 0; iter < number_of_heading_zeros; iter++)
	unsigned_long_as_string[iter] = ASCII_BASE;

    unsigned long a_copy = a; /* Start creating the string */
    for (unsigned long remainder = a_copy; char_index != 0; char_index--) {
	remainder %= NUMERIC_BASE; // Calculate remainder
	unsigned_long_as_string[number_of_heading_zeros + char_index - 1] = remainder + ASCII_BASE; // Put remainder in string
	a_copy -= remainder; a_copy = a_copy / NUMERIC_BASE; // Update a_copy
	remainder = a_copy; // Restore our remainder variable so that we can remainder %= NUMERIC_BASE
    } return unsigned_long_as_string;
}

unsigned long *STR_could_be_parsed_into_UL(char *STRING, unsigned long *UL_PTR) { // Alternative to "ul_from_str()"
    unsigned long length_of_string = 0; do {
	if (STRING[length_of_string] >= ASCII_BASE && STRING[length_of_string] < ASCII_BASE + 10) length_of_string++;
	else return NULL;
    } while (STRING[length_of_string] != STRING_TERMINATING_CHARACTER);
    // ^^^ Checks to see if the proposed char array at index is even parsable as an unsigned long, returns NULL if not

    unsigned long iteration_count, string_as_integer; // Declare needed variables
    iteration_count = string_as_integer = 0; // Initialize variables

    char *current_character = (STRING + (length_of_string - 1));
    while (current_character != STRING) {
	string_as_integer += (*current_character - ASCII_BASE) * N_exponentiation(NUMERIC_BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * (N_exponentiation(NUMERIC_BASE, length_of_string - 1));

    *UL_PTR = string_as_integer; // <<< Inserts the parsed variable into the INSERTMENT_SLOTH (see header file "string.h")
    return UL_PTR;
}
