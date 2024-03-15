#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>


#define ERROR -1
#define BUFFER 1024


int main() {
    struct sockaddr_in remote_server;
    int sock;
    char input[BUFFER];
    char output[BUFFER];
    int len;

    if( (sock = socket(AF_INET , SOCK_STREAM , 0)) == ERROR) {
        perror("socket");
        exit(-1);
    }
    else {
        printf("socket created/..\n");
    }

    remote_server.sin_family = AF_INET;
    remote_server.sin_port = htons(atoi(10000)); 
    remote_server.sin_addr.s_addr = inet_addr("1.1.1.1");
    bzero(&remote_server,8);

    inet_pton(AF_INET, "1.1.1.1", &remote_server.sin_addr);

    if((connect(sock,(struct sockaddr *)&remote_server,sizeof(struct sockaddr_in)))==ERROR) {
        perror("connect");
        exit(-1);
    } 

    while(1) {
        fgets(input,BUFFER,stdin);
        send(sock,input,strlen(input),0);

        len = recv(sock,output,BUFFER,0);
        output[len] = '\0';
        printf("%s\n",output);

    }

    close(sock);
}