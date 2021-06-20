/* This code was inspired by: https://www.youtube.com/watch?v=F3zzNa42-tQ
 * And it was written with help from the book "Serious Cryptography: A practical guide to Modern Encryption"
 *
 * In the above YouTube video. An example calculation is given which I have repeated here.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
// ^^ LIBRARY INCLUSIONS

struct ECC_point {
    unsigned long x;
    unsigned long y; };
// ^^ STRUCTURE TO CAPTURE POINT IDEA

// struct ECC_point field_operation(unsigned long generated_element, unsigned long generating_element, unsigned long group_modulus);

unsigned long a = 2;
unsigned long b = 2;
unsigned long mod = 17;
// ^^ FIXED VARIABLES

struct ECC_point field_combination(struct ECC_point P, struct ECC_point Q) {
    unsigned long m; struct ECC_point ret_val; // <<< Declare the needed variables
    if (P.x == Q.x && P.y == Q.y) m = ( ( ( ( (mod_exponentiate(P.x, 2, mod) * 3) % mod) + a) % mod ) * multiplicative_inverse( (P.y * 2) % mod, mod)) % mod; // Formula for point doubling
    else m = (((Q.y + (mod - P.y)) % mod) * multiplicative_inverse( ((Q.x + (mod - P.x)) % mod), mod) ) % mod; // <<< Formula for point addition
    ret_val.x = (((mod_exponentiate(m, 2, mod) + (mod - P.x)) % mod) + (mod - P.x)) % mod; // <<< Formula for 'x' coordinate
    ret_val.y = (((m * ( (P.x + (mod - ret_val.x)) % mod)) % mod) + (mod - P.y)) % mod; // <<< Formula for 'y' coordinate
    return ret_val;
}

int main(int argc, char **argv) {
    struct ECC_point one_K;
    one_K.x = 5; one_K.y = 1;
    // ^^ Prepare base point

    fprintf(stdout, "Public variables;\n");
    fprintf(stdout, "A: %lu\n", a);
    fprintf(stdout, "B: %lu\n", b);
    fprintf(stdout, "Modulus: %lu\n\n", mod);

    struct ECC_point two_K = field_combination(one_K, one_K);
    struct ECC_point four_K = field_combination(two_K, two_K);
    struct ECC_point eight_K = field_combination(four_K, four_K);
    struct ECC_point sixteen_K = field_combination(eight_K, eight_K);
    struct ECC_point thirdteen_K = field_combination(sixteen_K, sixteen_K);
    struct ECC_point seven_K = field_combination(thirdteen_K, thirdteen_K);
    struct ECC_point fourteen_K = field_combination(seven_K, seven_K);
    struct ECC_point nine_K = field_combination(fourteen_K, fourteen_K);
    struct ECC_point eighteen_K = field_combination(nine_K, nine_K);
    struct ECC_point seventeen_K = field_combination(eighteen_K, eighteen_K);
    struct ECC_point fifteen_K = field_combination(seventeen_K, seventeen_K);
    struct ECC_point eleven_K = field_combination(fifteen_K, fifteen_K);
    struct ECC_point three_K = field_combination(eleven_K, eleven_K);
    struct ECC_point six_K = field_combination(three_K, three_K);
    struct ECC_point twelve_K = field_combination(six_K, six_K);
    struct ECC_point five_K = field_combination(twelve_K, twelve_K);
    struct ECC_point ten_K = field_combination(five_K, five_K);
    struct ECC_point twenty_K = field_combination(ten_K, ten_K);

    unsigned long card = 19;
    fprintf(stdout, "Deriving the group knowing that the cardinality of this group (%lu) is coprime to the modulus (%lu):\n", card, mod);
    fprintf(stdout, "1b: (%lu, %lu)\n", one_K.x, one_K.y);
    fprintf(stdout, "2b: (%lu, %lu)\n", two_K.x, two_K.y);
    fprintf(stdout, "4b: (%lu, %lu)\n", four_K.x, four_K.y);
    fprintf(stdout, "8b: (%lu, %lu)\n", eight_K.x, eight_K.y);
    fprintf(stdout, "16b: (%lu, %lu)\n", sixteen_K.x, sixteen_K.y);
    fprintf(stdout, "13b: (%lu, %lu)\n", thirdteen_K.x, thirdteen_K.y);
    fprintf(stdout, "7b: (%lu, %lu)\n", seven_K.x, seven_K.y);
    fprintf(stdout, "14b: (%lu, %lu)\n", fourteen_K.x, fourteen_K.y);
    fprintf(stdout, "9b: (%lu, %lu)\n", nine_K.x, nine_K.y);
    fprintf(stdout, "18b: (%lu, %lu)\n", eighteen_K.x, eighteen_K.y);
    fprintf(stdout, "17b: (%lu, %lu)\n", seventeen_K.x, seventeen_K.y);
    fprintf(stdout, "15b: (%lu, %lu)\n", fifteen_K.x, fifteen_K.y);
    fprintf(stdout, "11b: (%lu, %lu)\n", eleven_K.x, eleven_K.y);
    fprintf(stdout, "3b: (%lu, %lu)\n", three_K.x, three_K.y);
    fprintf(stdout, "6b: (%lu, %lu)\n", six_K.x, six_K.y);
    fprintf(stdout, "12b: (%lu, %lu)\n", twelve_K.x, twelve_K.y);
    fprintf(stdout, "5b: (%lu, %lu)\n", five_K.x, five_K.y);
    fprintf(stdout, "10b: (%lu, %lu)\n", ten_K.x, ten_K.y);
    fprintf(stdout, "20b \u2261 20 - 19 = 1b: (%lu, %lu)\n", twenty_K.x, twenty_K.y);

    fprintf(stdout, "\n\nFurther experiments:\n");
    struct ECC_point R = field_combination(one_K, eighteen_K);
    fprintf(stdout, "1 + 18 \u2261 19P: (%lu, %lu)\n", R.x, R.y);

    struct ECC_point point_at_infinity_one = field_combination(one_K, ten_K);
    fprintf(stdout, "1b + 10b (each others inverse): (%lu, %lu)\n", point_at_infinity_one.x, point_at_infinity_one.y);

    struct ECC_point point_at_infinity_two = field_combination(two_K, five_K);
    fprintf(stdout, "2b + 5b (each others inverse): (%lu, %lu)\n", point_at_infinity_two.x, point_at_infinity_two.y);
    return 0; }
