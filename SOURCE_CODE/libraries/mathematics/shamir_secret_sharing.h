// try to adapt the functions from 'shamir_secret_sharing.c' so that they fit '_Polynomial' instead of '_polynomial'
void equation_DISCARD(unsigned long **equation);
unsigned long *equation_ADD(unsigned long *first_equation, unsigned long *second_equation, int length);
unsigned long *equation_MULTIPLY(unsigned long *equation, unsigned long multiplier, int length);
unsigned long *equation_NEGATIVE(unsigned long *equation, int length);
unsigned long *equation_SUBTRACT(unsigned long *first_equation, unsigned long *second_equation, int length);
unsigned long equation_multiplier(unsigned long *first_equation, unsigned long *second_equation, int index, int length);
unsigned long *coefficient_cancel(unsigned long *first_equation, unsigned long *second_equation, int index, int length);
unsigned long **equations_ALLOCATE(int K);
int equation_amount(unsigned long ***equation);
void equations_DELETE(unsigned long **equations, int amount);
unsigned long **coefficients_ALLOCATE(int K);
