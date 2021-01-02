/* DEVELOPERS DESCRIPTION:
 * The inspiration for this project came to me from the following yt video:
 * https://www.youtube.com/watch?v=12Q3Mrh03Gk
 *
 * Because of this video, I have decided to implement Shor's algorithm on a classical computer.
 *
 * This to serve me multiple purposes:
 * ### AS AN EXCERCISE
 *      To become a better programmer
 *
 * ### TO ASSERT THIS NOTION IN THE VIDEO THAT SHOR'S ALGORITHM IS NOT EFFICIENT ON A CLASSICAL COMPUTER
 *      To me this is the main purpose
 *
 * This is the first prototype.
 *
 * What I desire is that it will work for any number I put in.
 *
 * Shor factorization cannot be achieved when any of the following two conditions are met:
 * #1. When the period of the chosen number coprime with the composite is not even
 * #2. When this chosen number raised to half it's period (it's period over two) is equivalent to one modulus the composite (watch the video to understand this)
 *
 * Currently, this program is equiped to deal with both cases by automatically going on to the next a when either one of these cases emerges.
 *
 * I know 65 doesn't work.
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
    /* ### PART ONE: TAKE IN NUMBER TO FACTORIZE ### */

    unsigned long *composite_number = (unsigned long *) malloc(sizeof(unsigned long));
    if (argc == 2) {
        *composite_number = string_to_unsigned_long(argv[1]);
	printf("Factor set to dissect: '%lu'\n", *composite_number);
    } else {
	printf("Hello, I am %s.\n\n", argv[0]);
	printf("I am an implementation of Shor's algorithm on a classical machine. Most of you would probably call my faculty (prime) factorization.\n");
	printf("I would like to redefine my faculty as dissecting the factor set of a composite number.\n");
	printf("I think it is best to keep the underlying set dynamics transparent.\n");
	printf("\nFor example, let's from now on denote the union of the sets {3, \u2205}, {7, \u2205}, and {13, \u2205} as '273'. Way to go. Now you understand my notation.\n");
	printf("\nThe way to get my to dissect any 'composite number' is by running me as:\n%s <composite number>\n", argv[0]);
	return -1;
    }
    /* ### END PART ONE ### */

    /* ### PART TWO: FIND SUITABLE A ### */
    unsigned long period;
    unsigned long a = 0;
    do {
        a++;
        a = find_a(a, *composite_number);
	period = find_period(a, *composite_number);
    } while (period % 2 != 0 || mod_exponentiate(a, period / 2, *composite_number) == *composite_number - 1); /* ### DEV NOTE #1: MAKE A SIGNED VERSION OF THIS FUNCTION ### */
    printf("\nALGEBRAS:\n");
    printf("$ \u22B4 <\u2124/%lu, *> = <%lu>\n", *composite_number, a);
    printf("|$| = %lu\n", period);
    printf("|$| % 2 = %lu % 2 = 0  \u21D2  2 \u2223 %lu", period, period);
    /* Supplementary information for stdout: */ printf("		2 DIVIDES %lu  \u21D2  \u2713 THE PERIOD OF %lu UNDER MOD %lu ARITHMATIC IS EVEN\n", period, a, *composite_number);
    printf("%lu^(%lu/2) \u2261 %lu^%lu \u2262 - 1 (mod %lu)", a, period, a, period / 2, *composite_number);
    /* Supplementary information for stdout: */ printf("		%lu^%lu \u2262 - 1 (mod %lu) \u21D2 %lu^%lu + 1 \u2262 0 (mod %lu) \u21D2 \u2713 \u2204 k \u2208 \u2115 : k | (%lu^%lu + 1)\n", a, period / 2, *composite_number, a, period / 2, *composite_number, a, period / 2);

    /* ### END PART TWO ### */

    /* ### PART THREE: FIND FACTOR SET INTERSECTIONS OF '*composite_number' WITH "a^(r/2) - 1" and "a^(r/2) + 1" ### */
    unsigned long intermediary = exponentiate(a, period / 2);
    printf("\nIntersection of the factor set '%lu' with '(a^(r/2) + 1)':\n", *composite_number);
    printf("'%lu' \u2229 '(%lu^%lu + 1)'  =  '%lu' \u2229 '%lu + 1'  =  '%lu' \u2229 '%lu'  ", *composite_number, a, period / 2, *composite_number, intermediary, *composite_number, intermediary + 1);
    unsigned long factor_a = euclidean_algorithm(intermediary + 1, *composite_number);
    printf("=  '%lu'\n", factor_a);

    printf("\nIntersection of the factor set '%lu' with '(a^(r/2) - 1)':\n", *composite_number);
    printf("'%lu' \u2229 '(%lu^%lu - 1)'  =  '%lu' \u2229 '%lu - 1'  =  '%lu' \u2229 '%lu'  ", *composite_number, a, period / 2, *composite_number, intermediary, *composite_number, intermediary - 1);
    unsigned long factor_b = euclidean_algorithm(intermediary - 1, *composite_number);
    printf("=  '%lu'\n", factor_b);
    /* ### END PART THREE ### */
    
    /* ### PART FOUR: VERIFY CALCULATIONS ### */
    printf("\nSuspected factors:\n");
    printf("Factor a: %lu\n", factor_a);
    printf("Factor b: %lu\n", factor_b);
    unsigned long suspected_original = factor_a * factor_b;
    printf("\nFactor a * factor b = %lu * %lu = %lu ", factor_a, factor_b, suspected_original);
    if (suspected_original == *composite_number) {
	printf("\nSuccesfull in determining the factor set of '%lu'\n", *composite_number);
	return 0;
    } else if (suspected_original != *composite_number) {
	printf("\nUnsuccesfull in determining the factor set of '%lu'\n", *composite_number);
	return -1;
    }
}
/* ### DEV NOTES:
 *     #1. MAKE A SIGNED VERSION OF THIS FUNCTION, THIS WAY I COULD JUST WRITE - 1 IN THIS CLAUSE
 */
