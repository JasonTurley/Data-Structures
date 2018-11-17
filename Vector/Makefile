# Makefile for vector.c
# @date - 11/16/18

test: main.o vector.o utils.o
	gcc -o test main.o vector.o utils.o -lm

main.o: main.c
	gcc -O -Wall -Wextra -Werror -c main.c

vector.o: vector.c
	gcc -O -Wall -Wextra -Werror -c vector.c

utils.o: utils.c
	gcc -O -Wall -Wextra -Werror -c utils.c

clean:
	rm -f main.o vector.o utils.o test
