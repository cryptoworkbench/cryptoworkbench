/* This library contains all of the string functions.
 *
 * See the header file for function descriptions. */
#include <stdlib.h>
#include "string.h"
#include "../mathematics/maths.h"
#define STRING_TERMINATING_CHARACTER 0
#define BASE 10
#define ASCII_BASE 48

/* Returns 1 if string_a and string_b are equal, if not; returns 0 */
unsigned int streql(char *string_a, char *string_b) {
    unsigned long iter;
    for (iter = 0; !(string_a[iter] == STRING_TERMINATING_CHARACTER || string_b[iter] == STRING_TERMINATING_CHARACTER) && (string_a[iter] == string_b[iter]); iter++) {}
    if (string_a[iter] == string_b[iter])
	return 1;
    else
	return 0;
}

/* Returns an unsigned long containing the number of characters in the string pointed at by the constant char pointer 'string_pointer' */
unsigned long strlen(const char *string_pointer) {
    unsigned long index = 0;
    for (; string_pointer[index] != STRING_TERMINATING_CHARACTER; index++) {}
    return index;
}

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int strlen_int(char *string_pointer) {
    int index = 0;
    for (; string_pointer[index] != STRING_TERMINATING_CHARACTER; index++) {}
    return index;
}

char *copy_over(char *recipient_adress, char *source_adress) {
    while (*source_adress != 0) {
	*recipient_adress = *source_adress;
	source_adress++; recipient_adress++;
    } return recipient_adress;
}

unsigned long str_to_ul(char *string) {
    unsigned long iteration_count, string_as_integer, length_of_string; // Declare needed variables
    iteration_count = string_as_integer = 0; length_of_string = strlen(string); // Initialize variables

    char *current_character = (string + (length_of_string - 1));
    while (current_character != string) {
	string_as_integer += (*current_character - ASCII_BASE) * exponentiate(BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * (exponentiate(BASE, length_of_string - 1));
    return string_as_integer;
}

int string_to_int(char *string) {
    int iteration_count, string_as_integer, length_of_string; // Declare needed variables
    iteration_count = string_as_integer = 0; length_of_string = strlen_int(string); // Initialize variables

    char *current_character = (string + (length_of_string - 1));
    while (current_character != string) {
	string_as_integer += (*current_character - ASCII_BASE) * exponentiate(BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * (exponentiate(BASE, length_of_string - 1));
    return string_as_integer;
}

unsigned long char_in_val(unsigned long a) {
    if (a == 0)
	return 1;

    unsigned long char_index, intermediate_value;
    char_index = 0; intermediate_value = exponentiate(BASE, char_index);

    while (!(intermediate_value >= a)) /* Calculate the first power of BASE which is greater than or equal to a */
    { char_index++; intermediate_value = exponentiate(BASE, char_index); }

    if (intermediate_value == a)
	char_index++;

    return char_index;
}

char *ul_to_str(unsigned long a, unsigned long min_out_length) { // Works!
    unsigned long char_index = char_in_val(a);
    unsigned long number_of_heading_zeros = 0; // Start off assuming there is no need for heading zeros
    if (min_out_length > char_index) // Check to see if there is any need for heading zeros
	number_of_heading_zeros = min_out_length - char_index; // If there is any need for heading zeros, calculate how many

    /* Assign the space needed */
    char *unsigned_long_as_string = (char *) malloc(sizeof(char) * (char_index + number_of_heading_zeros + 1)); // + 1 for the string terminating NULL character
    unsigned_long_as_string[number_of_heading_zeros + char_index] = 0; // Set this string terminating NULL character

    for (unsigned long iter = 0; iter < number_of_heading_zeros; iter++)
	unsigned_long_as_string[iter] = ASCII_BASE;

    unsigned long a_copy = a; /* Start creating the string */
    for (unsigned long remainder = a_copy; char_index != 0; char_index--) {
	remainder %= BASE; // Calculate remainder
	unsigned_long_as_string[number_of_heading_zeros + char_index - 1] = remainder + ASCII_BASE; // Put remainder in string
	a_copy -= remainder; a_copy = a_copy / BASE; // Update a_copy
	remainder = a_copy; // Restore our remainder variable so that we can remainder %= BASE
    } return unsigned_long_as_string;
}
