/* ABSTRACT
 * "open_modular_group()" returns a filestream to a file within the registry/ folder (under ~/crypto_lab/)
 *
 * It determines what file to open using the unsigned long value "CAP" (which represents the group modulus) and "ID" (which is either 0 or 1)
 *
 * It then puts the name of the file that it opened (or attempted to at least) over at "*loccation_of_char_pointer_to_filename_in_allocated_memory"
 *
 * If "logbook_fs_ptr" is a so-called "NULL" pointer, it treats the location it points to as an insertment sloth for a "FILE *".
 *
 * Worded differently, "open_modular_group()" 
 */
#define LOGBOOK_PATH "../lab_logbook" // <<< This will be the logbook filename
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name of the program printing to the logbook prepended to the line the program appends (to this logbook)

struct group_prams { // "group_prams" stands for "group parameters"
    unsigned long CAP; // <<< Cap on the infiniete field of natural numbers (N), also called the field's modulus
    unsigned long ID; // <<< The group identity
};

char *BUFFER_OF_SIZE(unsigned int SIZE);
FILE *open_logbook(); // <<< Not supposed to be called directly so might as well comment it out
int FLUSH_TO_FS(char *program_name, char *TO_BE_APPENDED_logbook_line);
FILE *open_modular_group(char *program_name, struct group_prams group, char **path_to_file_INSERTMENT_SLOTH);
