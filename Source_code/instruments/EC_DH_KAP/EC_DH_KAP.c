/* OLD ABSTRACT:
 * This code was inspired by: https://www.youtube.com/watch?v=F3zzNa42-tQ
 * And it was written with help from the book "Serious Cryptography: A practical guide to Modern Encryption"
 *
 * In the above YouTube video. An example calculation is given which I have repeated here.
 *
 * CURRENT INFORMATION:
 * Working on a scalar multiplication function. Thus far I have created the array allocation functionality only.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/mathematics/maths.h"
// ^^ LIBRARY INCLUSIONS

#define A 2
#define B 2
#define CARDINALITY 19
#define MOD 17

struct ECC_point {
    unsigned long x;
    unsigned long y; };
// ^^ STRUCTURE TO CAPTURE POINT IDEA

void field_combination(struct ECC_point *P, struct ECC_point *Q, struct ECC_point *R) {
    unsigned long old_Px = P->x;
    if (P == NULL) { R->x = Q->x; R->y = Q->y; return; }
    if (Q == NULL) { R->x = P->x; R->y = P->y; return; }
    // ^^^ A NULL pointer will be used to represent the point at infinity

    unsigned long m; // <<< Declare the needed variables
    if (P->x == Q->x && P->y == Q->y) {
	m = (((((mod_exponentiate(P->x, 2, MOD) * 3) % MOD) + A) % MOD) * multiplicative_inverse((P->y * 2) % MOD, MOD)) % MOD; // Formula for point doubling
	printf("The tangent was: %lu\n\n", m);
    }
    else {
	m = (((Q->y + (MOD - P->y)) % MOD) * multiplicative_inverse(((Q->x + (MOD - P->x)) % MOD), MOD)) % MOD;
	printf("The slope was: %lu\n\n", m);
    }// <<< Formula for point addition
    unsigned long new_x = (((mod_exponentiate(m, 2, MOD) + (MOD - P->x)) % MOD) + (MOD - P->x)) % MOD; 
    unsigned long new_y = (((m * ((P->x + (MOD - R->x)) % MOD)) % MOD) + (MOD - P->y)) % MOD; // <<< Formula for 'y' coordinate
    R->x = new_x;
    R->y = new_y;
}

struct ECC_point *scalar_array(struct ECC_point *Base_Point, unsigned long cardinality) {
    unsigned long least_base_two_logarithm = down_rounded_base_2_logarithm(cardinality); unsigned long index = 0;
    printf("Least base two logarithm of cardinality (%lu) of group: %lu\n", cardinality, least_base_two_logarithm);
    struct ECC_point *point_array = (struct ECC_point *) malloc(sizeof(struct ECC_point) * (least_base_two_logarithm + 1));
    // ^^ Prepare necessary variables

    point_array[index].x = Base_Point->x; point_array[index].y = Base_Point->y; do {
	printf("2^%luK = %luK = (%lu, %lu)\n", index, exponentiate(2, index), point_array[index].x, point_array[index].y, index);
	field_combination(point_array + index, point_array + index, point_array + index + 1); index++;
    } while (index <= least_base_two_logarithm);
    // ^^^ Initialize array

    return point_array;
}

int main(int argc, char **argv) { fprintf(stdout, "Domain parameters:\n");
    struct ECC_point *Base_Point = (struct ECC_point *) malloc(sizeof(struct ECC_point)); Base_Point->x = 5; Base_Point->y = 1;
    fprintf(stdout, "Base point: (%lu, %lu)\n", Base_Point->x, Base_Point->y);
    fprintf(stdout, "Cardinality: %lu\n", CARDINALITY);
    fprintf(stdout, "Modulus: %lu\n", MOD);
    fprintf(stdout, "A: %lu\n", A);
    fprintf(stdout, "B: %lu\n\n", B);

    struct ECC_point *working_array = scalar_array(Base_Point, CARDINALITY);

    unsigned long original_multiplier;
    printf("\nWhat multiplier do you wish to test? : ");
    fscanf(stdin, "%lu", &original_multiplier);

    printf("Original multiplier: %lu\n", original_multiplier); unsigned long multiplier = original_multiplier;
    unsigned long least_base_two_logarithm = down_rounded_base_2_logarithm(multiplier); // <<< We need the rounded down base 2 log of multiplier
    printf("Least base two logarithm of original multiplier: %lu\n", least_base_two_logarithm); // <<< Display this number

    struct ECC_point *R  = (struct ECC_point *) malloc(sizeof(struct ECC_point));
    R->x = working_array[least_base_two_logarithm].x; R->y = working_array[least_base_two_logarithm].y; // <<< Determine the first element we must mix
    printf("Initializing R to: (%lu, %lu)\n", R->x, R->y); // <<< Display it's coordinates
    multiplier -= exponentiate(2, least_base_two_logarithm); // <<< Calculate updated multiplier
    printf("Updated multiplier: %lu\n", multiplier); // <<< Display updated multiplier
    least_base_two_logarithm = down_rounded_base_2_logarithm(multiplier); // <<< Calculate new base 2 log
    printf("Updated least base two logarithm of multiplier: %lu\n", least_base_two_logarithm); // <<< Display this number
    while (multiplier != 0) {
	printf("\n\nWHILE LOOP ITERATION:\n");
	printf("Combining element: (%lu, %lu)\n", working_array[least_base_two_logarithm].x, working_array[least_base_two_logarithm].y);
	printf("With element: (%lu, %lu)\n", R->x, R->y);
	field_combination(R, working_array + least_base_two_logarithm, R);
	printf("New return value: (%lu, %lu)\n", R->x, R->y);
	multiplier -= exponentiate(2, least_base_two_logarithm);
	printf("New multiplier: %lu\n", multiplier);
	least_base_two_logarithm = down_rounded_base_2_logarithm(multiplier);
	printf("New least base two logarithm of multiplier: %lu\n", least_base_two_logarithm);
    }
    // ^^ Calculate point
    printf("%lu(%lu, %lu) = (%lu, %lu)\n", original_multiplier, Base_Point->x, Base_Point->y, R->x, R->y);

    struct ECC_point *new = (struct ECC_point *) malloc(sizeof(struct ECC_point));
    printf("New.x: "); fscanf(stdin, "%lu", &new->x);
    printf("New.y: "); fscanf(stdin, "%lu", &new->y);
    printf("New: (%lu, %lu)\n", new->x, new->y);
    unsigned long index; while (1) {
	printf("Index to take?: ");
	fscanf(stdin, "%lu", &index);
	printf("Combining with: (%lu, %lu)\n", working_array[index].x, working_array[index].y);
	field_combination(new, working_array + index, new);
	printf("Result: (%lu, %lu)\n", new->x, new->y);
    }
    exit(0);
}
