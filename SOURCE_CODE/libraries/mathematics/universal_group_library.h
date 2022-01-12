#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // <<< Needed for "execvp()"
#include <sys/wait.h> // <<< Needed for "waitpid()"
#include "maths.h"
#include "../functional/string.h"

#define ELEMENT_EXPORTER "modular_group_element_table_generator"
#define FILENAME_BODY "_group_of_integers_modulus_"
#define LOGBOOK_PATH ".LOGBOOK" // << This will be the logbook filename in "WORKBENCH/"
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group."
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process."

static char *argv_ZERO;
static FILE *logbook_fs;
static char *path_to_FILE;
// ^^ Variable definitions

static const char *additive_signs[] = {"0", "+", "addition", "additions", "additive"};
static const char *multiplicative_signs[] = {"1", "*", "multiplication", "multiplications", "multiplicative"};
// ^^ Even though the internet adviced against it, I like to have these in "universal_group_library.h"

unsigned long *STR_could_be_parsed_into_id(char *STR, unsigned long *ID);
/* ^^ Returns "NULL" upon parsing failure, otherwise parses "0" or "1" into their respective ENUM equivalents (a.k.a. representations) within this struct that is abbreviated "group_OBJ" */

char *BUFFER_OF_SIZE(unsigned int SIZE);
const char *ID_denoted_numerically(UL ID);
const char *ID_denoted_by_operation_symbol(UL ID);
const char *ID_proNOUNced(UL ID);
const char *ID_proNOUNSed(UL ID);
const char *operation_ADJECTIVE_from_ID(UL ID);

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line);
void open_and_append_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line);
FILE *open_group(char *prog_NAME, char *MOD, unsigned long ID);
FILE *open_group_INNER(char *group_MOD, const char *numerical_denomination, const char *adjective, const char *symbol, char *LINE);
void close_group(char *group_CAP, const char *symbol_to_use, FILE *opened_group);
void close_logbook();
