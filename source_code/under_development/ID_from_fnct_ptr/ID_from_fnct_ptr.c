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
#include "../../libraries/mathematics/group_operations.h"

// ##### Equivalent to "group_prams" ###==>
typedef struct _group_identifier { CAPPED_field_combination UNARY; unsigned long CAP; } GROUP_IDENTIFIER;

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
    function unCAPPED_field_combi = get_applicable_field_combination(SP);
    CAPPED_field_combination CAPPED_field_combi = get_applicable_CAPPED_field_combination(SP);
    // ^^^ Neccessary preperation before we can use library

    printf("A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, a, SYMBOL, b, unCAPPED_field_combi(a, b), CAPPED_field_combi(a, b, group->CAP), group->CAP);
    // ^^^ We use "unCAPPED_field_combi" function pointers for normal arithmetic combinations (but not yet higher than second-degree combinations (== multiplications))
    // ^^^ And we use "CAPPED_field_combi" function pointers for modular arithmetic combinations (also limited to second-degree combinations, inspect code).

    printf("A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, a, SYMBOL, b, unCAPPED_field_combi(a, b), RESTRICT(unCAPPED_field_combi, a, b, group->CAP), group->CAP);
    // ^^^ We can even do this

    exit(0);
}
