#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void myHandle(int mysignal)
{
    printf("my handle with signal %d\n",mysignal);
}

int main()
{
    int i=0;
    signal(SIGTERM , myHandle);

    while(1)
    {
        printf("i = %d\n",i);
        i++;
        sleep(1);
    }
    return 0;
}
