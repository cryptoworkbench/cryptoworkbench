#include "shamir_secret_sharing.h"
#include "math.extended.h"
#include <stdlib.h>
#include <stdio.h>

int k;
// global variable definitions ^

void SET_k(int length_minus_two) { k = length_minus_two; }

unsigned long *equation_ADD(unsigned long *first_equation, unsigned long *second_equation)
{ unsigned long *ret_val = (unsigned long *) malloc(sizeof(unsigned long) * (k + 2)); for (int i = 0; i < k + 2; i++) ret_val[i] = mod_add(first_equation[i], second_equation[i]); return ret_val; }

unsigned long *equation_MULTIPLY(unsigned long *equation, unsigned long multiplier)
{ unsigned long *ret_val = UL_array_of_SIZE(k + 2); for (int i = 0; i < k + 2; i++) ret_val[i] = mod_multiply(equation[i], multiplier); return ret_val; }

unsigned long *equation_NEGATIVE(unsigned long *equation)
{ unsigned long *ret_val = UL_array_of_SIZE(k + 2); for (int i = 0; i < k + 2; i++) ret_val[i] = mod_inverse(equation[i]); return ret_val; }

unsigned long *equation_SUBTRACT(unsigned long *first_equation, unsigned long *second_equation) {
    unsigned long *NEGATIVE_OF_first_equation = equation_NEGATIVE(first_equation);
    unsigned long *ret_val = equation_ADD(NEGATIVE_OF_first_equation, second_equation); free(NEGATIVE_OF_first_equation);
    return ret_val;
}

unsigned long equation_multiplier(unsigned long *first_equation, unsigned long *second_equation, int index)
{ if (first_equation[index] == second_equation[index]) return 1; return mod_divide(first_equation[index], mod_inverse(second_equation[index])); }

unsigned long *coefficient_cancel(unsigned long *first_equation, unsigned long *second_equation, int index)
{ return (first_equation[index] == second_equation[index]) ? equation_SUBTRACT(first_equation, second_equation) : equation_MULTIPLY(first_equation, mod_divide(first_equation[index], mod_inverse(second_equation[index])));}

unsigned long **equations_ALLOCATE()
{
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * k);
    for (int i = 0; i < k; i++) ret_val[i] = UL_array_of_SIZE(k + 2);
    return ret_val;
}

void equations_DELETE(unsigned long **equation)
{ for (int i = 0; i < k; i++) free(equation[i]); free(equation); }
