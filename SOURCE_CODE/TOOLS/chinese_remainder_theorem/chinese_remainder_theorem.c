/* Solves a system of congruences using the maths library function chinese_remainder_theorem().
 *
 * Check for moduli congruences is done in main and not within chinese_remainder_theorem() itself.
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
    if (2 > argc || !str_represents_ul(unparsed_arg, &remainder)) error_message(arg_error(1), -1); if (argc < 3) error_message(arg_error(2), -2);
    unsigned long moduli = argc - 2; unsigned long **array_of_moduli = (unsigned long **) malloc(sizeof(unsigned long *) * moduli); unsigned long i;
    for (i = 0; i < moduli; i++) array_of_moduli[i] = (unsigned long *) malloc(sizeof(unsigned long));
    for (i = 0; i < moduli; i++) if (!str_represents_ul(argv[2 + i], array_of_moduli[i])) error_message(arg_error(2), - (2 + i)); // take in all information < ^^^
    for (i = 0; i < moduli; i++) for (unsigned long j = i + 1; j < moduli; j++) { if (GCD(*array_of_moduli[i], *array_of_moduli[j]) != 1) error_message(arg_error(3), -3); }
    // checks to see if the chinese remainder theorem can help solve the supplied system of congruences ^^ 
    unsigned long ans = chinese_remainder_theorem(remainder, array_of_moduli, moduli); // ans++; // #1
    fprintf(stdout, "According to chinese_remainder_theorem() the solution to this system of congruences is %lu.", ans);
    for (i = 0; i < moduli; i++) if (ans % *array_of_moduli[i] != remainder) error_message(arg_error(4), -4); fprintf(stdout, "\n");
    for (i = 0; i < moduli; i++) free(array_of_moduli[i]); free(array_of_moduli); return 0; }
/* # 1:
 * 	Re-enable to see RESULT_ERROR in action. Yields an interresting result; displays the correct error, but seems to execute line 27 therafter.
 */
