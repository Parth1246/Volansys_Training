#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int b = 10;

void * thread(void * arg) {
    static int a = 10;

    int * threadid = (int *)arg;
    printf("the thread_id %u , global var %d , static val %d\n",*threadid,b,a);
}

int main() {
    pthread_t mythread;
    int i;

    mythread = pthread_create(&mythread,NULL,thread,(void *)mythread);


    pthread_exit(0);

    return 0;

}