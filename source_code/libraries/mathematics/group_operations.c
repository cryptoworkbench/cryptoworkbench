#include "group_operations.h"
// ^^^ Required because here I need the definitions of "ADDITIVE_IDENTITY" and "MULTIPLICTIVE_IDENTITY"

unsigned long _MODULAR_addition(unsigned long A, unsigned long B, unsigned long CAP) { return (A + B) % CAP; }
unsigned long _MODULAR_multiplication(unsigned long A, unsigned long B, unsigned long CAP) { return (A * B) % CAP; }
// ^^^ Functions for the first two modular operations of arithmetica

MODULAR_operation_PTR MODULAR_operation_BASED_ON_(unsigned long ID)
{   if (ID == ADDITIVE_IDENTITY) return &_MODULAR_addition;
    else if (ID == MULTIPLICATIVE_IDENTITY) return &_MODULAR_multiplication; }
// ^^ This function returns the right function pointer to one of the two above functions from modular arithmetic
