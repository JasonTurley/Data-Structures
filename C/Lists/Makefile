# setup the compiler
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Wno-error=unused-parameter

# the build target exec
TARGET = list

.PHONY: all

$(TARGET): $(TARGET).c main.c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c main.c

clean:
	rm -rf $(TARGET) *.o
