#ifndef AST_H
#define AST_H

#include "defs.h"
#include "type.h"

#define YYSTYPE past_node

typedef enum {
	CHAR_TOKEN, INT_TOKEN, FLOAT_TOKEN, ID_TOKEN,
	SEMI_TOKEN, COMMA_TOKEN,
	ASSIGNOP_TOKEN, RELOP_TOKEN,
	PLUS_TOKEN, MINUS_TOKEN, STAR_TOKEN, DIV_TOKEN,
	AND_TOKEN, OR_TOKEN, DOT_TOKEN, NOT_TOKEN,
	TYPE_TOKEN,
	LP_TOKEN, RP_TOKEN, LB_TOKEN, RB_TOKEN, LC_TOKEN, RC_TOKEN,
	STRUCT_TOKEN, RETURN_TOKEN, IF_TOKEN, ELSE_TOKEN, WHILE_TOKEN,

	Program_SYNTAX, ExtDefList_SYNTAX, ExtDef_SYNTAX, ExtDecList_SYNTAX,
	Specifier_SYNTAX, StructSpecifier_SYNTAX, OptTag_SYNTAX, Tag_SYNTAX,
	VarDec_SYNTAX, FunDec_SYNTAX, VarList_SYNTAX, ParamDec_SYNTAX,
	CompSt_SYNTAX, StmtList_SYNTAX, Stmt_SYNTAX,
	DefList_SYNTAX, Def_SYNTAX, DecList_SYNTAX, Dec_SYNTAX,
	Exp_SYNTAX, Args_SYNTAX
} node_type;

typedef struct {
    Type *inh_type;
    Type *type;
    unsigned char is_in_struct;
    FieldList *structure;
    unsigned char is_legal;
    arg_node *args, *inh_args;
    char *id;
    Type *ret_type;
    unsigned char is_definition;
    unsigned char is_declared;
} Attribute;

typedef struct ast {
	// string name;
	node_type type;
	struct ast *lchild, *next_sib;
	// bool is_token;
	union {
		char char_val;
		int int_val;
		float float_val;
		string str_val;
		basic_type type_val;
	} value;
	int lineno;
	int column;
    Attribute attr;
} ast_node, * past_node;
/* declare AST Root */
extern past_node gl_ast_root;
/* Functions */
past_node create_token(node_type type);
past_node create_syntax(node_type type, int argno, ...);
void print_ast(past_node p_node, int spaces);
void free_ast_tree(past_node p_root);

#endif
