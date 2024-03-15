#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

#define MAX 1024

void sig_handler(int signum)
{
    printf("caught the signal...\n");
    printf("exiting...\n");
    sleep(1);
    exit(0);
}

int main()
{
    // create pipe
    int p[2];
    int get;
    char x[MAX];
    char y[MAX];

    if (pipe(p) == -1)
    {
        return 1;
    }
    else
    {
        signal(SIGINT, sig_handler);
        int pid = fork();
        if (pid == 0)
        {
            while (1)
            {
                printf("Enter Command: ");
                fgets(x, 1024, stdin);

                write(p[1], x, 1024);
                printf("Child send %s\n", x);
                sleep(1);
            }
            //exit(0);
        }
        else
        {
            // parent process
            while (1)
            {
                if ((get = read(p[0], y, sizeof(y))) > 0)
                {
                    if ((strcmp(y, "quit")) == 0)
                    {
                        break;
                    }
                    printf("Parent Recieved %s\n", y);
                    printf("Command Execution: %s\n", y);
                    system(y);
                }
            }
            //exit(0);
        }
        close(p[0]);
        close(p[1]);
    }
    return 0;
}