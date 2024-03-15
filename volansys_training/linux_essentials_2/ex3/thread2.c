#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//function pointer taking void pointer as an argument
void * print_message_function(void * ptr) {
    //typecasting of ptr pointer from void to char
    char * message;
    message  = (char *) ptr;

    printf("%s\n",message);
}

void main() {
    pthread_t thread1 , thread2 ;

    char * message1 = "thread1";
    char * message2 = "thread2";
    int iret1,iret2;

    //created independent threads each of will execute the functions as given
    iret1 = pthread_create(&thread1,NULL,print_message_function,(void *)message1);
    iret2 = pthread_create(&thread2,NULL,print_message_function,(void *)message1);
    

/* Wait till threads are complete before main continues. Unless we */
/* wait we run the risk of executing an exit which will terminate  */
/* the process and all threads before the threads have completed.  */

    pthread_join(thread1,NULL);
    pthread_join(thread1,NULL);

    printf("Thread 1 returns: %d\n",iret1);
    printf("Thread 2 returns: %d\n",iret2);
    exit(0);
}



