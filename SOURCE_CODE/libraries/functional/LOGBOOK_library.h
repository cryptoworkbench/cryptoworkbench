/* ABSTRACT
 * "open_modular_group()" returns a filestream to a file within the registry/ folder (under ~/crypto_lab/)
 *
 * It determines what file to open using the unsigned long value "CAP" (which represents the group modulus) and "ID" (which is either 0 or 1)
 *
 * It then puts the name of the file that it opened (or attempted to at least) over at "*loccation_of_char_pointer_to_filename_in_allocated_memory"
 *
 * If "logbook_fs_ptr" is a so-called "NULL" pointer, it treats the location it points to as an insertment sloth for a "FILE *".
 *
 * Worded differently
 */
#include <stdio.h> // <<<< Needed for "fprintf()"
#include <stdlib.h> // <<< Needed for "malloc()"
#include <unistd.h> // <<< Needed for "execvp()"
#include <sys/wait.h> // <<< Needed for "waitpid()"
#include "string.h" // <<< Needed for "str_len()"
#define LOGBOOK_PATH ".LOGBOOK" // <<< This will be the logbook filename
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)
#define ARCHIVE_FOLDER "ARCHIVE/"

struct group_prams { // "group_prams" stands for "group parameters"
    unsigned long CAP; // <<< Cap on the infiniete field of natural numbers (N), also called the field's modulus
    unsigned long ID; // <<< The group identity
};

static FILE *logbook_fs;
static char *argv_ZERO;
// ^^^ Declare global file stream pointer for the logbook

char *adjective_to_use(unsigned long ID);
char *symbol_to_use(unsigned long ID);
char *BUFFER_OF_SIZE(unsigned int SIZE);
void flush_to_LOGBOOK(char *prog_NAME, char *TO_BE_APPENDED_logbook_line);
void append(char *TO_BE_APPENDED_logbook_line);

FILE *open_group_INNER(char **path_to_filename_INSERTMENT_SLOTH, char *group_CAP, char *group_ID, char *adjective, char *symbol, char *LINE); // << Not supposed to be called directly
FILE *open_group(char *prog_NAME, struct group_prams *group, char **path_to_filename_INSERTMENT_SLOTH, char **group_CAP_INSERTMENT_SLOTH);
// ^^^ Basically, the last one is the function this library is all about

void close_group(char *prog_NAME, char *group_CAP, char *symbol_to_use, char *path_to_filename, FILE *opened_group);
