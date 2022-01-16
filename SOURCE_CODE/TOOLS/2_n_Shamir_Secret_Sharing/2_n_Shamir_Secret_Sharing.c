/* A first degree polynomial function is obviously of the form:
 * "f(x) = A * X^1 + B * X^0"
 *
 * A.k.a.
 * "f(x) = A * X^1 + B * 1"
 *
 * A.k.a.
 * "f(x) = A * X^1 + B"
 *
 * A.k.a. "A LINEAR EQUATION!"
 *
 * THIS PROGRAM takes the MOD value and the value for A from the command line arguments.
 * Then it determines what linear equation to use based on which number you wished to split/encode.
 * Then it prints out the coordinates of this linear curve over the finite field defined by the MOD value.
 *
 * The user then will choose what two points (which are obviously never "f(0)" (!) ) this proof of concept program should proceed to work with.
 *
 * The program then:
 * #1). Determines 'A' again (verifies* 'A') from these two specified points [* verification by program termination: if 'A' calculated again is not the same, the program terminates; THIS PROOF CONCEPT]
 * #2). Determines "f(0)" using the Mod value and this set of coordinates. This equates to the calculation of the linear equation (first degree polynomial) parameter 'B'
 */

#include <stdio.h>
#include <unistd.h> // 'execvp()'
#include <sys/wait.h> // 'waitpid()'
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
ul MOD;
// ^^ Handle library inclusions

#define EXTERNAL_PROGRAM "polynomial_function_map_over_GF"

unsigned long a, _secret_B;

struct cartesian_coordinates {
    unsigned long x;
    unsigned long y;
};

void secret_reduce() { if (_secret_B >= MOD) { _secret_B %= MOD; printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", MOD, _secret_B); } }

int main(int argc, char **argv) {
    if (2 > argc || !str_represents_ul(argv[1], &MOD)) { printf("%s is not MOD!\n", argv[1]); exit(-1); }
    fprintf(stdout, "Give me two function inputs and outputs:\n"); struct cartesian_coordinates point_one, point_two;
    fprintf(stdout, "f(x): "); fscanf(stdin, "%lu", &point_one.y); fprintf(stdout, "x   : "); fscanf(stdin, "%lu", &point_one.x);
    fprintf(stdout, "\nf(y): "); fscanf(stdin, "%lu", &point_two.y); fprintf(stdout, "y   : "); fscanf(stdin, "%lu", &point_two.x);
    // ^^ Get 'random' (a.k.a. chosen) coordinates

    unsigned long Y_difference = point_one.y + (MOD - point_two.y); Y_difference %= MOD;
    unsigned long X_difference = point_one.x + (MOD - point_two.x); X_difference %= MOD;
    while (Y_difference % X_difference != 0) Y_difference += MOD;
    // ^^ We need to make the numerator divisible by the denominator given this specific field's conditions before we should divide in this modular arithmetic. "#MODULARARITHMETICRULES"

    ul a = Y_difference / X_difference;
    ul b = (point_one.y + (MOD - (point_one.x * a) % MOD)) % MOD;
    fprintf(stdout, "\nThe linear equation which generated the specified points:\n");
    fprintf(stdout, "f(x) \u2261 (%lu * x^1) + (%lu * x^0)	(%% %lu)\n", a, b, MOD);
    return 0;
}
