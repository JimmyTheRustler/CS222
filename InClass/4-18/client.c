#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

void readLine(char buffer[]){
	char c = getchar();
	int i;
	while( (c = getchar()) != '\n' ){
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\n';
	buffer[i+1] = '\0';
}


int main(){
	int port;
	char ipAddress[64];
	
	printf("Enter a port: ");
	scanf("%d", &port);
	printf("Enter an IP: ");
	scanf("%s", ipAddress);
	
	
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress, &(address.sin_addr));
	
	connect(fd, (struct sockaddr *) &address, sizeof(address));
	
	char message[8192] = "";
	
	while( strcmp("stop\n", message) != 0 ){
		
		printf("Enter a message: ");
		readLine(message);
		send(fd, message, strlen(message), 0);		
	}
	close(fd);
	return 0;
}

