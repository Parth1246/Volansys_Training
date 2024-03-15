#include<stdio.h>
#include<signal.h>

//take golbal flag with 0
int alarmFlag = 0;

void sig_handler() {
    printf("alarm clock signal received\n");
    //whenever the signal received this func runs
    alarmFlag = 1;
}

int main() {
    //register the alarm signal 
    signal(SIGALRM,sig_handler);
    //after three second schedule an alarm signal
    alarm(3);

    printf("Looping...\n");

    while(!alarmFlag) {
        //pause will suspends calling process 
        //untill alarm gets signal 
        //after 3 sec it will recive signal and sig_handler func will run
        pause();
    }
    printf("loop ends due to alarm signal\n");
}