/*
TCP ECHO SERVER USING SOCKETS

BY:
Prashant Shrivastava- DTU/2K12/CO/090
Pulkit Tanwar- DTU/2K12/CO/92
Rishabh Agarwal- DTU/2K12/CO/102
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<error.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>

#define ERROR -1
#define MAX_CLIENTS	2
#define	MAX_DATA	1024

main(int argc, char **argv)
{
	struct sockaddr_in server;
	struct sockaddr_in client;
	int sock;
	int new;
	int sockaddr_len = sizeof(struct sockaddr_in);
	int data_len;
	char data[MAX_DATA];

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
	{
		perror("Server Socket: ");
		exit(-1);
	}

	server.sin_family = AF_INET;
   	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 8);

	if((bind(sock, (struct sockaddr *)&server, sockaddr_len)) == ERROR)
	{
	    perror("Bind: ");
	    exit(-1);
	}

	if((listen(sock, MAX_CLIENTS)) == ERROR)
	{
	    perror("Listen");
	    exit(-1);

	}

	while(1)
    {
        if((new = accept(sock,(struct sockaddr *)&client, &sockaddr_len)) == ERROR)
        {
            perror("Accept");
            exit(-1);
        }
        printf("New Client connected from Port No: %d and IP: %s\n",ntohs(client.sin_port), inet_ntoa(client.sin_addr));
        data_len = 1;

        while(data_len)
        {
            data_len = recv(new, data, MAX_DATA, 0);

            if(data_len)
            {
                send(new, data, data_len, 0);
                data[data_len] = '\0';
                printf("Sent Message: %s", data);
            }
        }

        printf("Client Disconnected\n");
        close(new);


    }
    close(sock);


}
