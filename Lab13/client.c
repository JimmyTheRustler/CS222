#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void readLine(char line[])
{	
	int c = 0;	
	int i = 0;

	while( (c = getchar()) != '\n' )
	{
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	line[i+1] = '\0';
}


int main(){
	char ipAddress[64];
	int port;
	char userName[20];
	
	printf("Enter an IP: ");
	scanf("%s", ipAddress);
	printf("Enter a port: ");
	scanf("%d", &port);
	printf("Enter a Username: ");
	scanf("%s", userName);
	
	
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress, &(address.sin_addr));
	
	connect(fd, (struct sockaddr *) &address, sizeof(address));
	
	
	printf("\n*Chat Started*\n\n");	
	char message[8192] = "";
	char fullMessage[8192] = "";
	
	while( 1 ){
		printf("%s: ", userName);		
		readLine(message);
		sprintf(fullMessage, "%s: %s", userName, message);
		send(fd, fullMessage, strlen(fullMessage), 0);		
	}
	printf("\n*Chat Closed*\n");
	close(fd);
	return 0;
}

