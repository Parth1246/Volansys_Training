#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
#define MAX 4

int counter = 0;

void *mythread2(void *arg)
{

    for (int i = 0; i < 100; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *mythread1(void *arg)
{

    for (int i = 0; i < 100; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *mythread3(void *arg)
{

    for (int i = 0; i < 100; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid1, tid2, tid3;

    pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&tid1, NULL, mythread1, NULL) != 0)
    {
        printf("failed to create thread\n");
        return 1;
    }

    printf("thread 1 is started\n");

    if (pthread_create(&tid2, NULL, mythread2, NULL) != 0)
    {
        printf("failed to create thread\n");
        return 1;
    }

    printf("thread 2 is started\n");

    if (pthread_create(&tid3, NULL, mythread3, NULL) != 0)
    {
        printf("failed to create thread\n");
        return 1;
    }

    printf("thread 3 is started\n");

    pthread_join(tid1, NULL);
    sleep(1);
    printf("thread 1 is finished\n");

    pthread_join(tid2, NULL);
    sleep(1);
    printf("thread 2 is finished\n");

    pthread_join(tid3, NULL);
    sleep(1);
    printf("thread 3 is finished\n");

    pthread_mutex_destroy(&mutex);

    printf("%d\n", counter);

    return 0;
}