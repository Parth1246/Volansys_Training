#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int signum)
{
    printf("\n inside of the handler function\n");
}

int main()
{
    signal(SIGINT,handler); // register signal handler
    for(int i=0;;i++)
    {
        printf("%d: you are in main function\n",i);
        sleep(1); // delay of 1 second
    }
    return 0;
}
