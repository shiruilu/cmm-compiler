parser : y.tab.c main.c
	cc main.c y.tab.c -lfl -ly -o parser
main.c :

y.tab.c : lex.yy.c

lex.yy.c : y.tab.h scanner.l
	lex scanner.l
y.tab.h : parser.y
	yacc -d parser.y

clean :
	rm parser y.tab.c y.tab.h lex.yy.c
