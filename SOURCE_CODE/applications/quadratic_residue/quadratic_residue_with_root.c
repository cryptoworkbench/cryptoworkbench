/* Program description:
 * Used to print a list of quadratic residues along with their roots.
 *
 * Worked until I changed 'ul_parse_str'.
 *
 * Need to make this work again.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"

struct LL_ { struct LL_ *next; unsigned long e; unsigned long first_root; }; // << THIS I CAN ABSTRACT OUT. It is already in "factorization.h".
struct LL_ *quadratic_residue_LL = NULL; char *unparsed_str;
// global variable definitions ^^

void least_to_most_INSERT(struct LL_ **tracer, unsigned long first_root, unsigned long quadratic_residue) {
    while (*tracer && (**tracer).e <= quadratic_residue) { if ((**tracer).e == quadratic_residue) return; tracer = &(*tracer)->next; }
    struct LL_ *new_quadratic_residue = (struct LL_ *) malloc(sizeof(struct LL_)); new_quadratic_residue->e = quadratic_residue; new_quadratic_residue->first_root = first_root;
    new_quadratic_residue->next = *tracer; *tracer = new_quadratic_residue;
}

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod; unparsed_str = argv[1];
    if (!ul_parse_str(unparsed_str, mod_)) { fprintf(stderr, "Mod incorrect!\n"); exit(-1); } // <-- Make an error function specifically for this case!
    for (unsigned long i = 1; i <= mod / 2; i++) if (GCD(i, mod) == 1) least_to_most_INSERT(&quadratic_residue_LL, i, mod_multiply(i, i)); // # (1.
    printf("Quadratic residue with roots for \u2115/%lu\u2115:\n", mod);
    for (; quadratic_residue_LL; quadratic_residue_LL = quadratic_residue_LL->next)
	fprintf(stdout, "%lu^2 \u2261 %lu \u2261 %lu^2\n", quadratic_residue_LL->first_root, quadratic_residue_LL->e, mod_inverse(quadratic_residue_LL->first_root));
    return 0;
}
/* # (1. Idea for plotting elliptic curves over finite fields:
 * #	 Use Legendres symbol, Jacobis symbol, the law of quadratic reciprocity, etc. to determine if some element from a multiplicative group is a quadratic residue
 * #	 Then if you were to change the cause here from 'i <= mod / 2' to 'i < mod'
 * #     Then also add to the linked list the roots of the quadratic residues.
 * #	 You get the idea.
 */
