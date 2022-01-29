#include "SSSS.h"
#include "maths.h"
#include <stdlib.h>
#include <stdio.h>

void equation_DISCARD(unsigned long **equation) { for (int i = 0; equation[i]; i++) free(equation[i]); free(equation); }
// ^ free()'s an equation

int equation_length(unsigned long **equation) { int equation_length = 0; while (equation[equation_length]) equation_length++; return equation_length; }
// ^ returns the length of an equation array based on the position of it's ZERO terminating character

unsigned long **equation_initialize(int required_size) {
    unsigned long **ret_val = (unsigned long **) malloc(sizeof(unsigned long *) * (required_size + 1)); ret_val[required_size] = NULL;
    for (int i = 0; i < required_size; i++) ret_val[i] = (unsigned long *) malloc(sizeof(unsigned long)); return ret_val;
}

unsigned long **equation_ADD(unsigned long **equation_ONE, unsigned long **equation_TWO) { int LENGTH_OF_equation_ONE = equation_length(equation_ONE); int LENGTH_OF_equation_TWO = equation_length(equation_TWO);
    if (LENGTH_OF_equation_ONE != LENGTH_OF_equation_TWO) { fprintf(stderr, "equations had different length: %i vs %i", LENGTH_OF_equation_ONE, LENGTH_OF_equation_TWO); exit(-2); }
    unsigned long **resulting_equation = equation_initialize(LENGTH_OF_equation_ONE);
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = add(*equation_ONE[i], *equation_TWO[i]);
    return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_MULTIPLY(unsigned long **equation, unsigned long multiplier) { unsigned long **resulting_equation = equation_initialize(equation_length(equation));
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = multiply(*equation[i], multiplier); return resulting_equation;
}

unsigned long **equation_NEGATIVE(unsigned long **equation) {
    unsigned long **resulting_equation = equation_initialize(equation_length(equation));
    for (int i = 0; resulting_equation[i]; i++) *resulting_equation[i] = inverse(*equation[i]);
    return resulting_equation;
} // ^ dep of 'equation_SUBTRACT()'

unsigned long **equation_SUBTRACT(unsigned long **equation_ONE, unsigned long **equation_TWO) {
    unsigned long **NEGATIVE_OF_equation_ONE = equation_NEGATIVE(equation_ONE);
    unsigned long **resulting_equation = equation_ADD(NEGATIVE_OF_equation_ONE, equation_TWO); equation_DISCARD(NEGATIVE_OF_equation_ONE);
    return resulting_equation;
}

void equation_DISPLAY(unsigned long **equation) { int LENGTH_OF_equation = equation_length(equation); 
    char ch = 'a'; int i = LENGTH_OF_equation; printf("%lu = ", *equation[0]);
    do { i--;
	printf("%c%lu", ch, *equation[i]); 
	if (i == 1) break; printf(" + "); ch++;
    } while (1); printf("\n");
}

unsigned long equation_multiplier(unsigned long **equation_ONE, unsigned long **equation_TWO, int index) {
    int LENGTH_OF_equation_ONE = equation_length(equation_ONE); if (LENGTH_OF_equation_ONE != equation_length(equation_TWO)) exit(-1);
    if (*equation_ONE[index] == *equation_TWO[index]) return 1; return modular_division(*equation_ONE[index], inverse(*equation_TWO[index]));
}

unsigned long **coefficient_cancel(unsigned long **equation_ONE, unsigned long **equation_TWO, int index) { unsigned long **ret_val;
    int LENGTH_OF_equation_ONE = equation_length(equation_ONE); if (LENGTH_OF_equation_ONE != equation_length(equation_TWO)) exit(-1);
    if (*equation_ONE[index] != *equation_TWO[index]) ret_val = equation_MULTIPLY(equation_ONE, modular_division(*equation_ONE[index], inverse(*equation_TWO[index])));
    else ret_val = equation_ADD(equation_ONE, equation_NEGATIVE(equation_TWO)); return ret_val;
}

unsigned long ***equations_ALLOCATE(int K) // 'K' as in "K-n Shamir Secret Sharing"
{ unsigned long ***equations = (unsigned long ***) malloc(sizeof(unsigned long **) * K); for (int i = 0; i < K; i++) equations[i] = equation_initialize(K); return equations; }
// ^ returns an array which is does not contain a terminating character: remember array length in calling application
