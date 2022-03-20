/* This library is full of (wrapper) functions that support functions from 'maths.c' */
#include "maths.extended.h"

unsigned int _id = 0;

int mod_ul_parse_str(char *str, int exit_status) { return _ul_parse_str(mod_, str, exit_status); }
int id_identity_parse_str(char *str, int exit_status) { return _identity_parse_str(id_, str, exit_status); }
int id_identity_parse_str_(char *str, int exit_status) { return _identity_parse_str_(id_, str, exit_status); }

void group_parse(ul_ptr mod_ptr, group_operation_ *oper, error_function_ mod_instruction, error_function_ _id_instruction, unsigned int argv_index)
{
    mod_ = mod_ptr; _group_operation = oper;
    conditional_goodbye(n(n(error_specification(mod_instruction, n(          mod_ul_parse_str((*argv_ptr)[argv_index + 0], - (argv_index + 0) ))))));
    conditional_goodbye(n(n(error_specification(_id_instruction, n(_group_operation_parse_str((*argv_ptr)[argv_index + 1], - (argv_index + 1) ))))));
}

// NEW:
int _group_operation_parse_str(char *str, int exit_status)
{
    return group_operation_parse_str(_group_operation, str, exit_status);
}

unsigned long mod_group_operation(ul a, ul b)
{
    return (*_group_operation)(a, b, *mod_);
}











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
{

 





    return _exponentiate(base, exponent, *mod_);
}

unsigned long mod_polynomial(ul x, ul *coefficient, int number_of_coefficients)
{



    return _polynomial(x, coefficient, number_of_coefficients, *mod_);
}

const char *sign_array(int SELECTOR) { return _sign_array(_group_operation, SELECTOR); }

int mod_eulers_criterion(ul odd_prime_p)
{ return _eulers_criterion(odd_prime_p, *mod_); }
/* ===================== corresponds to 'maths.basic.c' (!) ================== */
