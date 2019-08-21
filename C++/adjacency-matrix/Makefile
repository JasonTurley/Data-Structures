EXE = adjacency_matrix
OBJS = main.o adjacency_matrix.o

CXX = g++
WARNINGS = -pedantic -Wall -Wextra -Werror -Wfatal-errors -Wno-unused-parameter -Wno-unused-variable
CXXFLAGS = $(WARNINGS) -c -g -O2

LD = g++
LDFLAGS = -std=c++11

.PHONY: all
.PHONY: clean
.PHONY: valgrind

all: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(EXE)

# run valgrind to test for memory leaks
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE)
