#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_barrier_t barrier;


void * routine (void * arg) {
    printf("waiting for barrier\n");
    pthread_barrier_wait(&barrier);
    printf("we passed the barrier\n");
}

int main() {
    pthread_t tid[9];

    pthread_barrier_init(&barrier,NULL,3);


    for(int i=0;i<9;i++) {
        if(pthread_create(&tid[i],NULL,&routine,NULL)!=0) {
            perror("the error\n");
        }
    }

    for(int j = 0;j<9;j++) {
        if(pthread_join(tid[j],NULL)!=0) {
            perror("the error\n");
        }
    }


    pthread_barrier_destroy(&barrier);

    return 0;
}