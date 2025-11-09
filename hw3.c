#include <limits.h>

#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "created process %d\n", getpid());
    for (int i = 0; i < 3; i++)
    {
        int pid = fork();

        if (pid != 0)
            printf(1, "created process %d\n", pid);
        else
            break;
    }

    int mypid = getpid();

    int j = 0;
    int cnt = 0;
    while (1)
    {
        printf(1, "%d, priority: %d, cnt: %d\n", mypid, get_proc_priority(), cnt++);
        while (j++ < INT_MAX) {}
        j = 0;
    }
}
