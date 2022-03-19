#include "maths.basic.h"
// library inclusion ^

/* Description of library:
 * This library is an extention for the 'maths.basic' library
 *
 * Two useful pointers are introduced, see line 17 & 18
 *
 *
 *
 *
 *
 *
 *
 */

unsigned long *mod_;
unsigned int *id_;
// new variables (!) ^^

typedef unsigned long (*group_operation) (ul, ul);
// new type


/* ===================== corresponds to 'string.h' (!) =========================== */
int mod_ul_parse_str(char *str, int exit_status);
/* ===================== corresponds to 'string.h' (!) =========================== */

/* ===================== corresponds to 'maths.basic.h' (!) ====================== */
int id_identity_parse_str(char *str, int exit_status);

unsigned long mod_exponentiate(ul base, ul exponent);
unsigned long mod_conditional_cap(ul result);
unsigned long mod_inverse(ul element_of_additive_group);
unsigned long mod_add(ul a, ul b);
unsigned long mod_subtract(ul a, ul b);
unsigned long mod_multiply(ul a, ul b);
unsigned long mod_divide(ul numerator, ul denominator);
unsigned long mod_polynomial(ul x, ul *coefficient, int coefficients);
// basic (in)finite field operations ^

const char *id_as_number();
const char *id_as_operation_symbol();
const char *id_as_noun();
const char *id_as_nouns();
const char *id_as_adjective();
const char *id_as_verb();
// functions that have to do with the identity element ^

int mod_eulers_criterion(ul odd_prime_p);
/* ===================== corresponds to 'maths.basic.h' (!) ====================== */

group_operation _group_operation(ui id_);
group_operation id_group_operation();
