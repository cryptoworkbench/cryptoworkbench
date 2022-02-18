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

struct LL_ { struct LL_ *next; unsigned long first_positive_root_in_Z; unsigned long quadratic_residue; }; // first_positive_root_in_Z
struct LL_ *quadratic_residue_LL = NULL; char *unparsed_arg;
// global variable definitions ^^

void least_to_most_INSERT(struct LL_ **trt, unsigned long quadratic_residue, unsigned long least_root_in_N) {
    struct LL_ *new_quadratic_residue = (struct LL_ *) malloc(sizeof(struct LL_)); new_quadratic_residue->quadratic_residue = quadratic_residue;
    new_quadratic_residue->first_positive_root_in_Z = least_root_in_N; new_quadratic_residue->next = NULL; struct LL_ **tracer = trt;
    while (*tracer && (**tracer).quadratic_residue <= quadratic_residue) { if ((**tracer).quadratic_residue == quadratic_residue) return; tracer = &(**tracer).next; }
    new_quadratic_residue->next = *tracer; *tracer = new_quadratic_residue;
}

int main(int argc, char **argv) { unsigned long mod; mod_ = &mod; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, mod_)) { fprintf(stderr, "Mod incorrect!\n"); exit(-1); } // <-- Make an error function specifically for this case!
    for (unsigned long i = 1; i <= mod / 2; i++) if (GCD(i, mod) == 1) least_to_most_INSERT(&quadratic_residue_LL, mod_multiply(i, i), i); // # (1.
    fprintf(stdout, "Roots of quadratic residue in \u2115/%lu\u2115:\n", mod);
    for (; quadratic_residue_LL; quadratic_residue_LL = quadratic_residue_LL->next)
	fprintf(stdout, "%lu^2 \u2261 %lu^2 \u2261 %lu\n",
		quadratic_residue_LL->first_positive_root_in_Z,
		mod_inverse(quadratic_residue_LL->first_positive_root_in_Z),
		quadratic_residue_LL->quadratic_residue
		);
    return 0;
}
/* # (1. Idea for plotting elliptic curves over finite fields:
 * #	 Use Legendres symbol, Jacobis symbol, the law of quadratic reciprocity, etc. to determine if some element from a multiplicative group is a quadratic residue
 * #	 Then if you were to change the cause here from 'i <= mod / 2' to 'i < mod'
 * #     Then also add to the linked list the roots of the quadratic residues.
 * #	 You get the idea.
 */
