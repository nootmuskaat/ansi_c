CC=gcc
CFLAGS=-Wall -Werror -std=c11 -ggdb

bowl: bowling_test.c bowling.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^
