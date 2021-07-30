#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^ These two definitions are required by the function description of "MODULAR_operation_BASED_ON_()" in "group_operations.c"

unsigned long ordinator(unsigned long a, unsigned long b);
unsigned long CAPPED_ordinator(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the ordinating addition operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic respectively

unsigned long ordinated(unsigned long a, unsigned long b);
unsigned long CAPPED_ordinated(unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ Define the ordinated multiplication operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic, also respectively

typedef unsigned long (*function) (unsigned long, unsigned long);
typedef unsigned long (*CAPPED_function) (unsigned long, unsigned long, unsigned long);
// ^^^ Define the neccessary function pointer types in order to define the following two functions

function get_applicable_function_for_(unsigned long SP);
CAPPED_function get_applicable_CAPPED_function_for_(unsigned long SP);
// ^^^ Define two functions to get the right (in)finite field operation (addition or multiplication {right == regarding finite or infinite fields})

unsigned long RESTRICT(function base_UNARY, unsigned long a, unsigned long b, unsigned long CAP);
// ^^^ And this is the magic, see under_development/

/* ############# OLD:
unsigned long _MODULAR_multiplication(unsigned long A, unsigned long B, unsigned long CAP);
unsigned long _MODULAR_addition(unsigned long A, unsigned long B, unsigned long CAP);
// ^^^ Functions for the first two modular operations of arithmetica

typedef unsigned long (*MODULAR_operation_PTR) (unsigned long, unsigned long, unsigned long);
// ^^ Assigning an "alias"/"nickname", or rather "abbreviation" to this type of function pointer (because otherwise my compiler gets confused).

MODULAR_operation_PTR MODULAR_operation_BASED_ON_(unsigned long ID);
// ^^ This function returns the right function pointer to one of the two above functions which represent two of the most basic functions that exist in modular arithmetica
*/
