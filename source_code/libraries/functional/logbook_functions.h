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
#define LOGBOOK_NAME "../lab_logbook" // <<< This will be the logbook filename
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name prepend

FILE *open_modular_group_UNRESTRICTED(char *program_name, unsigned long CAP, unsigned long ID, char **location_of_char_pointer_to_filename_in_allocated_memory, FILE *logbook_fs);
FILE *open_modular_group(FILE *throw_away_logbook_fs, char *program_name, unsigned long CAP, unsigned long ID);
