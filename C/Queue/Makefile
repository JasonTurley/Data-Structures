# set up compiler
CC = gcc
CFLAGS = -c -Wall -Wextra

.PHONY: clean

queue: main.o queue.o list.o
	$(CC) -o queue main.o queue.o list.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) main.c 

queue.o: queue.c queue.h list.h
	$(CC) $(CFLAGS) queue.c 

list.o: list.c list.h
	$(CC) $(CFLAGS) list.c

clean:
	rm -rf *.o queue
