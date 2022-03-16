// Program description:
// Factorizes a number to it's bare prime divisors.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/factorization_methods.h"

unsigned long number;

void number_failed_to_parse() { fprintf(stderr, "Please provide as first argument the number to factorize. '%s' is not a number!", (*argv_location)[1]); }
// error functions ^

int main(int argc, char **argv) { number = ADDITIVE_IDENTITY; argv_location = &argv;
    conditional_goodbye(n(n(error_specification(number_failed_to_parse, n(ul_parse_str(&number, argv[1], -1))))));
    _preferred_factorization_engine = factorization_method_retrieve(argv[2]); // set this global variable because PRIME_FACTORIZATION() needs it <--
    PRIME_FACTORIZATION_free(PRIME_FACTORIZATION_print(PRIME_FACTORIZATION(number))); // calculate the prime factorization, print the prime factorization, and free the memory that was involved in the operations <--
    return 0;
}
