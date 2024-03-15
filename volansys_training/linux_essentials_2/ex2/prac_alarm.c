#include<stdio.h>

int main() {
    //schedule alarm signal in 3 seconds
    alarm(3);
    printf("Looping Forever...\n");
    while(1) {
        printf("this line shouldnt be executed\n");
        sleep(1);
    }
    return 0;
}