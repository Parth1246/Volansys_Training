#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define PORT 10000

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};
    char buffer2[1024] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    else
    {
        printf("socket created...\n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("server connceted...\n");

    while (1)
    {
        printf("Client: ");
        scanf("%s", buffer);
        send(sock, buffer, strlen(buffer), 0);
        if ((strcmp(buffer, "exit")) == 0)
        {
            printf("disconnected from server...\n");
           
            exit(0);
        }
        //printf("connceted to server\n");

        if (recv(sock, buffer, 1024, 0) < 0)
        {
            printf("error recieving data\n");
        }
        else
        {
            printf("server: %s\n", buffer);
        }
        
    }

   
    return 0;
}
