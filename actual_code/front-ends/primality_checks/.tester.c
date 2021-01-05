/* DESCRIPTION
 * Code to test the other code. */
#include <stdio.h>
#include "../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.h"

int main(int argc, char **argv) {
    for (unsigned long i = 0; i < 10000; i++) {
	unsigned long var = prime(i, argv[1], 1);
	switch (var) {
	    case 1:
		printf("%lu\n", i);
		break;
	    case 2:
		printf("prime_table_too short!\n");
		return -1;
	    case 3:
		printf("failed to open\n");
		return -2;
	    default:
		continue;
	}
    }

    return 0;
}
