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

unsigned long ordinator(unsigned long a, unsigned long b) { return a + b; }
unsigned long CAPPED_ordinator(unsigned long a, unsigned long b, unsigned long CAP) { return ordinator(a, b) % CAP; }
// ^^^ Define the ordinating addition operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic respectively

unsigned long ordinated(unsigned long a, unsigned long b) { return a * b; }
unsigned long CAPPED_ordinated(unsigned long a, unsigned long b, unsigned long CAP) { return ordinated(a, b) % CAP; }
// ^^^ Define the ordinated multiplication operations for 'regular' (not CAPPED) and 'modular' (CAPPED) arithmetic, also respectively

typedef unsigned long (*function) (unsigned long, unsigned long);
function get_applicable_function_for_(unsigned long SP) { if (SP == 0) return &ordinator; else if (SP == 1) return &ordinated; }
// ^^^ Define a function that will get you the right ordinator (== addition operation)

typedef unsigned long (*CAPPED_function) (unsigned long, unsigned long, unsigned long);
CAPPED_function get_applicable_CAPPED_function_for_(unsigned long SP) { if (SP == 0) return &CAPPED_ordinator; else if (SP == 1) return &CAPPED_ordinated; }
// ^^^ Define a function that will get you the right ordinated (== multiplication operation)

unsigned long RESTRICT(function base_UNARY, unsigned long a, unsigned long b, unsigned long CAP) { return base_UNARY(a, b) % CAP; }
// ^^^ This is my general GROUP_operation unary function

// ##### Equivalent to "group_prams" ###==>
typedef struct _group_identifier { CAPPED_function UNARY; unsigned long CAP; } GROUP_IDENTIFIER;

void main(int argc, char **argv) {
    unsigned long a; if (2 > argc || !(ul_ptr_from_str(&a, argv[1]))) { fprintf(stderr, "Failed to interpret '%s' as A.\n\nExiting '-1'.\n", argv[1]); exit(-1); }
    unsigned long b; if (3 > argc || !(ul_ptr_from_str(&b, argv[2]))) { fprintf(stderr, "Failed to interpret '%s' as b.\n\nExiting '-2'.\n", argv[2]); exit(-2); }
    GROUP_IDENTIFIER *group = (struct _group_identifier *) malloc(sizeof(GROUP_IDENTIFIER)); 
    if (4 > argc || !(ul_ptr_from_str(&group->CAP, argv[3]))) { fprintf(stderr, "Failed to interpret '%s' as the limit to the infinite field N.\n\nExiting '-3'.\n", argv[3]); exit(-3); }
    unsigned long SP; if (5 > argc || !(ul_ptr_from_str(&SP, argv[4]))) { fprintf(stderr, "Failed to interpret '%s' as symetry point.\n\nExiting '-4'.\n", argv[4]); exit(-4); }
    // ^^^ Identify to my self the values that I should work with

    fprintf(stdout, "A: %lu\n", a);
    fprintf(stdout, "B: %lu\n\n", b);
    // ^^^ Identify to my user the values that I have identifier to myself

    char *SYMBOL = combination_SYMBOL_for_(SP);
    function unCAPPED_field_combi = get_applicable_function_for_(SP);
    CAPPED_function CAPPED_field_combi = get_applicable_CAPPED_function_for_(SP);
    // ^^^ Neccessary preperation before we can use library

    printf("A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, a, SYMBOL, b, unCAPPED_field_combi(a, b), CAPPED_field_combi(a, b, group->CAP), group->CAP);
    // ^^^ We use "unCAPPED_field_combi" function pointers for normal arithmetic combinations (but not yet higher than second-degree combinations (== multiplications))
    // ^^^ And we use "CAPPED_field_combi" function pointers for modular arithmetic combinations (also limited to second-degree combinations, inspect code).

    printf("A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, a, SYMBOL, b, unCAPPED_field_combi(a, b), RESTRICT(unCAPPED_field_combi, a, b, group->CAP), group->CAP);
    // ^^^ We can even do this

    exit(0);
}
