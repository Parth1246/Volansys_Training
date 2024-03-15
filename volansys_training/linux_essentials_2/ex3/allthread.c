#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * func(void * arg) {

    printf("inside the thread\n");
    sleep(2);
    pthread_exit(NULL);
}

void * table(void * arg) {
    int i=0;
    printf("%d\n",i);
    sleep(2);
    pthread_exit(NULL);
}

void fun (void) {
    pthread_t thrd,temp;

    //create the thread
    pthread_create(&thrd,NULL,&func,NULL);
    printf("hurrahhh thread's been created\n");

    //waiting for the current thread to terminate
    pthread_join(thrd,NULL);
    
    pthread_create(&temp,NULL,table,NULL);
    printf("temp has been created\n");

    sleep(2);
    pthread_join(temp,NULL);
    //compare the threades
    if(pthread_equal(thrd,temp)) {
        printf("threads are equal\n");
    }
    else {
        printf("threads are not equal\n");
    }

    

    printf("now thread has terminated \n");

    pthread_exit(NULL);
}

int main() {
    fun();
    return 0;
}