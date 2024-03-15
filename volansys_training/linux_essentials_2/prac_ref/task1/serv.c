#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<time.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>


#define MAX 1024
#define PORT 10000

int main() {
    struct sockaddr_in serv,cli;
    int sock_fd,connect_fd,len;

    //step - 1: create socket

    if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        perror("socket error\n");
        return 1;
    }
    else {
        printf("socket created...\n");
    }

    //step - 2: make the struct member null
    bzero(&serv,sizeof(serv));

    //step - 3: assign IP & PORT
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT); 

    //step - 3: bind this ip and port to socket  
    if ((bind(sock_fd, (struct sockaddr *)&serv, sizeof(serv))) != 0)
	{
		perror("bind error\n");
		return 2;
	}
	else {
		printf("Socket successfully binded...\n");
    }

    //step - 4: server is ready to listen 
    if((listen(sock_fd,10)) != 0) {
        perror("listen error\n");
        return 3;
    }
    else {
        printf("server is ready to listen\n");
    }

    //step - 5: server is ready to accept the data from client
    len = sizeof(cli);

    if((connect_fd = accept(sock_fd,(struct sock_addr *)&cli,&len)) < 0) {
        perror("conncet error\n");
        return 4;
    }
    else {
        printf("server has accepted the client...\n");
    }

    //step - 6: start the chat bw server and client
    char message[MAX];
    int n;

    //run the infinite loop

    while (1) {
        //make message null
        bzero(message,1024);

        //step - 6.1: read the message from client and put it into message
        read(connect_fd,message,sizeof(message));

        printf("Client: %s\n",message);
        //make message null again to store new data
        bzero(message,1024);
        n = 0;
        //step - 6.2: copy server message to in to message
        while ((message[n++] = getchar()) != '\n') 
            ;

        //step - 6.3: send this message to client
        write(connect_fd,message,sizeof(message));

        //if u get quit , just break the loop
        if(strcmp(message,"quit") == 0) {
            printf("server exited...\n");
            break;
        }
    }

    close(sock_fd);
}