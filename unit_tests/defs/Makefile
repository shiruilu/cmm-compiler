CC = gcc
CFLAGS = -Wall
LIB = -lfl -ly

test : test_defs.c defs.c defs.h
	$(CC) defs.c test_defs.c $(CFLAGS) $(LIB) -o test

clean: 
	rm *.o test
