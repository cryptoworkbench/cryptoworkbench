#include <stdio.h>
#include "../../../libraries/functional/string.h"

unsigned int prime(unsigned long potential_prime) {
    for (unsigned long i = 2; i <= potential_prime / 2; i++)
	if (potential_prime % i == 0)
	    return 0; // Prime

    return 1; // Not prime
}

int main(int argc, char *argv[]) {
    unsigned long limit;
    switch (argc) {
	case 2:
	    limit = string_to_int(argv[1]);
	    break;
	default:
	    printf("Program takes the union of factor sets %s <first factor set denoted as representative composite number> <second factor set denoted as representative composite number>\n", argv[0]);
	    printf("\nWrong program usage.\n\n\nExiting -1\n");
	    return -1;
    }

    printf("Limit: ");
    if (2 > argc) {
	scanf("%lu", &limit);
    } else { printf("%lu\n", limit); }

    for (unsigned long i = 1; i <= limit; i++)
	if (prime(i))
	    printf("%lu\n", i);
}
