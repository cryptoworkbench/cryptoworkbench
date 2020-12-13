#include <stdio.h>
#include "../../../../libraries/functional/string.h"
#include "../../../../libraries/mathematics/maths.h" // mod_exponentiate();

int main(int argc, char **argv) {
    unsigned long modulus, exponent, base;
    switch (argc) {
	case 4:
	    modulus = string_to_unsigned_long(argv[3]);
	case 3:
	    exponent = string_to_unsigned_long(argv[2]);
	case 2:
	    base = string_to_unsigned_long(argv[1]);
    }
    
    printf("Modulus: ");
    if (4 > argc)
	scanf("%lu", &modulus);
    else { printf("%lu\n", modulus); }

    printf("Exponent: ");
    if (3 > argc)
	scanf("%lu", &exponent);
    else { printf("%lu\n", exponent); }

    printf("Base: ");
    if (2 > argc)
	scanf("%lu", &base);
    else { printf("%lu\n", base);
    } printf("\n");

    printf("%lu^%lu %% %lu = %lu\n", base, exponent, modulus, mod_exponentiate(base, exponent, modulus));
    return 0;
}
