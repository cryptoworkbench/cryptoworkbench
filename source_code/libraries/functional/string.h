/* Returns an unsigned long containing the number of characters in the string pointed at by variable 'string_pointer' of type 'constant char *' */
unsigned long strlen(const char *string_pointer); // Just like in the standard library, works just as expected

/* Returns an int containing the number of characters in the string pointed at by the char pointer 'string_pointer' */
int strlen_int(char *string_pointer); // Almost the same functionality as the above function

unsigned int streql(char *string_a, char *string_b); // Returns 1 if string_a and string_b are equal, returns 0 if not
char *copy_over(char *recipient_adress, const char *source_adress); // Copies over source onto recipient, terminating at the string terminating character 0 in the byte sequence pointed at by source_adress, then appends one onto the string pointed at by char *repicient_adress

unsigned long ul_from_str(char *string); // Returns the numeric value represented by the string pointed to by char *string as unsigned long
int string_to_int(char *string); // Returns the numeric value represented by the string pointed to by char *string as int

unsigned long char_in_val(unsigned long a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *str_from_ul(unsigned long a, unsigned long min_out_length); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as str_from_ul(unsigned long a, characters_in_val(a))
