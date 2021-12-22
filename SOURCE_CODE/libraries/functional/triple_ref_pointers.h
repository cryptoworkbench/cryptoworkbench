#include <stdlib.h>

struct _CHANNEL_PTR_pair { void **head; void **iterator; };

void **open_CHANNEL();
void INITIALIZE_CHANNEL_PTR_pair(struct _CHANNEL_PTR_pair *in);
void *_close_CHANNEL(void **to_be_dereferenced);
