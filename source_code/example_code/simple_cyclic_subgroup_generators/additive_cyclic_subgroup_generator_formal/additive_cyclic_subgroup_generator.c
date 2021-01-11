#include <stdio.h>
#include "../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.h"
#define ADDITIVE_IDENTITY 0

void main(int argc, char *argv[]) {
    unsigned long modulus;
    if (argc == 1) {
	printf("Modulus: ");
	scanf("%lu", &modulus);
    } else
	string_as_unsigned_long(argv[1], strlen(argv[1]), &modulus);

    printf("<0> = {0}\n");
    for (unsigned long generating_element = 1; generating_element < modulus; generating_element++) {
	unsigned long iterator = generating_element;
	printf("<%lu> = {%lu, ", generating_element, ADDITIVE_IDENTITY);
	while ((iterator + generating_element) % modulus != ADDITIVE_IDENTITY) {
	    printf("%lu, ", iterator);
	    iterator += generating_element;
	    iterator %= modulus;
	} printf("%lu}\n", iterator);
    }
}
