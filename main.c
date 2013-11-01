#include <stdio.h>
#include "defs.h"
#include "ast.h"
#include "ErrorHandler.h"
#include "symbol_table.h"
#include "semantic_analysis.h"

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
    //#ifdef SEMANTIC_ANALYSIS
    //sdt(gl_ast_root);
    if (!gl_error_exist) {
        init_symbol_table();
        enter_deeper_scope();

        p_char_type = (Type*)malloc(sizeof(Type));
        p_int_type = (Type*)malloc(sizeof(Type));
        p_float_type = (Type*)malloc(sizeof(Type));
        p_char_type->kind = p_int_type->kind = p_float_type->kind = Basic;
        p_char_type->u.basic = Char;
        p_int_type->u.basic = Int;
        p_float_type->u.basic = Float;

        insert_type(p_char_type);
        insert_type(p_int_type);
        insert_type(p_float_type);

        sdt(gl_ast_root);
        check_undef_func();
        exit_top_scope();
    }
    //#endif
    free_ast_tree(gl_ast_root);
	return 0;
}
