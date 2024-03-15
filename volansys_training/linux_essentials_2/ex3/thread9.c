#include<stdio.h>
#include<pthread.h>

int global = 10;

void * print(void * arg) {
    int a = 5;
    static int b = 10;

    b++;
    global++;

    //passed tid as an argument so need to typecast it in to int
    //and store that value in pointer varible
    int * thread_id = (int *)arg;
    printf("static %d | global %d | tid %d\n",b,global,*thread_id);
}

int main() {
    pthread_t tid;

    int i;
    for(i = 0;i<3;i++) {
        //creating thread
        pthread_create(&tid,NULL,print,(void *)&tid);
        sleep(1);
    }
    pthread_exit(NULL);


    return 0;
}