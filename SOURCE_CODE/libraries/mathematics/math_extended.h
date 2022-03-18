#include "math_basic.h"
// get all the function headers '_maths.c' needs ^

unsigned long *mod_; int *id_;
// variable declarations ^^














unsigned long mod_exponentiate(unsigned long base, unsigned long exponent);
unsigned long mod_conditional_cap(unsigned long result);
unsigned long mod_inverse(unsigned long element_of_additive_group);
unsigned long mod_add(unsigned long a, unsigned long b);
unsigned long mod_subtract(unsigned long a, unsigned long b);
unsigned long mod_multiply(unsigned long a, unsigned long b);
unsigned long mod_divide(unsigned long numerator, unsigned long denominator);
unsigned long mod_polynomial(unsigned long x, unsigned long *coefficient, int coefficients);
// basic (in)finite field operations ^

const char *id_as_number();
const char *id_as_operation_symbol();
const char *id_as_noun();
const char *id_as_nouns();
const char *id_as_adjective();
const char *id_as_verb();
// functions that have to do with the identity element ^

int mod_eulers_criterion(unsigned long odd_prime_p);

group_operation ___group_operation(unsigned int id_);
group_operation id_group_operation();
