/* Solves a system of congruences using the maths library function chinese_remainder_theorem().
 *
 * The answer if checked at line 30.
 */
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
// library inclusions ^

char *unparsed_arg;
// global variables ^

void RESULT_ERROR() { fprintf(stderr, "\nThe check on the result from chinese_remainder_theorem() failed.\n\n"); }
void number_unparsable() { fprintf(stderr, "\n%s is not a number.\n\n", unparsed_arg); }
void not_a_system() { fprintf(stderr, "\nAt least one congruence must be supplied.\n\n"); }
void moduli_not_coprime() { fprintf(stderr, "\nIt turned out not all moduli were coprime with one another. Hence the Chinese Remainder Theorem cannot be used to solve this problem.\n\n"); }
_error_selector arg_error(int SELECTOR) { switch (SELECTOR) { case 1: return number_unparsable; case 2: return not_a_system; case 3: return moduli_not_coprime; case 4: return RESULT_ERROR; }; }
// error functions ^ ^^^

int main(int argc, char **argv) { unparsed_arg = argv[1]; unsigned long remainder;
    if (argc == 1 || !str_represents_ul(unparsed_arg, &remainder)) error_message(arg_error(1), -1); if (argc == 2) error_message(arg_error(2), -2);
    unsigned long moduli = argc - 2; unsigned long **array_of_moduli = (unsigned long **) malloc(sizeof(unsigned long *) * moduli); unsigned long i;
    for (i = 0; i < moduli; i++) array_of_moduli[i] = (unsigned long *) malloc(sizeof(unsigned long));
    for (i = 0; i < moduli; i++) if (!str_represents_ul(argv[2 + i], array_of_moduli[i])) error_message(arg_error(2), - (2 + i)); // take in all information < ^^^
    // parse remainder and congruences (moduli) from terminal arguments ^

    for (i = 0; i < moduli; i++) for (unsigned long j = i + 1; j < moduli; j++) { if (GCD(*array_of_moduli[i], *array_of_moduli[j]) != 1) error_message(arg_error(3), -3); }
    // check to see if all moduli are coprime to each other ^

    unsigned long ans = chinese_remainder_theorem(remainder, array_of_moduli, moduli);
    for (i = 0; i < moduli; i++) { if (ans % *array_of_moduli[i] != remainder) error_message(arg_error(4), -4); fprintf(stdout, "%lu \u2261 %lu (mod %lu)\n", ans, remainder, *array_of_moduli[i]); }
    // verify the result from chinese_remainder_theorem() ^

    for (i = 0; i < moduli; i++) free(array_of_moduli[i]); free(array_of_moduli);
    // free all allocated memory ^

    return 0;
}
