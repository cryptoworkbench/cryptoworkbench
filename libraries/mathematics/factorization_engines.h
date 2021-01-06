#include "maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

struct number_pair {
    unsigned long number_one;
    unsigned long number_two;
};

struct number_pair classic_shor(unsigned long composite_number);
unsigned long find_period(unsigned long a, unsigned long modulus);
unsigned long find_a(unsigned long previous_a, unsigned long composite);
/* ### ^^^^^ Switched around in order so they can be in any order in classic_shor.c ^^^^^ ### */

struct number_pair fermat_factorize(unsigned long odd_composite);
struct number_pair _fermat_factorize(struct number_pair *pair_one, struct number_pair *pair_two);
void inflate(struct number_pair *square_pair);
struct number_pair *construct_square(unsigned long root, unsigned long square);
