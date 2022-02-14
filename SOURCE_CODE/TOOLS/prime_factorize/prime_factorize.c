// INTENDED program operation:
// It interprets the intended factorization method from an external preferences file instead of from 'argv[1]'.
// Instead 'argv[1]' will be used for the composite, which makes more sense.
//
// The external file's specification of what factorization engine to use can be overruled by 'argv[2]' though.
// If 'argv[2]' is not a valid signification of what factorization engine to use, the default (externally specified!) factorization engine is used.
//
// When the program is ran for the first time it asks what factorization engine should be preferred and this is automatically saved to the external preferences file.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/primality_testing.h"
#include "../../libraries/mathematics/factorization_methods.h"

struct LL_ { struct LL_ *next; unsigned long e; };
// linked list type for the triple ref technique ^

_error_selector error_selector(int SELECTOR) { switch (SELECTOR) { case 1: fprintf(stderr, "Please provide as first argument the composite to factorize.\n\n"); return str_not_parsable_as_number; }; }
// error functions ^

void insert(struct LL_ ***tracer_location, unsigned long new_ulong)
{ struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; *tracer_location = (struct LL_ **) **tracer_location; }

struct LL_ ***factorize(unsigned long composite) {
    if (factorize
    insert(divisor_CHANNEL, composite);
}

int main(int argc, char **argv) { unsigned long composite; unparsed_arg = argv[1];
    if (!str_represents_ul(unparsed_arg, &composite)) error_message(error_selector(1), -1);
    // interpret composite ^
    
    char *ptr = argv[2]; if (!ptr) ptr = query_preferences_file();
    if (!(_preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(ptr)))) { fprintf(stderr, "Failed to interpret '%s' from ", ptr);
	if (argv[2]) fprintf(stderr, "terminal argument"); else fprintf(stderr, "global preferences file '%s'", _REPORT_preferred_factorization_engine_file()); fprintf(stderr, ".\n\n");
	char *UPDATE_VALUE; _preferred_factorization_ENGINE = factorization_method(SELECTOR_from_str_representing_factorization_method(UPDATE_VALUE = STDIN_factorization_engine(ptr)));
	if (!argv[2]) { write_to_preferences_file(UPDATE_VALUE, fopen(_REPORT_preferred_factorization_engine_file(), "w")); fprintf(stdout, "Updated preferences file.\n\n"); } }
    fprintf(stdout, "Interpreted '%s' from ", _preferred_factorization_ENGINE_description()); if (argv[2]) fprintf(stdout, "terminal argument"); else fprintf(stdout, "the global preferences file"); fprintf(stdout, ".\n");
    // interpret and set factorization engine ^

    struct VOID_ptr_ptr_PAIR divisors_of_original_number_ptr_pair = initialize_CHANNEL_ptr_pair();
    insert((struct LL_ ***) &divisors_of_original_number_ptr_pair.iterator, composite);
    return 0;
}
