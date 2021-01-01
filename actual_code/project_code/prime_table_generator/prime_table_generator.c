/* Hello, I am ./prime_table_generator; the prime table creator.
 *
 * I use the sieve of Eratosthenes to generate prime tables.
 *
 * I am very picky with my input, I only listen when you supply me one with argument, or one and a second one which may only constitute 'stdout', '-nr', or '--no-rename'
 *
 * When the second argument you supply me with is anything else, I refuse to cooperate.
 *
 * The first argument you supply me with I will interpret as the upper bound to my sieve: this means I will not be able to confirm primality for any number greater than this limit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../libraries/functional/string.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
const char *temporary_name_prefix = "primes_less_than_";
const char *rename_command = "mv";
const char *final_name_prefix = "first_";
const char *final_name_appendix = "_primes";

int main(int argc, char *argv[]) {
    FILE *filestream = NULL; // Initialize the filestream to NULL
    unsigned long sieve_upper_bound; // we use an unsigned long to store the sieve's upper bound (limit)
    switch (argc) {
	case 3:
	    if (streql(argv[2], "stdout"))
		filestream = stdout;
	    else if (!(streql(argv[2], "-nr") || streql(argv[2], "--no-rename"))) {
		/* Message for when only one correct input was put in. */
		fprintf(stdout, "Still in dev . . .\n");
		return -1; }
	case 2:
	    sieve_upper_bound = string_to_unsigned_long(argv[1]);
	    break;
	default:
	    fprintf(stdout, "Program usage: %s <upper limit> [output filename]\n\n", argv[0]);
	    fprintf(stdout, "Use [output filename] to generate a prime table.\n\n\n");
	    fprintf(stdout, "For example:\n'%s 100 primes_less_than_100'\n\nwill generate the prime table with all the primes less than 100 in 'primes_less_than_100'.\n\n\n\n", argv[0]);
	    fprintf(stdout, "Incomplete argumentation problem, exiting -1.\n");
	    return -1;
    }

    int binary_mode;
    if (filestream != stdout) { /* Ask whether to enable binary_mode or not */
	fprintf(stdout, "Enable binary mode (0/1): ");
	fscanf(stdin, "%i", &binary_mode); fprintf(stdout, "\n");
    } if (binary_mode < 0) /* And reduce the answer to a boolean */
	binary_mode = 0;

    /* ### BEGIN PROGRAM ### */
    char *array = malloc(sizeof(char) * sieve_upper_bound);

    /* ### INITIALIZE THE ARRAY ### */
    for (unsigned long i = 0; i < sieve_upper_bound; i++)
	array[i] = ADDITIVE_IDENTITY;

    /* ### MARK ALL COMPOSITES NEGATIVE ### */
    for (unsigned long i = 2; i * i < sieve_upper_bound; i++)
	for (unsigned long j = i; j * i < sieve_upper_bound; j++)
	    array[j * i] = MULTIPLICATIVE_IDENTITY;

    /* ### PREPARE FILESTREAM ### */
    char *temporary_prime_table_name;
    if (filestream == stdout) {
	fprintf(stdout, "Complete list of primes less than %lu:\n", sieve_upper_bound);
    } else if (filestream == NULL) { // if the filestream is yet to be initialized, initialize a connection to an external prime table to be generated
	temporary_prime_table_name = malloc(sizeof(char) * (strlen(temporary_name_prefix) + char_in_val(sieve_upper_bound) + MULTIPLICATIVE_IDENTITY));
	sprintf(temporary_prime_table_name, "%s%lu", temporary_name_prefix, sieve_upper_bound);
	filestream = fopen(temporary_prime_table_name, "w");
    }

    unsigned long no_of_primes = 0; // WRITE OUT ALL NUMBERS WHICH ARE STILL POSITIVE (THE PRIMES)
    if (binary_mode) {
	for (unsigned long i = 2; i < sieve_upper_bound; i++)
	    if (array[i] == ADDITIVE_IDENTITY) {
		fwrite(&i, sizeof(unsigned long), 1, filestream);
		no_of_primes++; }
    } else {
	for (unsigned long i = 2; i < sieve_upper_bound; i++)
	    if (array[i] == ADDITIVE_IDENTITY) {
		fprintf(filestream, "%lu\n", i);
		no_of_primes++; }
    } free(array);

    if (filestream == stdout) {
	fprintf(stdout, "\n%lu primes printed to stdout.", no_of_primes);
    } else if (filestream != stdout) { // If we just wrote to an external file
	fclose(filestream); // Close this external file
	char *current_name = temporary_prime_table_name; // Save the old external file name so we can free it later (or otherwise it will be freed in the following if statement)

	if (!(argc == 3 && (streql(argv[2], "-nr") || streql(argv[2], "--no-rename")))) { // Unless otherwise specified, rename this old file
	    /* ### Prepare the new name ### */
	    char *final_table_name = malloc(sizeof(char) * (strlen(final_name_prefix) + char_in_val(no_of_primes) + strlen(final_name_appendix) + 1));
	    sprintf(final_table_name, "%s%lu%s", final_name_prefix, no_of_primes, final_name_appendix);

	    /* ### Prepare the rename command we will use to rename the closed file ### */
	    char *rename_command_string = malloc(sizeof(char) * (strlen(rename_command) + 1 + strlen(temporary_prime_table_name) + 1 + strlen(final_table_name) + 1));
	    sprintf(rename_command_string, "%s %s %s", rename_command, temporary_prime_table_name, final_table_name);
	    system(rename_command_string); free(rename_command_string);
	    
	    free(temporary_prime_table_name);
	    current_name = final_table_name;
	} fprintf(stdout, "%lu primes printed to %s.", no_of_primes, current_name);
	free(current_name);
    } fprintf(stdout, "\n");

    /* Exit cleanly */
    return 0; }
