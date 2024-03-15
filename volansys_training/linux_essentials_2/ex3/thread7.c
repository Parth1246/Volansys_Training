#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * thrd(void  * arg) {
    printf("thread strarted\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    printf("before thread\n");
    int rt;
    rt = pthread_create(&thread,NULL,thrd,NULL);

    pthread_join(thread,NULL);
    printf("after thread\n");

    for(int i=0;i<10;i++) {
        printf("%d\n",i);
        sleep(1);
    }
    exit(0);
}