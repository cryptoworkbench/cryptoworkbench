#include <stdio.h>
#define RED "\x1B[31m"
#define BLUE "\x1B[34m"

int main(int argc, char **argv) {
    printf("%sred\n", RED);
    printf("%sblue\n", BLUE);
    return 0;
}
