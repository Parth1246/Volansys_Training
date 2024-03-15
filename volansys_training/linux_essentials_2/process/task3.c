#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// declaration of signal we are using
void sighup();
void sigint();
void sigquit();

void main()
{
    int pid;

    // get child process
    if ((pid = fork()) < 0)
    {
        perror("fork\n");
        exit(1);
    }

    // child
    if (pid == 0)
    {
        while (1)
        {
            signal(SIGHUP, sighup);
            signal(SIGINT, sigint);
            signal(SIGQUIT, sigquit);
        }
        
        // loop forever
    }
    // parent
    else
    {
        // pid holds id of child
        printf("\nPARENT: sending SIGHUP\n\n");
        kill(pid, SIGHUP);
        // pause it for 3 sec
        sleep(3);
        printf("\nPARENT: sending SIGINT\n\n");
        kill(pid, SIGINT);
        // again pause it for 3 sec
        sleep(3);
        printf("\nPARENT: sending SIQUIT\n\n");
        kill(pid, SIGQUIT);
        sleep(3);
    }
}

void sighup()
{
    signal(SIGHUP, sighup); // reset the signal
    printf("CHILD: I have received a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT, sigint); // reset the signal
    printf("CHILD: I have received a SIGINT\n");
}

void sigquit()
{
    printf("My PARENT has killed me!!!\n");
    exit(0);
}
