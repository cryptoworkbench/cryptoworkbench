#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"
char *unparsed_arg; // <-- keep this pointer equal to the pointer that points to the as-of-yet unparsed argument

void identity_error() { fprintf(stderr, "\nFailed to understand '%s' as the identity element of any additive group (which is always zero) or any multiplicative group (which is always one).\n\n", unparsed_arg); }
void mod_error() { fprintf(stderr, "\nFailed to understand '%s' as the modulus value of any group to examplify.\n\n", unparsed_arg); }
_error_selector arg_error(int SELECTOR) { switch(SELECTOR) { case 1: return mod_error; case 2: return identity_error; }; }

int main(int argc, char **argv) { unsigned long *mod = (unsigned long *) malloc(sizeof(unsigned long)); mod_ = mod;
    unparsed_arg = argv[1]; if (!str_represents_ul(unparsed_arg, mod)) error_message(arg_error(1), -1); int *SELECTOR = (int *) malloc(sizeof(int));
    unparsed_arg = argv[2]; if (10 == (*SELECTOR = identity_SELECTOR(unparsed_arg))) error_message(arg_error(2), -2); unsigned long *id = (unsigned long *) malloc(sizeof(unsigned long)); id_ = id;
    // ^ Acquire information about what group to work with

    *id_ = identity_(*SELECTOR);
    // ^ Set the global function pointer which always points to the function which performs the right mathematics

    printf("%lu %s %lu \u2261 %lu (%% %lu)\n", 2, id_as_operation_symbol(), 5, GF_combi(2, 5), *mod);
    *id_ = 0;
    printf("%lu %s %lu \u2261 %lu (%% %lu)\n", 2, id_as_operation_symbol(), 5, GF_combi(2, 5), *mod);
    return 0;
}
