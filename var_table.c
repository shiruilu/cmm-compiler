#include "var_table.h"
#include <malloc.h>
#include <string.h>

int hash_int(int key) {
    return ((key << 5) - key + 941) % NR_VAR_TABLE;
}

void init_var_table() {
    int i;
    for (i = 0; i < NR_VAR_TABLE; ++ i) {
        var_table[i].next = var_table[i].prev = NULL;
    }
}

var_node *get_var_node(int var_id) {
    int index = hash_int(var_id);
    var_node *p_node = var_table[index].next;
    while (p_node) {
        if (var_id == p_node->key)
            return p_node;
        p_node = p_node->next;
    }
    return NULL;
}

void insert_var_node(int var_id, bool is_param_reg, int offset) {
    int index = hash_int(var_id);
    var_node *new_node = (var_node*)malloc(sizeof(var_node));
    new_node->key = var_id;
    new_node->is_param_reg = is_param_reg;
    new_node->offset = offset;
    new_node->next = var_table[index].next;
    new_node->prev = &(var_table[index]);
    if (var_table[index].next)
        var_table[index].next->prev = new_node;
    var_table[index].next = new_node;
}
