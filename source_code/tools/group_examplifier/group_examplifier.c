/* USAGE:
 * ./group_examplifier <CAP> <ID> [name of output file] [external command] [argument string for external command]
 *
 * Examplifies groups using CAP as modulus value on the infinite field N.
 * 
 * So for example:
 * ./group_examplifier 12 0
 *
 * will yield the elements that are in the group concerning analog clocks (additive group).
 *
 * And also:
 * ./group_examplifier 24 0
 *
 * will yield the elements that are in the group concerning digital clocks (additive group).
 *
 * While:
 * ./group_examplifier 17 1
 *
 * will yield the multiplicative group that Cruise Brit talked about (used as an example) in his two video's where he gives an example of a DH key agreement:
 * https://www.youtube.com/watch?v=YEBfamv-_do (call "Public key cryptography - Diffie-Hellman Key Exchange (full version)")
 * https://www.youtube.com/watch?v=3QnD2c4Xovk (called "Public Key Cryptography: Diffie-Hellman Key Exchange (short version)")
 * https://www.youtube.com/watch?v=ESPT_36pUFc (supplementary video in this list about Diffie-Hellman) */
#include <stdio.h>
#include <unistd.h>
#include "../../libraries/mathematics/maths.h" // <<< Needed for "GCD()"
#include "../../libraries/functional/string.h" // <<< Needed for "ul_ptr_from_str()"
#include "../../libraries/functional/LOGBOOK_library.h" // <<< Needed for "ul_ptr_from_str()"
// ^^^ LIBRARY INCLUSIONS

#define ARGV_TWO_INSTRUCTION "Please provide as second argument '0' for the additive identity,\nOr '1' for the multiplicative identity.\n"
#define ARGV_ONE_INSTRUCTION "Please provide as first argument the modulus of the group (in decimal notation).\n"
#define MULTIPLICATIVE_IDENTITY 1
#define ADDITIVE_IDENTITY 0
// ^^^ DEFINITIONS

// struct group_prams { unsigned long ID; unsigned long CAP; };
struct group_prams group;
// ^^^ PROGRAM VARIABLES

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) {
    fprintf(stderr, ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is neither '0' nor '1'. Returning -2.\n", argv_two);
    exit(-2);
} // << ^^ Works in conjunction with the definition of ARGV_TWO_INSTRUCTION

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) {
    fprintf(stderr, ARGV_ONE_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from registry the group '<\u2124/%s\u2124>' makes no sense to me. Returning -1.\n", argv_one);
    exit(-1);
} // << ^^ Works in conjunction with the definition of ARGV_ONE_INSTRUCTION

void main(int argc, char **argv) { FILE *main_fs = stdout;
    if (2 > argc || !(ul_ptr_from_str(&group.CAP, argv[1]))) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    if (3 > argc || !(ul_ptr_from_str(&group.ID, argv[2]))) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    if (3 < argc) main_fs = fopen(argv[3], "w");
    // ^^^ Parse the first three arguments, argv[1] and argv[2] are mandatory, argv[3] is not
    
    for (unsigned long element = group.ID; element < group.CAP; element++)
	if (group.ID == ADDITIVE_IDENTITY || GCD(group.CAP, element) == MULTIPLICATIVE_IDENTITY) fprintf(main_fs, "%lu\n", element);
    if (main_fs != stdout) fclose(main_fs); // <^^ fprintf() the list of elements to main_fs and close this filestream.

    if (5 > argc) exit(0);
    else execvp(*(argv + 4), (argv + 4)); // <<< Pass on command string which begins at argv[4]
}
