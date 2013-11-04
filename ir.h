#ifndef _IR_H_
#define _IR_H_

#include <stdio.h>
#include "defs.h"

typedef struct Operand_ Operand;
typedef struct InterCode_ InterCode;

struct Operand_ {
    enum { Label, Variable, Constant, Address, Reference } kind;
    union {
        int var_no;
        int value;
    } u;
};

typedef enum { FunCode, LabelDec, Assign, Add, Sub, Mul, Div, Goto, Equal \
               , More, Less, MoreEqual, LessEqual, NotEqual, Return, Dec \
               , Arg, Call, Param, Read, Write } code_kind;

struct InterCode_ {
    code_kind kind;
    union {
        struct { char func_name[MAX_SYMBOL_NAME]; } func;
        struct { Operand *dest; } label;
        struct { Operand *right, *left; } assign;
        struct { Operand *result, *op1, *op2; } binop;
        struct { Operand *op; } command;
        struct { Operand *result; char func_name[MAX_SYMBOL_NAME]; } call;
        struct { Operand *addr, *size; } dec;
    } u;
};

typedef struct InterCodes InterCodeList;

struct InterCodes {
    InterCode *code;
    struct InterCodes *prev, *next;
};


InterCode *gen_func_code(char *func_name);
InterCode *gen_label_code(Operand *dest);
InterCode *gen_assign_code(Operand *right, Operand *left);
InterCode *gen_binop_code(code_kind, Operand *result, Operand *op1, Operand *op2);
InterCode *gen_command_code(code_kind kind, Operand *op);
InterCode *gen_call_code(Operand *result, char *func_name);
InterCode *gen_dec_code(Operand *addr, Operand *size);

Operand *new_var_op(int var_no);
Operand *new_const_op(int value);
Operand *new_addr_op(int value);
Operand *new_ref_op(int val_no);
Operand *new_lbl_op(int val_no);

int temp_now;
int label_now;
Operand *new_temp();
Operand *new_label();

void init_translate();

InterCodeList *link_inter_code(int n, ...);
InterCodeList *make_code_list(InterCode *code);

void print_inter_code(FILE* file, InterCodeList* codes);

#endif
