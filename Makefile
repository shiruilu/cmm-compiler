CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall
LIB = -lfl -ly

HEADERS = defs.h ErrorHandler.h

OBJS =	main.o\
	parser.tab.o\
	ErrorHandler.o

parser : parser.tab.c main.c
	$(CC) main.c parser.tab.c ErrorHandler.c $(CFLAGS) $(LIB) -o parser
scanner	: lexmain.c lex.yy.c
	$(CC) lex.yy.c lexmain.c $(CFLAGS) -lfl -o scanner
main.o : main.c $(HEADERS)
	$(CC) $(CFALGS) main.c -c
lexmain.c:

parser.tab.o: parser.tab.c $(headers)
	$(CC) $(CFLAGS) $(LIB) parser.tab.c -c
parser.tab.c : lex.yy.c parser.y $(HEADERS)
	$(YACC) -d parser.y
lex.yy.c : parser.tab.h scanner.l
	$(LEX) scanner.l
parser.tab.h : parser.y

parser.y:

scanner.l:

clean :
	rm *.o parser scanner

realclean:
	rm -f *.o parser scannner parser.tab.c parser.tab.h lex.yy.c
