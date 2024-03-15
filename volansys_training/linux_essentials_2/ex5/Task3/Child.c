#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>


int main() {
    //ftok to genrate unique key
    key_t key = ftok("shmfile",65);
    int summ;

    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    
  
    printf("Calculating Data...\n");
    sleep(1);
    // shmat to attach to shared memory
    int *str =(int *) shmat(shmid,(void*)0,0);
  
    int sum = 0;
    for(int i =0;i<1001;i++) {
        sum += i*i;
        *str = sum;
        printf("Data written in memory: %d\n",*str);
        sleep(5);
    }
      
    //detach from shared memory 
    shmdt(str);
    
    return 0;
}