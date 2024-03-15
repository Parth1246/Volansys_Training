#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define IP_ADDRESS "127.0.0.1" // localhost
#define PORT_NO 10000
#define SIZE 200
#define n 10

int count = 0;

// to clear buffer
void clearBuf(char *b)
{
	int i;
	for (i = 0; i < SIZE; i++)
		b[i] = '\0';
}

// for decryption of data
char Cipher(char ch)
{
	return ch;
}

// to receive file data
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

int counter(int count)
{
	for (int i = 0; i < n; i++)
	{
		count++;
		sleep(1);
	}

	if (count == n)
	{
		return 1;
	}
	else
	{
		count = 0;
		return 0;
	}
}

int main()
{
	int sockfd, nBytes;
	struct sockaddr_in addr_con;

	int addrlen = sizeof(addr_con);
	int perm;

	addr_con.sin_family = AF_INET;
	addr_con.sin_port = htons(PORT_NO);
	addr_con.sin_addr.s_addr = inet_addr(IP_ADDRESS);

	char net_buf[SIZE];

	char *data = "dummy.txt";

	FILE *fptr2;

	// socket creation
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd < 0)
		printf("\nfile descriptor not received!!\n");
	else
		printf("\nfile descriptor %d received\n", sockfd);

	system("ls -l | awk 'print{$9 $6 $7 $5}'>temp.txt");
	while (1)
	{
		printf("list of files on client\n");
		system("ls");

		time_t begin = clock();

		printf("\nPlease enter file name to send to the server:\n");
		scanf("%s", net_buf);

		system("touch dummy.txt");
		sleep(1);

		sendto(sockfd, net_buf, SIZE,
			   0, (struct sockaddr *)&addr_con,
			   addrlen);

		time_t end = clock();

		float time = end - begin;
		// if it gets name after 120 sec it will breakdown connection
		if ((time * 1000) > 120)
		{
			printf("sorry youve lost connectiion\n");
			break;
		}

		else
		{
			printf("\nData Received\n");
			fptr2 = fopen(data, "w");

			while (1)
			{
				// receive
				clearBuf(net_buf);

				nBytes = recvfrom(sockfd, net_buf, SIZE,
								  0, (struct sockaddr *)&addr_con,
								  &addrlen);

				fprintf(fptr2, net_buf);
				// process
				if (recvFile(net_buf, SIZE))
				{
					break;
				}
			}
		}
		printf("\n");
		fclose(fptr2);
	}

	return 0;
}
