#include "group_operations.h"
// ^^^ Required because here I need the definitions of "ADDITIVE_IDENTITY" and "MULTIPLICTIVE_IDENTITY"

unsigned long addition(unsigned long a, unsigned long b) { return a + b; }
unsigned long multiplication(unsigned long a, unsigned long b) { return a * b; }
// ^^^ Define respectively, the following first-degree (in)finite field combinations:
// ^^^ ~ Addition in infinite fields (regular addition without MODding the result)
// ^^^ ~ Addition in finite fields (addition with MODding the result)

unsigned long FINITE_addition(unsigned long a, unsigned long b, unsigned long CAP) { return addition(a, b) % CAP; }
unsigned long FINITE_multiplication(unsigned long a, unsigned long b, unsigned long CAP) { return multiplication(a, b) % CAP; }
// ^^^ Define respectively, the following second-degree (in)finite field combinations:
// ^^^ ~ Multiplication in infinite fields (regular multiplication without MODding the result)
// ^^^ ~ Multiplication in finite fields (multiplication with MODding the result)

INFINITE_field_combination get_INFINITE_field_combination_from_inflection_point_(unsigned long inflection_point) {
    if (inflection_point == ADDITIVE_IDENTITY) return &addition;
    else if (inflection_point == MULTIPLICATIVE_IDENTITY) return &multiplication;
}

FINITE_field_combination get_FINITE_field_combination_from_inflection_point_(unsigned long inflection_point) {
    if (inflection_point == ADDITIVE_IDENTITY) return &FINITE_addition;
    else if (inflection_point == MULTIPLICATIVE_IDENTITY) return &FINITE_multiplication;
}

unsigned long N_field_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID) {
    if (ID) return (N_quotient == ADDITIVE_IDENTITY) ? multiplication(A, B) : FINITE_multiplication(A, B, N_quotient);
    return (N_quotient == ADDITIVE_IDENTITY) ? addition(A, B) : FINITE_addition(A, B, N_quotient);
}
