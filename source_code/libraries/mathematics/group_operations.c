#include "group_operations.h"
// ^^^ Required because here I need the definitions of "ADDITIVE_IDENTITY" and "MULTIPLICTIVE_IDENTITY"

unsigned long ordinator(unsigned long a, unsigned long b) { return a + b; }
unsigned long ordinated(unsigned long a, unsigned long b) { return a * b; }
// ^^^ Define respectively, the following first-degree (in)finite field combinations:
// ^^^ ~ Addition in infinite fields (regular addition without MODding the result)
// ^^^ ~ Addition in finite fields (addition with MODding the result)

unsigned long CAPPED_ordinator(unsigned long a, unsigned long b, unsigned long CAP) { return ordinator(a, b) % CAP; }
unsigned long CAPPED_ordinated(unsigned long a, unsigned long b, unsigned long CAP) { return ordinated(a, b) % CAP; }
// ^^^ Define respectively, the following second-degree (in)finite field combinations:
// ^^^ ~ Multiplication in infinite fields (regular multiplication without MODding the result)
// ^^^ ~ Multiplication in finite fields (multiplication with MODding the result)

INFINITE_field_combination get_INFINITE_field_combination_from_inflection_point_(unsigned long SP) {
    if (SP == ADDITIVE_IDENTITY) return &ordinator;
    else if (SP == MULTIPLICATIVE_IDENTITY) return &ordinated;
}

FINITE_field_combination get_FINITE_field_combination_from_inflection_point_(unsigned long SP) {
    if (SP == ADDITIVE_IDENTITY) return &CAPPED_ordinator;
    else if (SP == MULTIPLICATIVE_IDENTITY) return &CAPPED_ordinated;
}

unsigned long N_field_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long ID) {
    if (ID) return (N_quotient == ADDITIVE_IDENTITY) ? ordinated(A, B) : CAPPED_ordinated(A, B, N_quotient);
    return (N_quotient == ADDITIVE_IDENTITY) ? ordinator(A, B) : CAPPED_ordinator(A, B, N_quotient);
}
