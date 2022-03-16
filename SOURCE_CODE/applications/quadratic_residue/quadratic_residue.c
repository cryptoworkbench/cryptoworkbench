/* Program description:
 * Print the complete list of quadratic residues.
 *
 * Can be verified using 'subgroup_examplifier':
 * Use a horizontal offset of 2 and the first column to the right of the leftmost column* will contain only squares.
 *
 * * the column where the generated subgroup begins.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/functional/triple_ref_pointers.h"

struct LL_ { struct LL_ *next; unsigned long e; }; struct LL_ *quadratic_residue_LL = NULL; unsigned long mod;
// global variable definitions ^^

void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument the modulus of the multiplicative group.\n\nA.k.a. specify '\u2115/\u2115?*'"); }

void least_to_most_INSERT(struct LL_ **tracer, unsigned long quadratic_residue) {
    while (*tracer && (**tracer).e <= quadratic_residue) { if ((**tracer).e == quadratic_residue) return; tracer = &(*tracer)->next; }
    struct LL_ *new_quadratic_residue = (struct LL_ *) malloc(sizeof(struct LL_)); new_quadratic_residue->e = quadratic_residue;
    new_quadratic_residue->next = *tracer; *tracer = new_quadratic_residue;
}

int main(int argc, char **argv) { mod = ADDITIVE_IDENTITY;
    conditional_goodbye(n(n(error_specification(mod_failed_to_parse, n(ul_parse_str(&mod, argv[1], -1)))))); mod_ = &mod;
    for (unsigned long i = 1; i <= mod / 2; i++) if (GCD(i, mod) == 1) least_to_most_INSERT(&quadratic_residue_LL, mod_multiply(i, i));
    fprintf(stdout, "Quadratic residue in \u2115/%lu\u2115:\n", mod);
    for (; quadratic_residue_LL; quadratic_residue_LL = quadratic_residue_LL->next) fprintf(stdout, "%lu\n", quadratic_residue_LL->e);
    return 0;
}
