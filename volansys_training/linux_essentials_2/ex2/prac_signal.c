#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>


void int_handler() {
    printf("you are inside int_handler func\n");
}

void hup_handler() {
    printf("you are inside hup_handler func\n");
}

void quit_handler() {
    printf("you are inside quit_handler func\n");
}




int main() {

    int pid;
    pid = fork();

    //chilod process
    if(pid == 0) {
    //first step is to register signal you will use
    signal(SIGINT,int_handler);
    signal(SIGHUP,hup_handler);
    signal(SIGQUIT,quit_handler);

    //now to let this child process alive , use infinite loop
        while(1) {
            sleep(2);
        }
    }

    else {
        //parent process
        printf("you are in parent\n");
        kill(pid,SIGINT);
        sleep(2);

        printf("you are in parent\n");
        kill(pid,SIGHUP);
        sleep(2);

        printf("you are in parent\n");
        kill(pid,SIGQUIT);
        sleep(2);

    }
    return 0;
}