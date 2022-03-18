/* This library is full of (wrapper) functions that support functions from 'maths.c' */
#include "math_extended.h"

unsigned long mod_conditional_cap(unsigned long result) { return (*mod_) ? _conditional_cap(result, *mod_) : result; }
unsigned long mod_add(unsigned long a, unsigned long b) { return _add(a, b, *mod_); }
unsigned long mod_inverse(unsigned long element_of_additive_group) { return _inverse(element_of_additive_group, *mod_); }
unsigned long mod_subtract(unsigned long a, unsigned long b) { return _subtract(a, b, *mod_); }
unsigned long mod_multiply(unsigned long a, unsigned long b) { return mod_conditional_cap(a * b); } 
unsigned long mod_divide(unsigned long numerator, unsigned long denominator) { return _divide(numerator, denominator, *mod_); }
unsigned long mod_exponentiate(unsigned long base, unsigned long exponent) { return _exponentiate(base, exponent, *mod_); }
unsigned long mod_polynomial(unsigned long x, unsigned long *coefficient, int number_of_coefficients) { return _polynomial(x, coefficient, number_of_coefficients, *mod_); }
// same basic (in)finite field functions as in the math.basic library ^^

const char *id_as_number() { return _as_number(*id_); }
const char *id_as_operation_symbol() { return _as_operation_symbol(*id_); }
const char *id_as_noun() { return _as_noun(*id_); }
const char *id_as_nouns() { return _as_nouns(*id_); }
const char *id_as_adjective() { return _as_adjective(*id_); }
const char *id_as_verb() { return _as_verb(*id_); }
// get the identity represented by corresponding number, operation symbol, singular noun, plural noun, adjective, or verb

group_operation ___group_operation(unsigned int id_) { return (id_) ? mod_multiply : mod_add; }
group_operation id_group_operation() { return ___group_operation(*id_); }
// to get the appriopiate group operation ^

int mod_eulers_criterion(unsigned long odd_prime_p) { return _eulers_criterion(odd_prime_p, *mod_); }

unsigned long multiplicative_inverse(unsigned long a) { unsigned long x, y; extended_gcd(a, *mod_, &x, &y); return mod_conditional_cap(*mod_ + x); }
