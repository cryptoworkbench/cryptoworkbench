// Examplifies additive and multiplicative groups and lists their generators.
#include <stdio.h>
#include <stdlib.h>
#include "../../libraries/functional/string.h" // <<< Needed for "match()", "STR_could_be_parsed_into_UL()", etc
#include "../../libraries/functional/triple_ref_pointers.h" // << Needed for "zoom_out()", "initialize_PTR_pair()", and "zoom_in()"
#include "../../libraries/mathematics/universal_group_library.h" // <<< Needed for "group_OBJ"
#include "../../libraries/mathematics/maths.h" // <<< Needed for "group_OBJ"

int main(int argc, char **argv) { id_ = malloc(sizeof(unsigned long));
    str_represents_ul(argv[2], id_);
    FILE *a = open_group(argv);
    return 0;
}
