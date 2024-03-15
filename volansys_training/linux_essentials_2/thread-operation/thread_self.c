#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * thread_identifier (void * arg) {

    pthread_t pt;
    pt = pthread_self();
    printf("thread %x ran\n",(int)pt);
    //to get hexadecimal val use %x
    sleep(1);

    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    int thrd;

    thrd = pthread_create(&tid,NULL,thread_identifier,NULL);

    if(thrd == 0) {
        sleep(1);
        printf("thread %x is running\n",(int)thrd);
    }

    printf("terminating thread\n");


    return 0;
}