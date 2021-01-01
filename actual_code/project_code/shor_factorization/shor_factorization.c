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
 *
 * I will implement it at first with a modular exponentiation library.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/maths.h"

int main(int argc, char **argv) {
    printf("Composite number to factorize: ");

    unsigned long *composite_number = (unsigned long *) malloc(sizeof(unsigned long));
    if (argc > 1) {
	*composite_number = string_to_unsigned_long(argv[1]);
	printf("%lu\n", *composite_number);
    } else
	scanf("%lu", &composite_number);

    /* Temporary */
    printf("SETTING COMPOSITE_NUMBER TO 35!\n");
    *composite_number = 35;

    printf("\n\nFinding 'a'; the first number coprime to composite (%lu) . . .\n", *composite_number);
    unsigned long current_gcd;
    unsigned long iter = 1;
    do {
	iter++;
	current_gcd = euclidean_algorithm(*composite_number, iter);
	printf("Current GCD:\n");
	printf("%lu \u2229 %lu = %lu\n", *composite_number, iter, current_gcd);
    } while (current_gcd != 1);
    printf("\nFirst number coprime with the composite: %lu\n", iter);
    printf("SETTING a TO 8.\n");

    return 0;
}
