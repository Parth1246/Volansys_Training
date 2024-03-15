#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signum)
{
    printf("\n you are inside handler func\n");
}

int main()
{
    signal(SIGUSR1,sig_handler);
    printf("you are in main func\n");
    raise(SIGUSR1);
    printf("you are again in main func\n");

    return 0;
}
