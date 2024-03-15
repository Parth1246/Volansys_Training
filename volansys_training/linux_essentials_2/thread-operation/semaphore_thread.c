//this program is introduction of using semaphore
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
//to use semaphore like pthread incluide semaphore library
#include<semaphore.h>

//now define semaphore variable

sem_t semaphore;


#define NUM_THREAD 5

void * func(void * arg) {
    printf("hello from thread %d\n",*(int*)arg);
    free(arg);
}

int main() {
    pthread_t tid[NUM_THREAD];
    sem_init(&semaphore,0,1);
    int i;
    for(i=0;i<NUM_THREAD;i++) {
        int * a = malloc(sizeof(int));
        *a =i;
        if (pthread_create(&tid[i],NULL,&func,a)!=0) {
            perror("cant create thread\n");
        }
    }

    for(i=0;i<NUM_THREAD;i++) {
        if (pthread_join(tid[i],NULL)) {
            perror("cant join thread\n");
        }
    }

    sem_destroy(&semaphore);
    return 0;
}