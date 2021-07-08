#define LOGBOOK_NAME "../lab_logbook" // <<< This will be the logbook filename
#define LOGBOOK_FORMULA "%s: "// <<< This will be the name prepend

FILE *open_logbook();
FILE *open_modular_group(FILE *logbook_fs, char *program_name, unsigned long modulus, unsigned long identity, char **location_of_char_pointer_to_filename_in_allocated_memory);
