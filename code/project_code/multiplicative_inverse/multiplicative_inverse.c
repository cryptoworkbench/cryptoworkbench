#include <stdio.h>

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

long multiplicative_inverse(long a, long b) { // Yield a^-1 mod b
    long x, y; extended_gcd(a, b, &x, &y);
    return b + x;
}

int main(int argc, char *argv[]) {
    long small, big;

    printf("First number  :  ");
    scanf("%li", &small); // process small

    printf("Second number :  ");
    scanf("%li", &big); // process big

    if (!(small <= big)) { // Switch around if necessary
	long temp = small;
	small = big; big = temp;
    }

    printf("Multiplicative inverse of %li %% %li: %li\n", small, big, multiplicative_inverse(small, big));
    return 0;
}
