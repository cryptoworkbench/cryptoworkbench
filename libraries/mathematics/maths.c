// This library contains all the math functions which are not verbose.
// 
// See the header file for function descriptions.
#define MULTIPLICATIVE_IDENTITY 1

/* unsigned int prime(unsigned long potential_prime) {
    for (unsigned long i = 2; i <= (potential_prime - (potential_prime % 2)) / 2; i++)
	if (potential_prime % i == 0)
	    return 0;
    return 1;
} */

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

unsigned long exponentiate(unsigned long base, unsigned long exponent) {
    if (base == 0)
	return 0;
    else if (base == 1)
	return 1;
    else {
	unsigned long ret = MULTIPLICATIVE_IDENTITY;
	for (unsigned long iterator = 0; iterator < exponent; iterator++)
	    ret *= base;
	return ret;
    }
}
