#include<stdio.h>
#include<signal.h>
#include<wait.h>

int main() {
    int stat;
    int pid;

    if((pid = fork())== 0) {
        while(1) ;
    }
    else {
        kill(pid,SIGINT);
        wait(&stat);

        if(WIFSIGNALED(stat)) {
            psignal(WTERMSIG(stat),"child term due to: ");
        }
    }
}