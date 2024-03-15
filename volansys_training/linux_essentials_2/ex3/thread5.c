#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void * thrd(void * arg) {
    pthread_t pt;

    pt = pthread_self();

    printf("thread %x ran\n",(int)pt);

    pthread_exit(NULL);
}

int main() {
    int ret;
    //creating thread
    pthread_t thrd;

    ret = pthread_create(&thrd,NULL,thrd,NULL);

    if(ret!=0) {
        printf("errorrrrrr\n");
        exit(-1);
    }
    else {
        printf("created thread successfully\n");
    }

    return 0;
}