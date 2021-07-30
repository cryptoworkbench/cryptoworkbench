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

unsigned long primary_UNARY_unCAPPED(unsigned long A, unsigned long B) { return A + B; }
unsigned long secular_UNARY_unCAPPED(unsigned long A, unsigned long B) { return A * B; }
typedef unsigned long (*unCAPPED_function) (unsigned long, unsigned long);
unCAPPED_function get_applicable_unCAPPED_UNARY_for(unsigned long SP) { if (SP == 0) return &primary_UNARY_unCAPPED; else if (SP == 1) return &secular_UNARY_unCAPPED; }
// ^^^ Everything we need for normal (unCAPPED) arithmetics

unsigned long primary_UNARY_CAPPED(unsigned long A, unsigned long B, unsigned long LIM) { return primary_UNARY_unCAPPED(A, B) % LIM; }
unsigned long secular_UNARY_CAPPED(unsigned long A, unsigned long B, unsigned long LIM) { return secular_UNARY_unCAPPED(A, B) % LIM; }
typedef unsigned long (*CAPPED_function) (unsigned long, unsigned long, unsigned long);
CAPPED_function get_applicable_CAPPED_UNARY_for(unsigned long SP) { if (SP == 0) return &primary_UNARY_CAPPED; else if (SP == 1) return &secular_UNARY_CAPPED; }
// ^^^ Everything we need for modular (CAPPED) arithmetics

typedef struct _group_identifier { CAPPED_function UNARY; unsigned long LIM; } GROUP_IDENTIFIER;
// ^^^ Equivalent to "group_prams"

unsigned long LIMIT_(unCAPPED_function base_UNARY, unsigned long A, unsigned long B, unsigned long LIM) { return base_UNARY(A, B) % LIM; }
// ^^^ This is my general GROUP_operation unary function

void main(int argc, char **argv) {
    unsigned long A; if (2 > argc || !(ul_ptr_from_str(&A, argv[1]))) { fprintf(stderr, "Failed to interpret '%s' as A.\n\nExiting '-1'.\n", argv[1]); exit(-1); }
    unsigned long B; if (3 > argc || !(ul_ptr_from_str(&B, argv[2]))) { fprintf(stderr, "Failed to interpret '%s' as B.\n\nExiting '-2'.\n", argv[2]); exit(-2); }
    GROUP_IDENTIFIER *group = (struct _group_identifier *) malloc(sizeof(GROUP_IDENTIFIER)); 
    if (4 > argc || !(ul_ptr_from_str(&group->LIM, argv[3]))) { fprintf(stderr, "Failed to interpret '%s' as the limit to the infinite field N.\n\nExiting '-3'.\n", argv[3]); exit(-3); }
    unsigned long SP; if (5 > argc || !(ul_ptr_from_str(&SP, argv[4]))) { fprintf(stderr, "Failed to interpret '%s' as symetry point.\n\nExiting '-4'.\n", argv[4]); exit(-4); }
    // ^^^ Process input

    unCAPPED_function field_combination = get_applicable_unCAPPED_UNARY_for(SP); // <<< Sets the standard unary from arithmetic
    char *SYMBOL = combination_SYMBOL_for_(SP);
    fprintf(stdout, "A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, A, SYMBOL, B, field_combination(A, B), LIMIT_(field_combination, A, B, group->LIM), group->LIM);
    exit(0);
}
