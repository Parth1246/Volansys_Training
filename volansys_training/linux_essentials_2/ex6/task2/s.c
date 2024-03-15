// server code for UDP socket programming
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define PORT_NO 10000
#define SIZE 200
#define nofile "File Not Found!"
#define n 10

int count = 0;

// to clear buffer
void clearBuf(char *b)
{
	int i;
	for (i = 0; i < SIZE; i++)
		b[i] = '\0';
}

// to encrypt data of file
char Cipher(char ch)
{
	return ch;
}

// function to send file data
int sendFile(FILE *fp, char *buf, int s)
{
	int i, len;
	if (fp == NULL)
	{
		strcpy(buf, nofile);
		len = strlen(nofile);
		buf[len] = EOF;
		for (i = 0; i <= len; i++)
			buf[i] = Cipher(buf[i]);
		return 1;
	}

	char ch, ch2;
	for (i = 0; i < s; i++)
	{
		ch = fgetc(fp);
		ch2 = Cipher(ch);
		buf[i] = ch2;
		if (ch == EOF)
			return 1;
	}
	return 0;
}

void list_files(void)
{
	chdir("/home/parth/Training_exercise/parth.varsani_idp/Linux_Essentials_2/ex6/task2");
	system("ls -al | awk '{print $9 $6 $7 $5}' > temp.txt");
}

int main()
{
	int sockfd, nBytes;
	struct sockaddr_in addr_con;

	int addrlen = sizeof(addr_con);

	addr_con.sin_family = AF_INET;
	addr_con.sin_port = htons(PORT_NO);
	addr_con.sin_addr.s_addr = INADDR_ANY;

	char net_buf[SIZE];

	FILE *fp;

	// socket creation
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd < 0)
		printf("\nfile descriptor not received!!\n");
	else
		printf("\nfile descriptor %d received\n", sockfd);

	// bind the socket to ip and port
	if (bind(sockfd, (struct sockaddr *)&addr_con, sizeof(addr_con)) == 0)
		printf("\nSuccessfully binded!\n");
	else
		printf("\nBinding Failed!\n");

	list_files();
	printf("listdown the metadata of files on server\n");
	system("cat temp.txt");
	sleep(3);

	// infinite loop
	while (1)
	{
		printf("list of the all files given below\n");
		system("ls -al");

		printf("\nWaiting for file name...\n");

		time_t begin = clock();
		// clear data of buffer before it gets data
		clearBuf(net_buf);

		// receive file name

		nBytes = recvfrom(sockfd, net_buf, SIZE, 0,
						  (struct sockaddr *)&addr_con, &addrlen);

		printf("\nFile Name Received: %s\n", net_buf);

		time_t end = clock();

		float time = end - begin;
		//if it gets name after 120 sec it will breakdown connection
		if ((time * 1000) > 120)
		{
			printf("sorry youve lost connectiion\n");
			break;
		}
		else
		{

			fp = fopen(net_buf, "r");

			if (fp == NULL)
				printf("\nFile open failed!\n");
			else
				printf("\nFile Successfully opened!\n");

			while (1)
			{
				// process the data
				if (sendFile(fp, net_buf, SIZE))
				{
					sendto(sockfd, net_buf, SIZE, 0,
						   (struct sockaddr *)&addr_con, addrlen);
					break;
				}
				// send the data
				sendto(sockfd, net_buf, SIZE, 0,
					   (struct sockaddr *)&addr_con, addrlen);

				// after sending data clear buffer every time to get data again
				clearBuf(net_buf);
			}
		}
		if (fp != NULL)
			fclose(fp);
	}
	return 0;
}
