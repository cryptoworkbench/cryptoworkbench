/* Inspired by: https://www.youtube.com/watch?v=F3zzNa42-tQ
 *
 * Try with 17 2 2 19 5 1
 * 3, 8
 *
 * To get point of infinity.
 *
 * For some reason fails when using these arguments in combination with secret values 4, and 6.
 *
 * And they do not correspond when you put in 5 with 6. (?). */
#include <stdio.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

// *** Global variables:
unsigned long m, a, b, cardinality;
const char *point_at_infinity_strings[] = {"PAI", "0", "O", "o", "pointatinfinity", "ID"};
char *symbol[] = {"m", "a", "b", "cardinality of field", "_base_Point.x", "_base_Point.y"};
struct coordinates { unsigned long x; unsigned long y; };
struct coordinates _base_Point;

unsigned long modular_division(unsigned long numerator, unsigned long denominator) { while (numerator % denominator != 0) numerator += m; return (numerator / denominator) % m; }
unsigned long m_inv(unsigned long inv_of_inv) { return modular_division(1, inv_of_inv); } // << dependend upon ^^
unsigned long inv(unsigned long inv_of_inv) { return m - (inv_of_inv % m); }

unsigned long y_calculate(unsigned long slope, unsigned long previous_x, unsigned long new_x, unsigned long previous_y) { return (((slope * ((previous_x + inv(new_x)) % m)) % m) + inv(previous_y)) % m; }
unsigned long x_calculate(unsigned long slope, unsigned long Xp, unsigned long Xq) { return (((slope * slope) % m) + inv((Xp + Xq) % m)) % m; }

void print_point(struct coordinates *point) { fprintf(stdout, "(%lu,%lu)", point->x, point->y); }

void FORMAL_print_point(struct coordinates *point) {
    if (point) { print_point(point); fprintf(stdout, "\n"); }
    else fprintf(stdout, "%s	(Point At Infinity)\n", *point_at_infinity_strings);
}

// * Performs both point doubling and point addition
struct coordinates *point_addition(struct coordinates *p, struct coordinates *q) {
    if (!(p && q)) { if (p) return p; else if (q) return q; return NULL; } // < return point when combining with ID
    else if ((p->y != q->y || p->x == 0) && p->x == q->x) { return NULL; } // < return ID upon adding inverses and upon doubling points with x = 0
    struct coordinates *r = (struct coordinates *) malloc(sizeof(struct coordinates)); unsigned long s;
    if (p->x == q->x && p->y == q->y) s = modular_division(((3 * ((p->x * p->x) % m) % m) + a) % m, (2 * p->y) % m);
    else s = modular_division(((p->y + (m - q->y)) % m), ((p->x + (m - q->x)) % m));
    r->x = (((s * s) % m) + inv((p->x + q->x) % m)) % m; r->y = (((s * ((p->x + inv(r->x)) % m)) % m) + inv(p->y)) % m; return r;
}

void argv_ERROR(unsigned long index, char **argv) { fprintf(stderr, "'%s' not interpretable as %s.\n", argv[index], symbol[index - 1]); exit(-index); }

void take_in_point(char symbol, struct coordinates **point) {
    char *inp = (char *) malloc(sizeof(char) * 25);
    while (1) { fprintf(stdout, "point %c = ", symbol);
	fscanf(stdin, "%s", inp); if (match(inp, point_at_infinity_strings)) break;
	// ^^ See if a mention of the point at infinity is there

	unsigned long new_x, new_y; if (sscanf(inp, "%lu,%lu", &new_x, &new_y) != 2) // I want to replace "PAI" with "pai", "P" with an underscored "p", "A" with an underscored "a", "I" with an underscored "i"
	{ fprintf(stderr, "'%s' is neither coordinates formatted like 'x,y'; nor '%s' or '%s' to signify the Point At Infinity (a.k.a. the identity element). Please try again:\n\n", inp, point_at_infinity_strings[0], point_at_infinity_strings[1]); } else { *point = (struct coordinates *) malloc(sizeof(struct coordinates)); (**point).x = new_x; (**point).y = new_y; break; }
    }; free(inp);
}

struct coordinates *point_multiplication(unsigned long multiplier, struct coordinates *base) {
    unsigned long down_rounded_base_two_log = down_rounded_BASE_2_logarithm(multiplier);
    struct coordinates **scalar_multiplication_backbone = (struct coordinates **) malloc(sizeof(struct coordinates *) * (down_rounded_base_two_log + 1));
    *scalar_multiplication_backbone = (struct coordinates *) malloc(sizeof(struct coordinates)); *scalar_multiplication_backbone = base;
    unsigned long index = 0; do { scalar_multiplication_backbone[index + 1] = point_addition(scalar_multiplication_backbone[index], scalar_multiplication_backbone[index]); index++; } while (index < down_rounded_base_two_log);
    // ^^ Initialize "scalar_multiplication_backbone"

    struct coordinates *permutation_accumulator = NULL;
    // ^^ First set the return value to the identity element (which is the point at infinity, which this program understand as a "NULL" pointer where a "struct coordinates" pointer was expected)

    if (multiplier != 0) {
	unsigned long down_rounded_base_two_log = down_rounded_BASE_2_logarithm(multiplier);
	while (multiplier != 0) {
	    permutation_accumulator = point_addition(scalar_multiplication_backbone[down_rounded_base_two_log], permutation_accumulator);
	    multiplier -= N_exponentiation(2, down_rounded_base_two_log);
	    down_rounded_base_two_log = down_rounded_BASE_2_logarithm(multiplier);
	}
    } free(scalar_multiplication_backbone);
    return permutation_accumulator;
}

void print_multiple_of_ECC_point(unsigned long multiplier, struct coordinates *result) { fprintf(stdout, "%luG = ", multiplier); FORMAL_print_point(result); }

struct coordinates *entire_calculation(unsigned long multiplier, struct coordinates *base)
{ struct coordinates *i = point_multiplication(multiplier, base); fprintf(stdout, "%lu * (%lu,%lu) = (%lu,%lu)\n", multiplier, base->x, base->y, i->x, i->y); return i; }

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
    fprintf(stdout, "base point (a.k.a. 'G') (x,y): (%lu,%lu)\n\n", _base_Point.x, _base_Point.y);
    // ^^ Display success

    unsigned long multiplier_Bob; fprintf(stdout, "Bob's secret value: "); fscanf(stdin, "%lu", &multiplier_Bob);
    fprintf(stdout, "Bob's calculation : ");  struct coordinates *public_Bob = entire_calculation(multiplier_Bob, &_base_Point);

    unsigned long multiplier_Alice; fprintf(stdout, "\nAlice's secret value: "); fscanf(stdin, "%lu", &multiplier_Alice);
    fprintf(stdout, "Alice's calculation : "); struct coordinates *public_Alice = entire_calculation(multiplier_Alice, &_base_Point);

    fprintf(stdout, "\nValue Alice received from Bob: "); FORMAL_print_point(public_Bob);
    fprintf(stdout, "Value Bob received from Alice: "); FORMAL_print_point(public_Alice);
    // ^^ Values parties receive from each other

    fprintf(stdout, "\nValue Alice calculates using Bob's public value: "); struct coordinates *Alice_end = entire_calculation(multiplier_Alice, public_Bob);
    fprintf(stdout, "Value Bob calculates using Alice's public value: "); struct coordinates *Bob_end = entire_calculation(multiplier_Bob, public_Alice);
    // ^^ Values parties synthesize individually

    if (Alice_end->x == Bob_end->x && Alice_end->y == Bob_end->y)
    { fprintf(stdout, "\nValues Bob and Alice calculated individually corresponded. Elliptic Curve Diffie-Hellman proof of concept successfull.\n\nReturning '0'.\n"); return 0; }
    else { fprintf(stdout, "\nValues Bob and Alice calculated individually did not correspond. Elliptic Curve Diffie-Hellman proof of concept not successfull.\n\nReturning '-1'.\n"); return -1; }
}
/* MATH NOTES:
 * 1). This is the case where p and q are inverses, so here I return the identity element
 */
