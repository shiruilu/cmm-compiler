%{
/*
	NOTE: union type_double about the Factor value
*/
	#include "lex.yy.c"
	int yylex();
%}

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

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

PROGRAM :   ExtDefList { syntax_tree_root = create_syntax_tree_node("PROGRAM", 1, $1); }
        ;

ExtDefList  :   ExtDef  ExtDefList { $$ = create_syntax_tree_node("ExtDefList", 2, $1, $2);  }
            |   /* empty */ { $$ = create_syntax_tree_node("ExtDefList", 0); }
            ;

ExtDef  :   Specifier ExtDecList SEMI { $$ = create_syntax_tree_node("ExtDef", 3, $1, $2, $3);  }
        |   Specifier SEMI { $$ = create_syntax_tree_node("ExtDef", 2, $1, $2);  }
        |   Specifier FunDec CompSt { $$ = create_syntax_tree_node("ExtDef", 3, $1, $2, $3);  }
        |   error SEMI { resume_from_error("SEMI"); }
        ;

ExtDecList  :   VarDec { $$ = create_syntax_tree_node("ExtDecList", 1, $1);  }
            |   VarDec COMMA ExtDecList { $$ = create_syntax_tree_node("ExtDecList", 3, $1, $2, $3);  }
            ;

Specifier   :   TYPE { $$ = create_syntax_tree_node("Specifier", 1, $1);  }
            |   StructSpecifier { $$ = create_syntax_tree_node("Specifier", 1, $1);  }
            ;

StructSpecifier :   STRUCT OptTag LC DefList RC { $$ = create_syntax_tree_node("StructSpecifier", 5, $1, $2, $3, $4, $5);  }
                |   STRUCT Tag { $$ = create_syntax_tree_node("StructSpecifier", 2, $1, $2);  }
                ;

OptTag  :   ID { $$ = create_syntax_tree_node("OptTag", 1, $1);  }
        |   /* empty */ { $$ = create_syntax_tree_node("OptTag", 0);  }
        ;

Tag :   ID { $$ = create_syntax_tree_node("Tag", 1, $1);  }
    ;

VarDec  :   ID { $$ = create_syntax_tree_node("VarDec", 1, $1);  }
        |   VarDec LB INT RB { $$ = create_syntax_tree_node("VarDec", 4, $1, $2, $3, $4);  }
        ;

FunDec  :   ID LP VarList RP { $$ = create_syntax_tree_node("FunDec", 4, $1, $2, $3, $4);  }
        |   ID LP RP { $$ = create_syntax_tree_node("FunDec", 3, $1, $2, $3);  }
        ;

VarList :   ParamDec COMMA VarList { $$ = create_syntax_tree_node("VarList", 3, $1, $2, $3);  }
        |   ParamDec { $$ = create_syntax_tree_node("VarList", 1, $1);  }
        ;

ParamDec    :   Specifier VarDec { $$ = create_syntax_tree_node("ParamDec", 2, $1, $2);  }
            ;

CompSt  :   LC  DefList StmtList RC { $$ = create_syntax_tree_node("CompSt", 4, $1, $2, $3, $4);  }
        |   error RC { resume_from_error("RC"); }
        ;

StmtList    :   Stmt StmtList { $$ = create_syntax_tree_node("StmtList", 2, $1, $2);  }
            |   /* empty */ { $$ = create_syntax_tree_node("StmtList", 0);  }
            ;

Stmt    :   Exp SEMI { $$ = create_syntax_tree_node("Stmt", 2, $1, $2);  }
        |   CompSt { $$ = create_syntax_tree_node("Stmt", 1, $1);  }
        |   RETURN Exp SEMI { $$ = create_syntax_tree_node("Stmt", 3, $1, $2, $3);  }
        |   IF LP Exp RP Stmt %prec LOWER_THAN_ELSE { $$ = create_syntax_tree_node("Stmt", 5, $1, $2, $3, $4, $5);  }
        |   IF LP Exp RP Stmt ELSE Stmt { $$ = create_syntax_tree_node("Stmt", 7, $1, $2, $3, $4, $5, $6, $7);  }
        |   WHILE LP Exp RP Stmt { $$ = create_syntax_tree_node("Stmt", 5, $1, $2, $3, $4, $5);  }
        |   error SEMI { resume_from_error("SEMI"); }
        ;

DefList :   Def DefList { $$ = create_syntax_tree_node("DefList", 2, $1, $2);  }
        |   /* empty */ { $$ = create_syntax_tree_node("DefList", 0);  }
        ;

Def :   Specifier DecList SEMI { $$ = create_syntax_tree_node("Def", 3, $1, $2, $3);  }
    |   error SEMI { resume_from_error("SEMI"); }
    ;

DecList :   Dec { $$ = create_syntax_tree_node("DecList", 1, $1);  }
        |   Dec COMMA DecList { $$ = create_syntax_tree_node("DecList", 3, $1, $2, $3);  }
        ;

Dec :   VarDec { $$ = create_syntax_tree_node("Dec", 1, $1);  }
    |   VarDec ASSIGNOP Exp { $$ = create_syntax_tree_node("Dec", 3, $1, $2, $3);  }
    ;

Exp :   Exp ASSIGNOP Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp AND Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp OR Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp RELOP Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp PLUS Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp MINUS Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp STAR Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp DIV Exp { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   LP Exp RP { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   MINUS Exp %prec UMINUS { $$ = create_syntax_tree_node("Exp", 2, $1, $2);  }
    |   NOT Exp { $$ = create_syntax_tree_node("Exp", 2, $1, $2);  }
    |   ID LP Args RP { $$ = create_syntax_tree_node("Exp", 4, $1, $2, $3, $4);  }
    |   ID LP RP { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   Exp LB Exp RB { $$ = create_syntax_tree_node("Exp", 4, $1, $2, $3, $4);  }
    |   Exp DOT ID { $$ = create_syntax_tree_node("Exp", 3, $1, $2, $3);  }
    |   ID { $$ = create_syntax_tree_node("Exp", 1, $1);  }
    |   INT { $$ = create_syntax_tree_node("Exp", 1, $1);  }
    |   FLOAT { $$ = create_syntax_tree_node("Exp", 1, $1);  }
    ;

Args    :   Exp COMMA Args { $$ = create_syntax_tree_node("Args", 3, $1, $2, $3); }
        |   Exp { $$ = create_syntax_tree_node("Args", 1, $1);  }
        ;

%%

#include <stdio.h>

extern char * yytext;
extern int column;

yyerror(char *msg)
{
	fflush(stdout);
	printf("\nerror: %*s\ncolumn %d: %*s\n", yylineno, "^", column, msg);
}
