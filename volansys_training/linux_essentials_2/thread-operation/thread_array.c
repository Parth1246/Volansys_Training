#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * mythread(void * arg) {
    printf("thread %d is running\n",(int)arg);
    pthread_exit(arg);
}

int main() {
    int i,ret,status;
    pthread_t thread[5];

    for(i = 0;i<5;i++) {
        ret = pthread_create(&thread[i],NULL,mythread,(void *)i);

        if(ret != 0) {
            printf("error creating thread %d\n",(int)thread[i]);
        }
    }

    for(i =0;i<5;i++) {
        ret = pthread_join(thread[i],(void **)&status);

        if(ret == 0) {
            printf("status %d\n",status);
        }
    }
    return 0;

}