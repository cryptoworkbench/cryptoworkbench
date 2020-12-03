unsigned long strlen(const char *string); // Works just as expected
int strlen_int(char *string); // Same functionality as the above, just with int instead of unsigned long as return type

unsigned int streql(char *string_a, char *string_b); // Returns 1 if string_a and string_b are equal, returns 0 if not
char *copy_over(char *recipient_adress, char *source_adress); // Copies over source onto recipient, terminating at the string terminating character 0 in the byte sequence pointed at by source_adres, then appends one onto the string pointed at by char *repicient_adress

unsigned long string_to_unsigned_long(char *string); // Returns the numeric value represented by the string pointed to by char *string as unsigned long
int string_to_int(char *string); // Returns the numeric value represented by the string pointed to by char *string as int

unsigned long char_in_val(unsigned long a); // Calculates the number of characters needed to display a in base BASE notation (BASE = 10)
char *ul_to_str(unsigned long a, unsigned long min_out_length); // Converts from ul to string with a minimum of min_out_length characters, heading zeros are fixed if needed, call as unsigned_long_to_string(unsigned long a, characters_in_val(a))
