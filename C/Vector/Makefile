# specify compiler, compile flags, and needed libs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Werror=unused-parameter -Werror=unused-variable

LD = gcc
LIBS = -lm

# specify all source files here
SRCS = main.c vector.c

# specify target here (name of executable)
TARG = test

# this translates .c files in src list to .o's
OBJS = $(SRCS:.c=.o)

all: $(TARG)

# this generates the target executable
$(TARG): $(OBJS)
	$(LD) -o $(TARG) $(OBJS) $(LIBS)

# this is a generic rule for .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARG)
