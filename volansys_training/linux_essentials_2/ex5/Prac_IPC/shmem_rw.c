#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<errno.h>

#define MY_SHM_ID 111

int main()
{
    int shmid, ret;
    void *mem;
    /* Get the shared memory segment using MY_SHM_ID */
    shmid = shmget(MY_SHM_ID, 0, 0);
    mem = shmat(shmid, (const void *)0, 0);

    strcpy((char *)mem, "This is a test string.\n");

    printf("%s\n",(char *)mem);


    if(shmid >=0) {
        ret = shmdt(mem);
        if(ret == 0) {
            printf("shared memory segment removed\n");
        }
        else {
            printf("shmctl %d failed\n",errno);
        }
    }
    else {
        printf("shared memory segment not found\n");
    }

    return 0;
}