#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10000

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front;
struct queue *rear;

struct queue *enqueue(struct queue *head, int x)
{
    struct queue *ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->data = x;

    if (front == NULL)
    {
        // to set element on first place = front
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        // to set element after rear
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
}

struct queue *dequeue(struct queue *head)
{
    struct queue *ptr;
    if (front == NULL)
    {
        printf("dequeue is not possible\n");
        return NULL;
    }
    else
    {
        ptr = front;
        front = front->next;

        free(ptr);
    }
}

void display(struct queue *head)
{
    struct queue *ptr = front;
    if (front == NULL)
    {
        printf("there is no queue\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

#pragma pack(1)

struct node
{
    int portno;
    char buf[1024];
};

struct node * data;
void * ptr;
int main()
{

    int sockfd, ret;
    struct sockaddr_in serverAddr;

    int length = sizeof(serverAddr);

    int newSocket;
    struct sockaddr_in newAddr;

    FILE * fp;
    int * portno;

    struct queue *head = NULL;

    head = NULL;

    socklen_t addr_size;

    char buffer[1024];
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Server Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if (ret < 0)
    {
        printf("[-]Error in binding.\n");
        exit(1);
    }
    printf("[+]Bind to port %d\n", 10000);

    if (listen(sockfd, 3) == 0)
    {
        printf("[+]Listening....\n");
    }
    else
    {
        printf("[-]Error in binding.\n");
    }

    fp = fopen("test.txt","r");

    while (1)
    {
        newSocket = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);

        if (newSocket < 0)
        {
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
        printf("client Id: %d\n", newSocket);



        if ((childpid = fork()) == 0)
        {
            close(sockfd);

            while (1)
            {   
                recv(newSocket,portno, sizeof(portno), 0);
                printf("recieved %d portno\n",*portno);
                
                //recv(newSocket, data, strlen(data), 0);
                //recvfrom(newSocket,data, sizeof(data), 0,(struct sockaddr *)&serverAddr,&length);

                //printf("recieved done\n");
               

                //if (strcmp(data->buf, "exit") == 0)
                //{
                //    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                //    break;
                //}
                //else
                //{
                //    printf("data.portno: %d\ndata.buf: %s\n", data->portno,data->buf);
                //    
                //    sendto(newSocket, data, sizeof(data), 0,&serverAddr,length);
                //    //send(newSocket, data, sizeof(data), 0);
                //    bzero(data, sizeof(data));
                //}
            }
        }
    }
    close(newSocket);

    return 0;
}