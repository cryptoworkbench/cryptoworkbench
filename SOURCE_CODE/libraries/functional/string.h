#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
// library inclusions ^^^

#define STRING_TERMINATING_CHARACTER 0
#define NUMERIC_BASE 10
#define ASCII_BASE 48
// definitions ^^^

typedef void (*_error_function) ();
// variable type declarations ^

unsigned int *width_; char ***argv_loc; char *unparsed_arg;
// global variable declarations ^^^

void str_not_parsable_as_number();
int error_message(_error_function error_explainer, int exit_status);
int error_specification(_error_function error_explainer, int exit_status);
int n(int pass_through); int h(int pass_through);
void conditional_goodbye(int exit_status);
int ul_parse_str(unsigned long *ul_ptr, char *str, int exit_status); // to parse unsigned longs
int ui_parse_str(unsigned int *ui_ptr, char *str, int exit_status); // to parse unsigned ints

char *BUFFER_OF_SIZE(unsigned int SIZE);

/* Returns an unsigned long containing the number of characters in the string pointed at by variable 'string_pointer' of type 'constant char *' */
unsigned long str_len(const char *string_pointer); // Just like in the standard library, works just as expected

/* Returns 1 if A and B are the same character, even when they are different in case. If either one of the characters are not from the alphabet, returns 0. */
int case_insensitive_cmp(char A, char B);
int case_insensitive_strcmp(const char *STR, char *STS);

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int str_len_int(char *string_pointer); // Almost the same functionality as the above function

int match_case_insensitive(char *INPUT, const char *char_PTR_array[], unsigned long length);
int match(char *INPUT, const char *char_PTR_array[]); // <<< Inst the makes
int _match(char *str, int array_SIZE, const char *char_PTR_array[]);
int match_variadic(char *INPUT, int number_of_comparisons, ...); // Variadic function that can compare one string against a variable number of strings to compare it to

unsigned long char_in_val(unsigned long a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *_str_from_ul(unsigned long a, unsigned int width_); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as _str_from_ul(unsigned long a, characters_in_val(a))
char *width_str_from_ul(unsigned long a);

void ignored_arguments(int argc, char **argv, int used_arguments);
