#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.h"
#define ADDITIVE_IDENTITY 0

void main(int argc, char *argv[]) {
    unsigned long modulus;
    if (argc == 1) {
	printf("Modulus: ");
	scanf("%lu", &modulus);
    } else
	string_as_unsigned_long(argv[1], strlen(argv[1]), &modulus);

    for (unsigned long generating_element = ADDITIVE_IDENTITY; generating_element < modulus; generating_element++) {
	unsigned long iterator = generating_element;
	printf("<%lu> = {", generating_element);
	while (iterator % modulus != ADDITIVE_IDENTITY) {
	    printf("%lu, ", iterator);
	    iterator += generating_element;
	    iterator %= modulus;
	} printf("%lu}\n", iterator);
    }
}
