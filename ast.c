#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifdef PRINT_AST
char *gl_ref_table[] = {
	"CHAR_TOKEN", "INT_TOKEN", "FLOAT_TOKEN", "ID_TOKEN",
	"SEMI_TOKEN", "COMMA_TOKEN",
	"ASSIGNOP_TOKEN", "RELOP_TOKEN",
	"PLUS_TOKEN", "MINUS_TOKEN", "STAR_TOKEN", "DIV_TOKEN",
	"AND_TOKEN", "OR_TOKEN", "DOT_TOKEN", "NOT_TOKEN",
	"TYPE_TOKEN",
	"LP_TOKEN", "RP_TOKEN", "LB_TOKEN", "RB_TOKEN", "LC_TOKEN", "RC_TOKEN",
	"STRUCT_TOKEN", "RETURN_TOKEN", "IF_TOKEN", "ELSE_TOKEN", "WHILE_TOKEN",

	"Program_SYNTAX", "ExtDefList_SYNTAX", "ExtDef_SYNTAX", "ExtDecList_SYNTAX",
	"Specifier_SYNTAX", "StructSpecifier_SYNTAX", "OptTag_SYNTAX", "Tag_SYNTAX",
	"VarDec_SYNTAX", "FunDec_SYNTAX", "VarList_SYNTAX", "ParamDec_SYNTAX",
	"CompSt_SYNTAX", "StmtList_SYNTAX", "Stmt_SYNTAX",
	"DefList_SYNTAX", "Def_SYNTAX", "DecList_SYNTAX", "Dec_SYNTAX",
	"Exp_SYNTAX", "Args_SYNTAX"
};
#endif

/* define AST Root */
past_node gl_ast_root;

extern int yylineno;
extern YYLTYPE yylloc;

past_node create_token(node_type type)
{
	past_node p = (past_node)ck_malloc(sizeof(ast_node));
	p->type = type;
	p->lchild = p->next_sib = NULL;
	p->lineno = yylineno;
	p->column = yylloc.first_column;

	return p;
}

past_node create_syntax(node_type type, int argno, ...)
{
	past_node p = (past_node)ck_malloc(sizeof(ast_node));
	p->type = type;
	p->lchild = p->next_sib = NULL;

	va_list argp;
	va_start(argp, argno);

	past_node tmp = NULL;
	if(argno > 0) {
		tmp = p->lchild = va_arg(argp, past_node);
		assert(tmp);
	}
	/* implied: argno >= 2*/
	int i = 1;
	for( ; i < argno; ++i ) {
		tmp->next_sib = va_arg(argp, past_node);
		tmp = tmp->next_sib;
		assert(tmp);
	}
	if(argno > 0) { /* argno ==0 means tmp ==NULL*/
		assert(tmp);
		tmp->next_sib = NULL;
	}
	va_end(argp);

	if(0 == argno) {
		p->lineno = yylineno;
		p->column = yylloc.first_column;
	}
	else {
		assert(p->lchild);
		p->lineno = p->lchild->lineno;
		p->column = p->lchild->column;
	}

	return p;
}

#ifdef PRINT_AST
void print_ast(past_node p_node, int spaces)
{
	if ( p_node ) {

		// fprintf(stdout, "@%d ", spaces);
		if ( p_node->lchild || p_node->type <Program_SYNTAX ) {
			/* not syntax node generated eps, print */

			/* print spaces */
			int i = 0;
			for (; i<spaces; ++i)
				fprintf(stdout, " ");

			if (p_node->type < Program_SYNTAX) {
				/* LEXICAL TOKEN */
				fprintf(stdout, "%s", gl_ref_table[p_node->type]);
				switch (p_node->type)
				{
					case ID_TOKEN:
						fprintf(stdout, ": %s\n", p_node->value.str_val); break;
					case TYPE_TOKEN:
						if (Char == p_node->value.type_val)
							fprintf(stdout, ": char\n");
						else if (Int == p_node->value.type_val)
							fprintf(stdout, ": int\n");
						else if (Float == p_node->value.type_val)
							fprintf(stdout, ": float\n");
						break;
					case CHAR_TOKEN:
						fprintf(stdout, ": %c\n", p_node->value.char_val); break;
					case INT_TOKEN:
						fprintf(stdout, ": %d\n", p_node->value.int_val); break;
					case FLOAT_TOKEN:
						fprintf(stdout, ": %f\n", p_node->value.float_val); break;
					default:
						fprintf(stdout, "\n");
				}
			}
			else if ( p_node->lchild ){
				/* SYNTAX  didn't generate epsilong */
					fprintf(stdout, "%s (%d:%d)\n", gl_ref_table[p_node->type] \
								, p_node->lineno, p_node->column);
			}
		}
		print_ast(p_node->lchild, spaces+2);
		print_ast(p_node->next_sib, spaces);
	}
}
#endif

void free_ast_tree(past_node p_root)
{
	if ( p_root ) {
		/*the first line will check NULL,
		 *so the next 2 ifs are useless
		*/
		// if( p_root->lchild )
			free_ast_tree(p_root->lchild);
		// if( p_root->next_sib )
			free_ast_tree(p_root->next_sib);
		free(p_root);
	}
}
