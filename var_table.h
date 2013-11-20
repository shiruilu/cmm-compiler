#ifndef _VAR_TABLE_H_
#define _VAR_TABLE_H_

#include "defs.h"

typedef struct var_node_ var_node;
struct var_node_ {
    int key;
    bool is_param_reg;
    int offset;
    var_node *prev, *next;
};

#define NR_VAR_TABLE 521

var_node var_table[NR_VAR_TABLE];

int hash_int(int key);
void init_var_table();
var_node *get_var_node(int var_id);
void insert_var_node(int var_id, bool is_param_reg, int offset);

#endif