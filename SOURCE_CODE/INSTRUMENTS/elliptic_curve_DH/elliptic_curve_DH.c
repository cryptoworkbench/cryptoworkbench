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
struct coordinates *array;

unsigned long modular_division(unsigned long numerator, unsigned long denominator) { while (numerator % denominator != 0) numerator += m; return (numerator / denominator) % m; }
unsigned long m_inv(unsigned long inv_of_inv) { return modular_division(1, inv_of_inv); } // << dependend upon ^^
unsigned long inv(unsigned long inv_of_inv) { return m - (inv_of_inv % m); }

// * Point doubling
void scalar_array_doubling_function(unsigned long index) {
    unsigned long s = modular_division(((3 * ((array[index].x * array[index].x) % m) % m) + a) % m, (2 * array[index].y) % m); // See math note "#1"
    array[index + 1].x = (((s * s) % m) + (inv((2 * array[index].x) % m))) % m; // << For some reason I need to do it like this
    array[index + 1].y = (((s * ((array[index].x + inv(array[index + 1].x)) % m)) % m) + inv(array[index].y)) % m; // << Write values into the next struct (in this array of type "struct coordinates")
}

void initialize_scalar_array(unsigned long least_base_two_logarithm) {
    array = (struct coordinates *) malloc(sizeof(struct coordinates) * (least_base_two_logarithm + 1));
    // ^^ Prepare necessary variables

    unsigned long index = 0;
    array[index].x = _base_Point.x; array[index].y = _base_Point.y; do {
	unsigned long s = modular_division(((3 * ((array[index].x * array[index].x) % m) % m) + a) % m, (2 * array[index].y) % m); // See math note "#1"
	array[index + 1].x = (((s * s) % m) + (inv((2 * array[index].x) % m))) % m; // << For some reason I need to do it like this
	array[index + 1].y = (((s * ((array[index].x + inv(array[index + 1].x)) % m)) % m) + inv(array[index].y)) % m; // << Write values into the next struct (in this array of type "struct coordinates")
	index++;
    } while (index <= least_base_two_logarithm);
    // ^^^ Initialize array
}

void argv_ERROR(unsigned long index, char **argv) { fprintf(stderr, "'%s' not interpretable as %s.\n", argv[index], symbol[index - 1]); exit(-index); }

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &m)) argv_ERROR(1, argv);
    if (3 > argc || !STR_could_be_parsed_into_UL(argv[2], &a)) argv_ERROR(2, argv); else a %= m;
    if (4 > argc || !STR_could_be_parsed_into_UL(argv[3], &b)) argv_ERROR(3, argv); else b %= m;
    if (5 > argc || !STR_could_be_parsed_into_UL(argv[4], &cardinality)) argv_ERROR(4, argv);
    if (6 > argc || !STR_could_be_parsed_into_UL(argv[5], &_base_Point.x)) argv_ERROR(5, argv); else _base_Point.x %= m;
    if (7 > argc || !STR_could_be_parsed_into_UL(argv[6], &_base_Point.y)) argv_ERROR(6, argv); else _base_Point.y %= m;
    // ^^ Take in all necessary information

    printf("m: %lu\n", m);
    printf("a: %lu\n", a);
    printf("b: %lu\n", b);
    printf("Cardinality of group: %lu\n", cardinality);
    printf("base point x: %lu\n", _base_Point.x);
    printf("base point y: %lu\n", _base_Point.y);
    // ^^ Display success

    unsigned long least_base_two_logarithm = down_rounded_BASE_2_logarithm(cardinality);
    fprintf(stdout, "\nLeast base two logarithm of cardinality (%lu) of group: %lu\n", cardinality, least_base_two_logarithm);
    initialize_scalar_array(least_base_two_logarithm);
    for (unsigned long i = 0; i <= least_base_two_logarithm; i++) {
	fprintf(stdout, "POINT #%lu: [%lu,%lu]\n", i + 1, array[i].x, array[i].y);
	fprintf(stderr, "Calculated as [%lu,%lu]^%lu\n\n", _base_Point.x, _base_Point.y, N_exponentiation(2, i));
    }

    // printf("Point #2: [%lu,%lu]\n", array[1].x, array[1].x);
    // printf("Point #3: [%lu,%lu]\n", array[2].x, array[2].x);
    /*
    struct coordinates two_Base = POINT_DOUBLING(_base_Point);
    printf("2 base: (%lu, %lu)\n", two_Base.x, two_Base.y); */

    return 0;
}
/* MATH NOTES:
 * 1). A.k.a. "s = M(M(M(3 * M(POINT.x * POINT.x)) + a) * m_inv(M(2 * POINT.y)));"
 */
