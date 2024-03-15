#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void * thread_Handler(void * arg) {
    printf("the thread is called for this func specially\n");
    sleep(5);
}

int main() {
    pthread_t t_id;
    printf("process id %d\n",getpid());

    int ret;
    printf("before creation of thread\n");

    ret = pthread_create(&t_id,NULL,thread_Handler,NULL);

    if(ret == 0) {
        printf("thread has been created successfully\n");
    }
    else {
        printf("thread cant be created\n");
    }

    //waiting for the created thread to get terminated
    //argument = the thread itself and the return value by the thread
    pthread_join(t_id,NULL);
    printf("thread terminated\n");

    return 0;

}