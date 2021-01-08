/* This is genius, a function that spits the digits of any number in the notation of any base, woedie */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define ASCII_BASE 48

unsigned long down_rounded_base_B_logarithm(unsigned long B, unsigned long exponent) {
    unsigned long logarithm = ADDITIVE_IDENTITY;
    unsigned long power_of_Base = MULTIPLICATIVE_IDENTITY;

    /* Find the first power of B which is not smaller than the base_exponent */
    while (!(power_of_Base >= exponent)) {
	power_of_Base *= B;
	logarithm++;
    }

    /* If the first power of 2 which is not smaller than the base_exponent, is equal to the base_exponent, then the base_exponent is a power of two, and all is set and done.
     *
     * If however, as will be in most cases, the first power of two which is not smaller than 'base_exponent' is actually greater than 'base_exponent', we over-estimated.
     *
     * In this case 'power_of_Base' over 2 ('power_of_Base / 2' in code) will be less than base_exponent, but also the greatest power of two which still fits base_exponent. */
    if (power_of_Base > exponent)
	logarithm--;

    return logarithm;
}

int base_B_notation_of(unsigned long number, unsigned long base, char **string_head) {
    unsigned long digit, accumulator, cumulator, power, decumulator, logarithm;
    logarithm = accumulator = ADDITIVE_IDENTITY;
    decumulator = number;

    unsigned long char_needed = down_rounded_base_B_logarithm(base, number);
    char *string_tail;
    *string_head = (char *) malloc(sizeof(char) * char_needed + 1);
    *(string_tail = *string_head + char_needed + 1) = 0;
    
    do {
	string_tail--;
	digit = decumulator % base;
	*string_tail = digit + ASCII_BASE;
	power = exponentiate(base, logarithm);
	cumulator = digit * power;
	printf("%lu^%lu * %c = %lu * %c = %lu\n", base, logarithm, *string_tail, power, *string_tail, cumulator);

	accumulator += cumulator;
	logarithm++;
	decumulator = (decumulator - digit) / base; // <-- Remove digit from number
    } while (decumulator -= 0); printf("\n");

    /* ## Success check --> */
    if (accumulator == number) return 1;
    else if (accumulator != number) return 0;
}

int main(int argc, char **argv) {
    if (argc != 3)
	return -1;
    // ^ Terminate upon wrong number of inputs

    unsigned long number = string_to_unsigned_long(argv[1]);
    unsigned long base = string_to_unsigned_long(argv[2]);
    printf("Number to write in base %lu notation: %lu\n", base, number);
    // ^ Display texts

    char *answer;
    if (base_B_notation_of(number, base, &answer)) {
	printf("%lu in base %lu notation: %s\n", number, base, answer);
	free(answer);
	return 0;
    } else {
	fprintf(stderr, "Calculation incorrect!\n\n");
	fprintf(stderr, "Exiting -1.\n");
	return -1;
    } // <-- End of program
}
