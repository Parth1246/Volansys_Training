#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main() {
    int pid;

    if((pid = fork()) == 0) {
        //child
        int i=0;
        while(i++ < 15) {
            printf("you are in child\n");
            sleep(1);
        }
    }
    else {
        //parent
        int i=0;
        while(i++ < 15) {
            printf("you are in parent\n");
            sleep(1);
        }
        kill(pid,SIGKILL);
    }

    return 0;
}