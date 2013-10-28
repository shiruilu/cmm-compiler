#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include "defs.h"
#include "type.h"

#define SYMBOL_TABLE_LEN 0x4000
#define MAX_SCOPE 20

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
    string name;
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
    hash_node *next, *prev, *scope_next;
} hash_node;

/* Variables */
extern hash_node gl_scope_stack[MAX_SCOPE];
extern hash_node gl_symbol_table[SYMBOL_TABLE_LEN];
extern unsigned int gl_cur_depth;

/* Functions */
unsigned int hash_pjw(char * name);
void init_symbol_table();
void enter_deeper_scope();
void exit_top_scope();

#endif
