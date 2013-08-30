%{
/*
	NOTE:
    1.union type_double about the Factor value
    2.UMINUS not declared in scanner
    3.%left COMMA??
*/
#include "lex.yy.c"
#include "defs.h"
#include "ErrorHandler.h"
int yylex();
void yyerror(const char *msg);
%}

%locations

%union{
	char type_char;
	int type_int;
	float type_float;
}

%token <type_char> CHAR
%token <type_int> INT 
%token <type_float> FLOAT
%token ID
%token SEMI COMMA
%token ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR
%token DOT NOT
%token TYPE
%token LP RP LB RB LC RC
%token STRUCT RETURN IF ELSE WHILE

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right UMINUS NOT
%left  LB RB LP RP DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

PROGRAM :   ExtDefList
        ;

ExtDefList  :   ExtDef  ExtDefList
            |   /* empty */
            ;

ExtDef  :   Specifier ExtDecList SEMI
        |   Specifier SEMI
        |   Specifier FunDec CompSt
        |   error SEMI
        ;

ExtDecList  :   VarDec
            |   VarDec COMMA ExtDecList
            ;

Specifier   :   TYPE
            |   StructSpecifier
            ;

StructSpecifier :   STRUCT OptTag LC DefList RC
                |   STRUCT Tag
                ;

OptTag  :   ID
        |   /* empty */
        ;

Tag :   ID
    ;

VarDec  :   ID
        |   VarDec LB INT RB
        ;

FunDec  :   ID LP VarList RP
        |   ID LP RP
        ;

VarList :   ParamDec COMMA VarList
        |   ParamDec
        ;

ParamDec    :   Specifier VarDec
            ;

CompSt  :   LC  DefList StmtList RC
        |   error RC
        ;

StmtList    :   Stmt StmtList
            |   /* empty */
            ;

Stmt    :   Exp SEMI
        |   CompSt
        |   RETURN Exp SEMI
        |   IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
        |   IF LP Exp RP Stmt ELSE Stmt
        |   WHILE LP Exp RP Stmt
        |   error SEMI
        ;

DefList :   Def DefList
        |   /* empty */
        ;

Def :   Specifier DecList SEMI
    |   error SEMI
    ;

DecList :   Dec
        |   Dec COMMA DecList
        ;

Dec :   VarDec
    |   VarDec ASSIGNOP Exp
    ;

Exp :   Exp ASSIGNOP Exp
    |   Exp AND Exp
    |   Exp OR Exp
    |   Exp RELOP Exp
    |   Exp PLUS Exp
    |   Exp MINUS Exp
    |   Exp STAR Exp
    |   Exp DIV Exp
    |   LP Exp RP
    |   MINUS Exp %prec UMINUS
    |   NOT Exp
    |   ID LP Args RP
    |   ID LP RP
    |   Exp LB Exp RB
    |   Exp DOT ID
    |   ID
    |   INT
    |   FLOAT
    ;

Args    :   Exp COMMA Args
        |   Exp
        ;

%%

extern char * yytext;
extern int yycolumn;

void yyerror(const char *msg)
{
  //fflush(stdout);
  //fprintf(stderr, "error :%d:%d: %s\n", yylineno, yycolumn, msg);
  reportError(SYNTAX_ERROR, yylineno, yycolumn, msg);
}
