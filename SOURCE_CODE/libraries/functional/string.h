#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
// ^^^ Necessary library inclusions that are needed in "string.c"

#define GENERIC_PARSING_ERROR "'%s' is not something I am able to understand as a suitable number;"
#define EXIT_STATUS_GOODBYE "Terminating with exit status '%i'. Goodbye." // still need this for now <--
#define STRING_TERMINATING_CHARACTER 0
#define NUMERIC_BASE 10
#define ASCII_BASE 48
// ^^^ Necessary definitions that are needed in "string.c"

char ***argv_location; char *unparsed_arg; // enable easy access to these variables outside of 'main()' <

typedef void (*_error_selector) (); // this we will use for 'error_message'
_error_selector _str_not_parsable_as_number(char *str); void str_not_parsable_as_number();
typedef const char *(*arg_error_selector) (int); arg_error_selector local_error_selector;

int error_message(_error_selector error_explainer, int exit_status);
int error_specification(_error_selector error_explainer, int exit_status);
int n(int pass_through);
void conditional_goodbye(int exit_status);
int str_represents_ul(char *str, unsigned long *ul_ptr, int exit_status);
int str_represents_ul_(char *str, unsigned long *ul_ptr, int exit_status); // <-- Make this one replace 'str_represents_ul()' <--
// ^^^ Puts the numeric value of "str" at the location pointed at by "ul_ptr".
// 
// Returns "VOID" if "str" is not parsable as a base-10 number.

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
int match_variadic(char *INPUT, int number_of_comparisons, ...); // Variadic function that can compare one string against a variable number of strings to compare it to

char *copy_over(char *recipient_adress, const char *source_adress); // Copies over source onto recipient, terminating at the string terminating character 0 in the byte sequence pointed at by source_adress, then appends one onto the string pointed at by char *repicient_adress

unsigned long ul_from_str(char *string); // Returns the numeric value represented by the string pointed to by char *string as unsigned long
int string_to_int(char *string); // Returns the numeric value represented by the string pointed to by char *string as int

unsigned long char_in_val(unsigned long a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *str_from_ul(unsigned long a, unsigned long min_out_length); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as str_from_ul(unsigned long a, characters_in_val(a))


void ignored_arguments(int argc, char **argv, int used_arguments);
void str_does_not_represent_suitable_ul(char **argv, int index);
