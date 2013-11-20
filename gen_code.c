#include "gen_code.h"
#include "var_table.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define IS_RELOP(code) ((code)->kind == Equal || (code)->kind == NotEqual \
        || (code)->kind == More || (code)->kind == Less                 \
        || (code)->kind == MoreEqual || (code)->kind == LessEqual)

#define ASSEM_HDR ".data\n"\
"_prompt: .asciiz \"Enter an integer:\"\n"\
"_ret: .asciiz \"\\n\"\n"\
".globl main\n"\
"\n"\
".text\n"\
"read:\n"\
"\tli $v0, 4\n"\
"\tla $a0, _prompt\n"\
"\tsyscall\n"\
"\tli $v0, 5\n"\
"\tsyscall\n"\
"\tjr $ra\n"\
"\n"\
"write:\n"\
"\tli $v0, 1\n"\
"\tsyscall\n"\
"\tli $v0, 4\n"\
"\tla $a0, _ret\n"\
"\tsyscall\n"\
"\tmove $v0, $0\n"\
"\tjr $ra\n"\
"\n"

char *reg_names[] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
                     "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9",
                     "$a0", "$a1", "$a2", "$a3"};

char *print_reg(int reg_id) {
    return reg_names[reg_id];
}

void spill_reg(FILE *file, int reg_id) {
    if (reg_id >= NR_REGS)
        return;
    //assert(reg_id < NR_REGS);
    var_node *p_var = get_var_node(regs[reg_id].var_id);
    if (p_var->is_param_reg)
        return;
    fprintf(file, "\tsw %s, %d($fp)\n", print_reg(reg_id), -p_var->offset - 4);
}
// spill modified reg to mem
void free_reg(FILE *file, int reg_id) {
    if (reg_id >= NR_REGS)
        return;
    if (regs[reg_id].var_id < 0)
        return;
    if (regs[reg_id].is_modified) {
        spill_reg(file, reg_id);
    }
    regs[reg_id].var_id = -1; // mark as free
}

void set_reg_modified(int reg_id) {
    if (reg_id >= NR_REGS)
        return;
    regs[reg_id].is_modified = TRUE;
}

int allocate_reg(FILE *file, int var_id) {
    var_node *p_var = get_var_node(var_id);

    if (p_var && p_var->is_param_reg)
        return NR_REGS + p_var->offset;

    int i;
    for (i = 0; i < NR_REGS; ++ i)
    {
        if (regs[i].var_id < 0) {
            /* find an unalloc reg */
            regs[i].var_id = var_id;
            regs[i].is_modified = FALSE;
            return i;
        }
    }
    /* no unallocated reg */
    spill_reg(file, 0); // spill reg0
    regs[0].var_id = var_id;
    regs[0].is_modified = FALSE;

    return 0;
}

int store_const_into_reg(FILE *file, int val) {
    int reg = allocate_reg(file, CONST_TEMP_REG); // the virtual const var id
    fprintf(file, "\tli %s, %d\n", print_reg(reg), val);

    return reg;
}
/* ensure a reg relevant to var_id */
int ensure_reg(FILE *file, int var_id) {
    var_node *p_var = get_var_node(var_id);

    if (p_var == NULL)
        return -1;

    if (p_var->is_param_reg)
        return NR_REGS + p_var->offset;

    int i;
    for (i = 0; i < NR_REGS; ++ i)
        if (regs[i].var_id == var_id)
            return i;

    int reg = allocate_reg(file, var_id);
    fprintf(file, "\tlw %s, %d($fp)\n", print_reg(reg), -p_var->offset - 4);

    return reg;
}

void print_mips_code(FILE *file, InterCodeList *codes) {
    InterCode *code = codes->code;

    if (code->kind == LabelDec)
    {
        fprintf(file, "label%d:\n", code->u.label.dest->u.var_no);
    }
    else if (code->kind == Assign)
    {
        if (code->u.assign.right->kind == Variable      \
            && code->u.assign.left->kind == Constant)
        { /* v := #c */
            int regx = allocate_reg(file, code->u.assign.right->u.var_no);
            fprintf(file, "\tli %s, %d\n", print_reg(regx)  \
                , code->u.assign.left->u.value);
            set_reg_modified(regx);
            free_reg(file, regx);
        }
        else if (code->u.assign.right->kind == Variable \
            && code->u.assign.left->kind == Variable)
        { /* x := y */
            int regy = ensure_reg(file, code->u.assign.left->u.var_no);
            int regx = allocate_reg(file, code->u.assign.right->u.var_no);
            fprintf(file, "\tmove %s, %s\n", print_reg(regx), print_reg(regy));
            set_reg_modified(regx);
            free_reg(file, regx);
            free_reg(file, regy);
        }
        else if (code->u.assign.right->kind == Variable \
            && code->u.assign.left->kind == Address)
        {
            int regx, regy;

            regy = ensure_reg(file, code->u.assign.left->u.var_no);

            free_reg(file, regy);

            regx = allocate_reg(file, code->u.assign.right->u.var_no);

            fprintf(file, "\tlw %s, 0(%s)\n", print_reg(regx), print_reg(regy));
            set_reg_modified(regx);
            free_reg(file, regx);
        }
        else if (code->u.assign.right->kind == Address) {
            /* *x := y */
            int regx, regy;

            if (code->u.assign.left->kind == Variable)
                regy = ensure_reg(file, code->u.assign.left->u.var_no);
            else if (code->u.assign.left->kind == Constant)
                regy = store_const_into_reg(file, code->u.assign.left->u.var_no);

            regx = ensure_reg(file, code->u.assign.right->u.var_no);

            free_reg(file, regx);free_reg(file, regy);

            fprintf(file, "\tsw %s, 0(%s)\n", print_reg(regy), print_reg(regx));
        }
        else {
            fprintf(file, "\tUnexpected assign inter code!\n");
        }

    }
    else if (code->kind == Add || code->kind == Sub     \
        || code->kind  == Mul || code->kind == Div)
    {
        if (code->kind == Add && code->u.binop.op1->kind == Reference)
        { /* t = &v + */
            var_node *p_var = get_var_node(code->u.binop.op1->u.var_no);
            if (code->u.binop.op2->kind == Constant)
            { /* t = &v + #c */
                int regx = allocate_reg(file, code->u.binop.result->u.var_no);
                fprintf(file, "\taddi %s, $fp, %d\n", print_reg(regx)   \
                    , -p_var->offset - code->u.binop.op2->u.value - 4);
                set_reg_modified(regx);
                free_reg(file, regx);
            }
            else if (code->u.binop.op2->kind == Variable)
            { /* t = &v + vb */
                int regz = ensure_reg(file, code->u.binop.op2->u.var_no);

                free_reg(file, regz);

                int regx = allocate_reg(file, code->u.binop.result->u.var_no);
                fprintf(file, "\tsub %s, $fp, %s\n", print_reg(regx), print_reg(regz));
                fprintf(file, "\taddi %s, %s, %d\n", print_reg(regx), print_reg(regx) \
                    , -p_var->offset - 4);

                set_reg_modified(regx);
                free_reg(file, regx);
            }
        }
        else {
            int regy, regz;

            if (code->u.binop.op1->kind == Constant)
                regy = store_const_into_reg(file, code->u.binop.op1->u.value);
            else if (code->u.binop.op1->kind == Variable)
                regy = ensure_reg(file, code->u.binop.op1->u.var_no);

            if (code->u.binop.op2->kind == Constant)
                regz = store_const_into_reg(file, code->u.binop.op2->u.value);
            else if (code->u.binop.op2->kind == Variable)
                regz = ensure_reg(file, code->u.binop.op2->u.var_no);

            free_reg(file, regy);free_reg(file, regz);

            int regx = allocate_reg(file, code->u.binop.result->u.var_no);

            if (code->kind == Add)
                fprintf(file, "\tadd %s, %s, %s\n", print_reg(regx), print_reg(regy) \
                    , print_reg(regz));
            else if (code->kind == Sub)
                fprintf(file, "\tsub %s, %s, %s\n", print_reg(regx), print_reg(regy) \
                    , print_reg(regz));
            else if (code->kind == Mul)
                fprintf(file, "\tmul %s, %s, %s\n", print_reg(regx), print_reg(regy) \
                    , print_reg(regz));
            else if (code->kind == Div) {
                fprintf(file, "\tdiv %s, %s\n", print_reg(regy), print_reg(regz));
                fprintf(file, "\tmflo %s\n", print_reg(regx));
            }

            set_reg_modified(regx);
            free_reg(file, regx);
        }
    }
    else if (IS_RELOP(code)) {
        int regx, regy;

        if (code->u.binop.op1->kind == Constant)
            regx = store_const_into_reg(file, code->u.binop.op1->u.value);
        else if (code->u.binop.op1->kind == Variable)
            regx = ensure_reg(file, code->u.binop.op1->u.var_no);

        if (code->u.binop.op2->kind == Constant)
            regy = store_const_into_reg(file, code->u.binop.op2->u.value);
        else if (code->u.binop.op2->kind == Variable)
            regy = ensure_reg(file, code->u.binop.op2->u.var_no);

        free_reg(file, regx);free_reg(file, regy);

        fprintf(file, "\t");

        if (code->kind == Equal)
            fprintf(file, "beq");
        else if (code->kind == NotEqual)
            fprintf(file, "bne");
        else if (code->kind == More)
            fprintf(file, "bgt");
        else if (code->kind == Less)
            fprintf(file, "blt");
        else if (code->kind == MoreEqual)
            fprintf(file, "bge");
        else if (code->kind == LessEqual)
            fprintf(file, "ble");


        fprintf(file, " %s, %s, label%d\n", print_reg(regx), print_reg(regy) \
            , code->u.binop.result->u.var_no);

    }
    else if (code->kind == Return) {
        int regx;

        if (code->u.command.op->kind == Constant)
            regx = store_const_into_reg(file, code->u.command.op->u.value);
        else if (code->u.command.op->kind == Variable)
            regx = ensure_reg(file, code->u.command.op->u.var_no);

        free_reg(file, regx);

        fprintf(file, "\tmove $v0, %s\n", print_reg(regx)); // return value

        fprintf(file, "\taddi $sp, $fp, 8\n");
        fprintf(file, "\tlw $ra, -4($sp)\n");
        fprintf(file, "\tlw $fp, -8($sp)\n");

        fprintf(file, "\tjr $ra\n");
    }
    else if (code->kind == Goto) {
        fprintf(file, "\tj label%d\n", code->u.command.op->u.var_no);
    }
    else if (code->kind == Arg) {

        int i;
        for (i = 0; i < 4; ++ i)
            fprintf(file, "\tsw $a%d, %d($sp)\n", i, -(i + 1) * 4);
        fprintf(file, "\tsubu $sp, $sp, %d\n", 16);

        args_num = 0;

        InterCodeList *tmp = codes;

        while (tmp && tmp->code->kind == Arg) {
            ++ args_num;
            tmp = tmp->next;
        }

        fprintf(file, "\tsubu $sp, $sp, %d\n", args_num >= 4 ? 4 * (args_num - 4) : 0);

        tmp = codes;
        i = args_num;

        while (i > 0) {
            int regx;

            if (tmp->code->u.command.op->kind == Constant) // const arg
                regx = store_const_into_reg(file, tmp->code->u.command.op->u.value);
            else if (tmp->code->u.command.op->kind == Variable) // var arg
                regx = ensure_reg(file, tmp->code->u.command.op->u.var_no);
            -- i;
            if (i < 4) {
                fprintf(file, "\tmove $a%d, %s\n", i, print_reg(regx));
            }
            else {
                fprintf(file, "\tsw %s, %d($sp)\n", print_reg(regx), 4 * (i - 4));
            }
            free_reg(file, regx);
            tmp = tmp->next;
        }
    }
    else if (code->kind == Call) {
        int regx = allocate_reg(file, code->u.call.result->u.var_no);

        fprintf(file, "\tjal %s\n", code->u.call.func_name);
        fprintf(file, "\taddi $sp, $sp, %d\n", args_num >= 4 ?  4 * (args_num - 4) : 0);
        fprintf(file, "\tmove %s, $v0\n", print_reg(regx));

        fprintf(file, "\taddi $sp, $sp, %d\n", 16);

        int i;
        for (i = 0; i < 4; ++ i)
            fprintf(file, "\tlw $a%d, %d($sp)\n", i, -(i + 1) * 4);

        set_reg_modified(regx);
        free_reg(file, regx);
    }
    else if (code->kind == Read) {
        int regx = allocate_reg(file, code->u.command.op->u.var_no);
        fprintf(file, "\tsubu $sp, $sp, 4\n");
        fprintf(file, "\tsw $a0, 0($sp)\n");
        fprintf(file, "\tjal read\n");
        fprintf(file, "\taddi $sp, $sp, %d\n", args_num >= 4 ?  4 * (args_num - 4) : 0);
        fprintf(file, "\tmove %s, $v0\n", print_reg(regx));
        fprintf(file, "\tlw $a0, 0($sp)\n");
        fprintf(file, "\taddi $sp, $sp, 4\n");
        set_reg_modified(regx);
        free_reg(file, regx);
    }
    else if (code->kind == Write) {
        int regx;
        if (code->u.command.op->kind == Variable)
            regx = ensure_reg(file, code->u.command.op->u.var_no);
        else if (code->u.command.op->kind == Constant)
            regx = store_const_into_reg(file, code->u.command.op->u.value);
        free_reg(file, regx);
        fprintf(file, "\tsubu $sp, $sp, 4\n");
        fprintf(file, "\tsw $a0, 0($sp)\n");
        fprintf(file, "\tmove $a0, %s\n", print_reg(regx));
        fprintf(file, "\tjal write\n");
        fprintf(file, "\tlw $a0, 0($sp)\n");
        fprintf(file, "\taddi $sp, $sp, 4\n");
    }

}

bool is_first_instr(InterCodeList *codes) {
    return codes->code->kind == FunCode || codes->code->kind == Call    \
        || codes->code->kind == LabelDec || IS_RELOP(codes->prev->code) \
        || codes->prev->code->kind == Goto || codes->prev->code->kind == Call;
}

void init_basic_block(InterCodeList *codes) {

}

void init_regs() {
    int i;
    for (i = 0; i < NR_REGS; ++ i)
        regs[i].var_id = -1;
}

void ensure_var(int var_id, int size) {
    var_node *p_var = get_var_node(var_id);

    if (p_var == NULL) {
        insert_var_node(var_id, FALSE, offset_now);
        offset_now += size;
    }
}

bool is_in_func = FALSE;

void init_func_var(FILE *file, InterCodeList *codes) {
    offset_now = 0;
    args_num = 0;
    is_in_func = TRUE;
    init_var_table();
    init_regs();

    if (codes && codes->code->kind == FunCode) {
        fprintf(file, "%s:\n", codes->code->u.func.func_name);

        codes = codes->next;

        int param_num = 0;

        while (codes && codes->code->kind != FunCode) {
            InterCode *code = codes->code;
            if (code->kind == Param) {
                if (param_num < 4) {
                    insert_var_node(code->u.command.op->u.var_no, TRUE, param_num);
                }
                else {
                    insert_var_node(code->u.command.op->u.var_no, FALSE \
                        , -(param_num - 4) * 4 - 12);
                }
                ++ param_num;
            }
            else if (code->kind == Add || code->kind == Sub     \
                || code->kind == Mul || code->kind == Div)
            {
                if (code->u.binop.result->kind == Variable) {
                    ensure_var(code->u.binop.result->u.var_no, 4);
                }
            }
            else if (code->kind == Call) {
                if (code->u.call.result->kind == Variable) {
                    ensure_var(code->u.call.result->u.var_no, 4);
                }
            }
            else if (code->kind == Assign) {
                if (code->u.assign.right->kind == Variable) {
                    ensure_var(code->u.assign.right->u.var_no, 4);
                }
            }
            else if (code->kind == Read) {
                if (code->u.command.op->kind == Variable) {
                    ensure_var(code->u.command.op->u.var_no, 4);
                }
            }
            else if (code->kind == Dec) {
                ensure_var(code->u.dec.addr->u.var_no, code->u.dec.size->u.value);
            }

            codes = codes->next;
        }
    }

    fprintf(file, "\tsw $ra, -4($sp)\n");
    fprintf(file, "\tsw $fp, -8($sp)\n");
    fprintf(file, "\taddi $fp, $sp, -8\n");
    fprintf(file, "\taddi $sp, $sp, %d\n", -8 - offset_now);
}

InterCodeList *codes_next(FILE *file, InterCodeList *codes) {
    InterCodeList *ret;
    if (codes->code->kind == Arg) {
        while (codes->code->kind == Arg)
            codes = codes->next;
        ret = codes;
    }
    else
        ret = codes->next;

    if (ret == NULL)
        is_in_func = FALSE;

    if (ret && ret->code->kind == FunCode) {
        if (is_in_func) {
            is_in_func = FALSE;
            fprintf(file, "\n");
        }

        init_func_var(file, ret);
    }

    if (ret && is_first_instr(ret)) {
        init_basic_block(ret);
    }

    return ret;
}

void gen_code(FILE *file, InterCodeList *codes) {
    if (codes) { //break "head and tail" loop of the linked list
        InterCodeList *tail = codes->prev;
        codes->prev = NULL;
        tail->next = NULL;
    }

    fprintf(file, ASSEM_HDR);

    init_func_var(file, codes);
    init_basic_block(codes);

    while (codes) {
        print_mips_code(file, codes);
        codes = codes_next(file, codes);
    }
}
