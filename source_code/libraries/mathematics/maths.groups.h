#define ELEMENT_EXPORTER "group_elements"
#define FILENAME_BODY "_group_of_integers_modulus_"
#define LOGBOOK_PATH "logbook" // << This will be the logbook filename in "WORKBENCH/"
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group."
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process."

char *failed_identity; char *argv_ZERO; FILE *logbook_fs;
// variable definitions ^

unsigned long group_exponentiate(ul base, ul exponent);
unsigned long group_conditional_cap(ul result);
unsigned long group_inverse(ul element_of_additive_group);
unsigned long group_add(ul a, ul b);
unsigned long group_subtract(ul a, ul b);
unsigned long group_multiply(ul a, ul b);
unsigned long group_divide(ul numerator, ul denominator);
unsigned long group_polynomial(ul x, ul *coefficient, int coefficients);

void argv_group_parse(struct group *pass_through, error_function_ mod_instruction, error_function_ _id_instruction, int argv_index);

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line);
void open_and_append_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line);
FILE *open_group(char **argv);
FILE *open_group_INNER(char *group_MOD, const char *numerical_denomination, const char *adjective, const char *symbol, char *LINE);
void close_group(char *group_CAP, FILE *opened_group);
void close_logbook();
