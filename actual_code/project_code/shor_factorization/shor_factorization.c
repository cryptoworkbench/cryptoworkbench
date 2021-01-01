/* DEVELOPERS DESCRIPTION:
 * The inspiration for this project came to me from the following yt video:
 * https://www.youtube.com/watch?v=12Q3Mrh03Gk
 *
 * Because of this video, I have decided to implement Shor's algorithm on a classical computer.
 *
 * This to serve me multiple purposes:
 * ### AS AN EXCERCISE
 * 	To become a better programmer
 *
 * ### TO ASSERT THIS NOTION IN THE VIDEO THAT SHOR'S ALGORITHM IS NOT EFFICIENT ON A CLASSICAL COMPUTER
 * 	To me this is the main purpose
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

unsigned long find_a(unsigned long previous_a, unsigned long composite) {
    unsigned long current_gcd;
    do {
	previous_a++;
	current_gcd = euclidean_algorithm(composite, previous_a);
    } while (current_gcd != 1);

    /* 'previous_a' has now been updated to the next suitable a */
    return previous_a;
}

unsigned long find_period(unsigned long a, unsigned long modulus) {
    unsigned long modular_logarithm = ADDITIVE_IDENTITY;
    unsigned long residue = MULTIPLICATIVE_IDENTITY;
    do {
	modular_logarithm++;
	residue = (residue * a ) % modulus;
    } while (residue != 1); return modular_logarithm;
}

int main(int argc, char **argv) {
    printf("Composite number to factorize: ");

    unsigned long *composite_number = (unsigned long *) malloc(sizeof(unsigned long));
    if (argc > 1) {
	*composite_number = string_to_unsigned_long(argv[1]);
	printf("%lu\n", *composite_number);
    } else
	scanf("%lu", &composite_number);

    /* FIND A */
    unsigned long a = 0;
    do {
	a++;
	a = find_a(a, *composite_number);
    } while (find_period(a, *composite_number) % 2 != 0);
    printf("First integer coprime to %lu with an even period: %lu\n", *composite_number, *composite_number, a);


    /* CALCULATE THE PERIOD OF A MOD 'N' */
    unsigned long period = find_period(a, *composite_number);
    printf("The period of %lu mod %lu is %lu.\n", a, *composite_number, period);

    /* CHECK TO SEE IF a^(r/2) - 1 IS A MULTIPLE OF 'N' */
    if (mod_exponentiate(a, period / 2, *composite_number) == 1) {
	printf("%lu^(%lu/2) \u2261 %lu^%lu \u2261 1 (mod %lu)\n", a, period, period / 2, *composite_number);
	printf("\n\nExiting -1.\n");
	return -1;
    } else {
	printf("%lu^(%lu/2) \u2261 %lu^%lu \u2261 0 (mod %lu)\n", a, period, a, period / 2, *composite_number);
	printf("\n\nProceeding to calculation of factors.\n");
    }
    unsigned long factor_a = euclidean_algorithm(exponentiate(a, period / 2) - 1, *composite_number);
    unsigned long factor_b = euclidean_algorithm(exponentiate(a, period / 2) + 1, *composite_number);
    
    printf("Factor a: %lu\n", factor_a);
    printf("Factor b: %lu\n", factor_b);
    return 0;
}
