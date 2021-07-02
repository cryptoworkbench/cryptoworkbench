/* This program will perform showcase scalar multiplication of the point (5, 1) existing on the elliptic curve defined by the following public parameters
 * a: 2
 * b: 2
 * p: 17
 *
 * The first step has been achieved:
 * Create a function that performs point doubling
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
// ^^ LIBRARY INCLUSIONS

struct ECC_point {
    unsigned long x;
    unsigned long y; };
// ^^ STRUCTURE TO CAPTURE POINT IDEA

unsigned long a = 2;
unsigned long b = 2;
unsigned long mod = 17;
// ^^ FIXED VARIABLES

unsigned long x_of_R(unsigned long tangent, struct ECC_point *P, struct ECC_point *Q) {
    unsigned long ret = mod_exponentiate(tangent, 2, mod); // << Calculate M^2
    ret += (mod - P->x); ret %= mod; ret += (mod - Q->x); ret %= mod;
    // ^^ Subtract two x of G
    return ret;
}

unsigned long y_of_R(unsigned long tangent, struct ECC_point *half, unsigned long x_2b) {
    unsigned long y = ( ( (tangent * ( (half->x + (mod - x_2b) ) % mod) ) % mod ) + (mod - half->y) ) % mod;
    return y;
}

struct ECC_point *point_doubling(struct ECC_point *half) {
    struct ECC_point *whole = malloc(sizeof(struct ECC_point)); unsigned long tangent = ( ( ( ( (mod_exponentiate(half->x, 2, mod) * 3) % mod) + a) % mod ) * multiplicative_inverse( (half->y * 2) % mod, mod)) % mod;
    whole->x = x_of_R(tangent, half, half);
    whole->y = y_of_R(tangent, half, whole->x);
    return whole;
}

unsigned long slope(struct ECC_point *P, struct ECC_point *Q) {
    unsigned long difference_in_vertical_plane = Q->y + (mod - P->y); difference_in_vertical_plane %= mod;
    unsigned long difference_in_horizontal_plane = Q->x + (mod - P->x); difference_in_horizontal_plane %= mod;
    unsigned long a = multiplicative_inverse(difference_in_horizontal_plane, mod);
    unsigned long slope = difference_in_vertical_plane * a; slope %= mod;
    return slope;
}

struct ECC_point *point_addition(struct ECC_point *P, struct ECC_point *Q) {
    unsigned long m = slope(P, Q);
    struct ECC_point *R = malloc(sizeof(struct ECC_point));
    R->x = x_of_R(m, P, Q);
    R->y = y_of_R(m, P, R->x);
    return R;
}

struct ECC_point *field_combination(struct ECC_point *P, struct ECC_point *Q) {
    struct ECC_point *R;
    if (P->x == Q->x && P->y == Q->y) R = point_doubling(P);
    else R = point_addition(P, Q);
    return R;
}

int main(int argc, char **argv) {
    struct ECC_point *iter_0 = malloc(sizeof(struct ECC_point));
    iter_0->x = 5; iter_0->y = 1;
    // ^^ Prepare base point

    fprintf(stdout, "Public variables;\n");
    fprintf(stdout, "A: %lu\n", a);
    fprintf(stdout, "B: %lu\n", b);
    fprintf(stdout, "Modulus: %lu\n\n", mod);

    struct ECC_point *iter_1 = field_combination(iter_0, iter_0);
    struct ECC_point *iter_2 = field_combination(iter_1, iter_1);
    struct ECC_point *iter_3 = field_combination(iter_2, iter_2);
    struct ECC_point *iter_4 = field_combination(iter_3, iter_3);
    struct ECC_point *iter_5 = field_combination(iter_4, iter_4);
    struct ECC_point *iter_6 = field_combination(iter_5, iter_5);
    struct ECC_point *iter_7 = field_combination(iter_6, iter_6);
    struct ECC_point *iter_8 = field_combination(iter_7, iter_7);

    unsigned long card = 19;
    fprintf(stdout, "Cardinality of group: %lu\n", card);
    fprintf(stdout, "P * 1 \u2261 %lu (mod %lu): (%lu, %lu)\n", 1 % card, card, iter_0->x, iter_0->y);
    fprintf(stdout, "P * 2 \u2261 %lu (mod %lu): (%lu, %lu)\n", 2 % card, card, iter_1->x, iter_1->y);
    fprintf(stdout, "P * 4 \u2261 %lu (mod %lu): (%lu, %lu)\n", 4 % card, card, iter_2->x, iter_2->y);
    fprintf(stdout, "P * 8 \u2261 %lu (mod %lu): (%lu, %lu)\n", 8 % card, card, iter_3->x, iter_3->y);
    fprintf(stdout, "P * 16 \u2261 %lu (mod %lu): (%lu, %lu)\n", 16 % card, card, iter_4->x, iter_4->y);
    fprintf(stdout, "P * 32 \u2261 %lu (mod %lu): (%lu, %lu)\n", 32 % card, card, iter_5->x, iter_5->y);
    fprintf(stdout, "P * 64 \u2261 %lu (mod %lu): (%lu, %lu)\n", 64 % card, card, iter_6->x, iter_6->y);
    fprintf(stdout, "P * 128 \u2261 %lu (mod %lu): (%lu, %lu)\n", 128 % card, card, iter_7->x, iter_7->y);
    fprintf(stdout, "P * 256 \u2261 %lu (mod %lu): (%lu, %lu)\n", 256 % card, card, iter_8->x, iter_8->y);

    struct ECC_point *R = field_combination(iter_0, iter_3); // << Point addition
    fprintf(stdout, "1 + 8 \u2261 9P: (%lu, %lu)\n", R->x, R->y);
    return 0;
}
