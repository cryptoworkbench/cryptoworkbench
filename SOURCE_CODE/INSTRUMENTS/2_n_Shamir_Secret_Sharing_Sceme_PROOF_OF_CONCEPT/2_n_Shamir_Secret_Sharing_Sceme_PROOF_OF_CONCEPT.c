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
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"
UL MODULUS;
// ^^ Handle library inclusions

unsigned long a, _secret_B;

struct cartesian_coordinates {
    unsigned long x_coordinate;
    unsigned long y_coordinate;
};

unsigned long y_calculate(unsigned long x) { return (((x * a) % MODULUS) + _secret_B) % MODULUS; }
void secret_reduce() { if (_secret_B >= MODULUS) { _secret_B %= MODULUS; printf("The secret has been reduced by mod %lu into the congruent secret %lu.\n\n", MODULUS, _secret_B); } }

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MODULUS)) { printf("%s is not MODULUS!\n", argv[1]); exit(-1); }
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &a)) { printf("%s is not a!\n", argv[2]); exit(-2); } a %= MODULUS;
    if (3 < argc) {
	if (STR_could_be_parsed_into_UL(argv[3], &_secret_B)) secret_reduce();
	else { printf("The secret '%s' has not yet been transformed into numerical form!\n", argv[3]); exit(-3); }
    } else { printf("Now please put in your secret less than %lu: ", MODULUS); fscanf(stdin, "%lu", &_secret_B); secret_reduce(); }
    fprintf(stdout, "Using coordinate format: [x, f(x)]\n\nPlot for the linear function 'f(x) \u2261 %lux + %lu':\n", a, _secret_B);
    for (unsigned long x_coordinate = 0; x_coordinate < MODULUS; x_coordinate++) {
	struct cartesian_coordinates point_on_graph = {x_coordinate, 0};
	point_on_graph.y_coordinate += y_calculate(x_coordinate);
	printf("[%lu, %lu]\n", x_coordinate, y_calculate(x_coordinate));
    } // << ^ Calculate all the possible coordinates for a linear curve over a finite field

    unsigned long x_one, x_two;
    printf("\nDO NOT CHOOSE POINT 0 SINCE IT CONTAINS YOUR SECRET!\n");
    printf("Specification of first point by x coordinate: "); fscanf(stdin, "%lu", &x_one); unsigned long y_one = ((((x_one * a) % MODULUS) + _secret_B % MODULUS) % MODULUS);
    printf("Specification of second point by x coordinate: "); fscanf(stdin, "%lu", &x_two); unsigned long y_two = ((((x_two * a) % MODULUS) + _secret_B % MODULUS) % MODULUS);
    // ^^ Get 'random' (a.k.a. chosen) coordinates

    unsigned long Y_difference = y_one + (MODULUS - y_two); Y_difference %= MODULUS;
    unsigned long X_difference = x_one + (MODULUS - x_two); X_difference %= MODULUS;
    while (Y_difference % X_difference != 0) Y_difference += MODULUS;
    // ^^ We need to make the numerator divisible by the denominator given this specific field's conditions before we should divide in this modular arithmetic. "#MODULARARITHMETICRULES"

    if (Y_difference / X_difference != a) { fprintf(stderr, "This proof of concept failed!, \"Y_difference / X_difference\" is not a!\n"); exit(-4); }
    else fprintf(stdout, "a = %lu / %lu = %lu\n", Y_difference, X_difference, a);
    // ^^ Exit when this proof of concept already failed

    if (_secret_B == (y_one + (MODULUS - (x_one * a) % MODULUS)) % MODULUS) fprintf(stdout, "Calculation of B succeeded: %lu\n", _secret_B);
    else { fprintf(stderr, "Calculation of B failed!, so this proof of concept failed!\n"); exit(-5); }
    return 0;
}
