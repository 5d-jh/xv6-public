#include "types.h"
#include "user.h"

int
main(void)
{
    int pid;
    printf(1, "[parent] before fork: %d\n", getNumFreePages());

    pid = fork();

    if (pid < 0)
        printf(1, "fork failed");
    else if (pid == 0)
    {
        printf(1, "[child] after fork: %d\n", getNumFreePages());
    }
    else
    {
        wait();
        printf(1, "[parent] after child process exit: %d\n", getNumFreePages());
    }
    exit();
}