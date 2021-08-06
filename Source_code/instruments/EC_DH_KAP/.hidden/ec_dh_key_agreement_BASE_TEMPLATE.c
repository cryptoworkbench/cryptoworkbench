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

unsigned long get_x(unsigned long tangent, struct ECC_point *P, struct ECC_point *Q) {
    unsigned long ret = mod_exponentiate(tangent, 2, mod); // << Calculate M^2
    ret += (mod - P->x); ret %= mod; ret += (mod - Q->x); ret %= mod;
    // ^^ Subtract two x of G
    return ret;
}

unsigned long get_y(unsigned long tangent, struct ECC_point *half, unsigned long x_2b) {
    unsigned long y = ( ( (tangent * ( (half->x + (mod - x_2b) ) % mod) ) % mod ) + (mod - half->y) ) % mod;
    return y;
}

// ### Point doubling (scalar multiplication)
struct ECC_point *simple(struct ECC_point *half) {
    unsigned long numerator = ( ( (mod_exponentiate(half->x, 2, mod) * 3) % mod) + a) % mod;
    unsigned long tangent = (numerator * multiplicative_inverse( (half->y * 2) % mod, mod)) % mod;

    struct ECC_point *whole = malloc(sizeof(struct ECC_point));
    whole->x = get_x(tangent, half, half);
    whole->y = get_y(tangent, half, whole->x);
    return whole;
}

unsigned long slope(struct ECC_point *P, struct ECC_point *Q) {
    unsigned long difference_in_vertical_plane = Q->y + (mod - P->y); difference_in_vertical_plane %= mod;
    unsigned long difference_in_horizontal_plane = Q->x + (mod - P->x); difference_in_horizontal_plane %= mod;
    unsigned long a = multiplicative_inverse(difference_in_horizontal_plane, mod);
    unsigned long slope = difference_in_vertical_plane * a; slope %= mod;
    return slope;
}

// ### Point addition
struct ECC_point *normal(struct ECC_point *P, struct ECC_point *Q) {
    unsigned long m = slope(P, Q);
    struct ECC_point *R = malloc(sizeof(struct ECC_point));
    R->x = get_x(m, P, Q);
    R->y = get_y(m, P, R->x);
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

    struct ECC_point *iter_1 = simple(iter_0);
    struct ECC_point *iter_2 = simple(iter_1);
    struct ECC_point *iter_3 = simple(iter_2);
    struct ECC_point *iter_4 = simple(iter_3);
    struct ECC_point *iter_5 = simple(iter_4);
    struct ECC_point *iter_6 = simple(iter_5);
    struct ECC_point *iter_7 = simple(iter_6);
    struct ECC_point *iter_8 = simple(iter_7);

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

    struct ECC_point *R = normal(iter_0, iter_3); // << Point addition
    fprintf(stdout, "1 + 8 \u2261 9P: (%lu, %lu)\n", R->x, R->y);
    return 0;
}
