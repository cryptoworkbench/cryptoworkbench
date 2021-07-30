#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
// ^^ These two definitions are required by the function description of "group_operation_FROM_()" in "group_operations.c"

typedef unsigned long (*group_operation_POINTER) (unsigned long, unsigned long, unsigned long);
// ^^ Assigning an "alias"/"nickname", or rather "abbreviation" to this type of function pointer (because otherwise my compiler gets confused).

unsigned long _the_unary_operator_addition_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus);
// ^^ Group operation for addition under modular arithmetic

unsigned long _the_unary_operator_multiplication_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus);
// ^^ Group operation for multiplication under modular arithmetic

group_operation_POINTER group_operation_FROM_(unsigned long group_ID);
// ^^ This function returns the right function pointer to one of the above group operation functions (based on the group ID)
