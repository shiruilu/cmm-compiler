#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include "defs.h"
#include "type.h"

#define SYMBOL_TABLE_LEN 0x4000
#define MAX_SCOPE_DEPTH 20

/* Symbols */
typedef struct {
    Type *type;
} var_symbol;

typedef struct {
    Type *structure;
} struct_symbol;

typedef struct {
    arg_node *args;
    Type *ret_type;
    unsigned char is_defined;
    int lineno;
} func_symbol;

typedef struct symbol_node_ {
    string key;
    unsigned int depth;
    enum { Var, Struct, Func } type;
    union {
        var_symbol var_value;
        struct_symbol struct_value;
        func_symbol func_value;
    } symbol;
} symbol_node;

typedef struct hash_node_ {
    symbol_node *data;
    struct hash_node_ *next, *prev, *scope_next;
} hash_node;
/* Type ? */
typedef struct type_list_ {
    Type *data;
    struct type_list_ *next;
} type_list;
Type *p_char_type, *p_int_type, *p_float_type;
extern type_list gl_type_stack[MAX_SCOPE_DEPTH];
/* Variables */
extern hash_node gl_scope_stack[MAX_SCOPE_DEPTH];
extern hash_node gl_symbol_table[SYMBOL_TABLE_LEN];
extern unsigned int gl_cur_depth;

/* Functions */
unsigned int hash_pjw(char * name);
void init_symbol_table();
void enter_deeper_scope();
void exit_top_scope();

#endif
