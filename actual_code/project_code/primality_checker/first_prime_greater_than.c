/* Reads an ASCII prime lookup table as can be generated with ../prime_table_generator/prime_table_generator
 *
 * Developer ambitions:
 * ~ Make it read binary prime lookup tables, which can also be generated with ../prime_table_generator/prime_table_generator
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
    { fprintf(stderr, "Proper amount of arguments not supplied.\n"); return -1; }

    FILE *fs; if (!(fs = fopen(argv[1], "r")))
    { fprintf(stderr, "Failed to open prime table.\n\nExiting -1;\n"); return -1; }

    unsigned long number;
    printf("\nFind first prime greater than: ");
    fscanf(stdin, "%lu", &number);

    unsigned int binary;
    fprintf(stdout, "Did you supply me with a binary prime lookup table (0/1)? ");
    fscanf(stdin, "%i", &binary);

    int success_reading;
    unsigned long current_prime;
    if (binary) {
	while (success_reading = fread(&current_prime, sizeof(unsigned long), 1, fs))
	    if (current_prime > number)
		break;
    } else {
	while (success_reading = fscanf(fs, "%lu\n", &current_prime) + 1)
	    if (current_prime > number)
		break; }

    if (success_reading)
	fprintf(stdout, "First prime greater than %lu: %lu.\n", number, current_prime);
    else
	fprintf(stderr, "Prime table too short!\n");

    return 0; }
