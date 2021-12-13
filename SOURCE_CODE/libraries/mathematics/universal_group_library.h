#include "../functional/string.h"
#define ADDITIVE_IDENTITY 0
#define MULTIPLICATIVE_IDENTITY 1

enum GROUP_IDentity { ADDITIVE, MULTIPLICATIVE };

typedef struct group_STRUCT {
    enum GROUP_IDentity ID;
    unsigned long MOD;
} group_OBJ;

enum GROUP_IDentity *STR_could_be_parsed_into_ID(char *STR, enum GROUP_IDentity *ID_sloth); // << Returns 0 upon parsing failure, otherwise parses "0" or "1" into their respective ENUM equivalents (a.k.a. representations)
int ID_as_boolean(enum GROUP_IDentity ID); // << Returns "0" when the identity is additive; returns "1" when the identity is multiplicative (converts ENUM into int)
// ^^^ Combined these functions can turn the string "0" into a zero int and the string "1" into an int which equals the quantity '1'
