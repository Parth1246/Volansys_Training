#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
    pid_t cpid;
    if(fork() == 0)
    {
        exit(0); //terminate the child
    }
    else
    {
        cpid = wait(NULL); // repeating parent
    }

    printf("parent pid = %d\n",getpid());
    printf("child pid = %d\n",cpid);

    return 0;
}
