CC = gcc
LEX = flex
YACC = bison
LIB = -lfl -ly

parser : parser.tab.c main.c
	$(CC) main.c parser.tab.c $(LIB) -o parser
scanner	: lexmain.c lex.yy.c
	$(CC) lexmain.c lex.yy.c -lfl -o scanner
main.c :

lexmain.c:

parser.tab.c : lex.yy.c parser.y

lex.yy.c : parser.tab.h scanner.l
	$(LEX) scanner.l
parser.tab.h : parser.y
	$(YACC) -d parser.y
scanner.l:

parser.y:

clean :
	rm parser scanner

realclean:
	rm -f parser scannner parser.tab.c parser.tab.h lex.yy.c
