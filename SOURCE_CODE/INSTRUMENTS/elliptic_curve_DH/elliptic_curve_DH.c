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
char *symbol[] = {"m", "a", "b", "cardinality of field", "_base_Point.x", "_base_Point.y"};
struct coordinates { unsigned long x; unsigned long y; };
struct coordinates _base_Point;
struct coordinates **array;

unsigned long modular_division(unsigned long numerator, unsigned long denominator) { while (numerator % denominator != 0) numerator += m; return (numerator / denominator) % m; }
unsigned long m_inv(unsigned long inv_of_inv) { return modular_division(1, inv_of_inv); } // << dependend upon ^^
unsigned long inv(unsigned long inv_of_inv) { return m - (inv_of_inv % m); }

struct coordinates *point_addition(struct coordinates *P_one, struct coordinates *P_two) { if (P_one->x == P_two->x) return NULL; else {
    struct coordinates *ret = (struct coordinates *) malloc(sizeof(struct coordinates));
    unsigned long s = modular_division(((P_one->y + (m - P_two->y)) % m), ((P_one->x + (m - P_two->x)) % m));
    ret->x = (((s * s) % m) + inv((P_one->x + P_two->x) % m)) % m;
    ret->y = (((s * ((P_one->x + inv(ret->x)) % m)) % m) + inv(P_one->y)) % m;
    return ret; }
}

// * Point doubling
struct coordinates *point_doubling(unsigned long index) {
    struct coordinates *point = (struct coordinates *) malloc(sizeof(struct coordinates));
    unsigned long s = modular_division(((3 * ((array[index]->x * array[index]->x) % m) % m) + a) % m, (2 * array[index]->y) % m); // See math note "#1"
    point->x = (((s * s) % m) + (inv((2 * array[index]->x) % m))) % m; // << For some reason I need to do it like this
    point->y = (((s * ((array[index]->x + inv(point->x)) % m)) % m) + inv(array[index]->y)) % m; // << Write values into the next struct (in this array of type "struct coordinates")
    return point;
}

void initialize_scalar_array(unsigned long least_base_two_logarithm) {
    array = (struct coordinates **) malloc(sizeof(struct coordinates *) * (least_base_two_logarithm + 2));
    *array = NULL;
    // ^^ Prepare necessary variables

    unsigned long index = 1;
    array[index] = (struct coordinates *) malloc(sizeof(struct coordinates)); array[index] = &_base_Point;
    do {
	array[index + 1] = point_doubling(index); index++;
    } while (index < least_base_two_logarithm + 1);
    // ^^^ Initialize array
}

void print_point_at_(struct coordinates *pair) {
    if (pair) fprintf(stdout, "[%lu,%lu]\n", pair->x, pair->y);
    else fprintf(stdout, "'o' (POINT AT INFINITY)\n");
}

void argv_ERROR(unsigned long index, char **argv) { fprintf(stderr, "'%s' not interpretable as %s.\n", argv[index], symbol[index - 1]); exit(-index); }

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
    fprintf(stdout, "Cardinality of group: %lu\n", cardinality);
    fprintf(stdout, "Generator (G) [x,y]: [%lu, %lu]\n\n", _base_Point.x, _base_Point.y);
    // ^^ Display success

    unsigned long least_base_two_logarithm = down_rounded_BASE_2_logarithm(cardinality);
    initialize_scalar_array(least_base_two_logarithm);

    fprintf(stdout, "SCALAR-MULTIPLICATION LOOKUP TABLE (back-bone):\n");
    fprintf(stdout, "Point #0: "); print_point_at_(*array);
    for (unsigned long index = 1; index < least_base_two_logarithm + 2; index++) { fprintf(stdout, "Point #%lu: ", N_exponentiation(2, index - 1)); print_point_at_(array[index]); }

    fprintf(stdout, "\nPoint addition operation:\n");
    struct coordinates *P_one = (struct coordinates *) malloc(sizeof(struct coordinates)); fprintf(stdout, "Point #1.x: "); scanf("%lu", &P_one->x); fprintf(stdout, "Point #1.y: "); scanf("%lu", &P_one->y);
    struct coordinates *P_two = (struct coordinates *) malloc(sizeof(struct coordinates)); fprintf(stdout, "Point #2.x: "); scanf("%lu", &P_two->x); fprintf(stdout, "Point #2.y: "); scanf("%lu", &P_two->y);
    struct coordinates *result = point_addition(P_one, P_two);
    fprintf(stdout, "[%lu,%lu] + [%lu,%lu] = ", P_one->x, P_one->y, P_two->x, P_two->y); print_point_at_(result); free(result);
    return 0;
}
/* MATH NOTES:
 * 1). A.k.a. "s = M(M(M(3 * M(POINT.x * POINT.x)) + a) * m_inv(M(2 * POINT.y)));"
 */
