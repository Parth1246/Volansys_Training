#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * thread(void * arg) {
    char * ptr;
    printf("this is from thread and %s\n",arg);

    if((ptr = (char *)malloc(20))==0) {
        perror("error\n");
        exit(2);
    }
    else {
        strcpy(ptr,"this is ptr");
    }
    pthread_exit(ptr);
}


int main() {
    pthread_t thrd;
    void * ptr;

    thrd = pthread_create(&thrd,NULL,thread,"this is main");

    pthread_join(thrd,&ptr);
    printf("thread exited with %s\n",ptr);

}