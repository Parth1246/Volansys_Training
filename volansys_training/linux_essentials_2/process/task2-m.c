#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>


int main(){

    int pid1;

    pid1 = fork();   /* Duplicate process. Child and parent continue from here */

    if(pid1 == 0)   //child 1
    {
        printf("im the first child pid %d and my ppid %d\n",getpid(),getppid());
    }
    else            //parent
    {
        if(fork() == 0)     //child 2
        {
            printf("im the child pid %d of child ppid %d\n",getpid(),getppid());
        }
        else                //parent of child 2 , child 3 of main parent
        {
            printf("im the parent pid %d and my ppid %d\n",getpid(),getppid());
        }
    }
    return 0;
}
