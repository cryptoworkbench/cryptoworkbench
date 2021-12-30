/* This is my second attempt at implementing Elliptic Curve DH.
 *
 * Remember y^2 = x^3 + ax + b (mod %)
 *
 * When run with 17 2 2 19 5 1 the result should be:
 * (6, 3)
 * */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

// *** Global variables:
unsigned long m, a, b, cardinality;
const char *identity_significations[] = {"0", "O", "o", "pointatinfinity", "ID"};
char *symbol[] = {"m", "a", "b", "cardinality of field", "_base_Point.x", "_base_Point.y"};
struct coordinates { unsigned long x; unsigned long y; };
struct coordinates _base_Point;
struct coordinates **array;

unsigned long modular_division(unsigned long numerator, unsigned long denominator) { while (numerator % denominator != 0) numerator += m; return (numerator / denominator) % m; }
unsigned long m_inv(unsigned long inv_of_inv) { return modular_division(1, inv_of_inv); } // << dependend upon ^^
unsigned long inv(unsigned long inv_of_inv) { return m - (inv_of_inv % m); }

unsigned long y_calculate(unsigned long slope, unsigned long x_coordinate_from_previous_point, unsigned long x_coordinate_of_new_point, unsigned long y_coordinate_of_previous_point) {
    return (((slope * ((x_coordinate_from_previous_point + inv(x_coordinate_of_new_point)) % m)) % m) + inv(y_coordinate_of_previous_point)) % m;
}

struct coordinates *point_addition(struct coordinates *P_one, struct coordinates *P_two) { if (!(P_one && P_two) || P_one->x == P_two->x) return NULL; else {
    struct coordinates *ret = (struct coordinates *) malloc(sizeof(struct coordinates));
    unsigned long s = modular_division(((P_one->y + (m - P_two->y)) % m), ((P_one->x + (m - P_two->x)) % m));
    ret->x = (((s * s) % m) + inv((P_one->x + P_two->x) % m)) % m;
    ret->y = y_calculate(s, P_one->x, ret->x, P_one->y);
    return ret; }
}

// * Point doubling
struct coordinates *point_doubling(struct coordinates *p) { if (!p || p->x == 0) return NULL;
    struct coordinates *point = (struct coordinates *) malloc(sizeof(struct coordinates));
    unsigned long s = modular_division(((3 * ((p->x * p->x) % m) % m) + a) % m, (2 * p->y) % m); // See math note "#1"
    point->x = (((s * s) % m) + (inv((2 * p->x) % m))) % m; // << For some reason I need to do it like this
    point->y = y_calculate(s, p->x, point->x, p->y);
    return point;
}

void print_point(struct coordinates *point) { fprintf(stdout, "(%lu,%lu)", point->x, point->y); }

void print_point_at_(struct coordinates *pair) {
    if (pair) { print_point(pair); fprintf(stdout, "\n"); }
    else fprintf(stdout, "%c	(the point at infinity)\n", **identity_significations);
}

void argv_ERROR(unsigned long index, char **argv) { fprintf(stderr, "'%s' not interpretable as %s.\n", argv[index], symbol[index - 1]); exit(-index); }

void take_in_point(char symbol, struct coordinates **point) {
    while (1) { fprintf(stdout, "point %c = ", symbol);
	char *inp = (char *) malloc(sizeof(char) * 30); fscanf(stdin, "%s", inp); if (match(inp, identity_significations)) { free(inp); break; }
	// ^^ See if a mention of the point at infinity is there

	unsigned long new_x, new_y; if (sscanf(inp, "%lu,%lu", &new_x, &new_y) == 2)
	{ free(inp); *point = (struct coordinates *) malloc(sizeof(struct coordinates)); (**point).x = new_x; (**point).y = new_y; break; }
	// ^^ If the input could also not otherwise be translated, demand another input looping through
    };
}

struct coordinates scalar_multiplication(unsigned long multiplier) {
    // Here implement a function that takes apart the 'power-of-2' additive partitions of 'multiplier'
    // and use
}

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &m)) argv_ERROR(1, argv);
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &a)) argv_ERROR(2, argv); a %= m;
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &b)) argv_ERROR(3, argv); b %= m;
    if (5 > argc || !STR_could_be_parsed_into_UL(argv[4], &cardinality)) argv_ERROR(4, argv);
    if (6 > argc || !STR_could_be_parsed_into_UL(argv[5], &_base_Point.x)) argv_ERROR(5, argv); _base_Point.x %= m;
    if (7 > argc || !STR_could_be_parsed_into_UL(argv[6], &_base_Point.y)) argv_ERROR(6, argv); _base_Point.y %= m;
    // ^^ Take in all necessary information

    fprintf(stdout, "PUBLIC VARIABLES:\n");
    fprintf(stdout, "m: %lu\n", m);
    fprintf(stdout, "a: %lu\n", a);
    fprintf(stdout, "b: %lu\n", b);
    fprintf(stdout, "cardinality of group: %lu\n", cardinality);
    fprintf(stdout, "generator (abbreviated G) (x,y): (%lu,%lu)\n\n", _base_Point.x, _base_Point.y);
    // ^^ Display success

    unsigned long least_base_two_logarithm = down_rounded_BASE_2_logarithm(cardinality);
    array = (struct coordinates **) malloc(sizeof(struct coordinates *) * (least_base_two_logarithm + 2)); *array = NULL;
    unsigned long index = 1; array[index] = (struct coordinates *) malloc(sizeof(struct coordinates)); array[index] = &_base_Point;
    do {array[index + 1] = point_doubling(array[index]); index++;} while (index < least_base_two_logarithm + 1);
    // ^^ Initialize array

    fprintf(stdout, "SCALAR-MULTIPLICATION LOOKUP TABLE (back-bone):\n");
    fprintf(stdout, "0G: "); print_point_at_(*array);
    for (unsigned long index = 1; index < least_base_two_logarithm + 2; index++) { fprintf(stdout, "%luG: ", N_exponentiation(2, index - 1)); print_point_at_(array[index]); }

    struct coordinates *p, *q; p = q = NULL;

    fprintf(stdout, "\nPOINT ADDITION (p + q = r):\n");
    take_in_point('p', &p);
    take_in_point('q', &q);

    struct coordinates *result = point_addition(p, q);
    fprintf(stdout, "point r = ");
    if (p) print_point(p); else fprintf(stdout, "%c", **identity_significations); fprintf(stdout, " + ");
    if (q) print_point(q); else fprintf(stdout, "%c", **identity_significations);
    fprintf(stdout, " = "); print_point_at_(result); free(result); return 0;
}
/* MATH NOTES:
 * 1). A.k.a. "s = M(M(M(3 * M(POINT.x * POINT.x)) + a) * m_inv(M(2 * POINT.y)));"
 */
