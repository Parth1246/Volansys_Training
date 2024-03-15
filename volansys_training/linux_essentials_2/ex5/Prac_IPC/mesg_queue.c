#include<stdio.h>
//library to add when use mesg Queue for IPC
#include<sys/msg.h>
#include<string.h>

#define MAX_LINE 80
#define MY_MQ_ID 111

typedef struct {

    long type;
    float fval;
    unsigned int uival;
    char strval[MAX_LINE];

} MY_TYPE_T;

int main() {
    int msgid,ret,qid;
    MY_TYPE_T myObject;
    struct msqid_ds buf;

    /* Create the message queue with the id MY_MQ_ID */
    msgid = msgget( MY_MQ_ID, 0666 | IPC_CREAT );

    /* Get the message queue for the id MY_MQ_ID */
    msgid = msgget( MY_MQ_ID, 0 );

    /* Get the queue ID for the existing queue */
    qid = msgget( MY_MQ_ID, 0 );

    if(qid>=0) {
        printf("\nCreated Mesg Queue Id: %d\n",qid);

        printf("write some mesgs in Queue Id: %d\n",qid);
        /* Create our message with a message queue type of 1 */
        myObject.type=1L;
        myObject.fval=128.356;
        myObject.uival=512;
        strncpy(myObject.strval,"this is test\n",MAX_LINE);

        /* Send the message to the queue defined by the queue ID */
        ret = msgsnd( qid, (struct msgbuf *)&myObject,sizeof(MY_TYPE_T), 0 );

        if(ret != -1) {
            printf( "Message successfully sent to Queue Id: %d\n",qid );
        }
    }

    printf("Lets Read Data From Queue Id: %d\n",qid);

    if(qid>=0) {
        ret = msgrcv( qid, (struct msgbuf *)&myObject,sizeof(MY_TYPE_T), 1, 0 );

        if(ret != -1) {
            printf("\nMessage Type: %ld\n",myObject.type);
            printf("Float Value: %f\n",myObject.fval);
            printf("Uint Value: %d\n",myObject.uival);
            printf("String Value: %s\n",myObject.strval);
        }

    }

    printf("Let's Remove The Message Queue\n");

    if(qid>=0) {
        /* Remove the message queue */
        ret = msgctl( msgid, IPC_RMID, NULL );

        if (ret != -1) {
            printf( "Queue Id: %d successfully removed.\n", msgid );
        }
    }
/* 
    if(msgid >= 0) {
        printf("\ncreated mesg queue id: %d\n",msgid);
        
        ret = msgctl( msgid, IPC_STAT, &buf );
        buf.msg_qbytes = 4096;
        ret = msgctl( msgid, IPC_SET, &buf );

        if (ret == 0) {
            printf( "\nSize successfully changed for queue id: %d.\n", msgid );
        }

    }
*/
    return 0;
}