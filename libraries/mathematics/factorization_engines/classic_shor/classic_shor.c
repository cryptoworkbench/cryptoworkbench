#include "classic_shor.h"

unsigned long find_a(unsigned long previous_a, unsigned long composite) {
    if (euclidean_algorithm(composite, previous_a) != 1) {
	unsigned long current_gcd;
	do {
	    previous_a++;
	    current_gcd = euclidean_algorithm(composite, previous_a);
	} while (current_gcd != 1);
    }

    /* 'previous_a' is now the first a in the infinite open interval with as open minimum endpoint a, and a maximum endpoint infinity. That's [a, infinity) */
    return previous_a;
}

unsigned long find_period(unsigned long a, unsigned long modulus) {
    unsigned long modular_logarithm = ADDITIVE_IDENTITY;
    unsigned long residue = MULTIPLICATIVE_IDENTITY;
    do {
        modular_logarithm++;
        residue = (residue * a ) % modulus;
    } while (residue != MULTIPLICATIVE_IDENTITY); return modular_logarithm;
}

struct number_pair classic_shor(unsigned long composite_number) {
    unsigned long period;
    unsigned long a = 1;
    do {
        a++;
        a = find_a(a, composite_number);
	period = find_period(a, composite_number);
    } while (period % 2 == 1 || mod_exponentiate(a, period / 2, composite_number) == composite_number - 1);

    unsigned long intermediary = exponentiate(a, period / 2);
    struct number_pair factors = {
	euclidean_algorithm(intermediary + 1, composite_number),
	euclidean_algorithm(intermediary - 1, composite_number) };

    return factors;
}
