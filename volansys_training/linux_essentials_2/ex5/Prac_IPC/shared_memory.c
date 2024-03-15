#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdlib.h>

#define MY_SHM_ID 111

int main()
{
    int shmid, shmid2;
    struct shmid_ds shmds;

    /* Create the shared memory segment using MY_SHM_ID */
    shmid = shmget(MY_SHM_ID, 4096, 0666 | IPC_CREAT);

    if (shmid >= 0)
    {
        printf("Created a shared memory segment %d\n", shmid);
    }

    shmid2 = shmctl(shmid, IPC_STAT, &shmds);
    if (shmid2 == 0)
    {
        printf("Size of memory segment is %ld\n", shmds.shm_segsz);
        printf("Number of attaches %d\n", (int)shmds.shm_nattch);
    }
    else
    {
        printf("shmctl failed (%d)\n", errno);
        exit(0);
    }

    return 0;
}