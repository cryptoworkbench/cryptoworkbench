/* This library is full of (wrapper) functions that support functions from 'maths.c' */
#include "maths.extended.h"

int mod_ul_parse_str(char *str, int exit_status) { return _ul_parse_str(mod_, str, exit_status); }
int id_identity_parse_str(char *str, int exit_status) { return _identity_parse_str(id_, str, exit_status); }












group_operation _group_operation(unsigned int id_) { return (id_) ? mod_multiply : mod_add; }
group_operation id_group_operation() { return _group_operation(*id_); }
// to get the appriopiate group operation ^

/* ===================== corresponds to 'maths.basic.c' (!) ================== */
unsigned long mod_conditional_cap(ul result)
{ return (*mod_) ? _conditional_cap(result, *mod_) : result; }

unsigned long mod_add(ul a, ul b)
{ return _add(a, b, *mod_); }

unsigned long mod_inverse(ul element_of_additive_group)
{ return _inverse(element_of_additive_group, *mod_); }

unsigned long mod_subtract(ul a, ul b)
{ return _subtract(a, b, *mod_); }

unsigned long mod_multiply(ul a, ul b)
{ return mod_conditional_cap(a * b); } 

unsigned long mod_divide(ul numerator, ul denominator)
{ return _divide(numerator, denominator, *mod_); }

unsigned long mod_exponentiate(ul base, ul exponent)
{ return _exponentiate(base, exponent, *mod_); }

unsigned long mod_polynomial(ul x, ul *coefficient, int number_of_coefficients)
{ return _polynomial(x, coefficient, number_of_coefficients, *mod_); }
/* ===================== corresponds to 'maths.basic.c' (!) ================== */

const char *id_as_number() { return _as_number(*id_); }
const char *id_as_operation_symbol() { return _as_operation_symbol(*id_); }
const char *id_as_noun() { return _as_noun(*id_); }
const char *id_as_nouns() { return _as_nouns(*id_); }
const char *id_as_adjective() { return _as_adjective(*id_); }
const char *id_as_verb() { return _as_verb(*id_); }
// get the identity represented by corresponding number, operation symbol, singular noun, plural noun, adjective, or verb

int mod_eulers_criterion(ul odd_prime_p) { return _eulers_criterion(odd_prime_p, *mod_); }
