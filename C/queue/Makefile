OBJS_DIR = .objs

# define executables
EXE_QUEUE=queue

# list object file dependencies for each
OBJS_QUEUE=$(EXE_QUEUE).o
OBJS_MAIN=main.o

OBJS_ALL = $(OBJS_QUEUE) $(OBJS_MAIN)

# set up compiler
CC = gcc
INCLUDES = -I./libs/
WARNINGS = -Wall -Wextra -Wno-unsued -Wno-unsued-parameter
CFLAGS_DEBUG = -O0 $(INCLUDES) $(WARNINGS) -g -std=c99 -c -D_GNU_SOURCE -DDEBUG
CFLAGS_RELEASE = -O0 $(INCLUDES) $(WARNINGS) -std=c99 -c -D_GNU_SOURCE

# set up linker
LD = gcc
LFLAGS = -Llibs/ -llist

.PHONY: all
all: release

.PHONY: debug
.PHONY: release
.PHONY: clean

release: $(EXE_QUEUE)
debug: $(EXE_QUEUE:%=%-debug)

#include dependencies
-include $(OBJS_DIR)/*.d
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# patterns to create objects
$(OBJS_DIR)/%-release.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS_RELEASE) $< -o $@

$(OBJS_DIR)/%-debug.o: %.c | (OBJS_DIR)
	$(CC) $(CFLAGS_DEBUG) $< -o $@

# exes
# you will need exe and exe-debug
$(EXE_QUEUE): $(OBJS_ALL:%.o=$(OBJS_DIR)/%-release.o)
	$(LD) $^ $(LFLAGS) -o $@

$(EXE_QUEUE)-debug: $(OBJS_ALL:%.o=$(OBJS_DIR)/%-debug.o)
	$(LD) $^ $(LFLAGS) -o $@

clean:
	rm -rf .objs $(EXE_QUEUE) $(EXE_QUEUE:%=%-debug)
