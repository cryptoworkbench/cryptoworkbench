#include "group_operations.h"

unsigned long _the_unary_operator_addition_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus)
{ return (generated_element + generating_element) % group_modulus; }
// ^^ Function for the group operation of addition mod a specified CAP value

unsigned long _the_unary_operator_multiplication_under_modular_arithmatic(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus)
{ return (generated_element * generating_element) % group_modulus; }
// ^^ Function for the group operation of multiplication mod a specified CAP value

group_operation_POINTER group_operation_FROM_(unsigned long group_ID)
{   if (group_ID == ADDITIVE_IDENTITY) return &_the_unary_operator_addition_under_modular_arithmatic;
    else if (group_ID == MULTIPLICATIVE_IDENTITY) return &_the_unary_operator_multiplication_under_modular_arithmatic; }
// ^^ This function returns the right function pointer to one of the above group operation functions (based on the group ID)
