/* ABSTRACT:
 * This example code examplifies how to perfectly model the mental view of a modular group as a set with it's corresponding unary group operation based on wether it is an additive
 * or a multiplicative group.
 *
 * It does so with the structure called "GROUP_IDENTIFIER".
 *
 * AMBITIONS:
 * Make subgroup_generator function in this manner.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/LOGBOOK_library.h"
#include "../../libraries/mathematics/group_operations.h"

unsigned long _BASIC_addition(unsigned long A, unsigned long B) { return A + B; }
unsigned long _BASIC_multiplication(unsigned long A, unsigned long B) { return A * B; }
// ^^^ First I define two functions for the BASIC operations.

typedef unsigned long (*BASIC_operation_PTR) (unsigned long, unsigned long);
// ^^^ Then I can define a function pointer type for pointing to either one of these above functions that perform the BASIC operations.

BASIC_operation_PTR BASIC_operation_BASED_ON_(unsigned long ID) { if (ID == 0) return &_BASIC_addition; else if (ID == 1) return &_BASIC_multiplication; }
// ^^^ And then I can define a function which returns a pointer to either one of the two BASIC operation functions depending (specified) by ID.

unsigned long GROUP_operation(unsigned long A, unsigned long B, BASIC_operation_PTR BASIC_operation, unsigned long CAP) { return BASIC_operation(A, B) % CAP; }
// ^^^ This is my general GROUP_operation unary function

struct GROUP_IDENTIFIER { MODULAR_operation_PTR operation; unsigned long CAP; };
// ^^^ Finally we are here

void main(int argc, char **argv) {
    unsigned long A; if (2 > argc || !(ul_ptr_from_str(&A, argv[1]))) { fprintf(stderr, "Failed to interpret '%s' as A.\n\nExiting '-1'.\n", argv[1]); exit(-1); }
    unsigned long B; if (3 > argc || !(ul_ptr_from_str(&B, argv[2]))) { fprintf(stderr, "Failed to interpret '%s' as B.\n\nExiting '-2'.\n", argv[2]); exit(-2); }
    // ^^^ Process A & B from command-line arguments

    struct GROUP_IDENTIFIER *group = (struct GROUP_IDENTIFIER *) malloc(sizeof(struct GROUP_IDENTIFIER));
    if (4 > argc || !(ul_ptr_from_str(&group->CAP, argv[3]))) { fprintf(stderr, "Failed to interpret '%s' as field CAP.\n\nExiting '-3'.\n", argv[3]); exit(-3); }
    unsigned long ID; if (5 > argc || !(ul_ptr_from_str(&ID, argv[4]))) { fprintf(stderr, "Failed to interpret '%s' as symetry point.\n\nExiting '-4'.\n", argv[4]); exit(-4); }
    // ^^^ Process remaining input from command-line arguments

    BASIC_operation_PTR BASIC_operation = BASIC_operation_BASED_ON_(ID); // <<< Sets the usual operation
    char *operation_symbol = OPERATION_SYMBOL(ID);
    fprintf(stdout, "A %s B \u2261 %lu %s %lu \u2261 %lu \u2261 %lu (%% %lu)\n", operation_symbol, A, operation_symbol, B, BASIC_operation(A, B), GROUP_operation(A, B, BASIC_operation, group->CAP), group->CAP);
    exit(0);
}
