/* Workings should be obvious. */
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
    printf("Multiplicative factor set to dissect :  '%lu'\n", factor_set);

    struct pure_square suspected_composite_factors = fermat_factorize(factor_set);
    printf("Suspected subset a                   :  '%lu'\n", suspected_composite_factors.root);
    printf("Suspected subset b                   :  '%lu'\n", suspected_composite_factors.square);

    unsigned long supposed_factor_set = suspected_composite_factors.root * suspected_composite_factors.square;
    if (supposed_factor_set == factor_set) {
	printf("%lu * %lu = %lu\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation successful.\n\nExiting '0'.\n");
	return 0;
    } else {
	printf("%lu * %lu != %lu\n", suspected_composite_factors.root, suspected_composite_factors.square, factor_set);
	printf("\n\nCalculation unsuccessful.\n\nExiting '-2'.\n");
	return -1;
    }
}
