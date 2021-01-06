#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#include "../../libraries/mathematics/maths.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
	printf("This program takes the union of two factor sets.\n");
	printf("\nUSAGE:\n%s <first factor set denoted as representative composite number> <second factor set denoted as representative composite number>\n", argv[0]);
	printf("\nWrong program usage. Exiting -1.\n");
	return -1; }
    /* ### ^^ ### EXIT WHEN NOT ENOUGH FACTOR SETS WERE SUPPLIED ### ^^ ### */
    unsigned long set_one = string_to_unsigned_long(argv[1]);
    unsigned long set_two = string_to_unsigned_long(argv[2]);

    printf("Factor set #1: '%lu'\n", set_one);
    printf("Factor set #2: '%lu'\n", set_two);

    if (!(set_one <= set_two)) {
	unsigned long temp = set_two; // Temporarily save set_two in temp
	set_two = set_one; set_one = temp; }
    /* ### ^^ ### SWITCH AROUND set_one AND BIG_FACTOR_SET IF SMALL_FACTOR_SET IS GREATER THAN set_two ### ^^ ### */

    unsigned long itersection_of_small_factor_set_and_big_factor_set = GCD(set_two, set_one);
    printf("\n'%lu' \u2229 '%lu' = '%lu'\n", set_two, set_one, itersection_of_small_factor_set_and_big_factor_set);
    return 0;
}
