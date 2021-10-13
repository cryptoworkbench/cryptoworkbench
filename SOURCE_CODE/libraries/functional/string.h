#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "../mathematics/maths.h"
// ^^^ Necessary library inclusions that are needed in "string.c"

#define STRING_TERMINATING_CHARACTER 0
#define NUMERIC_BASE 10
#define ASCII_BASE 48
// ^^^ Necessary definitions that are needed in "string.c"

/* Returns an unsigned long containing the number of characters in the string pointed at by variable 'string_pointer' of type 'constant char *' */
unsigned long str_len(const char *string_pointer); // Just like in the standard library, works just as expected

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int str_len_int(char *string_pointer); // Almost the same functionality as the above function

int match(char *INPUT, int number_of_comparisons, ...); // Variadic function that can compare one string against a variable number of strings to compare it to
char *copy_over(char *recipient_adress, const char *source_adress); // Copies over source onto recipient, terminating at the string terminating character 0 in the byte sequence pointed at by source_adress, then appends one onto the string pointed at by char *repicient_adress

unsigned long ul_from_str(char *string); // Returns the numeric value represented by the string pointed to by char *string as unsigned long
int string_to_int(char *string); // Returns the numeric value represented by the string pointed to by char *string as int

unsigned long char_in_val(unsigned long a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *str_from_ul(unsigned long a, unsigned long min_out_length); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as str_from_ul(unsigned long a, characters_in_val(a))

unsigned long *ul_ptr_from_str(unsigned long *INSERTMENT_SLOTH, char *terminal_argument);
/* ^^^ ALTERNATIVE TO "ul_from_str()" ^^^
 * Supposed to be used for the parsing of command line arguments as integers of the data type "unsigned long"
 *
 * Feed it a char array at argv[index].
 *
 * Parses "argv[index]" into "INSERTMENT_SLOTH" if "argv[index]" is parsable. Returns "INSERTMENT_SLOTH" if "argv[index]" is parsable.
 *
 * Returns a "NULL" pointer if "argv[index]" is not parsable.
 */
