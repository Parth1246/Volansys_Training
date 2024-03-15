#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main() {
    printf("this process has pid %d\n",getpid());
    printf("this process parent pid %d\n",getppid());

    //int return_val = system("ls -l");
    //printf("%d\n",return_val);

    pid_t child = fork();

    if(child == 0) {
        printf("this is child pid %d\n",getpid());
        printf("my parent pid is %d\n",child);
    }
    else {
        printf("this is parent pid %d\n",getpid());
    }

    return 0;
}