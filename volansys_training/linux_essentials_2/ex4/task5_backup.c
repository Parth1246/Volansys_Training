#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_barrier_t bar;
pthread_mutex_t mutex;
#define MAX 4

FILE *ptr1, *ptr2;
char ch,c;
int counter = 0;

void *mythread(void *arg)
{
    sleep(1);
    ptr1 = fopen("test.txt", "r");
    ptr2 = fopen("test2.txt","w");
    pthread_mutex_lock(&mutex);

    do{
        ch = fgetc(ptr1);
        c = ch + 0x50 ;
        putc(c,ptr2);
    } while(counter == 1024 || ch != EOF);
    counter = 0;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);

   
}

int main()
{
    pthread_t tid[3];
    pthread_mutex_init(&mutex, NULL);
    pthread_barrier_init(&bar,NULL,2);
    int i;

    for (i = 0; i < 3; i++)
    {

        if (pthread_create(&tid[i], NULL, mythread, NULL) != 0)
        {
            printf("failed to create thread\n");
            return 1;
        }
        printf("thread %d is started\n", i);
    }

    for (i = 0; i < 3; i++)
    {
        pthread_join(tid[i], NULL);
        printf("thread %d is finished\n", i);
        sleep(1);
    }

    printf("content copied successfullly\n");

    fclose(ptr1);
    fclose(ptr2);

    pthread_barrier_destroy(&bar);
    pthread_mutex_destroy(&mutex);
    

    return 0;
}