#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signum)
{
    printf("you are in handler func\n");
}

int main()
{
    pid_t pid;
    signal(SIGUSR1,sig_handler);  //register signal handler
    printf("you are in main func\n");
    pid=getpid();  //process id of itself
    kill(pid,SIGUSR1);  //send SIGUSR1 to itself
    printf("you are again inside main func\n");

    return 0;
}
