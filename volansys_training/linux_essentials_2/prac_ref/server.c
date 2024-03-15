#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>


#define ERROR -1
#define MAX_CLIENT 2
#define MAX_DATA 1024

int main(int argc,char **argv) {
    struct sockaddr_in server;
    struct sockaddr_in client;
    int sock;
    int new;
    int data_len;
    int sockaddr_len = sizeof(struct sockaddr_in);
    char data[MAX_DATA];


    if((sock = socket(AF_INET,SOCK_STREAM,0))==ERROR) {
        perror("socket");
        exit(-1);
    }
    else {
        printf("socket created...\n");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(10000));
    server.sin_addr.s_addr = inet_addr("1.1.1.1");
    bzero(&server,8);

    inet_pton(AF_INET, "1.1.1.1", &server.sin_addr);

    if((bind(sock,(struct sockaddr *)&server,sockaddr_len))==ERROR) {
        perror("bind");
        exit(-1);
    }
    else {
        printf("binding done...\n");
    }

    if((listen(sock,MAX_CLIENT))==ERROR) {
        perror("listen");
        exit(-1);
    }
    else {
        printf("socket is listening...\n");
    }

    while(1) {
        if((new = accept(sock,(struct sockaddr *)&client,&sockaddr_len))==ERROR) {
            perror("accept");
            exit(-1);
        }
        printf("new client connected from port %d and IP %s\n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));
        data_len = 1;

        while(data_len) {
            data_len=recv(new,data,MAX_DATA,0);

            if(data_len) {
                send(new,data,data_len,0);
                data[data_len] = '\0';
                printf("send mesg: %s\n",data);
            }
        }
        printf("client disconnected\n");
        close(new);
    }
    close(sock);
}