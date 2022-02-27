#define ELEMENT_EXPORTER "group_element_table_generator"
#define FILENAME_BODY "_group_of_integers_modulus_"
#define LOGBOOK_PATH "logbook" // << This will be the logbook filename in "WORKBENCH/"
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group."
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process."

char *failed_identity; char *argv_ZERO; FILE *logbook_fs; int *id_;
// variable definitions ^

int identity_SELECTOR(char *arg);
void identity_SELECTOR_error();
int identity_(int SELECTOR);
int identity_set(int *id_, int SELECTOR, int exit_status);
// identity functions ^

field_operation _finite_group_operation(int id);
// __finite_field_operation id_finite_group_operation();

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line);
void open_and_append_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line);
FILE *open_group(char **argv);
FILE *open_group_INNER(char *group_MOD, const char *numerical_denomination, const char *adjective, const char *symbol, char *LINE);
void close_group(char *group_CAP, FILE *opened_group);
void close_logbook();
