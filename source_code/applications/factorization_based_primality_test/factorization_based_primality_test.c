// doesn't get 'h'
#include <stdio.h>
#include "../../libraries/functional/string.basic.h"
#include "../../libraries/mathematics/factorization_methods.h"

unsigned long potential_prime;

void composite_parse_error() { fprintf(stderr, "Please provide as first argument the number to check if it is prime."); }

int main(int argc, char **argv) { potential_prime = 0;
    conditional_goodbye(n(n(error_specification(composite_parse_error, n(_ul_parse_str(&potential_prime, argv[1], -1))))));
    
    factorization_method_set(argv[2]);
    fprintf(stdout, "Using the factorization engine \"%s\" as the basis for my primality test on %lu.", _factorization_engine_description(_preferred_factorization_engine), potential_prime);
    if (!(argc < 3)) fprintf(stdout, "	(as specified by terminal argument)"); fprintf(stdout, "\n\n");

    fprintf(stdout, "%lu is ", potential_prime);
    if (!primality_test_based_on_preferred_factorization_engine(potential_prime)) fprintf(stdout, "not ");
    fprintf(stdout, "prime.\n", potential_prime);

    // for (unsigned long i = 2; i < 100; i++) if (prime(i, NULL)) printf("%lu\n", i);
    // ^ for a little prime batch
    return 0;
}
