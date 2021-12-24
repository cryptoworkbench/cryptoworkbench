#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // <<< Needed for "match()", "STR_could_be_parsed_into_UL()", etc
#include "../../libraries/functional/triple_ref_pointers.h" // << Needed for "zoom_out()", "initialize_PTR_pair()", and "zoom_in()"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"
#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDOUT_ARGV_ONE_INSTRUCTION "Okay so the modulus is %s\n\nBut what is this group identity?, what's this group's point of symetry?\n\nIs %s supposed to be the modulus for an additive group?, or is %s supposed to be the modulus for a multiplicative group?\n\n\nTO SPECIFY ADDITIVE (MODULAR) OPERATIONS/ARITHMETIC USE:\n0\n+\naddition\nadditions\nadditive\n\nTO SPECIFY MULTIPLICATIVE (MODULAR) OPERATIONS/ARITHMATIC USE:\n1\n*\nmultiplication\nmultiplications\nmultiplicative\n\n"
#define HELP_INFORMATION "Program usage: %s <CAP> <ID> [horizontal offset] [vertical offset] [output filename]\n\n<MANDATORY ARGUMENTS> are denoted like this. The program won't run without these.\n\n[optional arguments] are denoted like this. They are not very necessary.\n"

struct offset_values { unsigned long Y; unsigned long X; };

struct _general_LL { struct _general_LL *next; unsigned long element; };
typedef struct vertibrae {
    struct _general_LL *permutation;
    unsigned long ulong;
    char *ASCII;
} array_piece;
typedef array_piece *table_type;
// ^^ Declare variable types

unsigned long cardinality;
table_type LOOKUP_table;
FILE *main_fs;
struct offset_values *shifts;
_group_operation group_operation;
// ^^ Declare variables

const char *help_queries[] = {"--help", "-h", "help", "instructions", "usage", "--instructions", "--usage", "syntax", "--syntax"};
// ^^ I think that it is alrigh to put a variable initialization like this in this header file

unsigned long index_lookup(unsigned long ul);
struct _general_LL *circular_LL_from_CHAN(struct _CHANNEL_PTR_pair CHANNEL_PTR_pair);

void print_subgroup(unsigned long index);
void _general_LL_insert(struct _general_LL ***tracer, unsigned long new_ulong);
struct _general_LL *yield_subgroup(unsigned long index, struct _general_LL ***generator_CHANNEL, group_OBJ group);
struct _CHANNEL_PTR_pair element_LL_from_file(char **argv, group_OBJ group);

struct _general_LL *second_MAIN(struct _CHANNEL_PTR_pair, group_OBJ group);
// ^^ Takes the "struct _CHANNEL_PTR_pair" containing the triple ref linked list pointers created by "circular_LL_from_CHAN()"

unsigned long process_generator_information(struct _general_LL *generator_list, char *modulus, const char *symbol);
void free_permutation_pieces(unsigned long index);
void HELP_AND_QUIT(char *prog_NAME);
void MOD_not_parsable_ERROR(char *argv_one);
void ID_not_parsable_ERROR(char *argv_one, char *argv_two);
int main(int argc, char **argv);
// ^^^ Function declarations