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

INFINITE_field_combination get_INFINITE_field_combination_from_SP_(unsigned long SP) {
    if (SP == ADDITIVE_IDENTITY) return &ordinator;
    else if (SP == MULTIPLICATIVE_IDENTITY) return &ordinated;
}

FINITE_field_combination get_FINITE_field_combination_from_SP_(unsigned long SP) {
    if (SP == ADDITIVE_IDENTITY) return &CAPPED_ordinator;
    else if (SP == MULTIPLICATIVE_IDENTITY) return &CAPPED_ordinated;
}

unsigned long N_field_combine(unsigned long N_quotient, unsigned long A, unsigned long B, unsigned long Symetry_Point) {
    if (N_quotient == ADDITIVE_IDENTITY) { INFINITE_field_combination Unary = get_INFINITE_field_combination_from_SP_(Symetry_Point); return Unary(A, B); }
    else if (N_quotient == MULTIPLICATIVE_IDENTITY) return ADDITIVE_IDENTITY;
    else { FINITE_field_combination Unary = get_FINITE_field_combination_from_SP_(Symetry_Point); return Unary(A, B, N_quotient); }
} // ##### N_quotent signifies how into how many sections (quotient groups) the field N is divided into:
// | ### Supply a positive value to put a CAP to the infinite field
// | 
// | ### The statement "do not divide it" must necessarily be a literally equivalent of saying "divide it by zero" ===
// | ### # ==> To say "divide by zero" is to say "do not divide at all"
// |
// | ### For all number elements in the infinite field N it is true that mod 1 its 0
