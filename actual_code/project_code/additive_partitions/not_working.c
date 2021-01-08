/* This is genius, a function that spits the digits of any number in the notation of any base, woedie
 * Version 4.0 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define ASCII_BASE 48

struct ll {
    unsigned long logarithm;
    unsigned long multiplier;
    unsigned long partition;
    struct ll *next;
};

unsigned long down_rounded_base_B_logarithm(unsigned long B, unsigned long exponent) {
    unsigned long logarithm = 0;
    unsigned long power_of_Base = MULTIPLICATIVE_IDENTITY;

    /* Find the first power of B which is not smaller than the base_exponent */
    do {
	power_of_Base *= B;
	logarithm++;
    } while (power_of_Base < exponent);
    /* while (!(power_of_Base >= exponent)) {
	power_of_Base *= B;
	logarithm++;
    }

    if (power_of_Base > exponent)
	logarithm--; */

    return logarithm;
}

struct ll *base_B_notation_of(unsigned long number, unsigned long base, char **string_head) {
    FILE *out = stdout;
    if (!(out = fopen(".ignore", "w"))) {
	fprintf(stderr, "I/O Error.\n");
	fprintf(stderr, "Exiting -2.\n");
	return NULL; }
    // ^ <-- Open temporary storage file

    unsigned long digit, power, cumulator, decumulator, accumulator, logarithm;
    decumulator = number; logarithm = accumulator = ADDITIVE_IDENTITY;

    unsigned long char_needed = down_rounded_base_B_logarithm(base, number);
    char *string_tail;
    *string_head = (char *) malloc(sizeof(char) * char_needed + 1);
    *(string_tail = *string_head + char_needed + 1) = 0;
    
    struct ll *a = NULL;
    struct ll **tracer = &a;
    do {
	string_tail--;
	digit = decumulator % base;
	*string_tail = digit + ASCII_BASE;
	power = exponentiate(base, logarithm);

	cumulator = digit * power;
	if (cumulator != 0) {
	    struct ll *new_element = (struct ll *) malloc(sizeof(struct ll));
	    new_element->logarithm = logarithm;
	    new_element->partition = (new_element->multiplier = digit) * exponentiate(base, logarithm); 
	    new_element->next = *tracer;
	    // ^ Create new partition in partitions list

	    *tracer = new_element;
	}

	fprintf(out, "%lu^%lu * %c = %lu * %c = %lu\n", base, logarithm, *string_tail, power, *string_tail, cumulator);

	accumulator += cumulator;
	logarithm++;
	decumulator = (decumulator - digit) / base; // <-- Remove digit from number
    } while (decumulator -= 0);
    fclose(out);

    /* ## Success check --> */
    if (string_tail == *string_head) return a;
    if (string_tail != *string_head) return NULL;
}

void print_partitions(unsigned long base, struct ll *head) {
    printf("(%lu * %lu) ", exponentiate(base, head->logarithm), head->multiplier); do {
	head = head->next;
	printf("+ (%lu * %lu) ", exponentiate(base, head->logarithm), head->multiplier);
    } while (head->next != NULL); }

void print_logs(unsigned long base, struct ll *head) {
    unsigned long partition;
    while (head->next != NULL) {
	fprintf(stdout, "(%lu^%lu * %lu) + ", base, head->logarithm, head->multiplier);
	head = head->next;
    } fprintf(stdout, "(%lu^%lu * %lu)", base, head->logarithm, head->multiplier); }

int main(int argc, char **argv) {
    if (argc != 3)
	return -1;
    // ^ Terminate upon wrong number of arguments

    unsigned long number = string_to_unsigned_long(argv[1]);
    unsigned long base = string_to_unsigned_long(argv[2]);
    // ^ Process input arguments

    char *answer;
    struct ll *head = NULL;
    if (head = base_B_notation_of(number, base, &answer)) {
	fprintf(stdout, "How to write %lu in base %lu notation: %s\n", number, base, answer);
	free(answer);

	fprintf(stdout, "\nNamely because %lu = ", number);
	print_partitions(base, head); printf(" = "); /* print_multipliers(base, head); printf(" = "); */ print_logs(base, head);

	fprintf(stdout, "\n\nDissection:\n");
	/* for (unsigned long logarithm = 0; head != NULL; logarithm++) {
	    printf("%lu^%lu *"
	} */

	system("cat .ignore && rm .ignore");
	return 0;
    } else {
	fprintf(stderr, "Calculation incorrect!\n\n");
	fprintf(stderr, "Exiting -1.\n");
	return -1;
    } // <-- End of program
}
