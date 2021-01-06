#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // needed to call string_to_unsigned_long()
#include "../../libraries/mathematics/factorization_engines/struct_number_pair_declaration.h"
#include "../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.h" // 'classic_shor()'
#include "../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.h" // 'fermat_factorize()'

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "%s <factor set to dissect denoted as composite number>\n", argv[0]);
	fprintf(stderr, "\n\nWrong program usage.\n\nExiting with '-1'.\n");
	return -1;
    } unsigned long factor_set = string_to_unsigned_long(argv[1]);
    printf("Multiplicative factor set to dissect :  '%lu'\n", factor_set);
    printf("Choose factorization algorithm to use:\n");
    printf("#0. Fermat's factorization algorithm.\n");
    printf("#1. Shor's factorization algorithm.\n\n");
    int decision;
    printf("I choose number: ");
    scanf("%i", &decision); printf("\n");

    struct number_pair suspected_composite_factors;
    if (decision)
	suspected_composite_factors = fermat_factorize(factor_set);
    else
	suspected_composite_factors = classic_shor(factor_set);

    printf("Suspected subset a                   :  '%lu'\n", suspected_composite_factors.number_one);
    printf("Suspected subset b                   :  '%lu'\n", suspected_composite_factors.number_two);

    unsigned long supposed_factor_set = suspected_composite_factors.number_one * suspected_composite_factors.number_two;
    if (supposed_factor_set == factor_set) {
	printf("%lu * %lu = %lu\n", suspected_composite_factors.number_one, suspected_composite_factors.number_two, factor_set);
	printf("\n\nCalculation successful.\n\nExiting '0'.\n");
	return 0;
    } else {
	printf("%lu * %lu != %lu\n", suspected_composite_factors.number_one, suspected_composite_factors.number_two, factor_set);
	printf("\n\nCalculation unsuccessful.\n\nExiting '-1'.\n");
	return -1;
    }
}
