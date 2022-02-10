/* This will be a rewrite of ../Diffie_Hellman_Key_Agreement
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/universal_group_library.h"

struct LL_ { unsigned long e; struct LL_ *next; };
// type definitions ^

unsigned long group_cardinality_;
// global variables ^

void RESULT_ERROR() { fprintf(stderr, "\nAlice and Bob did not derive the same shared secret.\n\n"); }
void coprime_ERROR() { fprintf(stderr, "\nprovide instead of '%s' a number coprime to %lu.\n\n", unparsed_arg, *mod_); free(mod_); }
_error_selector error_selector(int SELECTOR) {
    switch (SELECTOR) {
	case 1: fprintf(stdout, "Please provide as first argument a modulus specifying the multiplicative group to use.\n\n"); free(mod_); return str_not_parsable_as_number; 
	case 2: fprintf(stdout, "Please provide as second argument an element within \u2115/%s\u2115* to perform modular exponentiation upon (preferably a generator).\n\n", argvv[1]); return coprime_ERROR;
	case 3: fprintf(stdout, "Please provide as third argument Bob's secret key.\n\n"); return coprime_ERROR;
	case 4: fprintf(stdout, "Please provide as fourth argument Alice's secret key.\n\n"); return coprime_ERROR;
	case 5: return RESULT_ERROR;
    };
} // error functions ^

void INSERT(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv) { FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { INSERT((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
    return element_CHANNEL_ptr_pair;
}

unsigned long group_cardinality_;
int main(int argc, char **argv) { argvv = argv; mod_ = (unsigned long *) malloc(sizeof(unsigned long)); unparsed_arg = argv[1];
    if (2 > argc || !str_represents_ul(unparsed_arg, mod_)) error_message(error_selector(1), -1); unparsed_arg = argv[2]; unsigned long generator;
    if (3 > argc || !str_represents_ul(unparsed_arg, &generator) || !coprime(generator, *mod_)) error_message(error_selector(2), -2); unparsed_arg = argv[3]; unsigned long priv_bob;
    if (4 > argc || !str_represents_ul(unparsed_arg, &priv_bob) || !coprime(priv_bob, *mod_)) error_message(error_selector(3), -3); unparsed_arg = argv[4]; unsigned long priv_alice;
    if (5 > argc || !str_represents_ul(unparsed_arg, &priv_alice) || !coprime(priv_alice, *mod_)) error_message(error_selector(4), -4);
    // take in needed variables ^

    group_cardinality_ = totient(*mod_); struct ordered_pair iso = _isomorphism(); do { iso.b = mod_multiply(iso.b, generator); iso.a++; if (iso.b == MULTIPLICATIVE_IDENTITY) break; } while (1);
    if (iso.a != group_cardinality_) {
	fprintf(stderr, "WARNING: %s only generates 1/%lu of \u2115/%s\u2115*  (tot(%s) / %lu = %lu / %lu = %lu), continue? (ans 'n' of 'N' for exit): ",
		argv[2],
		group_cardinality_ / iso.a,
		argv[1],
		argv[1],
		group_cardinality_ / iso.a,
		group_cardinality_,
		group_cardinality_ / iso.a,
		iso.a); // < figure out UNICODE symbol for totient
	char y_or_n; fscanf(stdin, " %c", &y_or_n); if (y_or_n == 'n' || y_or_n == 'N') exit(-1);
    } // detect when the permutation basis does not cover the group ^
    fprintf(stdout, "Alice and Bob promise each other to use %s as modulus	(a.k.a. they deploy the group multiplicative group \u2115/%s\u2115*).\n", argv[1], argv[1]);
    // fprintf(stdout, "They also both promise '%lu' as base for their modular exponentiation.\n", argv[1], mod_conditional_field_cap(generator) , argv[1]);

    fprintf(stdout, "\nBob's private key: %lu", priv_bob);
    fprintf(stdout, "\nAlice's private key: %lu\n", priv_alice);

    unsigned long pub_bob; fprintf(stdout, "\nBob's public key:\n%lu^%lu \u2261 %lu	(mod %lu)\n", generator, priv_bob, (pub_bob = mod_exponentiate(generator, priv_bob)), *mod_);
    unsigned long pub_alice; fprintf(stdout, "\nAlice's public key:\n%lu^%lu \u2261 %lu	(mod %lu)\n", generator, priv_alice, (pub_alice = mod_exponentiate(generator, priv_alice)), *mod_);
    // calculate public key's

    fprintf(stdout, "\nBob receives Alice's public key '%lu'.\n", pub_alice);
    fprintf(stdout, "Alice receives Bob's public key '%lu'.\n", pub_bob);

    unsigned long SS_according_to_Bob; fprintf(stdout, "\nBob calculates '%lu ^ %lu \u2261 %lu'.\n", pub_alice, priv_bob, (SS_according_to_Bob = mod_exponentiate(pub_alice, priv_bob)));
    unsigned long SS_according_to_Alice; fprintf(stdout, "Alice calculates '%lu ^ %lu \u2261 %lu'.\n", pub_bob, priv_alice, (SS_according_to_Alice = mod_exponentiate(pub_bob, priv_alice)));

    free(mod_); if (SS_according_to_Bob != SS_according_to_Alice) error_message(error_selector(5), -5);
    return 0; }
/* Termination status legend:
 * -1: 'argv[1]' not parsable as number
 * -2: 'argv[2]' not parsable as number or number not coprime to 'argv[1]'
 * -3: 'argv[3]' not parsable as number or number not coprime to 'argv[1]'
 * -4: 'argv[4]' not parsable as number or number not coprime to 'argv[1]'
 * -5: Alice and Bob did not derive the same key. Key exchange failed.
 */
