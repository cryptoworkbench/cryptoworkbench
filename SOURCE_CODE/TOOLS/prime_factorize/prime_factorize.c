// INTENDED program operation:
// Takes a LL of divisors and stretches it out by factorizing the composites.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/primality_testing.h"
#include "../../libraries/mathematics/factorization_methods.h"

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the number to factorize.\n\n"); return str_not_parsable_as_number; }; }
// error functions ^

int main(int argc, char **argv) { unsigned long number; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &number)) error_message(error_selector(1), -1);

    _preferred_factorization_ENGINE = factorization_method_retrieve(argv[2]);

    struct _PRIME_FACTORIZATION *prime_factorization_of_number = PRIME_FACTORIZATION(number);
    PRIME_FACTORIZATION_free(PRIME_FACTORIZATION_print(prime_factorization_of_number));
    return 0;
}
