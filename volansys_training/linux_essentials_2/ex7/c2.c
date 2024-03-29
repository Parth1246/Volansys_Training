#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 10000

//struct node data;

int main()
{

    int clientSocket, ret;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int portno;

    FILE * fp;
    //struct node data;

    int length = sizeof(serverAddr);

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Client Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
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

    fp = fopen("test.txt","w");
    if(fp == NULL) {
        printf("file cant be opened\n");
        exit(0);
    }

    while (1)
    {

        int tmp;
        printf("Client: ");
        scanf(" %d", &portno);

        send(clientSocket,&portno,sizeof(&portno),0);
        printf("portno sended\n");

        printf("Client: ");
        scanf(" %s", buffer);
        fwrite(buffer,1,strlen(buffer),fp);
        printf(" %d %s\n",portno,buffer);



        if (sendto(clientSocket,&portno,sizeof(&portno), 0,&serverAddr,length) < 0)
        {
            printf("error sending\n");
            exit(0);
        }
        else
        {
            //if (strcmp(buffer, "exit") == 0)
            //{
            //    close(clientSocket);
            //    printf("[-]Disconnected from server.\n");
            //    exit(1);
            //}

            printf("portno send done\n");
            //if (recvfrom(clientSocket,&data, sizeof(&data), 0,(struct sockaddr *)&serverAddr,&length) < 0)
            //{
            //    printf("[-]Error in receiving data.\n");
            //}
            //else
            //{
            //    printf("Server: %d\n", portno);
            //    printf("Server: %s\n", buffer);
            //}
        }
    }

    return 0;
}