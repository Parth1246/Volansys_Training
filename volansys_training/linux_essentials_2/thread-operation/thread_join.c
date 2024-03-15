/*
this program is for printing value of mythread funcs value in main func
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * mythread() {
    int value = 10;
    printf("the val of variable from mythread func is %d\n",value);

    int * result = malloc(sizeof(int));
    *result = value;
    printf("thread result %p\n",result);
    //you cant simply share local variables reference to other
    //that is why we have dynamicaly allote this variable and give value of local variable
    //and return  the pointer ref 
    //return the addrese of value but with the typecasting as required
    return (void *) result;
}

int main() {
    pthread_t tid;
    //declare a pointer
    int * ptr;
    //give reference of this pointer to join but typecast it with (void **)

    pthread_create(&tid,NULL,mythread,NULL);

    pthread_join(tid,(void **)&ptr);

    printf("main ptr %p\n",ptr);
    printf("the val of variable from main is %d\n",*ptr);
    free(ptr);

    return 0;
}