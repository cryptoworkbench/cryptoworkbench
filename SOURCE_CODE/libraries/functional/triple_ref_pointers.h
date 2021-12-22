#include <stdlib.h>

struct _CHANNEL_PTR_pair { void **head; void **iterator; };

void **open_CHANNEL();
void INITIALIZE_CHANNEL_PTR_pair(void ***PTR_one, void ***PTR_two);
void *_close_CHANNEL(void **to_be_dereferenced);
