CC=gcc
CFLAGS=-Wpedantic -g -Wall

main: main.o 
	$(CC) $(CFLAGS) -o $@ main.c

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

lexer.o: lexer.c
	$(CC) $(CFLAGS) -c $< -o $@


