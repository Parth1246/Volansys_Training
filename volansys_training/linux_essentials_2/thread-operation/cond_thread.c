#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//global variable on which every thread is gonna do job
int fuel = 0;

//globally declare mutex
pthread_mutex_t mutex;

//condition variable globally declared
pthread_cond_t cond;

void * fuel_filling(void * arg) {
    for(int i=0;i<5;i++) {
        pthread_mutex_lock(&mutex);
        fuel+=15;
        printf("filled fuel %d...\n",fuel);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        sleep(1);
    }


}

void * car(void * arg) {
    pthread_mutex_lock(&mutex);
    while(fuel<40) {
        printf("no fuel yet , waitin....\n");
        sleep(1);
        //it will wait till fule gets 40+ and then it will execute next statement
        pthread_cond_wait(&cond,&mutex);
    }
    fuel-=40;
    printf("got fuel... now lef %d\n",fuel);
    pthread_mutex_unlock(&mutex);
}

int main() {
    //declare a thread
    pthread_t tid[2];
    //initialise the mutex
    pthread_mutex_init(&mutex,NULL);
    //initialise the condition variable
    pthread_cond_init(&cond,NULL);

    //creating thread for diff func 
    for(int i=0;i<2;i++) {
        if(i==1) {
            pthread_create(&tid[i],NULL,fuel_filling,NULL);
        }
        else {
            pthread_create(&tid[i],NULL,&car,NULL);
        }
    }

    //making thread wait to exit first atleast
    for(int i=0;i<2;i++) {
        pthread_join(tid[i],NULL);
    }

    //destroying mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}