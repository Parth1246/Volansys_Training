#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

void * func(void * arg) {
    //typecast the arg into int
    int index = *(int *)arg;
    int sum =0;
    for(int j=0;j<5;j++) {
        sum+=arr[index + j];
    }
    printf("local sum : %d\n",sum);
    //return the sum of 1st 5 ele in 1st thread and rest in second
    *(int *)arg = sum;

    return arg;
}

int main() {

    pthread_t tid[2];
    int i;
    //dynamically allote memory to i at every execution of new thread
    //pass the referecne of i to the func 
    for( i=0;i<2;i++) {
        int * a = malloc(sizeof(int));
        *a = 5*i;
        //now pass the argument pointer a instead i
        if(pthread_create(&tid[i],NULL,func,a)!= 0) {
            perror("failed to create thread\n");
        }
    }

    int total_sum=0;
    for( i=0;i<2;i++) {
        //so now after you are getting sum as returned by func
        //store that to pointer 
        int * ptr;
        if(pthread_join(tid[i],&ptr)!=0) {
            perror("failed to join thread\n");
        }
        total_sum += *ptr;
        free(ptr);
    }
    printf("global sum: %d\n",total_sum);

    return 0;
}