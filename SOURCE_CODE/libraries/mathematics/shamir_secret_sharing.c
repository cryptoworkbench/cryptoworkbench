#include "shamir_secret_sharing.h"
#include "maths.h"
#include <stdlib.h>
#include <stdio.h>

unsigned long *equation_ADD(unsigned long *first_equation, unsigned long *second_equation, int length)
{
    unsigned long *ret_val = (unsigned long *) malloc(sizeof(unsigned long) * length);
    for (int i = 0; i < length; i++) ret_val[i] = mod_add(first_equation[i], second_equation[i]);
    return ret_val;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long *equation_MULTIPLY(unsigned long *equation, unsigned long multiplier, int length)
{
    unsigned long *ret_val = UL_array_of_SIZE(length);
    for (int i = 0; i < length; i++) ret_val[i] = mod_multiply(equation[i], multiplier); return ret_val;
}

unsigned long *equation_NEGATIVE(unsigned long *equation, int length) { unsigned long *ret_val = UL_array_of_SIZE(length);
    for (int i = 0; i < length; i++) ret_val[i] = mod_inverse(equation[i]);
    return ret_val;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long *equation_SUBTRACT(unsigned long *first_equation, unsigned long *second_equation, int length) {
    unsigned long *NEGATIVE_OF_first_equation = equation_NEGATIVE(first_equation, length);
    unsigned long *ret_val = equation_ADD(NEGATIVE_OF_first_equation, second_equation, length); free(NEGATIVE_OF_first_equation);
    return ret_val;
}

unsigned long equation_multiplier(unsigned long *first_equation, unsigned long *second_equation, int index, int length)
{
    if (first_equation[index] == second_equation[index]) return 1;
    return mod_divide(first_equation[index], mod_inverse(second_equation[index]));
}

unsigned long *coefficient_cancel(unsigned long *first_equation, unsigned long *second_equation, int index, int length)
{ unsigned long *ret_val;
    if (first_equation[index] != second_equation[index]) ret_val = equation_MULTIPLY(first_equation, mod_divide(first_equation[index], mod_inverse(second_equation[index])), length);
    else ret_val = equation_SUBTRACT(first_equation, second_equation, length); return ret_val;
}

unsigned long **equations_ALLOCATE(int K) {
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * K);
    for (int i = 0; i < K; i++) ret_val[i] = UL_array_of_SIZE(K + 2);
    return ret_val;
}

void equations_DELETE(unsigned long **equation, int k) { for (int i = 0; i < k; i++) free(equation[i]); free(equation); }
