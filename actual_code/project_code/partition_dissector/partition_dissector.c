/* This is genius, a function that spits the digits of any number in the notation of any base, woedie
 * Version 1.0
 *
 * Try 292 2
 * */
#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"
#include "../../../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define ASCII_BASE 48
#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

struct ll {
    unsigned long logarithm;
    unsigned long multiplier;
    struct ll *next;
};

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

void coloured_print_base_B_notation(char *answer, char *COLOUR, char *NORM) {
    for (unsigned long index = 0; answer[index] != '\0'; index++) {
	if (answer[index] != '0') {
	    fprintf(stdout, "%s", COLOUR);
	} else if (answer[index] == '0') {
	    fprintf(stdout, "%s", NORM);
	} fprintf(stdout, "%c", answer[index]);
    } fprintf(stdout, "%s", NORMAL); }
// ^^ Print colored digits

struct ll *base_B_notation_of(unsigned long number, unsigned long base, char **string_head) {
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
	    new_element->multiplier = digit;
	    new_element->next = *tracer;
	    // ^ Create new partition in partitions list

	    *tracer = new_element;
	}

	accumulator += cumulator;
	logarithm++;
	decumulator = (decumulator - digit) / base; // <-- Remove digit from number
    } while (decumulator -= 0);

    /* ## Success check --> */
    if (string_tail == *string_head) return a;
    if (string_tail != *string_head) return NULL;
}

void print_partitions(unsigned long base, struct ll *head) {
    while (1) {
	fprintf(stdout, "%lu", exponentiate(base, head->logarithm) * head->multiplier);
	if (head->next != NULL) { fprintf(stdout, " + "); head = head->next; continue; }
	else if (head->next == NULL) break; }
} // ^ print_partitions ==> 

void print_multipliers(unsigned long base, struct ll *head) {
    while (1) {
	fprintf(stdout, "(%lu * " GREEN "%lu" NORMAL ")", exponentiate(base, head->logarithm), head->multiplier);
	if (head->next != NULL) { fprintf(stdout, " + "); head = head->next; continue; }
	else if (head->next == NULL) break; }
} // ^ print_partitions ==> 

void print_logs(unsigned long base, struct ll *head) {
    while (1) {
	fprintf(stdout, "(%lu^%lu * " GREEN "%lu" NORMAL ")", base, head->logarithm, head->multiplier);
	if (head->next != NULL) { fprintf(stdout, " + "); head = head->next; continue; }
	else if (head->next == NULL) break; }
} // ^ print_logs ==> 

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Program usage:\n");
	fprintf(stderr, "%s <number> <base>\n\n", argv[0]);
	fprintf(stderr, "For example: %s 292 7\n\n\n", argv[0]);
	fprintf(stderr, "Wrong program usage.\n\nExiting '-1'.\n");
	return -1;
    } // ^ Terminate upon wrong number of arguments

    unsigned long number = string_to_unsigned_long(argv[1]);
    unsigned long base = string_to_unsigned_long(argv[2]);
    // ^ Process input arguments

    char *answer;
    struct ll *head = NULL;
    if (head = base_B_notation_of(number, base, &answer)) {
	fprintf(stdout, "How to write %lu in base %lu notation: ", number, base);
	coloured_print_base_B_notation(answer, GREEN, RED); printf("\n\n");
	free(answer);

	fprintf(stdout, "%lu = ", number);
	print_partitions(base, head); printf(" \u21D2\n");

	fprintf(stdout, "%lu = ", number);
	print_multipliers(base, head); printf(" \u21D2\n");

	fprintf(stdout, "%lu = ", number);
	print_logs(base, head); printf(" \u21D2 %lu =\n", number);

	unsigned long logarithm = head->logarithm + 1;
	do {logarithm--;
	    unsigned long i = exponentiate(base, logarithm);
	    if (head != NULL && logarithm == head->logarithm) {
		printf(GREEN"%lu^%lu * %lu = %lu * %lu = %lu\n", base, logarithm, head->multiplier, i, head->multiplier, head->multiplier * i);
		head = head->next; }
	    else
		printf(RED"%lu^%lu * 0 = %lu * 0 = 0\n", base, logarithm, i);
	} while (logarithm != 0); printf("%s", NORMAL); return 0;
    } else {
	fprintf(stderr, "Calculation incorrect!\n\n");
	fprintf(stderr, "Exiting -1.\n");
	return -1;
    } // <-- End of program
}
