#include "ast.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <stdarg.h>

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

void free_ast_tree(past_node p_root)
{
	if( p_root ) {
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
