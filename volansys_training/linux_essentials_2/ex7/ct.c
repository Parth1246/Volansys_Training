#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

struct Node
{
    char data[4096];
    struct Node *next;
};

struct Node *head;

void push(struct Node *head_ref, char *new_data)
{
    char output[4096];

    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    strcpy(output, new_data);
    *new_node->data = *output;
    new_node->next = (head_ref);

    (head_ref) = new_node;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%s\n", p->data);
        p = p->next;
    }
}

void *doRecieving(void *sockID)
{

    int clientSocket = *((int *)sockID);

    while (1)
    {

        char data[1024];
        int read = recv(clientSocket, data, 1024, 0);
        int id = atoi(data);
        data[read] = '\0';
        printf("Client Index: %d->", id);

        read = recv(clientSocket, data, 1024, 0);
        data[read] = '\0';

        printf("%s\n", data);
    }
}

int main()
{

    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;

    struct Node *head;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        return 0;

    printf("Connection established ............\n");

    pthread_t thread;
    pthread_create(&thread, NULL, doRecieving, (void *)&clientSocket);

    while (1)
    {

        char input[1024];
        scanf("%s", input);

        if (strcmp(input, "SEND") == 0)
        {
            send(clientSocket, input, 1024, 0);

            scanf("%s", input);
            send(clientSocket, input, 1024, 0);

            scanf("%[^\n]s", input);
            send(clientSocket, input, 1024, 0);
            push(head, input);
        }
        else if (strcmp(input, "EXIT") == 0)
        {
            send(clientSocket, input, 1024, 0);
            exit(0);
        }
        else if (strcmp(input, "SHOW") == 0)
        {
            send(clientSocket, input, 1024, 0);
        }
    }
}