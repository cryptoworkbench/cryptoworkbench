/* DESCRIPTION:
 * This is my first attempt at using the execvp function.
 *
 * Try ./pass_args_on group_examplifier 25 1
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int skip = 1;
    if(execvp(*(argv + skip), argv + skip)) {
	fprintf(stderr, "Failed to find %s\n", *(argv + skip)); 
    }
    return 0;
}
