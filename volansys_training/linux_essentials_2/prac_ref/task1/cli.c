#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORT 10000
#define MAX 1024

int main() {
    struct sockaddr_in serv,cli;
    int socket_fd,connect_fd;

    //step - 1: create socket 
    if((socket_fd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        perror("socket error\n");
        return 1;
    }
    else {
        printf("socket created...\n");
    }

    //make struct member null
    bzero(&serv,sizeof(serv));

    //step - 2: give the IP and PORT
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_port = htons(PORT);

    //step - 3: connect the client with server
    if(connect(socket_fd, (struct sockaddr *)&serv, sizeof(serv)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else {
        printf("connected to the server..\n");
    }

    //step - 4: read and write 
    char message[MAX];
    int n;

    //infinite loop
    while(1) {
        //make message null
        bzero(message,sizeof(message));

        printf("enter the string:\n");
        n = 0;

        while((message[n++] = getchar()) != '\n');
            ;
        
        //write that message into message
        write(socket_fd,message,sizeof(message));

        //make message again null to read other data
        bzero(message,sizeof(message));

        read(socket_fd,message,sizeof(message));

        printf("Server: %s\n",message);

        if((strcmp(message,"quit"))==0) {
            printf("client exited...\n");
            break;
        }
    }
    close(socket_fd);
}