#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>


int main() {
    int pid;
    pid = fork();

    if(pid == 0) {
        //child process
        printf("\ni am child\n");
        for(int i=1;i<=10000;i++) {
            printf("%d ",i);
        }
    }
    else if(pid == -1){
        printf("fork failed\n");
    }
    else {
        //parent process
        //wait till child finishes his job
        wait(NULL);
        printf("\ni am parent\n");
    }

    return 0;
}