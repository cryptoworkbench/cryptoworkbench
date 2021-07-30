#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^ These two definitions are required by the function description of "MODULAR_operation_BASED_ON_()" in "group_operations.c"

unsigned long _MODULAR_multiplication(unsigned long A, unsigned long B, unsigned long CAP);
unsigned long _MODULAR_addition(unsigned long A, unsigned long B, unsigned long CAP);
// ^^^ Functions for the first two modular operations of arithmetica

typedef unsigned long (*MODULAR_operation_PTR) (unsigned long, unsigned long, unsigned long);
// ^^ Assigning an "alias"/"nickname", or rather "abbreviation" to this type of function pointer (because otherwise my compiler gets confused).

MODULAR_operation_PTR MODULAR_operation_BASED_ON_(unsigned long ID);
// ^^ This function returns the right function pointer to one of the two above functions which represent two of the most basic functions that exist in modular arithmetica
