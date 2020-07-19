all: add-nbo

add-nbo: byte_ping.c
	g++ -o add-nbo byte_ping.c

