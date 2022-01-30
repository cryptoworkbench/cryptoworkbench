#include "SSSS.h"
#include "maths.h"
#include <stdlib.h>
#include <stdio.h>

void equation_DISCARD(unsigned long **equation) { for (int i = 0; equation[i]; i++) free(equation[i]); free(equation); }
// ^ free()'s an equation

unsigned long **equation_ADD(unsigned long **equation_ONE, unsigned long **equation_TWO) { int LENGTH_OF_equation_ONE = UL_array_SIZE(equation_ONE); int LENGTH_OF_equation_TWO = UL_array_SIZE(equation_TWO);
    if (LENGTH_OF_equation_ONE != LENGTH_OF_equation_TWO) { fprintf(stderr, "equations had different length: %i vs %i", LENGTH_OF_equation_ONE, LENGTH_OF_equation_TWO); exit(-2); }
    unsigned long **resulting_equation = UL_array_of_SIZE(LENGTH_OF_equation_ONE);
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = mod_add(*equation_ONE[i], *equation_TWO[i]);
    return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_MULTIPLY(unsigned long **equation, unsigned long multiplier) { unsigned long **resulting_equation = UL_array_of_SIZE(UL_array_SIZE(equation));
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = mod_multiply(*equation[i], multiplier); return resulting_equation;
}

unsigned long **equation_NEGATIVE(unsigned long **equation) {
    unsigned long **resulting_equation = UL_array_of_SIZE(UL_array_SIZE(equation));
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = inverse(*equation[i]);
    return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_SUBTRACT(unsigned long **equation_ONE, unsigned long **equation_TWO) {
    unsigned long **NEGATIVE_OF_equation_ONE = equation_NEGATIVE(equation_ONE);
    unsigned long **resulting_equation = equation_ADD(NEGATIVE_OF_equation_ONE, equation_TWO); equation_DISCARD(NEGATIVE_OF_equation_ONE);
    return resulting_equation;
}

unsigned long equation_multiplier(unsigned long **equation_ONE, unsigned long **equation_TWO, int index) {
    int LENGTH_OF_equation_ONE = UL_array_SIZE(equation_ONE); if (LENGTH_OF_equation_ONE != UL_array_SIZE(equation_TWO)) exit(-1);
    if (*equation_ONE[index] == *equation_TWO[index]) return 1; return modular_division(*equation_ONE[index], inverse(*equation_TWO[index]));
}

unsigned long **coefficient_cancel(unsigned long **equation_ONE, unsigned long **equation_TWO, int index) { unsigned long **ret_val;
    int LENGTH_OF_equation_ONE = UL_array_SIZE(equation_ONE); if (LENGTH_OF_equation_ONE != UL_array_SIZE(equation_TWO)) exit(-1);
    if (*equation_ONE[index] != *equation_TWO[index]) ret_val = equation_MULTIPLY(equation_ONE, modular_division(*equation_ONE[index], inverse(*equation_TWO[index])));
    else ret_val = equation_SUBTRACT(equation_ONE, equation_TWO); return ret_val;
}

unsigned long ***equations_ALLOCATE(int K) // 'K' as in "K-n Shamir Secret Sharing"
{ unsigned long ***equation = (unsigned long ***) malloc(sizeof(unsigned long **) * (K + 1)); equation[K] = NULL; for (int i = 0; i < K; i++) equation[i] = UL_array_of_SIZE(K); return equation; }
// ^ returns an array which is does not contain a terminating character: remember array length in calling application (at least) until initialization of equations!

int equation_amount(unsigned long ***equation) {
    int i; for (i = 0; equation[i]; i++) return i;
}

void equations_DELETE(unsigned long ***equation) { for (int i = 0; equation[i]; i++) equation_DISCARD(equation[i]); free(equation); }
