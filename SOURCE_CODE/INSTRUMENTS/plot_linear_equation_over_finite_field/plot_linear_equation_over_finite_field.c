/* Pretty simple:
 * Calculates all the possible coordinates for a linear curve over a finite field.
 *
 * Pipe this output to your next program.
 */
#include <stdio.h>
#include "../../libraries/functional/string.h"

struct cartesian_coordinates {
    unsigned long x_coordinate;
    unsigned long y_coordinate;
};

int main(int argc, char **argv) { unsigned long Mod, A, B;
    if (1 > argc || !STR_could_be_parsed_into_UL(argv[1], &Mod)) { printf("%s is not Mod!\n", argv[1]); exit(-1); }
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[2], &A)) { printf("%s is not A!\n", argv[2]); exit(-2); } A %= Mod;
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[3], &B)) { printf("%s is not B!\n", argv[3]); exit(-3); } B %= Mod;

    for (unsigned long x_coordinate = 0; x_coordinate < Mod; x_coordinate++) {
	struct cartesian_coordinates point_on_graph = {x_coordinate, 0};
	point_on_graph.y_coordinate += (((x_coordinate * A) % Mod) + B % Mod) % Mod;
	printf("(%lu, %lu)\n", point_on_graph.x_coordinate, point_on_graph.y_coordinate);
    }
    return 0;
}
