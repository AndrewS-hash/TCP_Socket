all: server client

server:
	gcc -o server tcp_server.c
client:
	gcc -o client tcp_client.c
