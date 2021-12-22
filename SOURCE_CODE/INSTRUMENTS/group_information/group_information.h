#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // <<< Needed for "match()", "STR_could_be_parsed_into_UL()", etc
#include "../../libraries/functional/triple_ref_pointers.h" // << Needed for "sub_ordinate()" and "disintermediate()"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"
#define STDOUT_VERTICAL_OFFSET_ERROR "Failed to parse \"%s\" (the 4th argument) as vertical offset. Defaulting to not using a vertical offset.\n"
#define STDERR_HORIZONTAL_OFFSET_ERROR "Failed to parse \"%s\" (the 3th argument) as horizontal offset. Defaulting to not using a horizontal offset.\n"
#define STDOUT_ARGV_TWO_INSTRUCTION "Please provide as first argument the modulus of the group in decimal notation.\n"
#define STDOUT_ARGV_ONE_INSTRUCTION "Okay so the modulus is %s\n\nBut what is this group identity?, what's this group's point of symetry?\n\nIs %s supposed to be the modulus for an additive group?, or is %s supposed to be the modulus for a multiplicative group?\n\n\nTO SPECIFY ADDITIVE (MODULAR) OPERATIONS/ARITHMETIC USE:\n0\n+\naddition\nadditions\nadditive\n\nTO SPECIFY MULTIPLICATIVE (MODULAR) OPERATIONS/ARITHMATIC USE:\n1\n*\nmultiplication\nmultiplications\nmultiplicative\n\n"
#define HELP_INFORMATION "Program usage: %s <CAP> <ID> [horizontal offset] [vertical offset] [output filename]\n\n<MANDATORY ARGUMENTS> are denoted like this. The program won't run without these.\n\n[optional arguments] are denoted like this. They are not very necessary.\n"

struct offset_values { unsigned long Y; unsigned long X; };
struct triple_ref_LL { struct triple_ref_LL *next; unsigned long element; };
struct content { unsigned long literal; char *ASCII_numerical; };
struct permutation_piece { struct permutation_piece *next; struct content *unit; };
typedef struct vertibrae { struct permutation_piece *permutation; struct content unit; } array_piece;
typedef array_piece *table_type;
static char *help_queries[] = {"--help", "-h", "help", "instructions", "usage", "--instructions", "--usage", "syntax", "--syntax"};
unsigned long cardinality;
table_type LOOKUP_table;
FILE *main_fs;
struct offset_values *shifts;
_group_operation group_operation;
// ^^^ Variable (type) declaration(s)

unsigned long index_lookup(unsigned long ul);
struct permutation_piece *permutation_insert(unsigned long unit_identifier, struct permutation_piece *previous_permutation_piece);
void print_subgroup(struct permutation_piece *link);
struct triple_ref_LL **triple_ref_LL_insert(struct triple_ref_LL **tracer, unsigned long new_ulong);
struct permutation_piece *yield_subgroup(unsigned long index, group_OBJ group, struct triple_ref_LL **generator_channel);
struct triple_ref_LL *zip(struct triple_ref_LL **channel);
struct triple_ref_LL **establish_LL(char **argv, group_OBJ group, struct triple_ref_LL **element_ll_INSERT_CHANNEL);
struct triple_ref_LL *replace_LL_with_table(struct triple_ref_LL **element_ll_INSERT_CHANNEL, group_OBJ group, struct triple_ref_LL **generator_ll_INSERT_CHANNEL);
unsigned long process_generator_information(struct triple_ref_LL *generator_list, char *modulus, char *symbol);
void free_permutation_pieces(unsigned long index);
void print_table();
void HELP_AND_QUIT(char *prog_NAME);
void MOD_not_parsable_ERROR(char *argv_one);
void ID_not_parsable_ERROR(char *argv_one, char *argv_two);
int main(int argc, char **argv);
// ^^^ Function declarations
