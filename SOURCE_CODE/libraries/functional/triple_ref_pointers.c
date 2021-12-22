#include "triple_ref_pointers.h"

void **CHANNEL_open() {
    void ***link;
    *(*(link = (void ***) malloc(sizeof(void *))) = (void **) malloc(sizeof(void *))) = NULL;
    void **source = *link; free(link);
    return source; }
// ^^ Open source

void initialize_PTR_pair(void **PTR_one, void **PTR_two) { *PTR_one = *PTR_two = CHANNEL_open(); }

void *_CHANNEL_close(void **to_be_dereferenced) {
    void *return_value = *to_be_dereferenced; free(to_be_dereferenced);
    return return_value; }
// ^^ Cut umbilical cord, disintermediates the pointer that was required for the triple ref technique.

