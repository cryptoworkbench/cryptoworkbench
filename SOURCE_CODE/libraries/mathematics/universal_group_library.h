#include <stdlib.h>
#include <unistd.h> // <<< Needed for "execvp()"
#include <sys/wait.h> // <<< Needed for "waitpid()"
#include "../functional/string.h"

#define ELEMENT_EXPORTER "modular_group_element_table_generator"
#define FILENAME_BODY "_group_of_integers_modulus_"
#define LOGBOOK_PATH ".LOGBOOK" // << This will be the logbook filename in "WORKBENCH/"
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"
#define FORK_ERROR "Failed to split up myself into two daughter processes so that I could dedicate one part of my being to securing the group."
#define FILE_DESCRIPTOR_ERROR "Failed to rewrite the file descriptor of child process."

static char *additive_signs[] = {"0", "+", "addition", "additions", "additive"};
static char *multiplicative_signs[] = {"1", "*", "multiplication", "multiplications", "multiplicative"};

enum GROUP_IDentity { ADDITIVE, MULTIPLICATIVE };
typedef struct group_STRUCT { /* <<< This lib's version of "group_prams" */
    enum GROUP_IDentity ID;
    unsigned long MOD;
} group; typedef group *group_OBJ;

static char *argv_ZERO;
static FILE *logbook_fs;
/* ^^^ VARIABLE DEFINITIONS ^^^ */


enum GROUP_IDentity *STR_could_be_parsed_into_group_OBJ_ID_Sloth(char *STR, group_OBJ group);
/* ^^ Returns "NULL" upon parsing failure, otherwise parses "0" or "1" into their respective ENUM equivalents (a.k.a. representations) within this struct that is abbreviated "group_OBJ" */

char *numerical_denomination_from_ID_Sloth(group_OBJ group);
char *operation_symbol_from_ID_Sloth(group_OBJ group);
char *noun_from_ID_Sloth(group_OBJ group);
char *multiple_from_ID_Sloth(group_OBJ group);
char *adjective_from_ID_Sloth(group_OBJ group);
int boolean_from_ID_Sloth(group_OBJ group);

void append_to_LOGBOOK(char *TO_BE_APPENDED_logbook_line);
FILE *open_group(char *prog_NAME, group_OBJ group, char *MOD, char **path_to_filename_INSERTMENT_SLOTH);
FILE *open_group_INNER(char **path_to_filename_INSERTMENT_SLOTH, char *group_MOD, char *numerical_denomination, char *adjective, char *symbol, char *LINE);
void close_group(char *group_CAP, char *symbol_to_use, char *path_to_filename, FILE *opened_group);
unsigned long N_combine_ABSTR(unsigned long N_quotient, unsigned long A, unsigned long B, enum GROUP_IDentity Operation);
