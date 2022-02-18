// Program description:
// Factorizes a number to it's bare prime divisors.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the number to factorize.\n\n"); return str_not_parsable_as_number; }; }
// error functions ^

int main(int argc, char **argv) { unsigned long number; unparsed_arg = argv[1]; // str_not_parsable_as_number() depends on this variable being set <--
    if (!str_represents_ul(unparsed_arg, &number)) error_message(error_selector(1), -1); // interpret number to factorize <--
    _preferred_factorization_engine = factorization_method_retrieve(argv[2]); // set this global variable because PRIME_FACTORIZATION() needs it <--
    PRIME_FACTORIZATION_free(PRIME_FACTORIZATION_print(PRIME_FACTORIZATION(number))); // calculate the prime factorization, print the prime factorization, and free the memory that was involved in the operations <--
    return 0;
}
