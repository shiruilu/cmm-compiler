#include "symbol_table.h"

hash_node gl_symbol_table[SYMBOL_TABLE_LEN];
hash_node gl_scope_stack[MAX_SCOPE];
unsigned int gl_cur_depth;

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
    //type_stack[scope_depth].data = NULL;
    //type_stack[scope_depth].next = NULL;
}