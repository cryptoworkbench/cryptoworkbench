#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define STRING_TERMINATING_CHARACTER 0
#define NUMERIC_BASE 10
#define ASCII_BASE 48
// inclusions and definitions ^^

typedef unsigned long ul;
typedef ul *ul_ptr;

typedef unsigned int ui;
typedef ui *ui_ptr;

typedef void (*_error_function) ();
// type declarations ^

char ***argv_ptr; char *unparsed_str;
// variable declarations ^^^

_error_function not_parsable(_error_function error_function, char *unparsable_str);

void conditional_goodbye(int exit_status);

int n(int pass_through);
int h(int pass_through);

int error_specification(_error_function error_explainer, int exit_status);
int error_message(_error_function error_explainer, int exit_status);

/* ===================== corresponds to 'maths.extended.h' (!) =================== */
int _ul_parse_str(ul_ptr ul_ptr, char *str, int exit_status);
/* ===================== corresponds to 'maths.extended.h' (!) =================== */

void LOOP_ul_parse_str(_error_function error_function, ul_ptr array, ui array_size, ui_ptr _i, ui start);

int _ui_parse_str(ui_ptr ui_ptr, char *str, int exit_status);

void str_not_parsable_as_number();
// functions for parsing terminal arguments ^

unsigned long str_len(const char *string_pointer); // str_len function Just like in the standard library, but with unsigned long

/* Returns 1 if A and B are the same character, even when they are different in case. If either one of the characters are not from the alphabet, returns 0. */
int case_insensitive_cmp(char A, char B);
int case_insensitive_strcmp(const char *STR, char *STS);

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int str_len_int(char *string_pointer); // Almost the same functionality as the above function

int match_case_insensitive(char *INPUT, const char *char_PTR_array[], ul length);
int match(char *INPUT, const char *char_PTR_array[]); // <<< Inst the makes
int _match(char *str, int array_SIZE, const char *char_PTR_array[]);
int match_variadic(char *INPUT, int number_of_comparisons, ...); // Variadic function that can compare one string against a variable number of strings to compare it to

unsigned long char_in_val(ul a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *_str_from_ul(ul a, ui width_); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as _str_from_ul(ul a, characters_in_val(a))

void ignored_arguments(int argc, char **argv, int used_arguments);

char *BUFFER_OF_SIZE(ui SIZE);
