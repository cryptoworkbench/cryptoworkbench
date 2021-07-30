/* ABSTRACT:
 * This example code examplifies how to perfectly model the mental view of a modular group as a set with it's corresponding unary group operation based on wether it is an additive
 * or a multiplicative group.
 *
 * It does so with the structure called "GROUP_IDENTIFIER".
 *
 * Try for example:
 * 15 1 12 0 and 15 1 12 1
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/LOGBOOK_library.h"
// #include "../../libraries/mathematics/group_operations.h"

unsigned long UNCAPPED_combination(unsigned long a, unsigned long B) { return a + B; } // <<< The primary operation of all of arithmetic is addition
unsigned long UNCAPPED_combination_REPEATED(unsigned long a, unsigned long B) { return a * B; }
typedef unsigned long (*UNCAPPED_functions) (unsigned long, unsigned long);
UNCAPPED_functions get_applicable_UNCAPPED_function_for(unsigned long SP) { if (SP == 0) return &UNCAPPED_combination; else if (SP == 1) return &UNCAPPED_combination_REPEATED; }
// ^^^ Everything we need for normal (unCAPPED) arithmetics

unsigned long CAPPED_combination(unsigned long a, unsigned long B, unsigned long CAP) { return UNCAPPED_combination(a, B) % CAP; }
unsigned long CAPPED_combination_REPEATED(unsigned long a, unsigned long B, unsigned long CAP) { return UNCAPPED_combination_REPEATED(a, B) % CAP; }
typedef unsigned long (*CAPPED_functions) (unsigned long, unsigned long, unsigned long);
CAPPED_functions get_applicable_CAPPED_function_for(unsigned long SP) { if (SP == 0) return &CAPPED_combination; else if (SP == 1) return &CAPPED_combination_REPEATED; }
// ^^^ Everything we need for modular (CAPPED) arithmetics

typedef struct _group_identifier { CAPPED_functions UNARY; unsigned long CAP; } GROUP_IDENTIFIER;
// ^^^ Equivalent to "group_prams"

unsigned long FINITE_(UNCAPPED_functions base_UNARY, unsigned long a, unsigned long B, unsigned long CAP) { return base_UNARY(a, B) % CAP; }
// ^^^ This is my general GROUP_operation unary function

void main(int argc, char **argv) {
    unsigned long a; if (2 > argc || !(ul_ptr_from_str(&a, argv[1]))) { fprintf(stderr, "Failed to interpret '%s' as A.\n\nExiting '-1'.\n", argv[1]); exit(-1); }
    unsigned long B; if (3 > argc || !(ul_ptr_from_str(&B, argv[2]))) { fprintf(stderr, "Failed to interpret '%s' as B.\n\nExiting '-2'.\n", argv[2]); exit(-2); }
    GROUP_IDENTIFIER *group = (struct _group_identifier *) malloc(sizeof(GROUP_IDENTIFIER)); 
    if (4 > argc || !(ul_ptr_from_str(&group->CAP, argv[3]))) { fprintf(stderr, "Failed to interpret '%s' as the limit to the infinite field N.\n\nExiting '-3'.\n", argv[3]); exit(-3); }
    unsigned long SP; if (5 > argc || !(ul_ptr_from_str(&SP, argv[4]))) { fprintf(stderr, "Failed to interpret '%s' as symetry point.\n\nExiting '-4'.\n", argv[4]); exit(-4); }
    // ^^^ Process input

    UNCAPPED_functions FIELD_COMBINATION = get_applicable_UNCAPPED_function_for(SP); // <<< Sets the standard unary from arithmetic
    char *SYMBOL = combination_SYMBOL_for_(SP);
    fprintf(stdout, "A: %lu\nB: %lu\n\n", a, B);
    fprintf(stdout, "A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, a, SYMBOL, B, FIELD_COMBINATION(a, B), FINITE_(FIELD_COMBINATION, a, B, group->CAP), group->CAP);
    exit(0);
}
