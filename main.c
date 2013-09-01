#include <stdio.h>
#include "defs.h"
#include "ast.h"
#include "ErrorHandler.h"

extern int yyrestart(FILE *f);
extern int yyparse();

int main(int argc, char** argv)
{
	if (argc <= 1) return 1;
	FILE* f = fopen(argv[1], "r");
	if ( !f)
	{
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
#ifdef PRINT_AST
    // fprintf(stdout, "debug @ print_ast :%d\n", gl_error_exist);
    if ( !gl_error_exist) {
      // fprintf(stdout, "debug @ print_ast :%p\n", gl_ast_root);
      print_ast(gl_ast_root, 0);
    }
#endif
    free_ast_tree(gl_ast_root);
	return 0;
}
