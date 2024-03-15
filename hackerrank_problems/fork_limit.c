#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    int pid[10];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if ((pid[i] = fork()) == 0)
        {
            // child process
            printf("i am child %d\n", getpid());
        }
        else
        {
            wait(NULL);
            // parent process
            printf("i am parent %d\n", getpid());
        }
    }

    return 0;
}