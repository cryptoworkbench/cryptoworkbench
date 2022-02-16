// INTENDED program operation:
// Takes a LL of divisors and stretches it out by factorizing the composites.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/primality_testing.h"
#include "../../libraries/mathematics/factorization_methods.h"

struct LL_ { struct LL_ *next; unsigned long e; };
// linked list type for the triple ref technique ^

struct _crux { unsigned long *prime_factor; int *log; }; struct _crux *crux;
// program crux ^

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the composite to factorize.\n\n"); return str_not_parsable_as_number; }; }
// error functions ^

struct LL_ *unit_spawn(unsigned long divisor) { struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = divisor; ret_val->next = NULL; return ret_val; }

struct LL_ *insert(struct LL_ *last, unsigned long new_divisor) {
    struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = new_divisor;
    // create the new unit ^

    struct LL_ *next = last->next; last->next = ret_val; ret_val->next = next; return ret_val;
    // insert said unit and return at this unit ^
} // divisor_list_stretch()

struct LL_ *stretched_divisor(struct LL_ *in, struct ordered_pair divisor_pair) { in->e = divisor_pair.a;
    // update factorized sloth with smaller divisor ^

    return insert(in, divisor_pair.b);
    // insert the greater divisor and return the as-of-yet unfactorized divisor in the LL
} // divisor_list_stretch()

struct LL_ *divisor_list_stretch(struct LL_ *cursor)
{ struct ordered_pair divisor_pair = factorize(cursor->e, NULL); if (!(divisor_pair.a - 1)) return cursor; return divisor_list_stretch(stretched_divisor(cursor, divisor_pair)); }
// recursive function which stretches a LL of divisors ^

unsigned long _number_of_distinct_prime_factors(unsigned long previous_prime_factor, struct LL_ *i, unsigned long ret_val) {
    if (!(i)) return ret_val;
    if (i->e != previous_prime_factor) ret_val++;
    _number_of_distinct_prime_factors(i->e, i->next, ret_val);
}
// recurive function ^

void _number_of_distinct_prime_factors_(unsigned long last_factor, struct LL_ *cursor, unsigned long index) {
    if (!(cursor)) return;
    if (cursor->e == last_factor) crux->log[index]++;
    else { index++; crux->prime_factor[index] = cursor->e; }
    _number_of_distinct_prime_factors_(cursor->e, cursor->next, index);
}
// recurive function ^

unsigned long number_of_distinct_prime_factors(struct LL_ *divisors) {
    struct LL_ *i = divisors; unsigned long ret_val = _number_of_distinct_prime_factors(i->e, i->next, 1);
    crux = (struct _crux *) malloc(sizeof(struct _crux));
    crux->prime_factor = (unsigned long *) malloc(sizeof(unsigned long) * ret_val);
    crux->log = (int *) malloc(sizeof(int) * ret_val); for (int i = 0; i < ret_val; i++) crux->log[i] = 1;
    crux->prime_factor[0] = divisors->e; _number_of_distinct_prime_factors_(crux->prime_factor[0], divisors->next, 0);
    return ret_val;
}

int main(int argc, char **argv) { unsigned long composite; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &composite)) error_message(error_selector(1), -1);
    // interpret composite ^
    
    char *ptr = argv[2]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) { fprintf(stderr, "Failed to interpret '%s' from ", ptr);
	if (argv[2]) fprintf(stderr, "terminal argument"); else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[2]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); } }
    fprintf(stderr, "Interpreted '%s' from ", _preferred_factorization_ENGINE_description()); if (argv[2]) fprintf(stderr, "terminal argument"); else fprintf(stderr, "the global preferences file"); fprintf(stderr, ".\n");
    // interpret and set factorization engine ^

    struct LL_ *divisors = unit_spawn(composite);
    struct LL_ *tail = divisor_list_stretch(divisors);
    fprintf(stdout, "%lu = ", composite);

    unsigned long number_of_distinct_factors = number_of_distinct_prime_factors(divisors);
    // printf("ret\n");
    for (unsigned long i = 0; i < number_of_distinct_factors - 1; i++) printf("%lu^%lu * ", crux->prime_factor[i], crux->log[i]);
    printf("%lu^%lu\n", crux->prime_factor[number_of_distinct_factors - 1], crux->log[number_of_distinct_factors - 1]);
    return 0;
}
