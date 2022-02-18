/* Program description:
 * Prints a list of quadratic residues.
 *
 * Should do.
 *
 * I think it works.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"

struct LL_ { struct LL_ *next; unsigned long e; }; // << THIS I CAN ABSTRACT OUT. It is already in "factorization.h".
struct LL_ *quadratic_residue_LL = NULL; char *unparsed_arg;
// global variable definitions ^^

void least_to_most_INSERT(struct LL_ **trt, unsigned long quadratic_residue) {
    struct LL_ *new_quadratic_residue = (struct LL_ *) malloc(sizeof(struct LL_)); new_quadratic_residue->e = quadratic_residue; new_quadratic_residue->next = NULL;
    struct LL_ **tracer = trt; while (*tracer && (!( (*tracer)->e > quadratic_residue))) { if ((*tracer)->e == quadratic_residue) return; tracer = &(*tracer)->next; }
    new_quadratic_residue->next = *tracer; *tracer = new_quadratic_residue;
}

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, mod_)) { fprintf(stderr, "Mod incorrect!\n"); exit(-1); } // <-- Make an error function specifically for this case!
    for (unsigned long i = 1; i <= mod / 2; i++) least_to_most_INSERT(&quadratic_residue_LL, mod_multiply(i, i));
    printf("\nQuadratic residue in \u2115/%lu\u2115:\n", mod);
    for (; quadratic_residue_LL; quadratic_residue_LL = quadratic_residue_LL->next) fprintf(stdout, "%lu\n", quadratic_residue_LL->e);
    return 0;
}
