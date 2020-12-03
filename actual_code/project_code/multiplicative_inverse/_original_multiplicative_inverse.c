#include <stdio.h>
#include "../../../libraries/functional/string.h"

long extended_gcd(long a, long b, long *x, long *y) {
    if (a == 0) {
	*x = 0;
	*y = 1;
	return b;
    }

    long _x, _y;
    long gcd = extended_gcd(b % a, a, &_x, &_y);

    *x = _y - (b/a) * _x;
    *y = _x;

    return gcd;
}

long multiplicative_inverse(int a, int b) { // Yield a^-1 mod b
    long x, y; extended_gcd(a, b, &x, &y);
    return b + x;
}

int main(int argc, char *argv[]) {
    long small, big;

    /* ## Take in supplied variables ## */
    switch (argc) {
	case 3:
	    small = string_to_int(argv[2]);
	case 2:
	    big = string_to_int(argv[1]);
	    break;
	default:
	    printf("Program takes the union of factor sets %s <first factor set denoted as representative composite number> <second factor set denoted as representative composite number>\n", argv[0]);
	    printf("\nWrong program usage.\n\n\nExiting -1\n");
	    return -1;
    }

    /* ### Attempt to process not supplied variables (and/or print the supplied ones) ### */
    printf("First number  :  ");
    if (3 > argc) // If small was not processed,
	scanf("%li", &small); // process small
    else /* Or print the already supplied factor set */ printf("%lu\n", small);

    printf("Second number :  ");
    if (2 > argc) // If big was not processed,
	scanf("%li", &big); // process big
    else /* Or print the already supplied factor set */ printf("%lu\n", big);

    if (!(small <= big)) { // Switch around if necessary
	long temp = small;
	small = big; big = temp;
    }

    printf("Multiplicative inverse of %li %% %li: %li\n", small, big, multiplicative_inverse(small, big));
    return 0;
}
