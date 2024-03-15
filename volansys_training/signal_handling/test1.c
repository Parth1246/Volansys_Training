#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int mysignal)
{
    printf("my handle with signal %d\n",mysignal);
}

int main(int argc,char *argv[])
{
    int i=0;
    signal(SIGTERM,handler);

    while(1)
    {
        printf("i = %d\n",i);
        i++;
        sleep(1);
    }
    return 0;
}
