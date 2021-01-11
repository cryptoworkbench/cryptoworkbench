#include <stdio.h>
#include "../../../libraries/functional/string.h" // ul_to_str & char_in_val

unsigned long euclidean_algorithm(unsigned long big, unsigned long small) {
    if (big % small == 0)
	return small;

    return euclidean_algorithm(small, big % small);
}

unsigned long totient_function_of(unsigned long x) {
    unsigned long ret = 0;
    for (unsigned long i = 1; i < x; i++)
	if (euclidean_algorithm(x, i) == 1)
	    ret++;

    return ret;
}

int main(int argc, char *argv[]) {
    unsigned long cell_width = char_in_val(100);
    for (unsigned long i = 1; i < 100; i++) {
	fprintf(stdout, "Totient of %s: %s", ul_to_str(i, cell_width), ul_to_str(totient_function_of(i), cell_width));

	if (totient_function_of(i) + 1 == i) {
	    fprintf(stdout, "	Prime!");
	} fprintf(stdout, "\n");
    }
    return 0;
}
