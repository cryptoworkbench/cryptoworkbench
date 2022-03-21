/* This library is full of (wrapper) functions that support functions from 'maths.c' */
#include "maths.extended.h"

int mod_ul_parse_str(char *str, int exit_status) { return _ul_parse_str(_mod, str, exit_status); }

/* 
group_operation_ *mod_group_parse(struct group *group_ptr, error_function_ mod_instruction, error_function_ _id_instruction, unsigned int argv_index)
{ return group_parse(group_ptr, mod_instruction, _id_instruction, argv_index); }
*/

int _group_operation_parse_str(char *str, int exit_status)
{ return group_operation_parse_str(_group_operation, str, exit_status); }

unsigned long mod_group_operation(ul a, ul b)
{ return (*_group_operation)(a, b, *_mod); }











/* ===================== corresponds to 'maths.basic.c' (!) ================== */
unsigned long mod_conditional_cap(ul result)
{ return (*_mod) ? _conditional_cap(result, *_mod) : result; }

unsigned long mod_add(ul a, ul b)
{ return _add(a, b, *_mod); }

unsigned long mod_inverse(ul element_of_additive_group)
{ return _inverse(element_of_additive_group, *_mod); }

unsigned long mod_subtract(ul a, ul b)
{ return _subtract(a, b, *_mod); }

unsigned long mod_multiply(ul a, ul b)
{ return mod_conditional_cap(a * b); } 

unsigned long mod_divide(ul numerator, ul denominator)
{ return _divide(numerator, denominator, *_mod); }

unsigned long mod_exponentiate(ul base, ul exponent)
{

 





    return _exponentiate(base, exponent, *_mod);
}

unsigned long mod_polynomial(ul x, ul *coefficient, int number_of_coefficients)
{



    return _polynomial(x, coefficient, number_of_coefficients, *_mod);
}

int mod_eulers_criterion(ul odd_prime_p)
{ return _eulers_criterion(odd_prime_p, *_mod); }

void _group_parse(struct group *group_ptr, error_function_ mod_instruction, error_function_ _id_instruction, int argv_index) {
    _mod = &group_ptr->mod; _group_operation = &group_ptr->oper;
    group_parse(group_ptr, mod_instruction, _id_instruction, argv_index);
}
/* ===================== corresponds to 'maths.basic.c' (!) ================== */
