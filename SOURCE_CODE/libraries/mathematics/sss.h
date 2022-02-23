// try to adapt the functions from 'shamir_secret_sharing.c' so that they fit '_Polynomial' instead of '_polynomial'
void equation_DISCARD(unsigned long **equation);
unsigned long **equation_ADD(unsigned long **equation_ONE, unsigned long **equation_TWO);
unsigned long **equation_MULTIPLY(unsigned long **equation, unsigned long multiplier);
unsigned long **equation_NEGATIVE(unsigned long **equation);
unsigned long **equation_SUBTRACT(unsigned long **equation_ONE, unsigned long **equation_TWO);
unsigned long equation_multiplier(unsigned long **equation_ONE, unsigned long **equation_TWO, int index);
unsigned long **coefficient_cancel(unsigned long **equation_ONE, unsigned long **equation_TWO, int index);
unsigned long ***equations_ALLOCATE(int k_in_k_N_SSSS);
int equation_amount(unsigned long ***equation);
void equations_DELETE(unsigned long ***equations);
unsigned long **coefficients_ALLOCATE(int K);
