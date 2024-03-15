#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>



int main() {

    int status;
    pid_t killReturnValue, forkReturnValue;

    forkReturnValue = fork();

    if(forkReturnValue==0){
        //child will sleep for 100 sec
        sleep(100);
        exit(EXIT_SUCCESS);
    } else {
        //parent will executed first
        killReturnValue = kill(forkReturnValue, SIGKILL);
        if(killReturnValue != 0){
            printf("Unable to kill child process.\n");
            //if it unable to kill then parent will wait 
            //for child to let finish first
            waitpid(forkReturnValue, &status, 0);
        } else {
            printf("Child process killed.\n");
        }
    }
    
    return 0;
}