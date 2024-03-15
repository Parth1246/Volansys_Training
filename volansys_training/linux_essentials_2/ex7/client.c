#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10000

int main()
{

    int clientSocket, ret;
    struct sockaddr_in serverAddr;
    int buffer1;
    char buffer2[1024];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Client Socket is created.\n");

    // memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (ret < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Connected to Server.\n");

    while (1)
    {

        printf("Client-Port: \n");
        scanf(" %d ", buffer1);

        if (send(clientSocket, &buffer1, 4, 0) < 0)
        {
            printf("sending portno failed\n");
            exit(0);
        }
        else
        {
            bzero(buffer1, sizeof(buffer1));

            printf("Client-String: \n");
            scanf(" %s ", buffer2);

            if (send(clientSocket, buffer2, sizeof(buffer2), 0) < 0)
            {
                printf("sending string %s", buffer2);
                if (strcmp(buffer2, "exit") == 0)
                {
                    close(clientSocket);
                    printf("[-]Disconnected from server.\n");
                    bzero(buffer2, sizeof(buffer2));
                    exit(1);
                }
            }
            else
            {
                printf("sending string failed\n");
                exit(0);
            }
        }

        if (recv(clientSocket, buffer1, 4, 0) == 0)
        {
            printf("Client-Port: %d\n", buffer1);
        }
        else
        {
            printf("cant recieve client's port\n");
            exit(0);
        }

        if (recv(clientSocket, buffer2, strlen(buffer2), 0) == 0)
        {
            printf("Client-String: %s\n", buffer2);
        }
        else
        {
            printf("cant recieve other client's message\n");
            exit(0);
        }
    }

    return 0;
}