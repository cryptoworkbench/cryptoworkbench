#include <stdlib.h>

struct _CHANNEL_PTR_pair { void **head; void **iterator; };

void **open_CHANNEL();
struct _CHANNEL_PTR_pair INITIALIZE_CHANNEL_PTR_pair();
void *_close_CHANNEL(void **to_be_dereferenced);
