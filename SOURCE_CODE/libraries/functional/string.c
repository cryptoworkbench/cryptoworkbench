/* This library contains all of the string functions.
 *
 * See the header file for function descriptions.
 *
 * The warning for an implicit declaration of "exponentiate" during "gcc -c string.c -o .string.o" can be ignored. Just include .maths.o in the linking process.
 * */
#include "string.h"
#include "../mathematics/maths.h" // 'exponentiation()'
#include <stdio.h>

_error_selector _str_not_parsable_as_number(char *str) { unparsed_arg = str; return str_not_parsable_as_number; }
void str_not_parsable_as_number() { fprintf(stderr, " parsing of '%s' failed: '%s' is not a number.", unparsed_arg, unparsed_arg); }

int error_message(_error_selector error_explainer, int exit_status)
{ if (exit_status) { fflush(stdout); fprintf(stderr, "### THE FOLLOWING ERROR OCCURRED -->"); error_explainer(); } return exit_status; }

int str_represents_ul(char *str, unsigned long *ul_ptr, int exit_status) { unparsed_arg = str; // <-- dodge having to use the wrapper for the error function (in case anything goes wrong)
    if (!str) return n(error_message(str_not_parsable_as_number, exit_status)); unsigned long length_of_string = 0;
    do { if (str[length_of_string] >= ASCII_BASE && str[length_of_string] < ASCII_BASE + 10) length_of_string++; else return n(error_message(str_not_parsable_as_number, exit_status)); }
    while (str[length_of_string] != STRING_TERMINATING_CHARACTER);
    // ^^^ Checks to see if the proposed char array at index is even parsable as an unsigned long, returns NULL if not

    unsigned long iteration_count, str_as_UL; // Declare needed variables
    iteration_count = str_as_UL = 0; // Initialize variables

    // char *current_character = &(str[length_of_string - 1]);
    char *current_character = (str + (length_of_string - 1));
    while (current_character != str) {
	str_as_UL += ((unsigned int) *current_character - ASCII_BASE) * exponentiate(NUMERIC_BASE, iteration_count);
	iteration_count++; // Update the iteration count (appriopiate log)
	current_character = (current_character - 1); // Move back one character
    } str_as_UL += (*current_character - ASCII_BASE) * (exponentiate(NUMERIC_BASE, length_of_string - 1));

    *ul_ptr = str_as_UL; // <<< Inserts the parsed variable into the INSERTMENT_SLOTH (see header file "string.h")
    return 1;
}

int str_represents_ul_(char *str, unsigned long *ul_ptr, int exit_status)
{ 
    unparsed_arg = str; // <-- dodge having to use the wrapper for the error function (in case anything goes wrong)
    if (!str) return n(error_message(str_not_parsable_as_number, exit_status)); unsigned long length_of_string = 0;
    do { if (str[length_of_string] >= ASCII_BASE && str[length_of_string] < ASCII_BASE + 10) length_of_string++; else return n(error_message(str_not_parsable_as_number, exit_status)); }
    while (str[length_of_string] != STRING_TERMINATING_CHARACTER);
    // ^^^ Checks to see if the proposed char array at index is even parsable as an unsigned long, returns NULL if not

    unsigned long iteration_count, str_as_UL; // Declare needed variables
    iteration_count = str_as_UL = 0; // Initialize variables

    // char *current_character = &(str[length_of_string - 1]);
    char *current_character = (str + (length_of_string - 1));
    while (current_character != str) {
	str_as_UL += ((unsigned int) *current_character - ASCII_BASE) * exponentiate(NUMERIC_BASE, iteration_count);
	iteration_count++; // Update the iteration count (appriopiate log)
	current_character = (current_character - 1); // Move back one character
    } str_as_UL += (*current_character - ASCII_BASE) * (exponentiate(NUMERIC_BASE, length_of_string - 1));

    *ul_ptr = str_as_UL; // <<< Inserts the parsed variable into the INSERTMENT_SLOTH (see header file "string.h")
    return 0;
}

int error_specification(_error_selector error_explainer, int exit_status)
{ if (exit_status) { fflush(stdout); error_explainer(); } return exit_status; }

int n(int exit_status) { if (exit_status) fprintf(stderr, "\n"); return exit_status; }

void conditional_goodbye(int exit_status) { if (!exit_status) return; fprintf(stderr, "\n" EXIT_STATUS_GOODBYE "\n", exit_status); exit(exit_status); }

char *BUFFER_OF_SIZE(unsigned int SIZE) {
    char *return_value = (char *) malloc(sizeof(char) * SIZE);
    return return_value;
}

/* Returns an unsigned long containing the number of characters in the string pointed at by the constant char pointer 'string_pointer' */
unsigned long str_len(const char *string_pointer) {
    unsigned long index = 0;
    for (; string_pointer[index] != STRING_TERMINATING_CHARACTER; index++) {}
    return index;
}

int case_insensitive_cmp(char a, char b) {
    // First we need to check if both characters are even from the alphabet
    if (!((64 < a && a < 91) || (96 < a && a < 123)) || !((64 < b && b < 91) || ( 96 < b && b < 123)))
	return 1; // << ^^^ If either one of the characters are not even from the alphabet

    /* Now we should be able to know for sure both "a" and "b" are from the alphabet */
    if (a == b) return 1; // <<< First we just check if the characters are the same:
    else if (b == a + 32) return 1; // <<< If this is not the case, check if "b" is the uppercase variant of "a"
    else if (a == b + 32) return 1; // <<< If this is also not the case, check if "a" is the uppercase variant of "b"
    else return 0; // ^^^ << This function also works with "@" and "`"
} // <<^^^ Only returns 1 if "a" and "b" are both from the alphabet and one is another case variant of the other

int case_insensitive_strcmp(const char *STR, char *STS) {
    unsigned long STR_length = str_len(STR);
    if (str_len(STS) != STR_length) return 0;
    // ^^ If the strings are not even of the same length, they could never be the same independent of case

    int i = 0; for (; i < STR_length; i++) if (case_insensitive_cmp(STR[i], STS[i]) == 0) return 0;
    // ^^ Check to see if any of the characters are not each other's variants

    return 1;
    // ^^ redundant
}

int match_case_insensitive(char *INPUT, const char *char_PTR_array[], unsigned long length) {
    unsigned long i = 0; do {
	if (case_insensitive_strcmp(char_PTR_array[length], INPUT) == 0) return 1;
	else length++;
    } while (i < length);

    return 0;
}

int match(char *INPUT, const char *char_PTR_array[]) { int i = 0; do { if (strcmp(char_PTR_array[i], INPUT) == 0) return 1; else i++; } while (char_PTR_array[i] != 0); return 0; }

int match_variadic(char *INPUT, int number_of_comparisons, ...) {
    va_list ap;
    va_start(ap, number_of_comparisons);

    for (int i = 0; i < number_of_comparisons; i++) if (strcmp(INPUT, va_arg(ap, char *)) == 0) return 1;

    /* End function */
    va_end(ap); return 0;
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

int string_to_int(char *string) {
    int iteration_count, string_as_integer, length_of_string; // Declare needed variables
    iteration_count = string_as_integer = 0; length_of_string = str_len_int(string); // Initialize variables

    char *current_character = (string + (length_of_string - 1));
    while (current_character != string) {
	string_as_integer += (*current_character - ASCII_BASE) * exponentiate(NUMERIC_BASE, iteration_count);

	iteration_count++; // Update the iteration count
	current_character = (current_character - 1); // Move back one character
    } string_as_integer += (*current_character - ASCII_BASE) * exponentiate(NUMERIC_BASE, length_of_string - 1);
    return string_as_integer;
}

unsigned long char_in_val(unsigned long a) {
    if (a == 0)
	return 1;

    unsigned long char_index, intermediate_value;
    char_index = 0; intermediate_value = exponentiate(NUMERIC_BASE, char_index);

    while (!(intermediate_value >= a)) /* Calculate the first power of NUMERIC_BASE which is greater than or equal to a */
    { char_index++; intermediate_value = exponentiate(NUMERIC_BASE, char_index); }

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

void ignored_arguments(int argc, char **argv, int used_arguments) {
    unsigned long difference = argc - 1 - used_arguments; if (difference) {
	fprintf(stderr, "The following %lu unused argument(s) were unneccesary: ", difference);
	do {fprintf(stderr, "%s", argv[used_arguments + 1]); used_arguments++; if (used_arguments + 1 == argc) break; fprintf(stderr, ", "); } while (1);
	fprintf(stdout, "\n"); fprintf(stderr, "\n"); }
}

void str_does_not_represent_suitable_ul(char **argv, int index) { fprintf(stderr, GENERIC_PARSING_ERROR "%s\n\n" EXIT_STATUS_GOODBYE, argv[index], local_error_selector(index), -index); exit(-index); }
