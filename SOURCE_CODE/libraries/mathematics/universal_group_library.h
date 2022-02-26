#define ELEMENT_EXPORTER "group_element_table_generator"
#define FILENAME_BODY "_group_of_integers_modulus_"
#define LOGBOOK_PATH "logbook" // << This will be the logbook filename in "WORKBENCH/"
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group."
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process."

char *failed_identity; char *argv_ZERO; FILE *logbook_fs; unsigned long *id_; // all function that begin with 'id_' work with this last variable <-
// variable definitions ^

int identity_SELECTOR(char *arg);
void identity_SELECTOR_error();
unsigned long identity_(int SELECTOR);
int identity_set(unsigned long *identity, int SELECTOR, int exit_status);
// identity functions ^

const char *_as_number(unsigned long ID); const char *_as_operation_symbol(unsigned long ID); const char *_as_noun(unsigned long ID); const char *_as_nouns(unsigned long ID); const char *_as_adjective(unsigned long ID);
const char *id_as_number(); const char *id_as_operation_symbol(); const char *id_as_noun(); const char *id_as_nouns(); const char *id_as_adjective();

__finite_field_operation id_finite_group_operation(); // wrapper function for commented out '__finite_field_operation _finite_group_operation(unsigned long id);' <-- 

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line);
void open_and_append_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line);
FILE *open_group(char **argv);
FILE *open_group_INNER(char *group_MOD, const char *numerical_denomination, const char *adjective, const char *symbol, char *LINE);
void close_group(char *group_CAP, FILE *opened_group);
void close_logbook();
