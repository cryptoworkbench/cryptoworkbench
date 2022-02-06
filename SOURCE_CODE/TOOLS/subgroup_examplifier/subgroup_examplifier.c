#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"
char *unparsed_ARG; // <-- keep this pointer equal to the pointer that points to the as-of-yet unparsed argument

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_ARG); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_ARG); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }

int main(int ARGc, char **ARGv) { unsigned long *mod = (unsigned long *) malloc(sizeof(unsigned long)); mod_ = mod;
    unparsed_ARG = ARGv[1]; if (!str_represents_ul(unparsed_ARG, mod)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int));
    unparsed_ARG = ARGv[2]; if (10 == (*SELECTOR = identity_SELECTOR(unparsed_ARG))) error_message(arg_error(2), -2); unsigned long *id = (unsigned long *) malloc(sizeof(unsigned long)); id_ = id;
    *id_ = identity_(*SELECTOR);
    mod_group_operation GF_combi = id_finite_group_operation();
    printf("%lu %s %lu \u2261 %lu (%% %lu)\n", 2, id_as_operation_symbol(), 5, GF_combi(2, 5), *mod);
    return 0;
}
