#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

long long sum = 0;


//this func will take arg at run time and thread will do sum 
void * plus(void * arg) {
    //typecast the arg

    long long * limit = (long long *)arg;
    long long lm = * limit;

    for(long long i =0;i<=lm;i++) {
        sum += i;
    }

    pthread_exit(0);
}

int main(int argc,char **argv) {
    //convert ascii to long long
    long long limit =  atoll(argv[1]);

    pthread_t thrd;
    pthread_create(&thrd,NULL,plus,&limit);

    pthread_join(thrd,NULL);
    //wait for thrd to be null and then get bakc to main func

    printf("the sum is %lld\n",sum);

    return 0;

}
