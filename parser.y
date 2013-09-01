%{
/*
NOTE:
    1.union type_double about the Factor value
    2.UMINUS not declared in scanner
    3.%left COMMA??
*/

#include "lex.yy.c"
#include "defs.h"
#include "ast.h"
#include "ErrorHandler.h"

int yylex();
void yyerror(const char *msg);
%}

%locations

%token CHAR INT FLOAT
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

PROGRAM :   ExtDefList { gl_ast_root = create_syntax(Program_SYNTAX, 1, $1); }
        ;

ExtDefList  :   ExtDef  ExtDefList { $$ = create_syntax(ExtDefList_SYNTAX, 2, $1, $2); }
            |   /* empty */ { $$ = create_syntax(ExtDefList_SYNTAX, 0); }
            ;

ExtDef  :   Specifier ExtDecList SEMI { $$ = create_syntax(ExtDef_SYNTAX, 3, $1, $2, $3); }
        |   Specifier SEMI { $$ = create_syntax(ExtDef_SYNTAX, 2, $1, $2); }
        |   Specifier FunDec CompSt { $$ = create_syntax(ExtDef_SYNTAX, 3, $1, $2, $3); }
        |   error SEMI { yyerrok; /* call yyerror() */ }
        ;

ExtDecList  :   VarDec { $$ = create_syntax(ExtDecList_SYNTAX, 1, $1); }
            |   VarDec COMMA ExtDecList  { $$ = create_syntax(ExtDecList_SYNTAX, 3, $1, $2, $3); }
            ;

Specifier   :   TYPE { $$ = create_syntax(Specifier_SYNTAX, 1, $1); }
            |   StructSpecifier { $$ = create_syntax(Specifier_SYNTAX, 1, $1); }
            ;

StructSpecifier :   STRUCT OptTag LC DefList RC { $$ = create_syntax(StructSpecifier_SYNTAX, 5, $1, $2, $3, $4, $5); }
                |   STRUCT Tag { $$ = create_syntax(StructSpecifier_SYNTAX, 2, $1, $2); }
                ;

OptTag  :   ID { $$ = create_syntax(OptTag_SYNTAX, 1, $1); }
        |   /* empty */ { $$ = create_syntax(OptTag_SYNTAX, 0); }
        ;

Tag :   ID { $$ = create_syntax(Tag_SYNTAX, 1, $1); }
    ;

VarDec  :   ID { $$ = create_syntax(VarDec_SYNTAX, 1, $1); }
        |   VarDec LB INT RB { $$ = create_syntax(VarDec_SYNTAX, 4, $1, $2, $3, $4); }
        ;

FunDec  :   ID LP VarList RP { $$ = create_syntax(FunDec_SYNTAX, 4,  $1, $2, $3, $4); }
        |   ID LP RP { $$ = create_syntax(FunDec_SYNTAX, 3,  $1, $2, $3); }
        ;

VarList :   ParamDec COMMA VarList { $$ = create_syntax(VarList_SYNTAX, 3,  $1, $2, $3); }
        |   ParamDec { $$ = create_syntax(VarList_SYNTAX, 1,  $1); }
        ;

ParamDec    :   Specifier VarDec { $$ = create_syntax(ParamDec_SYNTAX, 2, $1, $2); }
            ;

CompSt  :   LC  DefList StmtList RC { $$ = create_syntax(CompSt_SYNTAX, 4, $1, $2, $3, $4); }

        ;

StmtList    :   Stmt StmtList { $$ = create_syntax(StmtList_SYNTAX, 2, $1, $2); }
            |   /* empty */ { $$ = create_syntax(StmtList_SYNTAX, 0); }
            ;

Stmt    :   Exp SEMI { $$ = create_syntax(Stmt_SYNTAX, 2, $1, $2); }
        |   CompSt { $$ = create_syntax(Stmt_SYNTAX, 1, $1); }
        |   RETURN Exp SEMI { $$ = create_syntax(Stmt_SYNTAX, 3, $1, $2, $3); }
        |   IF LP Exp RP Stmt %prec LOWER_THAN_ELSE { $$ = create_syntax(Stmt_SYNTAX, 5, $1, $2, $3, $4, $5); }
        |   IF LP Exp RP Stmt ELSE Stmt { $$ = create_syntax(Stmt_SYNTAX, 7, $1, $2, $3, $4, $5, $6, $7); }
        |   WHILE LP Exp RP Stmt { $$ = create_syntax(Stmt_SYNTAX, 5, $1, $2, $3, $4, $5); }
        |   error SEMI { yyerrok; }
        ;

DefList :   Def DefList  { $$ = create_syntax(DefList_SYNTAX, 2, $1, $2); }
        |   /* empty */  { $$ = create_syntax(DefList_SYNTAX, 0); }
        ;

Def :   Specifier DecList SEMI { $$ = create_syntax(Def_SYNTAX, 3, $1, $2, $3); }

    ;

DecList :   Dec  { $$ = create_syntax(DecList_SYNTAX, 1, $1); }
        |   Dec COMMA DecList  { $$ = create_syntax(DecList_SYNTAX, 3, $1, $2, $3); }
        ;

Dec :   VarDec { $$ = create_syntax(Dec_SYNTAX, 1, $1); }
    |   VarDec ASSIGNOP Exp { $$ = create_syntax(Dec_SYNTAX, 3, $1, $2, $3); }
    ;

Exp :   Exp ASSIGNOP Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp AND Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp OR Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp RELOP Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp PLUS Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp MINUS Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp STAR Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp DIV Exp { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   LP Exp RP
    |   MINUS Exp %prec UMINUS { $$ = create_syntax(Exp_SYNTAX, 2, $1, $2); }
    |   NOT Exp { $$ = create_syntax(Exp_SYNTAX, 2, $1, $2); }
    |   ID LP Args RP { $$ = create_syntax(Exp_SYNTAX, 4, $1, $2, $3, $4); }
    |   ID LP RP { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   Exp LB Exp RB { $$ = create_syntax(Exp_SYNTAX, 4, $1, $2, $3, $4); }
    |   Exp DOT ID { $$ = create_syntax(Exp_SYNTAX, 3, $1, $2, $3); }
    |   ID { $$ = create_syntax(Exp_SYNTAX, 1, $1); }
    |   INT { $$ = create_syntax(Exp_SYNTAX, 1, $1); }
    |   FLOAT { $$ = create_syntax(Exp_SYNTAX, 1, $1); }
    |   CHAR { $$ = create_syntax(Exp_SYNTAX, 1, $1); }
    ;

Args    :   Exp COMMA Args { $$ = create_syntax(Args_SYNTAX, 3, $1, $2, $3); }
        |   Exp { $$ = create_syntax(Args_SYNTAX, 1, $1); }
        ;

%%

extern char * yytext;
extern int yycolumn;

void yyerror(const char *msg)
{
  //fflush(stdout);
  //fprintf(stderr, "error :%d:%d: %s\n", yylineno, yycolumn, msg);
  reportError(SYNTAX_ERROR, yylineno, yylloc.first_column, msg);
}
