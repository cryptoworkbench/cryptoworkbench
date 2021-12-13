#include "universal_group_library.h"

enum GROUP_IDentity *STR_could_be_parsed_into_ID(char *STR, enum GROUP_IDentity *ID_sloth) {
    if (match(STR, 2, "0", "additive")) { *ID_sloth = ADDITIVE; return ID_sloth; }
    else if (match(STR, 2, "1", "multiplicative")) { *ID_sloth = MULTIPLICATIVE; return ID_sloth; }
    else return NULL;
}

int ID_as_boolean(enum GROUP_IDentity ID) {
    if (ID == ADDITIVE) return 0;
    else if (ID == MULTIPLICATIVE) return 1;
}
