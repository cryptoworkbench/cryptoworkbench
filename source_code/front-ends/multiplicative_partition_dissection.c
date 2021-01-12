#include <stdio.h>
#include <stdlib.h>
#include "../libraries/functional/string.h" // needed to call str_to_ul()
#include "../libraries/mathematics/factorization_engines.h" // 'classic_shor()', 'fermat_factorize()'

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "%s <factor set to dissect denoted as composite number>\n", argv[0]);
	fprintf(stderr, "\n\nWrong program usage.\n\nExiting with '-1'.\n");
	return -1;
    } unsigned long factor_set = str_to_ul(argv[1]);
    fprintf(stdout, "Multiplicative partition set to dissect: '%lu'\n\n", factor_set);
    fprintf(stdout, "Factorization engines available under the hood:\n");
    fprintf(stdout, "#1. A factorization engine based a simple prime divisor lookup function (requires a prime table).\n");
    fprintf(stdout, "#2. A factorization engine based on Fermat's factorization method.\n");
    fprintf(stdout, "#3. A factorization engine based on Shor's factorization method.\n\n");
    int decision;
    fprintf(stdout, "This execution of \"%s\" should use factorization engine #", argv[0]);
    fscanf(stdin, "%i", &decision);

    struct number_pair *(*factorize)(unsigned long);
    switch (decision) {
	case 1:
	    factorize = lookup_factorize_wrapper; break;
	case 2:
	    factorize = fermat_factorize; break;
	case 3:
	    factorize = classic_shor;
    } struct number_pair *suspected_factors = factorize(factor_set);

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
