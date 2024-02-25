CC=gcc
CFLAGS=-Wpedantic -g -Wall

main: main.c
	$(CC) $(CFLAGS) -o $@ $<
