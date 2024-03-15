#include<stdio.h>
#include<pthread.h>

void * mythread(void * arg) {
    printf("thread %d started\n",(int )arg);
    //pthread_detach(pthread_self());
    sleep(2);
    pthread_exit(0);
}

int main() {
    pthread_t t_id;
    int ret;
    ret = pthread_create(&t_id,NULL,mythread,(void *)t_id);

    if(ret == 0) {
        printf("thread is created\n");
    }

    pthread_join(t_id,NULL);
    printf("thread terminated\n");

    return 0;
}