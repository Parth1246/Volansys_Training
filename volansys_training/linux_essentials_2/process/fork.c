#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(int argc , char * argv[])
{
    int pid;

    printf("before forking the parent\n");

    pid=fork();

    if(pid == 0)
    {
        printf("i am the child\n");
        exit(0);  // terminate the child
    }
    else
    {
        printf("i am the proud parent of pid %d\n",pid);
        
    }

    return 0;
}
