#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>

#define PORT 10000
#define MAX 20
#define SIZE 2048

void clearBuf(char *b)
{
    int i;
    for (i = 0; i < MAX; i++)
        b[i] = '\0';
}

int main()
{
    int skt, bnd, opt = 1, client, len, num;
    struct sockaddr_in address;
    FILE *fptr;
    char data[SIZE];
    len = sizeof(address);

    skt = socket(AF_INET, SOCK_STREAM, 0);

    if (skt == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    printf("1:- Socket Created...\n");

    // Forcefully attaching socket to the port 8080
    if (setsockopt(skt, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 10000

    bnd = bind(skt, (struct sockaddr *)&address, sizeof(address));
    if (bnd < 0)
    {
        printf("Bind Failed...");
        exit(0);
    }
    printf("2:- Socket Binded...\n");

    if (listen(skt, 10) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("3:- Server is ready to listen...\n");
        sleep(1);
    }

    client = accept(skt, (struct sockaddr *)&address, (socklen_t *)&len);

    if (client < 0)
    {
        printf("client couldnt connect...\n");
        exit(0);
    }
    printf("3:- Client Accepted...\n");
    sleep(1);
    char str[MAX];

    printf("the list of files are below\n");
    system("ls");

    clearBuf(str);

    num = recvfrom(skt, str, MAX, 0, (struct sockaddr *)&address, &len);

    printf("filename %s recieved\n", str);
    fptr = fopen(str, "r");

    if (fptr == NULL)
    {
        printf("file cant open\n");
    }
    else
    {
        printf("file open\n");
    }

    close(skt);
    return 0;
}