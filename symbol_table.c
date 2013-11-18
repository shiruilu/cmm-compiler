#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include "symbol_table.h"

type_list gl_type_stack[MAX_SCOPE_DEPTH];
hash_node gl_symbol_table[SYMBOL_TABLE_LEN];
hash_node gl_scope_stack[MAX_SCOPE_DEPTH];
unsigned int gl_cur_depth;
Type *p_char_type, *p_int_type, *p_float_type;

unsigned int hash_pjw(char * name)
{
  unsigned int val = 0, i;
  for( ; *name; ++name) {
    val = (val<<2) + *name;
    if ( i = val&~0x3fff)
      val = (val ^ (i>>12)) & 0x3fff;
  }

  return val;
}

void init_symbol_table()
{
    gl_cur_depth = -1;
    int i;
    for (i = 0; i < SYMBOL_TABLE_LEN; ++ i) {
        gl_symbol_table[i].data = NULL;
        gl_symbol_table[i].next = gl_symbol_table[i].prev =  NULL;
    }
}

void enter_deeper_scope() {
    ++gl_cur_depth;
    gl_scope_stack[gl_cur_depth].data = NULL;
    gl_scope_stack[gl_cur_depth].scope_next = NULL;
    //gl_type_stack[gl_cur_depth].data = NULL;
    //gl_type_stack[gl_cur_depth].next = NULL;
}

void exit_top_scope() {
    hash_node *p_node = gl_scope_stack[gl_cur_depth].scope_next;
    while (p_node) {
        /* adjust prev next symbol table node */
        p_node->prev->next = p_node->next;
        if (p_node->next)
            p_node->next->prev = p_node->prev;
        hash_node *tmp_node = p_node;
        /* delete node for function symbol */
        if (tmp_node->data->type == Func) {
            arg_node *arg = tmp_node->data->symbol.func_value.args;
            while (arg) {
                arg_node *tmp_arg = arg;
                arg = arg->next;
                free(tmp_arg);
            }
        }
        p_node = p_node->scope_next;
        free(tmp_node->data);
        free(tmp_node);
    }
    /* delete node for struct symbol */
    /*
    type_list *p_type = gl_type_stack[gl_cur_depth].next;
    while (p_type) {
        type_list *tmp_type = p_type;
        p_type = p_type->next;
        if (tmp_type->data->kind == Structure) {
            FieldList *field = tmp_type->data->u.structure;
            while (field) {
                FieldList *tmp_field = field;
                field = field->next;
                free(tmp_field);
            }
        }
        free(tmp_type->data);
        free(tmp_type);
    }
    */
    --gl_cur_depth;
}

symbol_node *get_symbol(char *name) {
    int index = hash_pjw(name);
    hash_node *p_node = gl_symbol_table[index].next;
    while (p_node) {
        if (strcmp(name, p_node->data->key) == 0)
            return p_node->data;
        p_node = p_node->next;
    }
    return NULL;
}

void insert_symbol(symbol_node *p_symbol) {
    unsigned int index = hash_pjw(p_symbol->key);
    hash_node *new_node = (hash_node*)malloc(sizeof(hash_node));
    p_symbol->depth = gl_cur_depth;
    new_node->data = p_symbol;
    /* symbol table adjust (head insert) */
    new_node->next = gl_symbol_table[index].next;
    new_node->prev = &(gl_symbol_table[index]);
    if (gl_symbol_table[index].next)
        gl_symbol_table[index].next->prev = new_node;
    gl_symbol_table[index].next = new_node;
    /* scope stack adjust (head insert) */
    new_node->scope_next = gl_scope_stack[gl_cur_depth].scope_next;
    gl_scope_stack[gl_cur_depth].scope_next = new_node;
}
/*
void insert_type(Type *data) {
    type_list *new_type = (type_list*)malloc(sizeof(type_list));
    new_type->data = data;
    new_type->next = gl_type_stack[gl_cur_depth].next;
    gl_type_stack[gl_cur_depth].next = new_type;
}
*/

void add_read_write_func() {
    symbol_node *read_func = (symbol_node*)malloc(sizeof(symbol_node));
    strcpy(read_func->key, "read");
    read_func->type = Func;
    read_func->symbol.func_value.ret_type = p_int_type;
    read_func->symbol.func_value.args = NULL;
    read_func->symbol.func_value.is_defined = TRUE;

    symbol_node *write_func = (symbol_node*)malloc(sizeof(symbol_node));
    strcpy(write_func->key, "write");
    write_func->type = Func;
    write_func->symbol.func_value.ret_type = p_int_type;
    write_func->symbol.func_value.args = (arg_node*)malloc(sizeof(arg_node));
    write_func->symbol.func_value.args->type = p_int_type;
    write_func->symbol.func_value.args->next = NULL;
    write_func->symbol.func_value.is_defined = TRUE;

    insert_symbol(read_func);
    insert_symbol(write_func);
}

