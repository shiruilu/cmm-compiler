#include <stdio.h>
#include <malloc.h>
#include "defs.h"
#include "ast.h"
#include "ErrorHandler.h"
#include "symbol_table.h"
#include "semantic_analysis.h"
#include "ir.h"
#include "trans.h"
#include "opt.h"

extern int yyrestart(FILE *f);
extern int yyparse();

int main(int argc, char** argv)
{
	//if (argc <= 2) return 1;
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

        //insert_type(p_char_type);
        //insert_type(p_int_type);
        //insert_type(p_float_type);

        add_read_write_func();

        //printf("before sdt\n");
        sdt(gl_ast_root);
        //printf("before chk undef func\n");
        check_undef_func();
        exit_top_scope();
    }
    //#endif
    if (!gl_error_exist) {
        init_translate();
        init_symbol_table();
        enter_deeper_scope();

        add_read_write_func();

        InterCodeList * ir_list = translate(gl_ast_root);
        if ( !strcmp(argv[2], "-O") )
        {
            opt(ir_list);
        }

        if ( !strcmp(argv[3], "-i") )
        {
            print_inter_code(fopen(argv[4], "w+"), ir_list );
        }
        else if ( !strcmp(argv[3], "-s") )
        {
            gen_code( fopen(argv[4], "w+"), ir_list );
        }

        exit_top_scope();
    }
    free_ast_tree(gl_ast_root);
	return 0;
}
