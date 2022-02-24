void SET_k(int k);
unsigned long *equation_ADD(unsigned long *first_equation, unsigned long *second_equation);
unsigned long *equation_MULTIPLY(unsigned long *equation, unsigned long multiplier);
unsigned long *equation_NEGATIVE(unsigned long *equation);
unsigned long *equation_SUBTRACT(unsigned long *first_equation, unsigned long *second_equation);
unsigned long equation_multiplier(unsigned long *first_equation, unsigned long *second_equation, int index);
unsigned long *coefficient_cancel(unsigned long *first_equation, unsigned long *second_equation, int index);

unsigned long **equations_ALLOCATE();
void equations_DELETE(unsigned long **equations);
// I need to keep these two because they are nice in the error functions ^^
