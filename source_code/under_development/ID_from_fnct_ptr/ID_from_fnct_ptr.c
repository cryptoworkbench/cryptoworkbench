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

/*
 * cap = 0 = <N / 0 N> == N (divide by 0 means do not divide at all)
 * cap = 1 = <N / 1 N> == 0
 * cap = 2 = <N / 2 N> == 0, 1
 * cap = 3 = <N / 3 N> == 0, 1, 2
 * ...
 *
 * ...
 * 
 * ...
 *
 * Etcetera
 */

void main(int argc, char **argv) {
    unsigned long A; if (2 > argc || !(ul_ptr_from_str(&A, argv[1]))) { fprintf(stderr, "Failed to interpret '%s' as A.\n\nExiting '-1'.\n", argv[1]); exit(-1); }
    unsigned long B; if (3 > argc || !(ul_ptr_from_str(&B, argv[2]))) { fprintf(stderr, "Failed to interpret '%s' as B.\n\nExiting '-2'.\n", argv[2]); exit(-2); }
    // ^^^ Process A & B

    unsigned long group_CAP; if (4 > argc || !(ul_ptr_from_str(&group_CAP, argv[3])))
    { fprintf(stderr, "Failed to interpret '%s' as the limit to the infinite field N.\n\nExiting '-3'.\n", argv[3]); exit(-3); }
    // ^^ Process group_CAP
    
    unsigned long Symetry_Point; if (5 > argc || !(ul_ptr_from_str(&Symetry_Point, argv[4])))
    { fprintf(stderr, "Failed to interpret '%s' as symetry point.\n\nExiting '-4'.\n", argv[4]); exit(-4); }
    // ^^^ Identify to my self the values that I should work with

    fprintf(stdout, "A: %lu\n", A);
    fprintf(stdout, "B: %lu\n\n", B);
    // ^^^ Identify to my user the values that I have identified to myself

    unsigned long UNCAPPED_result = N_field_combine(0, A, B, Symetry_Point);
    unsigned long CAPPED_result = N_field_combine(group_CAP, A, B, Symetry_Point);
    char *SYMBOL = combination_SYMBOL_for_(Symetry_Point);
    fprintf(stdout, "A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", SYMBOL, A, SYMBOL, B, UNCAPPED_result, CAPPED_result, group_CAP);
    exit(0);
}
