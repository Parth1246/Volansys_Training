#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

void catch_ctlc(int sig_num)
{
    printf("caught control-C\n");
    fflush(stdout);

    return;
}

int main()
{
    signal(SIGINT , catch_ctlc);

    printf("go ahead , make my day\n");
    //pause();
    sleep(5);

    return 0;
}
