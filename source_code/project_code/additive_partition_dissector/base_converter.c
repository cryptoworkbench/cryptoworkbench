/* This is genius, a function that spits the digits of any number in the notation of any base, woedie.
 * Try 22292 2.
 *
 * Version 1.1 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
#define ASCII_BASE 48
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"

struct ll {
    unsigned long logarithm;
    unsigned long multiplier;
    struct ll *next;
};

unsigned long elements(struct ll *head) {
    unsigned long elements;
    for (elements = 0; head != NULL; head = head->next) {
	elements++;
    } return elements; }
// Return number of elements in linked list

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

void coloured_print_base_B_notation(char *answer) {
    for (unsigned long index = 0; answer[index] != '\0'; index++) {
	if (answer[index] == '0')
	    fprintf(stdout, "%s", YELLOW);

	else if (answer[index] != '0')
	    fprintf(stdout, "%s", BLUE);

	fprintf(stdout, "%c", answer[index]);
    } fprintf(stdout, "%s", RESET);
} // ^^ Print colored digits

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

void included_partitions(struct ll *head, unsigned long base) {
    while (head != NULL) {
	fprintf(stdout, BLUE "%lu" RESET, exponentiate(base, head->logarithm) * head->multiplier);
	head = head->next;
	if (head != NULL)
	    fprintf(stdout, RESET " + ");
    } }
// ^^ Print one

/* void excluded_partitions(struct ll *head, unsigned long base) {
    unsigned long logarithm = exponentiate(base, head->logarithm);
    unsigned long length = elements(head);
    while (1) {
	logarithm--;
	if (head != NULL && logarithm == head->logarithm)
	    head = head->next;
	else if (all) {
	    fprintf(stdout, YELLOW "0" RESET);
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    } } */
// ^^ Print one

void reveal_partitions(struct ll *head, unsigned long base, int all) {
    unsigned long logarithm = head->logarithm + 1;
    int printed;
    while (1) {
	printed = 0;
	logarithm--;
	unsigned long i = exponentiate(base, logarithm);
	if (head != NULL && logarithm == head->logarithm) {
	    fprintf(stdout, BLUE "%lu" RESET, i * head->multiplier);
	    head = head->next;
	    printed = 1;
	} else if (all) {
	    fprintf(stdout, YELLOW "0" RESET);
	    printed = 1;
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    }
} // ^^ Print one

void first_print(struct ll *head, unsigned long base, int all) {
    unsigned long logarithm = head->logarithm + 1;
    int printed;
    while (1) {
	printed = 0;
	logarithm--;
	unsigned long i = exponentiate(base, logarithm);
	if (head != NULL && logarithm == head->logarithm) {
	    fprintf(stdout, BLUE "(%lu * %lu)" RESET, i, head->multiplier);
	    head = head->next;
	    printed = 1;
	} else if (all) {
	    fprintf(stdout, YELLOW "(%lu * 0)" RESET, i);
	    printed = 1;
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    }
} // ^^ Print two

void second_print(struct ll *head, unsigned long base, int all) {
    unsigned long logarithm = head->logarithm + 1;
    int printed;
    while (1) {
	printed = 0;
	logarithm--;
	unsigned long i = exponentiate(base, logarithm);
	if (head != NULL && logarithm == head->logarithm) {
	    fprintf(stdout, BLUE "(" RED "%lu " BLUE "* %lu)", i, head->multiplier);
	    head = head->next;
	    printed = 1;
	} else if (all) {
	    fprintf(stdout, YELLOW "(" RED "%lu " YELLOW "* 0" YELLOW ")", i);
	    // fprintf(stdout, YELLOW "0" RESET);
	    printed = 1;
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    }
} // ^^ Print two

void extensive_print(struct ll *head, unsigned long base, int all) {
    unsigned long logarithm = head->logarithm + 1;
    int printed;
    while (1) {
	printed = 0;
	logarithm--;
	if (head != NULL && logarithm == head->logarithm) {
	    fprintf(stdout, BLUE "(" RED "%lu" BLUE "^%lu " BLUE "* %lu)", base, logarithm, head->multiplier);
	    head = head->next;
	    printed = 1;
	} else if (all) {
	    fprintf(stdout, YELLOW "(" RED "%lu" YELLOW "^%lu * 0)", base, logarithm);
	    // fprintf(stdout, YELLOW "0" RESET);
	    printed = 1;
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    }
} // ^^ Print two

void last_print(struct ll *head, unsigned long base, int all) {
    unsigned long logarithm = head->logarithm + 1;
    int printed;
    while (1) {
	printed = 0;
	logarithm--;
	if (head != NULL && logarithm == head->logarithm) {
	    fprintf(stdout, RESET "(" RED "%lu" RESET "^%lu * " BLUE "%lu" RESET ")", base, logarithm, head->multiplier);
	    head = head->next;
	    printed = 1;
	} else if (all) {
	    fprintf(stdout, RESET "(" RED "%lu" RESET "^%lu * " YELLOW "0" RESET ")", base, logarithm);
	    // fprintf(stdout, YELLOW "0" RESET);
	    printed = 1;
	}

	if (!all && head == NULL) break;
	if (printed && logarithm != 0) fprintf(stdout, RESET " + "); // <-- extensive_print neutrally coloured "+" between items
	if (logarithm == 0) break;
    }
} // ^^ Print two

int main(int argc, char **argv) {
    if (argc != 3) {
	fprintf(stderr, "Program usage:\n");
	fprintf(stderr, "%s <number> <base>\n\n", argv[0]);
	fprintf(stderr, "For example: %s 292 7\n\n\n", argv[0]);
	fprintf(stderr, "Wrong program usage.\n\nExiting '-1'.\n");
	return -1;
    } // ^ Terminate upon wrong number of arguments

    unsigned long number = str_to_ul(argv[1]);
    unsigned long base = str_to_ul(argv[2]);
    // ^ Process input arguments

    char *answer;
    struct ll *head = NULL;
    if (head = base_B_notation_of(number, base, &answer)) {
	included_partitions(head, base);
	fprintf(stdout, RESET " = " GREEN "%lu " RESET "\u21D4\n", number);

	reveal_partitions(head, base, 1);
	fprintf(stdout, RESET " = " GREEN "%lu " RESET "\u21D4\n", number);

	first_print(head, base, 1);
	fprintf(stdout, RESET " = " GREEN "%lu " RESET "\u21D4\n", number);

	extensive_print(head, base, 1);
	fprintf(stdout, RESET " = " GREEN "%lu " RESET "\u21D4\n", number);

	last_print(head, base, 1);
	fprintf(stdout, RESET " = " GREEN "%lu " RESET "\u21D4\n", number);

	fprintf(stdout, GREEN "%lu" RESET " = '", number); coloured_print_base_B_notation(answer); fprintf(stdout, "' (in base " RED "%lu " RESET "notation)\n", base);
	free(answer); return 0;
    } else {
	fprintf(stderr, "Calculation incorrect!\n\n");
	fprintf(stderr, "Exiting -1.\n");
	return -1;
    } // <-- End of program
}
