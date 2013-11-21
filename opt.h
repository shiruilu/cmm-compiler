#ifndef _OPT_H_
#define _OPT_H_

#include "defs.h"
#include "ir.h"

typedef struct Cfg_node_ CfgBlock;
/* each basic block has a CfgNode */
struct Cfg_node_ {
    InterCodeList * start, *end;
    struct Cfg_node_ * next;
};

typedef struct Cfgs_ CfgFunc;
/* each function has a Cfgs */
struct Cfgs_ {
    CfgBlock *b_head;
    struct Cfgs_ * next;
};

typedef struct Regs_ {
    enum {Cons, Vari, Unde} stat;
    union {
        int val;
        int var_no;
    } u;
} Regs;

extern CfgFunc * cfg_func_head;
Regs get_reg_content(Operand * op);
void elim_two_const(InterCodeList * cur_code);
#endif