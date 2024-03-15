#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void my_signalhandler(int sig) {
    printf("i got signal %d\n",sig);
}
int main() {
    signal(SIGINT,my_signalhandler);

    while(1) {
        printf("waiting for intrruption..\n");
        sleep(1);
    }
    return 0;
}