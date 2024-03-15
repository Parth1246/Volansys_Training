#include <signal.h>
#include <stdio.h>

int main()
{
    int pid1;
    int pid2;

    pid1 = fork();
    if (pid1 == 0) /* First child */
    {
        while (1) 
        {
            printf("pid1 is alive\n");
            sleep(1);
        }
    }

    pid2 = fork(); /* Second child */
    if (pid2 == 0)
    {
        while (1) 
        {
            printf("pid2 is alive\n");
            sleep(1);
        }
    }

    sleep(3);
    kill(pid1, SIGSTOP);
    sleep(3);
    kill(pid1, SIGCONT);
    sleep(3);
    kill(pid1, SIGINT); 
    kill(pid2, SIGINT);
}