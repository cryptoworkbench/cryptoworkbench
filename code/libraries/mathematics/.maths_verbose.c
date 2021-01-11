// This library contains all the math functions which are verbose.
//
// See the header file for function descriptions.
#include <stdio.h>

unsigned long return_gcd_calculation_inner(unsigned long *divided, unsigned long old_divider) {
    if (*divided % old_divider == 0) {
	return old_divider;
    } else if (*divided % old_divider != 0) {
	printf("%lu = %lu * ", *divided, old_divider);

	unsigned long new_divider = *divided % old_divider;
	printf("(%lu) + %lu\n", *divided / old_divider, new_divider);

	// Recall to top
	return_gcd_calculation_inner(&old_divider, new_divider);
    }
}

void return_gcd_calculation(unsigned long smaller_number, unsigned long b) {
    if (smaller_number > b) { /* Swap values if needed */
	unsigned long c = smaller_number;
	smaller_number = b;
	b = c; }

    unsigned long greater_number = b; /* First we must prepare a copy of b */
    printf("\nGCD(%lu, %lu) = %lu\n", b, smaller_number, return_gcd_calculation_inner(&greater_number, smaller_number));
}
