/* ############# REMINDERS:
 * ########### #1: "See if I can sort out the lines 7, 8, 11 and 12."
 */
#include "group_operations.h"
// ^^^ Required because here I need the definitions of "ADDITIVE_IDENTITY" and "MULTIPLICTIVE_IDENTITY"

unsigned long ordinator(unsigned long a, unsigned long b) { return a + b; }
unsigned long CAPPED_ordinator(unsigned long a, unsigned long b, unsigned long CAP) { return ordinator(a, b) % CAP; }
// ^^^ Keep them in this order for now (see "REMINDER #1")

unsigned long ordinated(unsigned long a, unsigned long b) { return a * b; }
unsigned long CAPPED_ordinated(unsigned long a, unsigned long b, unsigned long CAP) { return ordinated(a, b) % CAP; }
// ^^^ Keep them in this order for now (see "REMINDER #1")

function get_applicable_function_for_(unsigned long SP) { if (SP == 0) return &ordinator; else if (SP == 1) return &ordinated; }
CAPPED_function get_applicable_CAPPED_function_for_(unsigned long SP) { if (SP == 0) return &CAPPED_ordinator; else if (SP == 1) return &CAPPED_ordinated; }

unsigned long RESTRICT(function base_UNARY, unsigned long a, unsigned long b, unsigned long CAP) { return base_UNARY(a, b) % CAP; }

/* ############# OLD:
unsigned long _MODULAR_addition(unsigned long A, unsigned long B, unsigned long CAP) { return (A + B) % CAP; }
unsigned long _MODULAR_multiplication(unsigned long A, unsigned long B, unsigned long CAP) { return (A * B) % CAP; }
// ^^^ Functions for the first two modular operations of arithmetica

MODULAR_operation_PTR MODULAR_operation_BASED_ON_(unsigned long ID)
{   if (ID == ADDITIVE_IDENTITY) return &_MODULAR_addition;
    else if (ID == MULTIPLICATIVE_IDENTITY) return &_MODULAR_multiplication;
}
// ^^ This function returns the right function pointer to one of the two above functions from modular arithmetic
*/

