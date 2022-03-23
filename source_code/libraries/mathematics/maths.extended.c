/* This library is full of (wrapper) functions that support functions from 'maths.c' */
#include "maths.extended.h"

int mod_ul_parse_str(char *str, int exit_status) { return _ul_parse_str(mod_, str, exit_status); }












/* ================ these wrapper functions insert the modulus value pointed at by 'mod_' ================ */
unsigned long mod_group_operation(ul a, ul b) { return (*_group_operation)(a, b, *mod_); }
unsigned long mod_conditional_cap(ul result) { return (*mod_) ? _conditional_cap(result, *mod_) : result; }
unsigned long mod_add(ul a, ul b) { return _add(a, b, *mod_); }
unsigned long mod_inverse(ul element_of_additive_group) { return _inverse(element_of_additive_group, *mod_); }
unsigned long mod_subtract(ul a, ul b) { return _subtract(a, b, *mod_); }
unsigned long mod_multiply(ul a, ul b) { return mod_conditional_cap(a * b); } 
unsigned long mod_divide(ul numerator, ul denominator) { return _divide(numerator, denominator, *mod_); }
unsigned long mod_exponentiate(ul base, ul exponent) { return _exponentiate(base, exponent, *mod_); }
unsigned long mod_polynomial(ul x, ul *coefficient, int number_of_coefficients) { return _polynomial(x, coefficient, number_of_coefficients, *mod_); }

int mod_eulers_criterion(ul odd_prime_p)
{ return _eulers_criterion(odd_prime_p, *mod_); }
/* ======= ^ = ^ == these wrapper functions insert the modulus value pointed at by 'mod_' == ^ = ^ ======= */
