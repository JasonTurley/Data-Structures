# set up compiler
CC = gcc
WARNINGS = -Wall -Wextra -Werror
DEBUG = -g
CFLAGS = $(WARNINGS) $(DEBUG)

# set up linker
LD = gcc
LIBS =

# specify all source files
SRCS = main.c hashtable.c

# specify executable
EXE = hashtable

# truncate all source files into object files
OBJS = $(SRCS:.c=.o)

.PHONY: all
.PHONY: clean

all: $(EXE)

# generate target executables
$(EXE): $(OBJS)
	$(LD) -o $(EXE) $(OBJS) $(LIBS)

# generic rule for all object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(EXE)
