#include <signal.h>
#include <stddef.h>

int catch_signal(int sig, void (*handler)(int));
