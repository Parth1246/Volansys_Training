#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int signum)
{
    printf("\nyou are inside handler funnction\n");
    signal(SIGINT,SIG_DFL); // re register signal handller for default action
}

int main()
{
    signal(SIGINT,handler); //register signal handler 

    for(int i=0;;i++) //infinite loop
    {
        printf("%d: you are inside main func\n",i);
        sleep(1);
    }
    return 0;
}
