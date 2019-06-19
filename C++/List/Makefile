EXE = list_test
OBJS = main.o list.o

CC = g++
WARNINGS = -pedantic -Wall -Wextra -Werror -Wfatal-errors -Wno-unused-parameter -Wno-unused-variable
DEBUG = -g
CFLAGS = $(WARNINGS) -c $(DEBUG) -O0

LD = g++
LDFLAGS = -std=c++1y

.PHONY: all
.PHONY: clean

all: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

main.o: main.cpp list.h
	$(CC) $(CFLAGS) main.cpp

list.o: list.cpp list.h
	$(CC) $(CFLAGS) list.cpp

clean:
	rm -rf $(OBJS) $(EXE)
