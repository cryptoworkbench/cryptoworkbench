/* Development progress:
 * This will be a rewrite of 'DEPRECATED_subgroup_examplifier/subgroup_examplifier.c'
 *
 * So far, so good.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"
char *unparsed_arg; // <-- keep this pointer equal to the pointer that points to the as-of-yet unparsed argument

void subgroup(unsigned long generator) { printf("<%lu> = {", generator); unsigned long e = generator;
    do {
	printf("%lu", e);
	e = GF_combi(e, generator);
	if (e == generator) break;
	printf(", ");
    } while (1); printf("}\n");
}

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }

int main(int argc, char **argv) { unsigned long *mod = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, mod)) error_message(arg_error(1), -1); mod_ = mod; int *SELECTOR = (int *) malloc(sizeof(int)); unparsed_arg = argv[2];
    if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg))) error_message(arg_error(2), -2); unsigned long *id = (unsigned long *) malloc(sizeof(unsigned long)); *id = identity_(*SELECTOR); id_ = id;
    // ^ process terminal arguments and prepare library variables

    for (int i = *id_; i < *mod_; i++) if (*id_ == ADDITIVE_IDENTITY || GCD(i, *mod_) == 1) subgroup(i);
    return 0;
}
