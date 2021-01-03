/* DESCRIPTION:
 * This is an application to find the prime factors of a composite number.
 *
 * The factorization algorithm implemented is Fermat's.
 *
 * I think this is the best implementation of Fermat's algorithm that's possible in C.
 * The most compact, intuitive, and the most intelligble. I also think is the best code I have ever written.
 *
 * Besides this perfect code, 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../../libraries/functional/string.h" // needed to call string_to_unsigned_long()
#include "../../../../libraries/mathematics/factorization_engines/fermats_algorithm.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "%s <factor set to dissect denoted as composite number>\n", argv[0]);
	fprintf(stderr, "\n\nWrong program usage.\n\nExiting with '-1'.\n");
	return -1;
    } unsigned long factor_set = string_to_unsigned_long(argv[1]);
    printf("Presumption:\n");
    printf("\u2203 p, q \u2208 2^%lu : \u2205 \u2282 p \u2282 '%lu', ('%lu' \u222A \u0305p) \u2286 q\n", factor_set, factor_set, factor_set);

    struct pure_square suspected_composite_factors = fermat_factorize(factor_set);
    printf("\nFinding a pair p, q:\n");
    printf("(p, q) = (%lu, %lu)\n", suspected_composite_factors.root, suspected_composite_factors.square);

    unsigned long supposed_factor_set = suspected_composite_factors.root * suspected_composite_factors.square;
    if (supposed_factor_set == factor_set) {
	printf("\nChecking the essential conditions:\n");
	printf("'%lu' \u222A \u0305p = %lu * (1 / %lu) = (1 * %lu) / %lu = %lu / %lu     \u21D2 '%lu' \u222A \u0305p = '%lu'\n", factor_set, factor_set, suspected_composite_factors.square, factor_set, suspected_composite_factors.square, factor_set, suspected_composite_factors.square, factor_set, suspected_composite_factors.root);

	printf("'%lu' \u222A \u0305q = %lu * (1 / %lu) = (1 * %lu) / %lu = %lu / %lu     \u21D2 '%lu' \u222A \u0305q = '%lu'\n", factor_set, factor_set, suspected_composite_factors.root, factor_set, suspected_composite_factors.root, factor_set, suspected_composite_factors.root, factor_set, suspected_composite_factors.square);

	// printf("'%lu' \u222A \u0305p = %lu * (1 / %lu) = (1 * %lu) / %lu = %lu / %lu = '%lu'\n", factor_set, factor_set, suspected_composite_factors.root, factor_set, suspected_composite_factors.root, factor_set, suspected_composite_factors.root, suspected_composite_factors.square);
	printf("\n\n'%lu' \u222A '%lu' = '%lu'\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation successful.\n\nExiting '0'.\n");
	return 0;
    } else {
	printf("'%lu' \u222A '%lu' \u2260 '%lu'\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation unsuccessful.\n\nExiting '-2'.\n");
	return -1;
    }
}
