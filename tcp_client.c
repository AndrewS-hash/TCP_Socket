//Andrew Schmidt

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 2000
#define BUF_SIZE 1024
#define ADDR "127.0.0.1"

int main(void) {

	int socket_desc;
	struct sockaddr_in server_addr;
	char server_message[BUF_SIZE], client_message[BUF_SIZE];

	memset(server_message, '\0', sizeof(server_message));
	memset(client_message, '\0', sizeof(client_message));	

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc < 0) {
		printf("unable to create socket\n");
		return -1;
	}

	printf("Socket created successfully\n");


	//Set port and IP addresses
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(ADDR);		

	// Send connection request
	if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		printf("unable to connect\n");
		return -1;
	} else {
		printf("Connected with server successfully\n");
	}
	
	// Get input from the user:
	printf("Enter Message to send: ");
	fgets(client_message, BUF_SIZE, stdin);

	// Send the message
	if (send(socket_desc, client_message, strlen(client_message), 0) < 0) {
		printf("Unable to send message\n");
		return -1;
	} else {
		printf("message sent\n");
	}

	// Recieve server response
	if (recv(socket_desc, server_message, sizeof(server_message), 0) < 0) {
		printf("Error while reciving message\n");
		return -1;
	} else {
		printf("Server's response: %s\n", server_message);
	}

	//Close socket
	close(socket_desc);

	return 0;
}
