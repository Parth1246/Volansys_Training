//this prog is for solving deadlock using recursive mutex

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

pthread_mutex_t mutex;
pthread_mutexattr_t recmutex;
int fuel = 50;

void * thread(void * arg) {
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    fuel+=50;
    printf("incremented fuel: %d\n",fuel);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);

}


int main() {
    pthread_t tid[8];
    pthread_mutexattr_init(&recmutex);
    pthread_mutexattr_settype(&recmutex,PTHREAD_MUTEX_RECURSIVE);
    //so now we have attribute we have set,so give it as second argument of mutex init
    pthread_mutex_init(&mutex,&recmutex);
    int i;

    for(i =0;i<8;i++) {
        pthread_create(&tid[i],NULL,thread,NULL);
    }

    for(i =0;i<8;i++) {
        pthread_join(tid[i],NULL);
    }

    printf("untill: %d\n",fuel);

    pthread_mutexattr_destroy(&recmutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}