%{
/*
NOTE:
	1. yycolumn not completed
	2. {IS} 3uull accept??
*/
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "defs.h"
#include "ErrorHandler.h"
#include "parser.tab.h"


#define TAB_WIDTH 1 // when not used, assign TAB_WIDTH=1
// #define PRINT_TOKEN

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
		yycolumn += yyleng;

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
TYPE    	char|int|float
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

BLANK		[ \v\f\r]

%x		COMMENT

%%

"//".*\n		{ yycolumn = 1; }

"/*"			{ BEGIN(COMMENT); }
<COMMENT>"*/"		{ BEGIN(INITIAL); }
<COMMENT><<EOF>>	{ 
	reportError(COMMENT_ERROR, yylineno, yylloc.first_column, "Unterminated comment");
}
<COMMENT>\n		{ yycolumn = 1; }
<COMMENT>.		{ }

{BLANK}			{ }
\n			{ yycolumn = 1; }
\t			{ yycolumn += (TAB_WIDTH-1); }

{CHAR} {
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d CHAR\t:%s\n", yylineno, yytext);
#endif
	yylval = create_token(CHAR_TOKEN);
	yylval->value.char_val = *(yytext+1); // yytext ~ '.' . stands for a char
	return CHAR;
}

{INT} {
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d INT\t:%s\n", yylineno, yytext);
#endif
	yylval = create_token(INT_TOKEN);
	yylval->value.int_val = full_atoi(yytext);
	return INT;
}

{FLOAT} {
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d FLOAT\t:%s\n", yylineno, yytext);
#endif
	yylval = create_token(FLOAT_TOKEN);
	yylval->value.float_val = atof(yytext);
	return FLOAT;
}

{SEMI} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d SEMI\n", yylineno);
#endif
	yylval = create_token(SEMI_TOKEN);
	return SEMI;
}

{COMMA}	{ 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d COMMA\n", yylineno);
#endif
	yylval = create_token(COMMA_TOKEN);
	return COMMA;
}

{ASSIGNOP} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ASSIGNOP\n", yylineno);
#endif
	yylval = create_token(ASSIGNOP_TOKEN);
	return ASSIGNOP;
}

{RELOP} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RELOP\n", yylineno);
#endif
	yylval = create_token(RELOP_TOKEN);
	/* RELOP is not unique, so remain to be analysed */
	yylval->value.str_val = String(yytext); 
	return RELOP;
}

{PLUS} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d PLUS\n", yylineno);
#endif
	yylval = create_token(PLUS_TOKEN);
	return PLUS;
}

{MINUS} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d MINUS\n", yylineno);
#endif
	yylval = create_token(MINUS_TOKEN);
	return MINUS;
}

{STAR} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d STAR\n", yylineno);
#endif
	yylval = create_token(STAR_TOKEN);
	return STAR;
}

{DIV} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d DIV\n", yylineno);
#endif
	yylval = create_token(DIV_TOKEN);
	return DIV;
}

{AND} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d AND\n", yylineno);
#endif
	yylval = create_token(AND_TOKEN);
	return AND;
}

{OR} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d OR\n", yylineno);
#endif
	yylval = create_token(OR_TOKEN);
	return OR;
}

{DOT} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d DOT\n", yylineno);
#endif
	yylval = create_token(DOT_TOKEN);
	return DOT;
}

{NOT} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d NOT\n", yylineno);
#endif
	yylval = create_token(NOT_TOKEN);
	return NOT;
}

{TYPE} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d TYPE\t:%s\n", yylineno, yytext);
#endif
	yylval = create_token(TYPE_TOKEN);
	if ( !strcmp(yytext, "char") )
		yylval->value.type_val = Char;
	else if( !strcmp(yytext, "int") )
		yylval->value.type_val = Int;
	else if( !strcmp(yytext, "float") )
		yylval->value.type_val = Float;
	return TYPE;
}

{LP} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LP\n", yylineno);
#endif
	yylval = create_token(LP_TOKEN);
	return LP;
}

{RP} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RP\n", yylineno);
#endif
	yylval = create_token(RP_TOKEN);
	return RP;
}

{LB} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LB\n", yylineno);
#endif
	yylval = create_token(LB_TOKEN);
	return LB;
}

{RB} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RB\n", yylineno);
#endif
	yylval = create_token(RB_TOKEN);
	return RB;
}

{LC} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d LC\n", yylineno);
#endif
	yylval = create_token(LC_TOKEN);
	return LC;
}

{RC} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RC\n", yylineno);
#endif
	yylval = create_token(RC_TOKEN);
	return RC;
}

{STRUCT} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d STRUCT\n", yylineno);
#endif
	yylval = create_token(STRUCT_TOKEN);
	return STRUCT;
}

{RETURN} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d RETURN\n", yylineno);
#endif
	yylval = create_token(RETURN_TOKEN);
	return RETURN;
}

{IF} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d IF\n", yylineno);
#endif
	yylval = create_token(IF_TOKEN);
	return IF;
}

{ELSE} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ELSE\n", yylineno);
#endif
	yylval = create_token(ELSE_TOKEN);
	return ELSE;
}

{WHILE} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d WHILE\n", yylineno);
#endif
	yylval = create_token(WHILE_TOKEN);
	return WHILE;
}

{ID} { 
#ifdef PRINT_TOKEN
	fprintf(stdout, "line:%4d ID\t:%s\n", yylineno, yytext);
#endif
	yylval = create_token(ID_TOKEN);
	yylval->value.str_val = String(yytext);
	return ID;
}

. {
	char err[MAX_ERRINFO];
	sprintf(err, "Mysterious character :\'%s\'", yytext);
	assert( strlen(err) < MAX_ERRINFO );
	reportError(LEXICAL_ERROR, yylineno, yylloc.first_column, err);
}

%%

int yywrap()
{
	return(1);
}
