#include <unistd.h>

void main() {
    execlp("less", "less", ".LOGBOOK", 0);
}
