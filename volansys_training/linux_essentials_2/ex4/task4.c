#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

FILE *fp;
pthread_mutex_t mutex;

void *dollor(void *arg)
{
    pthread_mutex_lock(&mutex);
    fp = fopen("test.txt", "w");
    int i;
    for (i = 1; i <= 1000; i++)
    {
        fprintf(fp, "$ thread: %d\n", i);
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void *hash(void *arg)
{
    fp = fopen("test.txt", "w");
    pthread_mutex_lock(&mutex);
    int i;
    for (i = 1; i <= 1000; i++)
    {
        fprintf(fp, "# thread: %d\n", i);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);

}

int main()
{
    pthread_t tid[2];
    int i;
    pthread_mutex_init(&mutex,NULL);
    // creating thread
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            if (pthread_create(&tid[i], NULL, &dollor, NULL) != 0)
            {
                perror("error creating thread\n");
            }
        }
        else
        {
            if (pthread_create(&tid[i], NULL, &hash, NULL) != 0)
            {
                perror("cant create thread\n");
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("cant join thread\n");
        }
    }

    fclose(fp);

    return 0;
}