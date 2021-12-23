#include <stdlib.h>

struct _CHANNEL_PTR_pair { void **head; void **iterator; }; // << I have gone through the deductions and figured it's best not to try to make these "void ***"'s

void **open_CHANNEL();
struct _CHANNEL_PTR_pair INITIALIZE_CHANNEL_PTR_pair();
void *_close_CHANNEL(void **to_be_dereferenced);
