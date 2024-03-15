// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

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

    // Convert IPv4 and IPv6 addresses from text to binary form
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
        printf("\nenter string: ");
        scanf("%s", buffer);

        if ((strcmp(buffer, "quit")) == 0)
        {
            send(sock, buffer, 1024, 0);
            break;
        }

        else
        {
            // Calculate the time taken
            clock_t t;
            t = clock();
            send(sock, buffer, 1024, 0);

            recv(sock, buffer2, 1024, 0);

            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

            printf("Client: %s\n", buffer2);
            printf("Message Tx + Rx Time: %f seconds \n", time_taken);
            bzero(buffer2, 1024);
            bzero(buffer, 1024);
        }
    }

    close(sock);
    return 0;
}
