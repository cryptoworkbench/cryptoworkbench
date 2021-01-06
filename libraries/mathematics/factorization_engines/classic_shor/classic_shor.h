// #include "../struct_number_pair_declaration.h"
#include "../../maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

struct number_pair classic_shor(unsigned long composite_number);
unsigned long find_period(unsigned long a, unsigned long modulus);
unsigned long find_a(unsigned long previous_a, unsigned long composite);
/* ### ^^^^^ Switched around in order so they can be in any order in classic_shor.c ^^^^^ ### */
