/* PROGRAM DESCRIPTION:
 * Solves a system of congruences using the maths library function chinese_remainder_theorem().
 *
 * PROBLEMS:
 * ~ Does not work with terminal inputs 2 3 7 11 (try!)
 */
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.basic.h"
// library inclusions ^

int i; char *unparsed_modulus; unsigned long *modulis; unsigned long ans, mod;
// global variables ^

void sanity_check_result() { fprintf(stderr, "sanity check on chinese_remainder_theorem() failed."); }
void sanity_check_result_specification() { fprintf(stderr, "chinese_remainder_theorem() returned '%lu', but '%lu' is not congruent to '%lu' mod '%lu'; it is congruency to '%lu' mod '%lu'.", ans, ans, mod, modulis[i], ans % modulis[i], modulis[i]); }
void not_a_system() { fprintf(stderr, "\nAt least one congruence must be supplied.\n\n"); }
void moduli_not_coprime() { fprintf(stderr, "\n\nIt turned out not all moduli were coprime with one another. Hence the Chinese Remainder Theorem cannot be used to solve this problem."); }
// error functions ^ ^^^

void ______system_not_provided() { fprintf(stderr, "Please provide besides a remainder also a system of congruences."); }
void remainder_failed_to_parse() { fprintf(stderr, "Please provide as first argument the remainder."); }
void __modulus_failed_to_parse() { fprintf(stderr, "Failed to understand '%s' as the %ith modulus.", unparsed_modulus, i + 1); }

int main(int argc, char **argv) { mod = ADDITIVE_IDENTITY; argv_ptr = &argv;
    conditional_goodbye(n(n(error_specification(remainder_failed_to_parse, n(_ul_parse_str(&mod, argv[1], -1))))));
    conditional_goodbye(n(n(error_specification(______system_not_provided,               (argc == 2)  *  -2))));
    // interpret remainder ^

    unsigned long moduli = argc - 2; modulis = (unsigned long *) malloc(sizeof(unsigned long) * moduli);
    for (i = 0; i < moduli; i++) { unparsed_modulus = argv[2 + i]; conditional_goodbye(n(n(error_specification(__modulus_failed_to_parse, n(_ul_parse_str(i + modulis, unparsed_modulus, - (2 + i))))))); }

    for (i = 0; i < moduli; i++) for (unsigned long j = i + 1; j < moduli; j++) if (GCD(modulis[i], modulis[j]) != 1) conditional_goodbye(n(n(error_message(moduli_not_coprime, -3))));
    // check to see if all moduli are coprime to each other ^

    ans = chinese_remainder_theorem(mod, modulis, moduli);
    for (i = 0; i < moduli; i++) {
	if (ans % modulis[i] != mod)
	    conditional_goodbye(n(n(error_specification(sanity_check_result_specification, n(n(error_message(sanity_check_result, -4)))))));
	fprintf(stdout, "%lu \u2261 %lu (mod %lu)\n", ans, mod, modulis[i]);
    }
    // verify and display the result from chinese_remainder_theorem() ^

    return 0;
}
