/* Illustrates the Diffie-Hellman Key Exchange Protocol (can be abbreviated DH-KAP).
 *
 * Uses 'ARCHIVE/'
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/functional/triple_ref_pointers.h"
#include "../../libraries/mathematics/maths.h"
#include "../../libraries/mathematics/group_library.h"

struct LL_ { unsigned long e; struct LL_ *next; };
// type definitions ^

STRUCT_DH_parameters DH_parameters; unsigned long group_cardinality_;
// global variables ^

void RESULT_ERROR() { fprintf(stderr, "\nAlice and Bob did not derive the same shared secret.\n\n"); }

void INSERT(struct LL_ ***tracer_location, unsigned long new_ulong) {
    struct LL_ *new_LL_element = (struct LL_ *) malloc(sizeof(struct LL_)); new_LL_element->e = new_ulong; new_LL_element->next = NULL; // create and initialize new element
    while (**tracer_location) *tracer_location = &(***tracer_location).next; **tracer_location = new_LL_element; // add this new element at the end
    *tracer_location = (struct LL_ **) **tracer_location; // update tracer
}

struct VOID_ptr_ptr_PAIR group_elements_LL(char **argv) { FILE *ELEMENT_database = open_group(argv); struct VOID_ptr_ptr_PAIR element_CHANNEL_ptr_pair = initialize_CHANNEL_ptr_pair(); unsigned long group_ELEMENT;
    while (fscanf(ELEMENT_database, "%lu\n", &group_ELEMENT) == 1) { INSERT((struct LL_ ***) &element_CHANNEL_ptr_pair.iterator, group_ELEMENT); group_cardinality_++; } close_group(argv[1], ELEMENT_database);
    return element_CHANNEL_ptr_pair;
}

int i;
void mod_failed_to_parse() { fprintf(stderr, "Please provide as first argument a modulus specifying the multiplicative group to use. '\u2115%s*' makes no sense to me.", (*argv_loc)[1]); }
void coprime_error() { fprintf(stderr, "gcd(%s, %s) != 1: %s is not an element from \u2115%s*.", (*argv_loc)[i], (*argv_loc)[1], (*argv_loc)[i], (*argv_loc)[1]); }
void generator_failed_to_parse() { fprintf(stderr, "Please provide as second argument a generator from \u2115%s*.", (*argv_loc)[1]); }

void _third_argument_instruction() { fprintf(stderr, "Please supply as third argument Bob's private key!"); }
void fourth_argument_instruction() { fprintf(stderr, "Please supply as fourth argument Alice's private key!"); }

int main(int argc, char **argv) { argv_loc = &argv;
    conditional_goodbye(n(n(pair_of_strs_represents_pair_of_coprime_ULs(mod_failed_to_parse, generator_failed_to_parse, &DH_parameters.a, &DH_parameters.b, 1, 2, -3)))); mod_ = &DH_parameters.a;
    // take in multiplicative group and element from multiplicative group using function 'pair_of_strs_represents_pair_of_coprime_ULs' ^

    unsigned long __priv_bob = 0; i = 3; if (argc > 3) conditional_goodbye(n(n(error_specification(_third_argument_instruction, n(ul_parse_str(&__priv_bob, argv[3], -3)))))); else __priv_bob = urandom_number(*mod_);
    unsigned long priv_alice = 0; i = 4; if (argc > 4) conditional_goodbye(n(n(error_specification(fourth_argument_instruction, n(ul_parse_str(&priv_alice, argv[4], -4)))))); else priv_alice = urandom_number(*mod_);
    // take complain about 

    group_cardinality_ = totient(*mod_); struct ordered_pair iso = _isomorphism(); do { iso.b = mod_multiply(iso.b, DH_parameters.b); iso.a++; if (iso.b == MULTIPLICATIVE_IDENTITY) break; } while (1);
    if (iso.a != group_cardinality_) {
	fprintf(stderr, "WARNING: %s only covers %.2f %% (1/%lu) of \u2115%s*  (|\u2115%s*| / %lu  =  \u03C6(%s) / %lu  =  %lu / %lu  = %lu), continue? ('n' of 'N' for exit): ",
		argv[2],
		((float) 1 / (group_cardinality_ / iso.a)) * 100,
		group_cardinality_ / iso.a,
		argv[1],
		argv[1],
		iso.a,
		argv[1],
		group_cardinality_ / iso.a,
		group_cardinality_,
		group_cardinality_ / iso.a,
		iso.a);
	char y_or_n; fscanf(stdin, " %c", &y_or_n); if (y_or_n == 'n' || y_or_n == 'N') exit(-1);
    } // detect when the permutation basis does not cover the group ^
    fprintf(stdout, "Alice and Bob use %lu within \u2115%s*.\n\nDiffie-Hellman key exchange example:\n", mod_conditional_cap(DH_parameters.b), argv[1]);
    fprintf(stdout, "Bob's private key: %lu\n", __priv_bob);
    fprintf(stdout, "Alice's private key: %lu\n", priv_alice);

    unsigned long pub_bob; fprintf(stdout, "\nBob's public key:\n%lu^%lu \u2261 %lu (mod %lu)\n", DH_parameters.b, __priv_bob, (pub_bob = DH_public_key(&DH_parameters, __priv_bob)), *mod_);

    unsigned long pub_alice; fprintf(stdout, "\nAlice's public key:\n%lu^%lu \u2261 %lu (mod %lu)\n", DH_parameters.b, priv_alice, (pub_alice = DH_public_key(&DH_parameters, priv_alice)), *mod_);
    // calculate public key's

    fprintf(stdout, "\nBob receives Alice's public key '%lu'.\n", pub_alice);
    fprintf(stdout, "Alice receives Bob's public key '%lu'.\n", pub_bob);

    unsigned long SS_according_to_Bob;   fprintf(stdout, "\nBob calculates '%lu^%lu \u2261 %lu (mod %lu)'.\n", pub_alice, __priv_bob, (SS_according_to_Bob = mod_exponentiate(pub_alice, __priv_bob)), *mod_);
    unsigned long SS_according_to_Alice; fprintf(stdout, "Alice calculates '%lu^%lu \u2261 %lu (mod %lu)'.\n", pub_bob, priv_alice, (SS_according_to_Alice = mod_exponentiate(pub_bob, priv_alice)), *mod_);

    if (SS_according_to_Bob == SS_according_to_Alice)
    { fprintf(stdout, "\nBoth derived %lu by raising the other's public key to their own private key: KEY EXCHANGE COMPLETE.\n", SS_according_to_Bob); return 0; }
    else error_message(RESULT_ERROR, -1); }
/* Termination status legend:
 * -1: 'argv[1]' not parsable as number
 * -2: 'argv[2]' not parsable as number or number not coprime to 'argv[1]'
 * -3: 'argv[3]' not parsable as number or number not coprime to 'argv[1]'
 * -4: 'argv[4]' not parsable as number or number not coprime to 'argv[1]'
 * -5: Alice and Bob did not derive the same key. Key exchange failed.
 */
