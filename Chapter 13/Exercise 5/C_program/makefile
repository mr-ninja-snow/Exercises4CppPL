all: client server

client: client.o
	gcc -o client client.o

server: server.o
	gcc -o server server.o

server.o: server.c
	gcc -c server.c

client.o: client.c
	gcc -c client.c

clean:
	rm -rf *o server client