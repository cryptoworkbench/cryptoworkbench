#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define SET_DEVOID_OF_UNITS 0
#define SET_DEVOID_OF_PRIME_FACTORS 1
typedef unsigned long ul; extern ul MOD;
struct ordered_pair { unsigned long a; unsigned long b; };

typedef ul* UL_ptr;

unsigned long conditional_field_cap(unsigned long result);
unsigned long add(unsigned long a, unsigned long b);
unsigned long subtract(unsigned long a, unsigned long b);
unsigned long inverse(unsigned long element_of_additive_group); // yields the additive inverse of ul 'element_of_additive_group'
unsigned long multiply(unsigned long a, unsigned long b);

typedef unsigned long (*_group_operation) (unsigned long, unsigned long);
typedef struct ordered_pair (*_factorization_method) (unsigned long);
_group_operation operation_from_ID(unsigned long ID);

unsigned long exponentiation(unsigned long base, unsigned long exponent);
unsigned long exponentiate_UNRESTRICTEDLY(unsigned long base, unsigned long exponent); // << normal finite field exponentiation depends upon this ):
unsigned long N_operation(unsigned long a, unsigned long b, unsigned long ID);
// ^^^ Combine them all

/* ### OLD FUNCTIONS: */
unsigned long GCD(unsigned long a, unsigned long b);
unsigned long totient(unsigned long a);
// ^^^ Calculates the GCD using a procedural implementation of the euclidean algorithm: ^^ Order of inputs does not matter.

unsigned long extended_gcd(unsigned long a, unsigned long b, unsigned long *x, unsigned long *y);
unsigned long multiplicative_inverse(unsigned long a);

/* A simple exponentiation function which raises base to exponent.
 * 
 * Date type inputs are both unsigned, so we only need to watch these two potential exceptions:
 * Base is equal to the additive identity (0), in this case the resulting number from the exponentiation is always 0, because 0 multiplied by itself any amount of times will equal 0.
 * Base is equal to the multiplicative identity (1), in this case the resulting number from the exponentiation is always 1, because 1 multiplied by itself any amount of times will equal 1.
 *
 * Both I have been cognizant of in the design of this exponentiation function.
 *
 * Ps.
 * Returns the multiplicative identity when the exponent is 0.*/

/* Two functions for modular exponentiation */
unsigned long least_base_TWO_log(unsigned long power_of_TWO);
unsigned long modular_division(unsigned long member_from_equivalence_class_representing_the_numerator, unsigned long denominator);
unsigned long SINGULAR_polynomial_over_GF(unsigned long **coefficient, unsigned long _x); // < array of coefficient pointers needs to be in reversed order to how polynomials are usually written in standard form
unsigned long polynomial_over_GF(unsigned long x, int number_of_coefficients, ...);
unsigned long least_common_multiple(unsigned long a, unsigned long b);

unsigned long DOWN_ROUNDED_second_root(unsigned long number);

struct ordered_pair trail_division(unsigned long composite, unsigned long trail_limit);
struct ordered_pair inefficient_trail_division(unsigned long any_composite);
struct ordered_pair more_efficient_trail_division(unsigned long any_composite);
struct ordered_pair most_efficient_trail_division(unsigned long any_composite);

void update(struct ordered_pair *updated, unsigned long least);
struct ordered_pair fermats_factorization_approach_ENGINE(unsigned long odd_composite); struct ordered_pair fermats_factorization_approach(unsigned long composite);
// ^ Three functions for fermat factorization

// BECAUSE FERMAT's FACTORIZATION METHOD CANNOT HANDLE EVEN NUMBERS
struct ordered_pair pair_reorder(struct ordered_pair *pair);
struct ordered_pair factorization_method_WRAPPER(_factorization_method factorization_method_that_cannot_handle_even_numbers, unsigned long COMPOSITE);
