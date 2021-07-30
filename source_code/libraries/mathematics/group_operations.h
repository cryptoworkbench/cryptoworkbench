#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^ These two definitions are required by the function description of "MODULAR_operation_BASED_ON_()" in "group_operations.c"

unsigned long ordinator(unsigned long a, unsigned long b);
unsigned long CAPPED_ordinator(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the ordinating addition operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic respectively

unsigned long ordinated(unsigned long a, unsigned long b);
unsigned long CAPPED_ordinated(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the ordinated multiplication operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic, also respectively

typedef unsigned long (*field_combination) (unsigned long, unsigned long);
typedef unsigned long (*CAPPED_field_combination) (unsigned long, unsigned long, unsigned long);
// ^^^ Define the neccessary function pointer types in order to define the following two functions

field_combination get_field_combination_from_SP_(unsigned long SP);
CAPPED_field_combination get_CAPPED_field_combination_from_SP_(unsigned long SP);
// ^^^ Define two functions to get the right (in)finite field operation (addition or multiplication {right == regarding finite or infinite fields})

unsigned long RESTRICT(field_combination base_UNARY, unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ And this is the magic, see under_development/
