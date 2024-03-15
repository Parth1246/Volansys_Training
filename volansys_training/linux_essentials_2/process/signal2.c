#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_sigint(int sig)
{
    printf("termintated %d\n",sig);
}

int main()
{
    signal(SIGINT,handle_sigint);
    while(1)
    {
        printf("Hello World\n");
        sleep(1);
    }

    return 0;
}
