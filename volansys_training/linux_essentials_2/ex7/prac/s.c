#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 10000

struct queue
{
    char *data;
    struct queue *next;
};

struct queue *front;
struct queue *rear;

struct queue *enqueue(struct queue *head, char *chat)
{
    struct queue *ptr = (struct enqueu *)malloc(sizeof(struct queue));
    ptr->data = chat;

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
            printf("Client: %s\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;

    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    pid_t pid;

    struct queue *head = NULL;
    char *data;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("socket created...\n");

    // Forcefully attaching socket to the port 10000
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 10000
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("socket binded to port %d\n", 10000);
    }

    if (listen(server_fd, 5) < 0)
    {
        perror("Error in binding\n");
    }
    else
    {
        printf("server is ready to listen...\n");
        sleep(1);
    }

    while (1)
    {
        pid = fork();
        if (pid == 0)
        {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                     (socklen_t *)&addrlen)) < 0)
            {
                perror("accept");
                exit(1);
            }
            else
            {
                printf("new connection on port %d \n", ntohs(address.sin_port));
            }
        }
        else
        {
            wait(NULL);
            while (1)
            {
                bzero(buffer, sizeof(buffer));

                recv(new_socket, buffer, 1024, 0);

                if ((strcmp(buffer, "exit")) == 0)
                {
                    printf("client disconnected\n");

                    break;
                }
                else
                {
                    printf("Client: %s\n", buffer);
                    send(new_socket, buffer, strlen(buffer), 0);

                    bzero(buffer, sizeof(buffer));
                }
                data = buffer;
                enqueue(head, data);
            }
            close(new_socket);
        }
        display(head);
    }
    return 0;
}