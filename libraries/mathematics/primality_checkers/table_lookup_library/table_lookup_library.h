#include <stdio.h>
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

int _read_prime(unsigned long *prime_space_ptr, FILE *prime_table_fs, int binary_mode);
unsigned long _prime(unsigned long potential_prime, FILE *prime_table_fs, int binary_mode);
unsigned long prime(unsigned long potential_prime, char *prime_table_filename, int binary_mode);
