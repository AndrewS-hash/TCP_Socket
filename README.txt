Andrew Schmidt
3/5/2023

I have neither given nor recived unauthorized assistance on this work


----
Description:
Create a socket using TCP, Simulate sending a message to test code.


----
How to run:
1) Use 'make' to ensure both server and client executables are updated and ready to go
2) In one terminal, execute the server executable with './server'
3) Within the server terminal it will create the socket and begin listening for a connection
4) In another terminal, execute the client executable with './client'
5) It will show either an error or successful connection made, followed by a prompt to enter
   a message to be sent to the server
6) After sending the message, it will appear on the server terminal, along with reciving 
   a response from the server as an acknoledgment of receving the message.
7) The sockets will then be closed on both ends and both applications will close.


----
Files:
README.txt 

This file...Containes project description, run instructions, file notes, and leassons learned


Makefile

Use the command 'make' to run this file which compiles both tcp_client.c into client and
the tcp_server.c into server. If any changes are made to tcp_client.c or tcp_server.c this
file when run will update the executables


tcp_client.c - Help from textbook 

This file operates as an indiviudal trying to send a message. This needs to be run after
the tcp_server is started with matching IP and port numbers. Once connected successfully,
the user is able to enter in some text to be sent to tcp_server. It will then wait to
recive a message back (this can be text or just an ack) the close the connection.


tcp_server.c - Help from textbook

This files operates as a reciving individual that is reciving a message/request. This is run
first and if successful will get to a waiting for incoming connections message, which indicates
that it is ready for tcp_client to be run. It will then accept and print the message, along
with returning an ack/message before closing the socket.


client

This is the executable of tcp_client.c created from the Makefile


server

This is the executable of tcp_server.c created from the Makefile


----
Lessons:

A lot of functions that I don't fully understand what they are doing, such as connect. There
are a lot of things in the sockaddr_in struct that I need to do some more work at looking into.

Right now I have the code written and pursuably working, but getting them to run in the order
of server, the client with a successfuly connection between them hasn't worked yet. I need
to enusre that my code is correct, along with matching ports, and IP's before moving on in
troubleshooting. 

Through troubleshooting I found a couple of syntax errors causing segmentation faults and weird
stuff as you can notice by my if else statments put in to better find where a problem has occured
but aslo helpful in knowing what the system is doing for the end user so I kept them. 

I was using scanf() to get the user input but this ended up only getting the first word of input.
Looking online through some StackOverflow I found the gets() functions, which when compiled
shows a warning to not use gets() unless necessary. The code now runs as intended, but might look
for other ways to get input without having this warning appear.

I have updated to using a fgets() function to get user input, this runs the problem where a
user could enter in a string longer than the BUF_SIZE resulting in a crash. I could probably use
some kind of try/catch block to ensure user can input message without a failure, however since
the message size being sent is also limited by the buffer size I am leaving it as is.

If I was to work more on this I would want to find a way to ensure that if an entire message
couldn't fit into the BUF_SIZE that it would loop and contiune to send additional packets until
the entire message was transfered.

I also added a Makefile so instead of running both gcc commands you can no just use make to ensure
both executables are ready to go quick and easily. 


