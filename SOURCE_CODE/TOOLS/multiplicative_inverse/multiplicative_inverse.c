#include <stdio.h>
#include <unistd.h> // < 'execvp()'
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'GCD()'

const char *argv_ONE[] = {"first", "modulus"};
const char *argv_TWO[] = {"second", "number coprime with the modulus whose multiplicative mod_inverse you want to know"};

void argv_ERROR(char **argv, int index) {
    const char **error_specific_message = argv_ONE;
    if (index == 2) error_specific_message = argv_TWO;
    fprintf(stderr, "%s is not something I am able to understand as a number; please provide as %s argument the %s.\n\n" EXIT_STATUS_GOODBYE, argv[index], error_specific_message[0], error_specific_message[1], -index);
    exit(-index);
}

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &mod_)) argv_ERROR(argv, 1); unsigned long number_coprime_to_MOD;
    if (3 > argc || !str_represents_ul(argv[2], &number_coprime_to_MOD)) argv_ERROR(argv, 2); unsigned long GCD_of_arguments = GCD(number_coprime_to_MOD, mod_);
    if (GCD_of_arguments != 1) { fprintf(stderr, "%lu shares a factor of %lu with %lu.\n\n" EXIT_STATUS_GOODBYE, number_coprime_to_MOD, GCD_of_arguments, mod_, -3); exit(-3); }
    fprintf(stdout, "%lu^-1 \u2261 %lu	(mod %lu)\n", number_coprime_to_MOD, mod_divide(1, number_coprime_to_MOD), mod_); return 0;
}
