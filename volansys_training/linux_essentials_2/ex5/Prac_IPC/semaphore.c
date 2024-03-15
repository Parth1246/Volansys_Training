#include <stdio.h>
#include <stdlib.h>
// library to use when use semaphore for IPC
#include <sys/sem.h>

#define MY_SEM_ID 111

int main()
{
    int semid, cnt,ret;
    struct sembuf sb;

    /* Create the semaphore with the id MY_SEM_ID */
    semid = semget(MY_SEM_ID, 1, 0666 | IPC_CREAT);

    if (semid >= 0)
    {
        printf("\nSemcreate: Created a Semaphore Id: %d\n", semid);

        sb.sem_num = 0;
        sb.sem_op = 1;
        sb.sem_flg = 0;
        printf("\nsemacq: Attempting to acquire semaphore Id: %d\n", semid);

        /* Acquire the semaphore */
        if (semop(semid, &sb, 1) == -1)
        {
            printf("semacq: semop failed.\n");
            exit(-1);
        }
        printf("\nsemacq: Semaphore acquired %d\n", semid);
    }

    if (semid >= 0)
    {
        printf("\nsemrel: Releasing semaphore %d\n", semid);

        sb.sem_num = 0;
        sb.sem_op = 1;
        sb.sem_flg = 0;

        /* Release the semaphore */
        if (semop(semid, &sb, 1) == -1)
        {
            printf("\nsemrel: semop failed.\n");
            exit(-1);
        }
        printf("\nsemrel: Semaphore released %d\n", semid);

        /* Read the current semaphore count */
        if (semid >= 0)
        {
            cnt = semctl(semid, 0, GETVAL);
            if (cnt != -1)
            {
                printf("semcrd: current semaphore count %d.\n", cnt);
            }
        }

        if (semid >= 0)
        {
            ret = semctl(semid, 0, IPC_RMID);
            if (ret != -1)
            {
                printf("Semaphore %d removed.\n", semid);
            }
        }
    }
    return 0;
}