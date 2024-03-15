#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>

//declaratiion of signals
void sighup();
void sigint();
void sigquit();

int main() {

    int pid;
    pid = fork();

    // get child process
    if(pid < 0) {
        perror("error\n");
        exit(1);
    }

    //child process
    else if(pid == 0) {
        signal(SIGHUP,sighup);
        signal(SIGINT,sigint);
        signal(SIGQUIT,sigquit);

        while(1) {
            sleep(2);

        } 
            
    }

    //parent process
    else {
        sleep(5);
        printf("sending sighup\n");
        kill(pid,SIGHUP);
        sleep(2);

        printf("sending sigint\n");
        kill(pid,SIGINT);
        sleep(2);

        printf("sending sigquit\n");
        kill(pid,SIGQUIT);
        sleep(2);

        wait(NULL);
    }
}

void sighup() {
    printf("recieved sighup\n");
}

void sigint() {
    printf("recieved sigint\n");
}

void sigquit() {
    printf("received sigquit\n");
    exit(0);
}
