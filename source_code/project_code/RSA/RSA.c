#include <stdio.h>
#include <stdlib.h>
#include "../../../libraries/functional/string.h"

int main(int argc, char **argv) {
    if (argc != 3) {
	printf("Supply program with primes like in the example below:\n");
	printf("%s 97 101\n", argv[0]);
	printf("\nInproper amount of arguments supplied:\nExiting -1.\n");
	return -1; }
    /* ### ^^ ### EXIT WHEN NOT ALL PRIMES WERE SUPPLIED ### ^^ ### */
    unsigned long p_1, p_2, totient, modulus;
    p_1 = str_to_ul(argv[1]);
    p_2 = str_to_ul(argv[2]);
    totient = (p_1 - 1) * (p_2 - 1);
    modulus = p_1 * p_2;

    printf("p_1: %lu\n", p_1);
    printf("p_2: %lu\n", p_2);
    printf("totient: %lu\n", totient);
    return 0;
}
