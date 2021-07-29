/* DESCRIPTION:
 * This is my implementation of the sieve of Eratosthenes.
 * This implementation of the sieve of Eratosthenes is nicely embedded within an interface for creating prime tables.
 *
 * My most basic usage case would be:
 * './prime_table_generator <sieve limit>'
 * 
 * For example:
 * './prime_table_generator 20'
 *
 * This would make me generate an external prime table with all the primes greater than 1 and less than 20 in it.
 *
 * I do like to store in the name of such a prime table file the number of primes within it.
 * Unfortunatly I do not know how many primes will be in a prime table until I finish generating it (sieve mechanics).
 * So I would write to 'primes_less_than_100' and then rename to 'first_25_primes'; because there are 25 primes less than 100.
 * You get the idea: I use temporary filenames.
 *
 * In order to output to stdout, append 'stdout', like this:
 * './prime_table_generator 20 stdout'
 *
 * When you put 'stdout' like this, there is no external prime table generated.
 *
 * If you like to output to an external table file, but like my initial naming sceme better, put '--no-rename' or '-nr' instead. */
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1
/* global const char * declarations below */
const char *temporary_name_prefix = "primes_less_than_";
const char *rename_command = "mv";
const char *final_name_prefix = "first_";
const char *final_name_appendix = "_primes";

int main(int argc, char *argv[]) {
    FILE *filestream = NULL; // Initialize the filestream to NULL
    unsigned long *sieve_upper_bound; // we use an unsigned long to store the sieve's upper bound (limit)
    switch (argc) {
	case 3:
	    if (streql(argv[2], "stdout"))
		filestream = stdout;
	    else if (!(streql(argv[2], "-nr") || streql(argv[2], "--no-rename"))) {
		/* Message for when only one correct input was put in. */
		fprintf(stdout, "Still in dev . . .\n");
		return -1; }
	case 2:
	    if (sieve_upper_bound = ul_ptr_from_str(malloc(sizeof(unsigned long)), argv[1])) break;
	    else { fprintf(stderr, "Failed to interpret '%s' as the sieve's proposed upper limit.\n", argv[1]); return -1; }
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
    char *array = malloc(sizeof(char) * *sieve_upper_bound);

    /* ### INITIALIZE THE ARRAY ### */
    for (unsigned long i = 0; i < *sieve_upper_bound; i++)
	array[i] = ADDITIVE_IDENTITY;

    /* ### MARK ALL COMPOSITES NEGATIVE ### */
    for (unsigned long i = 2; i * i < *sieve_upper_bound; i++)
	for (unsigned long j = i; j * i < *sieve_upper_bound; j++)
	    array[j * i] = MULTIPLICATIVE_IDENTITY;

    /* ### PREPARE FILESTREAM ### */
    char *temporary_prime_table_name;
    if (filestream == stdout) {
	fprintf(stdout, "Complete list of primes less than %lu:\n", *sieve_upper_bound);
    } else if (filestream == NULL) { // if the filestream is yet to be initialized, initialize a connection to an external prime table to be generated
	temporary_prime_table_name = malloc(sizeof(char) * (str_len(temporary_name_prefix) + char_in_val(*sieve_upper_bound) + MULTIPLICATIVE_IDENTITY));
	sprintf(temporary_prime_table_name, "%s%lu", temporary_name_prefix, *sieve_upper_bound);
	filestream = fopen(temporary_prime_table_name, "w");
    }

    unsigned long no_of_primes = 0; // WRITE OUT ALL NUMBERS WHICH ARE STILL POSITIVE (THE PRIMES)
    if (binary_mode) {
	for (unsigned long i = 2; i < *sieve_upper_bound; i++)
	    if (array[i] == ADDITIVE_IDENTITY) {
		fwrite(&i, sizeof(unsigned long), 1, filestream);
		no_of_primes++; }
    } else {
	for (unsigned long i = 2; i < *sieve_upper_bound; i++)
	    if (array[i] == ADDITIVE_IDENTITY) {
		fprintf(filestream, "%lu\n", i);
		no_of_primes++; }
    } free(array);

    if (filestream == stdout) {
	fprintf(stdout, "\n%lu primes printed to stdout", no_of_primes);
    } else if (filestream != stdout) { // If we just wrote to an external file
	fclose(filestream); // Close this external file
	char *current_name = temporary_prime_table_name; // Save the old external file name so we can free it later (or otherwise it will be freed in the following if statement)

	if (!(argc == 3 && (streql(argv[2], "-nr") || streql(argv[2], "--no-rename")))) { // Unless otherwise specified, rename this old file
	    /* ### Prepare the new name ### */
	    char *final_table_name = malloc(sizeof(char) * (str_len(final_name_prefix) + char_in_val(no_of_primes) + str_len(final_name_appendix) + 1));
	    sprintf(final_table_name, "%s%lu%s", final_name_prefix, no_of_primes, final_name_appendix);

	    /* ### Prepare the rename command we will use to rename the closed file ### */
	    char *rename_command_string = malloc(sizeof(char) * (str_len(rename_command) + 1 + str_len(temporary_prime_table_name) + 1 + str_len(final_table_name) + 1));
	    sprintf(rename_command_string, "%s %s %s", rename_command, temporary_prime_table_name, final_table_name);
	    system(rename_command_string); free(rename_command_string);
	    
	    free(temporary_prime_table_name);
	    current_name = final_table_name;
	} fprintf(stdout, "%lu primes printed to ", no_of_primes);
	if (binary_mode) {
	    printf("binary ");
	} else {
	    printf("ASCII ");
	} printf("file '%s'", current_name);
	free(current_name);
    } fprintf(stdout, ".\n");

    /* Exit cleanly (0) */
    exit(0); }
