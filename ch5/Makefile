CC=gcc
CFLAGS=-Wall -Werror -std=c11 -ggdb

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

findstr: findstr.c getline.c getline.h
	$(CC) $(CFLAGS) -o $@ findstr.c getline.c

tail: ex13.c getline.c getline.h
	$(CC) $(CFLAGS) -o $@ ex13.c getline.c


.PHONY: clean
clean:
	rm findstr tail *.o
