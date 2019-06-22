EXE = test
OBJS = main.o avltree.o

CXX = g++
WARNINGS = -pedantic -Wall -Wextra -Werror -Wfatal-errors -Wno-unused-parameter -Wno-unused-variable
DEBUG = -g
CXXFLAGS = $(WARNINGS) -c $(DEBUG) -O0

LD = g++
LDFLAGS = -std=c++1y

.PHONY: all
.PHONY: clean

all: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(EXE)
