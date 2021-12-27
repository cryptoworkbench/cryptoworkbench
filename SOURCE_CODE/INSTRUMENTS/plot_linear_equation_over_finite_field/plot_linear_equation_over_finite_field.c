/* Supposed to become a proof of concept for Shamir's Secret Sharing sceme over finite fields using a first degree polynomial function (which is to say a linear equation). 
 *
 * A first degree polynomial function is obviously of the form:
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
 * #1). Determines A from these two specified points
 * #2). Determines "f(0)" using the Mod value and this set of coordinates (if I'm correct "f(0)" should be the value of the secret, and that should be it).
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"

struct cartesian_coordinates {
    unsigned long x_coordinate;
    unsigned long y_coordinate;
};

int main(int argc, char **argv) {
    printf("Welcome to the linear equation solver.\n"); unsigned long Mod, A;
    if (1 > argc || !STR_could_be_parsed_into_UL(argv[1], &Mod)) { printf("%s is not Mod!\n", argv[1]); exit(-1); }
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[2], &A)) { printf("%s is not A!\n", argv[2]); exit(-2); } A %= Mod;
    // ^^ Process supplied values

    printf("%%: %lu\n", Mod);
    printf("A: %lu\n", A);
    printf("Now please put in your secret less than %lu: ", Mod); unsigned long B; fscanf(stdin, "%lu", &B); B %= Mod;
    // ^^ Ask secret

    printf("\nCoordinate index: (x, y)\n");
    for (unsigned long x_coordinate = 0; x_coordinate < Mod; x_coordinate++) {
	struct cartesian_coordinates point_on_graph = {x_coordinate, 0};
	point_on_graph.y_coordinate += (((x_coordinate * A) % Mod) + B % Mod) % Mod;
	printf("               %lu: (%lu, %lu)\n", x_coordinate, point_on_graph.x_coordinate, point_on_graph.y_coordinate);
    } // << ^ Calculate all the possible coordinates for a linear curve over a finite field

    unsigned long point_one, point_two;
    printf("\nDO NOT CHOOSE POINT 0 SINCE IT CONTAINS YOUR SECRET!\n");
    printf("\nFirst coordinate from the above list (index): "); fscanf(stdin, "%lu", &point_one);
    printf("\nSecond coordinate from the above list (index): "); fscanf(stdin, "%lu", &point_two);
    return 0;
}
