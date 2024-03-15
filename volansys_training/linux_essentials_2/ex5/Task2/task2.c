#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

//fd[0] = read
//fd[1] = write

int main() {
    int file_dis[2];
    if (pipe(file_dis) == -1) {
        printf("error\n");
        return 1;
    }
    else {
        int id = fork();
        if(id==0) {
            //child process
            printf("you are in child process\n");
            
            //so in child , close read pipe caz we use write pipe only
            //one pipe only in a process
            close(file_dis[0]);
            int sum=0;
            int flag = 0;
            printf("Calculating the sum of 1000 squares\n");
            
            for(int i=1;i<1001;i++) {
                sum+=i*i;
                write(file_dis[1],&sum,sizeof(int));
                sleep(1);
            }
            close(file_dis[1]);
        }
        else {
            
            //parent process
            printf("you are in parent process\n");
            
            close(file_dis[1]);
            int y;
            for(int i=0;i<1001;i++) {

                read(file_dis[0],&y,sizeof(int));
                sleep(1);
                printf("Got Sum %d from child\n",y);
            }
            close(file_dis[0]);
        }
    }

    return 0;
}