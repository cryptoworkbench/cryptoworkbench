#include <unistd.h>

int main() {
    execlp("less", "less", ".LOGBOOK", NULL);
}
