CC = gcc
LEX = flex
YACC = bison
CFLAGS = -g
YFLAGS = -d -v
DEBUGFLAGS = -g
LIB = -lfl -ly
OUT_IR = tests/ir/out_files/
OUT_S = tests/goal/out_files/

HEADERS = parser.tab.h defs.h ErrorHandler.h ast.h type.h semantic_analysis.h symbol_table.h\
			type.h ir.h trans.h gen_code.h var_table.h opt.h

OBJS = defs.o\
	type.o\
	ErrorHandler.o\
	parser.tab.o\
	semantic_analysis.o\
	symbol_table.o\
	ast.o\
	ir.o\
	trans.o\
	opt.o\
	var_table.o\
	gen_code.o\
	main.o

scc	: defs.o ErrorHandler.o parser.tab.o semantic_analysis.o symbol_table.o ast.o\
		ir.o trans.o opt.o type.o var_table.o gen_code.o main.o lex.yy.c $(HEADERS)
	$(CC) $(DEBUGFLAGS) gen_code.o var_table.o defs.o ErrorHandler.o parser.tab.o	\
		semantic_analysis.o symbol_table.o ast.o ir.o trans.o opt.o type.o main.o	\
		$(CFLAGS) $(LIB) -o scc

parser : defs.o ErrorHandler.o parser.tab.o semantic_analysis.o symbol_table.o\
		ast.o ir.o trans.o type.o main.o lex.yy.c $(HEADERS)
	$(CC) $(DEBUGFLAGS) defs.o ErrorHandler.o parser.tab.o semantic_analysis.o	\
		symbol_table.o ast.o ir.o trans.o type.o main.o $(CFLAGS) $(LIB) -o parser

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
symbol_table.o : symbol_table.c symbol_table.h defs.h type.h ir.h
	$(CC) $(CFLAGS) $(LIB) symbol_table.c -c
semantic_analysis.o : semantic_analysis.c semantic_analysis.h ast.h	\
					symbol_table.h type.h ErrorHandler.h
	$(CC) $(CFLAGS) $(LIB) semantic_analysis.c -c
ast.o : ast.c ast.h defs.h parser.tab.h type.h
	$(CC) $(CFLAGS) ast.c -c
ir.o : ir.c ir.h defs.h
	$(CC) $(CFLAGS) ir.c -c
trans.o : trans.c trans.h ir.h ast.h defs.h symbol_table.h
	$(CC) $(CFLAGS) trans.c -c
opt.o : opt.c opt.h ir.h defs.h
	$(CC) $(CFLAGS) opt.c -c
type.o : type.c type.h
	$(CC) $(CFLAGS) type.c -c
var_table.o : var_table.c var_table.h defs.h
	$(CC) $(CFLAGS) var_table.c -c
gen_code.o : gen_code.c gen_code.h defs.h ir.h var_table.h
	$(CC) $(CFLAGS) gen_code.c -c
parser.tab.c : lex.yy.c parser.y $(HEADERS)
	$(YACC) $(YFLAGS) parser.y
lex.yy.c : parser.tab.h scanner.l $(HEADERS)
	$(LEX) scanner.l
parser.tab.h : parser.y

clean :
	rm -f ${OUT_IR}*.ir ${OUT_S}*.s *.o scc parser scanner

realclean:
	rm -f ${OUT_IR}*.ir ${OUT_S}*.s  *.o scc parser scannner parser.tab.c parser.tab.h lex.yy.c
