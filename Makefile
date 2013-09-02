CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall
YFLAGS = -d -v
LIB = -lfl -ly

HEADERS = defs.h ErrorHandler.h ast.h

OBJS = defs.o\
	ErrorHandler.o\
	parser.tab.o\
	ast.o\
	main.o

parser : defs.o ErrorHandler.o parser.tab.o ast.o main.o \
		lex.yy.c $(HEADERS)
	$(CC) defs.o ErrorHandler.o parser.tab.o ast.o main.o $(CFLAGS) $(LIB) -o parser
scanner	: lexmain.c lex.yy.c
	$(CC) lex.yy.c lexmain.c $(CFLAGS) -lfl -o scanner
main.o : main.c $(HEADERS)
	$(CC) $(CFLAGS) main.c -c
defs.o : defs.c defs.h
	$(CC) $(CFLAGS) defs.c -c
ErrorHandler.o: ErrorHandler.c ErrorHandler.h defs.h
	$(CC) $(CFLAGS) ErrorHandler.c -c
parser.tab.o: parser.tab.c $(HEADERS)
	$(CC) $(CFLAGS) $(LIB) parser.tab.c -c
ast.o : ast.c ast.h defs.h parser.tab.h
	$(CC) $(CFLAGS) ast.c -c
parser.tab.c : lex.yy.c parser.y $(HEADERS)
	$(YACC) $(YFLAGS) parser.y
lex.yy.c : parser.tab.h scanner.l $(HEADERS)
	$(LEX) scanner.l
parser.tab.h : parser.y

clean :
	rm *.o parser scanner

realclean:
	rm -f *.o parser scannner parser.tab.c parser.tab.h lex.yy.c
