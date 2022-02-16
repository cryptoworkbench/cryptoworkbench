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

// struct _crux *crux;
// global variable declarations ^

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

unsigned long _number_of_distinct_prime_factors(unsigned long previous_prime_factor, struct LL_ *i, unsigned long ret_val)
{ if (!(i)) return ret_val; if (i->e != previous_prime_factor) ret_val++; _number_of_distinct_prime_factors(i->e, i->next, ret_val); }
// recurive function ^

void crux_setup(struct _crux *crux, unsigned long last_factor, struct LL_ *cursor, unsigned long index)
{ if (!(cursor)) return; if (cursor->e == last_factor) crux->log[index]++; else { index++; crux->prime_factor[index] = cursor->e; } crux_setup(crux, cursor->e, cursor->next, index); }
// recurive function ^

struct _crux *initialize_crux(int length)
{
    struct _crux *ret_val = (struct _crux *) malloc(sizeof(struct _crux)); ret_val->prime_factor = (unsigned long *) malloc(sizeof(unsigned long) * length);
    ret_val->log = (int *) malloc(sizeof(int) * length); for (int i = 0; i < length; i++) ret_val->log[i] = 1; ret_val->entries = length; return ret_val;
}//recursive function ^

struct _crux *crux_prepare(unsigned long length, struct LL_ *divisors)
{
    struct _crux *ret_val = initialize_crux(length);
    ret_val->prime_factor[0] = divisors->e;
    crux_setup(ret_val, ret_val->prime_factor[0], divisors->next, 0); return ret_val;
} // a recursive function which initializes the table

void _RESULT(struct _crux *crux, int index)
{ fprintf(stdout, "%lu^%lu", crux->prime_factor[index], crux->log[index]); index++; if (index == crux->entries) return; fprintf(stdout, " * "); _RESULT(crux, index); }
void RESULT(struct _crux *crux, unsigned long composite) { fprintf(stdout, "%lu = ", composite); _RESULT(crux, 0); fprintf(stdout, "\n"); }
// a recursive do-while function which prints out the _RESULT (^^) and a wrapper for this function (^)

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

    struct _crux *crux = crux_prepare(_number_of_distinct_prime_factors(divisors->e, divisors->next, 1), divisors);
    RESULT(crux, composite);
    return 0;
}
