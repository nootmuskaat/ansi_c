CC=gcc
CFLAGS=-Wall -Werror -std=c11 -I.
CLIBS=-lm

calc: main.c getop.c stack.c  getch.c
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)


