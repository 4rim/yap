CC=gcc
CFLAGS=-Wpedantic -g -Wall
all: main main.o lexer.o

main: main.o 
	$(CC) $(CFLAGS) -o $@ main.c

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

lexer.o: lexer.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o

