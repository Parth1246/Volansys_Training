#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    signal(SIGINT,SIG_IGN); //register signal handler for ignoring the signal

    for(int i=0;;i++) //infinite loop
    {
        printf("%d: you are inside main func\n",i);
        sleep(1);
    }
    return 0;
}
