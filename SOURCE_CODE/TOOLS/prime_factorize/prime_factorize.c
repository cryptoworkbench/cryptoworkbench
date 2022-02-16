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

struct _crux { unsigned long *prime_factor; int *log; int entries; };
// program crux ^

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the composite to factorize.\n\n"); return str_not_parsable_as_number; }; }
// error functions ^

struct LL_ *unit_spawn(unsigned long divisor) // NON-recursive <--
{ struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = divisor; ret_val->next = NULL; return ret_val; }

struct LL_ *insert(struct LL_ *last, unsigned long new_divisor) // NON-recursive <--
{ struct LL_ *ret_val = (struct LL_ *) malloc(sizeof(struct LL_)); ret_val->e = new_divisor; struct LL_ *next = last->next; last->next = ret_val; ret_val->next = next; return ret_val; }

struct LL_ *stretched_divisor(struct LL_ *in, struct ordered_pair divisor_pair) // NON-recursive <--
{ in->e = divisor_pair.a; return insert(in, divisor_pair.b); }

struct LL_ *divisor_list_stretch(struct LL_ *i)
{ struct ordered_pair divisor_pair = factorize(i->e, NULL); if (!(divisor_pair.a - 1)) return i; return divisor_list_stretch(stretched_divisor(i, divisor_pair)); }
// recursive function yielding the list containing the prime factorization ^

unsigned long distinct_prime_factors(unsigned long previous_prime_factor, struct LL_ *i, unsigned long ret_val)
{ if (!(i)) return ret_val; if (i->e != previous_prime_factor) ret_val++; distinct_prime_factors(i->e, i->next, ret_val); }
// recursive function which counts the number of distinct prime factors said (^^) list ^

void associative_array_setup(struct _crux *crux, unsigned long last_factor, struct LL_ *i, unsigned long index)
{ if (!(i)) return; if (i->e == last_factor) crux->log[index]++; else { index++; crux->prime_factor[index] = i->e; } associative_array_setup(crux, i->e, i->next, index); }
// recursive function which set's up the program's crux (which holds the associative array)

struct _crux *allocate_crux(int number_of_distinct_prime_factors) {
    struct _crux *ret_val = (struct _crux *) malloc(sizeof(struct _crux)); ret_val->prime_factor = (unsigned long *) malloc(sizeof(unsigned long) * number_of_distinct_prime_factors);
    ret_val->log = (int *) malloc(sizeof(int) * number_of_distinct_prime_factors);
    for (int i = 0; i < number_of_distinct_prime_factors; i++) ret_val->log[i] = 1; ret_val->entries = number_of_distinct_prime_factors;
    return ret_val;
} void CRUX_free(struct _crux *crux) { free(crux->log); free(crux->prime_factor); free(crux); }
// funct^ons for allocation or destruction of a program's crux ^

struct _crux *CRUX_initialize(unsigned long number_of_distinct_prime_factors, struct LL_ *divisors) // NON-recursive wrapper function <--
{
    struct _crux *ret_val = allocate_crux(number_of_distinct_prime_factors); ret_val->prime_factor[0] = divisors->e;
    associative_array_setup(ret_val, ret_val->prime_factor[0], divisors->next, 0); return ret_val;
}
// '_crux' functions dealing with allocation and free'ing

struct _crux *_CRUX_printout(struct _crux *crux, int index) // recursive function <--
{ fprintf(stdout, "%lu^%lu", crux->prime_factor[index], crux->log[index]); index++; if (index == crux->entries) return crux; fprintf(stdout, " * "); return _CRUX_printout(crux, index); }

struct _crux *CRUX_printout(struct _crux *crux, unsigned long composite) // wrapper for the above recursive function <--
{ fprintf(stdout, "%lu = ", composite); _CRUX_printout(crux, 0); fprintf(stdout, "\n"); return crux; }

int main(int argc, char **argv) { unsigned long composite; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &composite)) error_message(error_selector(1), -1);
    char *ptr = argv[2]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) { fprintf(stderr, "Failed to interpret '%s' from ", ptr);
	if (argv[2]) fprintf(stderr, "terminal argument"); else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[2]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); } }
    fprintf(stderr, "Interpreted '%s' from ", _preferred_factorization_ENGINE_description()); if (argv[2]) fprintf(stderr, "terminal argument"); else fprintf(stderr, "the global preferences file"); fprintf(stderr, ".\n");
    // interpret composite and factorization engine ^

    struct LL_ *divisors = unit_spawn(composite);
    struct LL_ *tail = divisor_list_stretch(divisors);

    CRUX_free(CRUX_printout(CRUX_initialize(distinct_prime_factors(divisors->e, divisors->next, 1), divisors), composite));
    return 0;
}
