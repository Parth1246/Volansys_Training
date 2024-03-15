#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<time.h>

int main(int argc,char * argv[])
{
    int id = fork();
    int n,i;
    if(id == 0)
    {
        n =1;
        for(i = n;i<=10000;i++)
    {
        printf("%d ",i);

    }
    }
    else{
        wait(NULL);

        printf("after child now i come \n");

    }

    

    printf("\n");

    return 0;
}
