CC = gcc
LEX = flex
YACC = bison
LIB = -lfl -ly

parser : y.tab.c main.c
	$(CC) main.c y.tab.c $(LIB) -o parser
scanner	: lexmain.c lex.yy.c
	$(CC) lexmain.c lex.yy.c -lfl -o scanner
main.c :

lexmain.c:

y.tab.c : lex.yy.c

lex.yy.c : y.tab.h scanner.l
	$(LEX) scanner.l
y.tab.h : parser.y
	$(YACC) -d parser.y

clean :
	rm parser scanner

realclean:
	rm -f parser scannner y.tab.c y.tab.h lex.yy.c
