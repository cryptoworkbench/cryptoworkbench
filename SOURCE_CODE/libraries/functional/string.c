/* This library contains all of the string functions.
 *
 * See the header file for function descriptions.
 *
 * The warning for an implicit declaration of "exponentiate" during "gcc -c string.c -o .string.o" can be ignored. Just include .maths.o in the linking process.
 * */
#include "string.h"
#include "../mathematics/math.basic.h" // 'exponentiation()'
#include <stdio.h>

_error_function not_parsable(_error_function error_function, char *unparsable_str)
{
    unparsed_str = unparsable_str; return error_function;
}

void str_not_parsable_as_number() { fprintf(stderr, "parsing of '%s' failed: '%s' is not a number.", unparsed_str, unparsed_str); }

int error_message(_error_function error_explainer, int exit_status)
{ if (exit_status) { fflush(stdout); fprintf(stderr, "### THE FOLLOWING ERROR OCCURRED --> "); error_explainer(); } return exit_status; }

int _parse_str_failure(int exit_status) { return n(error_message(str_not_parsable_as_number, exit_status)); }

int _parse_str_NULL_check(char *str, int exit_status) { unparsed_str = str; if (!str) return _parse_str_failure(exit_status); return 0; }

int ul_parse_str(unsigned long *ul_ptr, char *str, int exit_status)
{
    int i = 0; if (i = _parse_str_NULL_check(str, exit_status)) return i;
    do {if (str[i] < ASCII_BASE || str[i] > ASCII_BASE + 10) return _parse_str_failure(exit_status);
	if (str[i + 1] == STRING_TERMINATING_CHARACTER) break; i++;
    } while (1); int log = 0; do { *ul_ptr += exponentiate(NUMERIC_BASE, log) * (str[i - log] - ASCII_BASE); log++; if (i + 1 - log == 0) break; } while (1);
    return 0;
}

int ui_parse_str(unsigned int *ui_ptr, char *str, int exit_status)
{
    int i = 0; if (i = _parse_str_NULL_check(str, exit_status)) return i;
    do {if (str[i] < ASCII_BASE || str[i] > ASCII_BASE + 10) return _parse_str_failure(exit_status);
	if (str[i + 1] == STRING_TERMINATING_CHARACTER) break; i++;
    } while (1); int log = 0; do {*ui_ptr += (unsigned int) exponentiate(NUMERIC_BASE, log) * (str[i - log] - ASCII_BASE); log++; if (i + 1 - log == 0) break; } while (1);
    return 0;
}

int error_specification(_error_function error_explainer, int exit_status)
{ if (exit_status) { fflush(stdout); error_explainer(); } return exit_status; }

int n(int exit_status) { if (exit_status) fprintf(stderr, "\n"); return exit_status; }
int h(int exit_status) { if (exit_status) fprintf(stderr, "\n#"); return exit_status; }

void conditional_goodbye(int exit_status)
{ if (!exit_status) return; fprintf(stderr, "\n# ^ ^ ^  THE ABOVE WAS A FATAL ERROR!  ^ ^ ^  #\n# Terminating with exit status '%i'. Goodbye. #\n", exit_status); exit(exit_status); }

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

int match(char *INPUT, const char *char_PTR_array[]) {
    int i = 0;
    do {
	if (strcmp(char_PTR_array[i], INPUT) == 0) return 1;
	else i++;
    } while (char_PTR_array[i] != 0);
    return 0;
}

int _match(char *str, int array_SIZE, const char *char_PTR_array[])
{
    for (int i = 0; i < array_SIZE; i++) if (strcmp(char_PTR_array[i], str) == 0) return 1; return 0;
}

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

char *_str_from_ul(unsigned long ul, unsigned int width_) { // Works!
    unsigned int base_ten_width = char_in_val(ul);
    unsigned int number_of_heading_zeros = 0; // Start off assuming there is no need for heading zeros
    if (width_ > base_ten_width) // Check to see if there is any need for heading zeros
	number_of_heading_zeros = width_ - base_ten_width; // If there is need for heading zeros, the number of heading zeros that are needed is the difference calculation

    char *transformed_str; *(number_of_heading_zeros + base_ten_width + (transformed_str = (char *) malloc(sizeof(char) * (base_ten_width + number_of_heading_zeros + 1)))) = 0;
    // allocate the needed char pointer array ^

    for (unsigned int i = 0; i < number_of_heading_zeros; i++) transformed_str[i] = ASCII_BASE;
    // prepare the array ^

    for (unsigned long remainder = ul; base_ten_width != 0; base_ten_width--) {
	remainder %= NUMERIC_BASE; // Calculate remainder
	transformed_str[number_of_heading_zeros + base_ten_width - 1] = remainder + ASCII_BASE; // Put remainder in string
	ul -= remainder; ul = ul / NUMERIC_BASE; // Update ul
	remainder = ul; // Restore our remainder variable so that we can remainder %= NUMERIC_BASE
    } return transformed_str;
}

char *width_str_from_ul(unsigned long ul) { return _str_from_ul(ul, *width_); }

void ignored_arguments(int argc, char **argv, int used_arguments) {
    unsigned long difference = argc - 1 - used_arguments; if (difference) {
	fprintf(stderr, "The following %lu unused argument(s) were unneccesary: ", difference);
	do {fprintf(stderr, "%s", argv[used_arguments + 1]); used_arguments++; if (used_arguments + 1 == argc) break; fprintf(stderr, ", "); } while (1);
	fprintf(stdout, "\n"); fprintf(stderr, "\n"); }
}
