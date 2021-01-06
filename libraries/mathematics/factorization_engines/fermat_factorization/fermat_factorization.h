// #include "../struct_number_pair_declaration.h"
struct number_pair fermat_factorize(unsigned long odd_composite);
struct number_pair _fermat_factorize(struct number_pair *pair_one, struct number_pair *pair_two);
void inflate(struct number_pair *square_pair);
struct number_pair *construct_square(unsigned long root, unsigned long square);
