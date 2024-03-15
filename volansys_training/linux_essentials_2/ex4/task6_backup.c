#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
#define MAX 4

FILE *ptr1, *ptr2;
char ch,c,ch2;
int counter = 0, words=0,itr=0;

void *mythread2(void *arg) {
    pthread_mutex_lock(&mutex);
    sleep(1);
    itr++;
    printf("itration No %d has completed...\n",itr);
    counter = 0;
    printf("after itration No %d\n%d words have been printed so far\n",itr,words);
    switch(itr) {
        case 1: printf("33 percent copy completed\n"); break;
        case 2: printf("67 percent copy completed\n"); break;
        case 3: printf("100 percent copy completed\n"); break;
        default:printf(" "); break;
    }

    pthread_mutex_unlock(&mutex);
}

void *mythread(void *arg)
{
    sleep(1);
    ptr1 = fopen("test.txt", "r");
    ptr2 = fopen("test2.txt","w");
    pthread_mutex_lock(&mutex);

    do{
        ch = fgetc(ptr1);
        if(ch=='\n'||ch == ' '||ch=='\t'||ch=='\0') {
            words++; 
        }
        c = ch + 0x50 ;
        putc(c,ptr2);
        counter++;
    } while(counter < 1024);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
  
}

void catcher(int sig_num) {
    printf("caught signal...\n");
    sleep(1);
    printf("exiting....\n");
    exit(0);
}

int main()
{
    pthread_t tid1[3],tid2[3];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond,NULL);
    int i;

    signal(SIGINT,catcher);

    for (i = 0; i < 2; i++)
    {
        if(i==0) {
            sleep(10);
            pthread_create(&tid1[i],NULL,mythread,NULL);
            printf("thread %d is started\n", i+1);
            pthread_create(&tid1[i+1],NULL,mythread,NULL);
            printf("thread %d is started\n", i+2);
        }
        else {
            sleep(10);
            pthread_create(&tid1[i+1],NULL,mythread,NULL);
            printf("thread %d is started\n", i+2);
        }
    }

    for(i =0;i<3;i++) {
        pthread_create(&tid2[i],NULL,mythread2,NULL);
    }

    for (i = 0; i < 3; i++)
    {
        pthread_join(tid1[i], NULL);
        printf("thread %d is finished\n", i+1);
        sleep(1);
    }

    for (i = 0; i < 3; i++)
    {
        pthread_join(tid2[i], NULL);
        sleep(1);
    }

    printf("content copied successfullly\n");

    fclose(ptr1);
    fclose(ptr2);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    

    return 0;
}