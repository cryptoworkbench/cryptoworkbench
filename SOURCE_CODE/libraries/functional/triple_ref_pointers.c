#include "triple_ref_pointers.h"

void **open_CHANNEL() {
    void ***link;
    *(*(link = (void ***) malloc(sizeof(void *))) = (void **) malloc(sizeof(void *))) = NULL;
    void **source = *link; free(link);
    return source; }
// ^^ Open source

void INITIALIZE_CHANNEL_PTR_pair(struct _CHANNEL_PTR_pair *in) { in->iterator = in->head = open_CHANNEL(); }

void *_close_CHANNEL(void **to_be_dereferenced) {
    void *return_value = *to_be_dereferenced; free(to_be_dereferenced);
    return return_value; }
// ^^ Cut umbilical cord, disintermediates the pointer that was required for the triple ref technique.

