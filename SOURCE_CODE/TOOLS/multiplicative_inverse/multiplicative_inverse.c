#include <stdio.h>
#include <unistd.h> // < 'execvp()'
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h" // 'str_represents_ul()'
#include "../../libraries/mathematics/maths.h" // 'GCD()'

const char *argv_ONE[] = {"first", "modulus"};
const char *argv_TWO[] = {"second", "number coprime with the modulus whose multiplicative inverse you want to know"};

void argv_ERROR(char **argv, int index) {
    const char **error_specific_message = argv_ONE;
    if (index == 2) error_specific_message = argv_TWO;
    fprintf(stderr, "%s is not something I am able to understand as a number; please provide as %s argument the %s.\n\nTerminating with exit status '-%i'.\n", argv[index], error_specific_message[0], error_specific_message[1], index);
    exit(-index);
} // ^ used by 'main()'

const char *prog_name = "modular_division";

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], _REPORT_LOCATION_OF_mod())) argv_ERROR(argv, 1); ul number_coprime_to_MOD;
    if (3 > argc || !str_represents_ul(argv[2], &number_coprime_to_MOD)) argv_ERROR(argv, 2); ul GCD_of_arguments = GCD(number_coprime_to_MOD, _REPORT_mod());
    // ^ take in supplied (MANDATORY) arguments

    if (GCD_of_arguments != 1) { fprintf(stderr, "%lu shares a factor of %lu with %lu.\n\nTerminating with exit status '-3'.\n", number_coprime_to_MOD, GCD_of_arguments, _REPORT_mod()); exit(-3); }
    // ^ exit if the number to calculate the multiplicative inverse of is not coprime to the modulus

    fprintf(stdout, "Executing external tool '%s':\n", prog_name);
    char *call_to_modular_division[] = {(char *) prog_name, argv[1], "1", argv[2], 0};
    pid_t modular_division_PID = fork(); if (modular_division_PID == -1) { exit(-11); } // < Fork
    if (!modular_division_PID) execvp(call_to_modular_division[0], call_to_modular_division);
    int modular_division_exit_status_RAW; waitpid(modular_division_PID, &modular_division_exit_status_RAW, 0); // < wait for the child process to finish

    int modular_division_exit_status = WEXITSTATUS(modular_division_exit_status_RAW);
    if (modular_division_exit_status) fprintf(stdout, "%s returned with exit status '%i': something went wrong.\n");
    return 0;
}
