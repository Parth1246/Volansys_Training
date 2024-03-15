#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void * print(void * data) {
    int my_data = (int )data;

    printf("hello  from new thread i got %d\n",my_data);
    //exit thread
    pthread_exit(NULL);
}

int main() {
    int rc;
    //declare new thread
    pthread_t thrd;

    int a = 11;

    //create new thread
    rc = pthread_create(&thrd,NULL,print,(void *)a);
    if(rc) {
        printf("ERROR : return code is generated %d by pthread_create\n",rc);
        exit(1);
    }

    //to print thread id
    printf("created new thread %u\n",thrd);

    return 0;
}