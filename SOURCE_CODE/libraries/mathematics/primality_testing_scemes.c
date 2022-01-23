#include "primality_testing_scemes.h"
#include "maths.h" // needed for 'ADDITIVE_IDENTITY', 'MULTIPLICATIVE_IDENTITY'
#include "factorization_methods.h" // needed for the definition of function pointer type _factorization_method

_factorization_method prefered_factorization_ENGINE;

int composite(unsigned long potential_composite) { return (potential_composite - prefered_factorization_ENGINE(potential_composite)) ? MULTIPLICATIVE_IDENTITY : ADDITIVE_IDENTITY; }
int prime(unsigned long potential_prime) { return (potential_prime - prefered_factorization_ENGINE(potential_prime)) ? ADDITIVE_IDENTITY : MULTIPLICATIVE_IDENTITY; }
