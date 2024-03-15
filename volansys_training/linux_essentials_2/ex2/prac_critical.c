#include<stdio.h>
#include<signal.h>

int main() {
    signal(SIGINT,SIG_IGN);
    int sum,i=0;
    printf("printing 10 numbers\n");

    while(i++ != 10) { 
            printf("%d ",i);
            sleep(1);
    }
    printf("captuation done\n");


    signal(SIGINT,SIG_DFL);
    while(i++ != 10) {
        printf("%d ",i);
        sleep(1);
    }
    printf("now comptuation cant be full\n");


    return 0;
}