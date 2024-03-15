#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 10000
#define SIZE 2048
#define MAX 20

// function for decryption
char Cipher(char ch)
{
    return ch + 32;
}

// function to receive file
int recvFile(char *buf, int s)
{
    int i;
    char ch;
    for (i = 0; i < s; i++)
    {
        ch = buf[i];
        ch = Cipher(ch);
        if (ch == EOF)
            return 1;
        else
            printf("%c", ch);
    }
    return 0;
}

int main()
{
    int skt, cli;
    struct sockaddr_in serv_addr;
    FILE *fptr;
    char str[MAX];
    int len = sizeof(serv_addr);

    skt = socket(AF_INET, SOCK_STREAM, 0);

    if (skt < 0)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    printf("1:- Socket created\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(skt, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    else
    {
        printf("Client Connceted...\n");
    }

    while (1)
    {
        printf("enter file name:-\n");
        scanf("%s", str);
        

        int num = sendto(skt, str, MAX, 0, (struct sockaddr *)&serv_addr, len);
        if (num > 0)
        {
            printf("filename %s sent...\n",str);
        }
        else
        {
            printf("cant send filename\n");
            exit(0);
        }
        char buffer[SIZE];
    }
    close(skt);
    return 0;
}