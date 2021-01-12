#include <stdio.h>
#include <stdlib.h>
#include "../libraries/functional/string.h" // needed to call string_to_unsigned_long()
#include "../libraries/mathematics/factorization_engines.h" // 'classic_shor()', 'fermat_factorize()'

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "%s <factor set to dissect denoted as composite number>\n", argv[0]);
	fprintf(stderr, "\n\nWrong program usage.\n\nExiting with '-1'.\n");
	return -1;
    } unsigned long factor_set = string_to_unsigned_long(argv[1]);
    printf("Multiplicative partition set to dissect: '%lu'\n\n", factor_set);
    printf("Factorization engines available under the hood:\n");
    printf("#0. The factorization engine based on Fermat's factorization method.\n");
    printf("#1. The factorization engine based on Shor's factorization method.\n");
    printf("#2. The factorization engine based a simple prime divisor lookup function.\n\n");
    int decision;
    printf("This execution '%s' is using factorization engine #", argv[0]);
    scanf("%i", &decision); printf("\n");

    struct number_pair *(*factorize)(unsigned long);
    switch (decision) {
	case 0:
	    factorize = fermat_factorize;
	case 1:
	    factorize = classic_shor;
	case 2:
	    factorize = lookup_factorize_wrapper;
    } struct number_pair *suspected_factors = factorize(factor_set);

    system("clear");
    printf("Suspected subset a                   :  '%lu'\n", suspected_factors->number_one);
    printf("Suspected subset b                   :  '%lu'\n", suspected_factors->number_two);

    unsigned long supposed_factor_set = suspected_factors->number_one * suspected_factors->number_two;
    if (supposed_factor_set == factor_set) {
	printf("%lu * %lu = %lu\n", suspected_factors->number_one, suspected_factors->number_two, factor_set);
	printf("\n\nCalculation successful.\n\nExiting '0'.\n");
	return 0;
    } else {
	printf("%lu * %lu != %lu\n", suspected_factors->number_one, suspected_factors->number_two, factor_set);
	printf("\n\nCalculation unsuccessful.\n\nExiting '-1'.\n");
	return -1;
    }
}
