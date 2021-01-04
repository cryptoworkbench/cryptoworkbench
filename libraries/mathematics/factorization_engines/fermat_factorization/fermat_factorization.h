/* DESCRIPTION:
 * Header file for fermats_algorithm.c
 *
 * Functions are in reversed order so that they can be placed in any order within fermats_algorithm.c */
struct pure_square {
    unsigned long root;
    unsigned long square;
};

struct pure_square fermat_factorize(unsigned long odd_composite);
struct pure_square _fermat_factorize(struct pure_square *pair_one, struct pure_square *pair_two);
void inflate(struct pure_square *square_pair);
struct pure_square *construct_square(unsigned long root, unsigned long square);
