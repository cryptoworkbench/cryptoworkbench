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
#include "modular_group_element_table_generator.h"

void QUIT_ON_ARGV_ONE_ERROR(char *argv_one) { fprintf(stderr, ARGV_ONE_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp infinite field CAP: to attempt to open from registry the group '<\u2124/%s\u2124>' makes no sense to me. Returning '-1'.\n", argv_one);
    exit(-1);
} // << ^^ Works in conjunction with the definition of ARGV_ONE_INSTRUCTION

void QUIT_ON_ARGV_TWO_ERROR(char *argv_two) { fprintf(stderr, ARGV_TWO_INSTRUCTION);
    fprintf(stderr, "\nFATAL ERROR: cannot grasp group ID: '%s' is neither '0' nor '1'. Returning '-2'.\n", argv_two);
    exit(-2);
} // << ^^ Works in conjunction with the definition of ARGV_TWO_INSTRUCTION

int main(int argc, char **argv) {
    if (2 > argc || !STR_could_be_parsed_into_UL(argv[1], &MOD)) QUIT_ON_ARGV_ONE_ERROR(argv[1]);
    if (3 > argc || !STR_could_be_parsed_into_enum_GROUP_IDentity(argv[2], &_group.ID)) QUIT_ON_ARGV_TWO_ERROR(argv[2]);
    // ^^ Parse the infinite field CAP and group ID

    unsigned long count = 0;
    for (unsigned long element = boolean_from_ID_Sloth(&_group); element < _group.MOD; element++)
	if (_group.ID == ADDITIVE || GCD(_group.MOD, element) == MULTIPLICATIVE_IDENTITY) {
	    fprintf(stdout, "%lu\n", element);
	    count++;
	}
    // ^^ Export the group

    printf("\nExported %lu elements.\n", count);
    char *BUFFER = BUFFER_OF_SIZE(50); sprintf(BUFFER, "Exported \u2115%lu%s", _group.MOD, operation_symbol_from_ID_Sloth(&_group));
    open_and_append_to_LOGBOOK(argv[0], BUFFER); free(BUFFER); close_logbook();
    // ^^ Notify in the LOGBOOK about my operations

    if (4 > argc) return 1; else execvp(*(argv + 3), (argv + 3));
    // ^^ Pass on the command string which begins at argv[3], or quit if appropiate
}
