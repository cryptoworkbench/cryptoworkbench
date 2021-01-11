#include <stdio.h>
#include "../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.h"
#include "../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.h"
#define MULTIPLICATIVE_IDENTITY 1

void main(int argc, char *argv[]) {
    unsigned long modulus;
    if (argc == 1) {
	printf("Modulus: ");
	scanf("%lu", &modulus);
    } else
	string_as_unsigned_long(argv[1], strlen(argv[1]), &modulus);

    unsigned long number_of_elements = 0;
    for (unsigned long generating_element = MULTIPLICATIVE_IDENTITY; generating_element < modulus; generating_element++) {
	if (gcd(modulus, generating_element) == 1) {
	    number_of_elements++;
	    unsigned long iterator = generating_element;
	    printf("<%lu> = {", generating_element);
	    while (iterator != MULTIPLICATIVE_IDENTITY) {
		printf("%lu, ", iterator);
		iterator *= generating_element;
		iterator %= modulus;
	    } printf("%lu}\n", iterator);
	}
    } printf("\nNumber of elements in the multiplicative group of integers Mod %lu: %lu\n", modulus, number_of_elements);
}
