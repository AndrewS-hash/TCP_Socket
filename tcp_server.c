// Andrew Schmidt


#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 2000
#define BUF_SIZE 1024
#define ADDR "127.0.0.1"

int main(void) {
	int socket_desc, client_sock, client_size;
	struct sockaddr_in server_addr, client_addr;
	char server_message[BUF_SIZE], client_message[BUF_SIZE];

	memset(server_message, '\0', sizeof(server_message));
	memset(client_message, '\0', sizeof(client_message));

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc < 0) {
		printf("Error creating socket\n");
		return -1;
	} else {
		printf("Socket created successfully\n");
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = inet_addr(ADDR);

	if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0) {
		printf("Error binding port");
		return -1;
	} else {
		printf("Binding done\n");
	}

	if(listen(socket_desc, 1) < 0) {
		printf("error while listening");
		return -1;
	} else {
		printf("\n\nListenting for connections.......\n");
	}

	client_size = sizeof(client_addr);
	client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);

	if (client_sock < 0) {
		printf("accepting failed\n");
		return -1;
	} else {
		printf("accpeted at IP: %s, and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));		
	}
	
	if (recv(client_sock, client_message, sizeof(client_message), 0) < 0) {
		printf("Message failed to recive\n");
		return -1;
	} else {
		printf("Message from client: %s\n", client_message);
	}

	//Response
	strcpy(server_message, "This is the server responding");

	if (send(client_sock, server_message, strlen(server_message), 0) < 0) {
		printf("Sending failed...\n");
		return -1;
	} else {
		printf("Retrun smssage sent successfully\n");
	}

	// Close the socket
	close(client_sock);
	close(socket_desc);

	return 0;
}
