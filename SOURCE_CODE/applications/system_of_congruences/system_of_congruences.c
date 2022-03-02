/* Solves a system of congruences using the maths library function chinese_remainder_theorem().
 *
 * The answer is checked at line 30.
 *
 * Check not work with terminal inputs 2 3 7 11.
 */
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

int i; char *unparsed_modulus;
// global variables ^

void RESULT_ERROR() { fprintf(stderr, "\nThe check on the result from chinese_remainder_theorem() failed.\n\n"); }
void number_unparsable() { fprintf(stderr, "\n%s is not a number.\n\n", unparsed_arg); }
void not_a_system() { fprintf(stderr, "\nAt least one congruence must be supplied.\n\n"); }
void moduli_not_coprime() { fprintf(stderr, "\n\nIt turned out not all moduli were coprime with one another. Hence the Chinese Remainder Theorem cannot be used to solve this problem."); }
_error_selector arg_error(int SELECTOR) { switch (SELECTOR) { case 1: return number_unparsable; case 2: return not_a_system; case 3: return moduli_not_coprime; case 4: return RESULT_ERROR; }; }
// error functions ^ ^^^

void system_not_provided() { fprintf(stderr, "Please provide besides a remainder also a system of congruences."); }
void remainder_not_parsable() { fprintf(stderr, "Please provide as first argument the remainder."); }
void modulus_failed_to_parse() { fprintf(stderr, "Failed to understand '%s' as the %ith modulus.", unparsed_modulus, i + 1); }

int main(int argc, char **argv) { unparsed_arg = argv[1];
    unsigned long remainder; conditional_goodbye(n(n(error_specification(remainder_not_parsable, n(ul_parse_str(argv[1], &remainder, -1))))));
                             conditional_goodbye(n(n(error_specification(system_not_provided, -2 * (argc == 2)))));
    // interpret remainder ^

    unsigned long moduli = argc - 2; unsigned long **array_of_moduli = (unsigned long **) malloc(sizeof(unsigned long *) * moduli); unsigned long i;
    for (i = 0; i < moduli; i++) array_of_moduli[i] = (unsigned long *) malloc(sizeof(unsigned long));
    for (i = 0; i < moduli; i++) { unparsed_modulus = argv[2 + i]; conditional_goodbye(n(n(error_specification(modulus_failed_to_parse, n(ul_parse_str(unparsed_modulus, array_of_moduli[i], - (2 + i))))))); }

    for (i = 0; i < moduli; i++) for (unsigned long j = i + 1; j < moduli; j++) if (GCD(*array_of_moduli[i], *array_of_moduli[j]) != 1) conditional_goodbye(n(n(error_message(moduli_not_coprime, -3))));
    // check to see if all moduli are coprime to each other ^

    unsigned long ans = chinese_remainder_theorem(remainder, array_of_moduli, moduli);
    for (i = 0; i < moduli; i++) { if (ans % *array_of_moduli[i] != remainder) error_message(arg_error(4), -4); fprintf(stdout, "%lu \u2261 %lu (mod %lu)\n", ans, remainder, *array_of_moduli[i]); }
    // verify the result from chinese_remainder_theorem() ^

    for (i = 0; i < moduli; i++) free(array_of_moduli[i]); free(array_of_moduli);
    // free all allocated memory ^

    return 0;
}
