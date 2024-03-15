#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 5;
void * print(void * arg) {
    static int b = 5;
    int * ptr = (int *)arg;

    printf("the val of arg: %d\n",*ptr);
    printf("the val of global a : %d\n",a);
    printf("the val of static b : %d\n",b);

    return NULL;
}

int main() {
    pthread_t t_id;

    for(int i=0;i<4;i++) {
        pthread_create(&t_id,NULL,print,(void *)&t_id);
        sleep(1);
    }

    pthread_exit(NULL);

    return 0;
}