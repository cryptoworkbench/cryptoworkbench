/* DESCRIPTION:
 * This is my first attempt at using the execvp function.
 *
 * Try ./pass_args_on 24 0 group_examplifier 25 1
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int skip = 1;
    execvp("group_examplifier", argv + skip);
    // execvp("argv_zero", argv + 3);
    return 0;
}
