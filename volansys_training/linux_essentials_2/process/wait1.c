#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


void waitexample()
{
    int stat;

    if(fork() == 0){
        exit(1);
    }
    else
        wait(&stat);

    if(WIFEXITED(stat))
        printf("Exit Status: %d\n",WIFEXITED(stat));
    else if(WIFEXITED(stat))
        psignal(WTERMSIG(stat),"Exit Signal");
}

int main()
{
    waitexample();

    return 0;
}
