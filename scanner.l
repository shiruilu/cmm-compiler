%{
/* NOTE:
	1. yycolumn not completed
	2. {IS} 3uull accept??
*/
#include <stdio.h>
#include "y.tab.h"

// #define PRINT_TOKEN

int yycolumn = 1;
/*
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
		yycolumn += yyleng;
*/
%}

%option yylineno

/* General Defination */

DEC		[0-9]
NDEC		[1-9]
HEX		[a-fA-F0-9]
OCT		[0-7]
LETTER		[_a-zA-Z]
E			[Ee][+-]?{DEC}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

/* Tokens */
CHAR		'(\\.|[^\\'])+'
INT		(0[xX]{HEX}+{IS}?)|(0{OCT}+{IS}?)|({DEC}{IS}?)|({NDEC}{DEC}+{IS}?)
FLOAT		({DEC}+{E}{FS}?)|({DEC}*"."{DEC}+({E})?{FS}?)|({DEC}+"."{DEC}*({E})?{FS}?)
ID		{LETTER}(({LETTER}|{DEC}){0,31})
SEMI    	;
COMMA   	,
ASSIGNOP    	=
RELOP   	>|<|>=|<=|==|!=
PLUS    	\+
MINUS   	-
STAR    	\*
DIV 		\/
AND 		&&
OR  		\|\|
DOT 		\.
NOT 		!
TYPE    	int|float|char
LP  		\(
RP  		\)
LB  		\[
RB  		\]
LC  		\{
RC  		\}
STRUCT  	struct
RETURN  	return
IF  		if
ELSE    	else
WHILE   	while

BLANK		[ \t\v\f\r]

%x		COMMENT

%%
/* line comment */
"//".*\n		{}

/* block comment */
"/*"			{ BEGIN(COMMENT); }
<COMMENT>"*/"		{ BEGIN(INITIAL); }
<COMMENT><<EOF>>	{ 
#ifdef PRINT_TOKEN
	fprintf(stdout, "Error type 1 at line %d: Unterminated comment\n", yylineno);
#endif 
}
<COMMENT>\n		{ yycolumn = 1; }
<COMMENT>.		{ }

/* blank characters */
{BLANK}			{ }
\n			{ yycolumn = 1; }

/* tokens */
{CHAR}	{
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d CHAR\t:%s\n", yylineno, yytext);
#endif
	return CHAR;
}

{INT} {
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d INT\t:%s\n", yylineno, yytext);
#endif
	return INT;
}

{FLOAT} {
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d FLOAT\t:%s\n", yylineno, yytext);
#endif
	return FLOAT;
}

{SEMI} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d SEMI\n", yylineno);
#endif
	return SEMI;
}

{COMMA}	{ 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d COMMA\n", yylineno);
#endif
	return COMMA;
}

{ASSIGNOP}    { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ASSIGNOP\n", yylineno);
#endif
	return ASSIGNOP;
}

{RELOP}   { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RELOP\n", yylineno);
#endif
	return RELOP;
}

{PLUS}    { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d PLUS\n", yylineno);
#endif
	return PLUS;
}

{MINUS}   { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d MINUS\n", yylineno);
#endif
	return MINUS;
}

{STAR}    { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d STAR\n", yylineno);
#endif
	return STAR;
}

{DIV} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d DIV\n", yylineno);
#endif
	return DIV;
}

{AND} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d AND\n", yylineno);
#endif
	return AND;
}

{OR}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d OR\n", yylineno);
#endif
	return OR;
}

{DOT} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d DOT\n", yylineno);
#endif
	return DOT;
}

{NOT} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d NOT\n", yylineno);
#endif
	return NOT;
}

{TYPE}    { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d TYPE\t:%s\n", yylineno, yytext);
#endif
	return TYPE;
}

{LP}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LP\n", yylineno);
#endif
	return LP;
}

{RP}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RP\n", yylineno);
#endif
	return RP;
}

{LB}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LB\n", yylineno);
#endif
	return LB;
}

{RB}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RB\n", yylineno);
#endif
	return RB;
}

{LC}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LC\n", yylineno);
#endif
	return LC;
}

{RC}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RC\n", yylineno);
#endif
	return RC;
}

{STRUCT}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d STRUCT\n", yylineno);
#endif
	return STRUCT;
}

{RETURN}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RETURN\n", yylineno);
#endif
	return RETURN;
}

{IF}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d IF\n", yylineno);
#endif
	return IF;
}

{ELSE}    { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ELSE\n", yylineno);
#endif
	return ELSE;
}

{WHILE}   { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d WHILE\n", yylineno);
#endif
	return WHILE;
}

{ID}  { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ID\t:%s\n", yylineno, yytext);
#endif
	return ID;
}

.			{ fprintf(stdout, "Error type 1 at line %d: Mysterious character\'%s\'\n", yylineno, yytext);  }

%%

yywrap()
{
	return(1);
}
