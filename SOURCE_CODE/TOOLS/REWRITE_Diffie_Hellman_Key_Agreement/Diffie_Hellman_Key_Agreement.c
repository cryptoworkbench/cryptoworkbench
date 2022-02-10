/* This will be a rewrite of ../Diffie_Hellman_Key_Agreement
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

struct LL_ { unsigned long val; struct LL_ *next; };
// type definitions ^

char *unparsed_arg;
// global variables ^

void mod_ERROR() { fprintf(stderr, "\n%s is not parsable as a number.\n\n", unparsed_arg); free(mod_); }
_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: return mod_ERROR; }; }
// error functions ^

int main(int argc, char **argv) { mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg = argv[1];
    if (2 > argc || !str_represents_ul(unparsed_arg, mod_)) error_message(error_selector(1), -1);
    printf("Mod: %lu\n", *mod_);
    free(mod_); return 0;
}
