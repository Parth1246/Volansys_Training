#include<stdio.h>
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>

int main() {
    int pid;
    pid = fork();


    switch(pid) {
        case 0:
            printf("child\n");
            printf("child pid is %d\nchild's parent pid is %d\n",getpid(),getppid());
            pid = fork();
            if(pid == 0) printf("child 's child pid is %d\nchild's parent id is %d\n",getpid(),getppid());
            break;
        case -1:
            perror("fork failed\n");
            break;
        default:
//            wait(NULL);
            printf("parent\n");
            printf("i am parent\nparent's pid is %d\nparent'sparent pid is %d\n",getpid(),getppid());
            break;
    }

/*
    if(pid == 0) {
        printf("child\n");
    }
    else {
        printf("parent\n");
    }
    printf("this will br printed 2 times\n");
*/

    return 0;
}
