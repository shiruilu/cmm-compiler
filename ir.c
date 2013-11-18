#include "ir.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int temp_now;
int label_now;

// construction functions of each intercode
InterCode *gen_func_code(char *func_name) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = FunCode;
   strcpy(code->u.func.func_name, func_name);
   return code;
}

InterCode *gen_label_code(Operand *dest) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = LabelDec;
   code->u.label.dest = dest;
   return code;
}

InterCode *gen_assign_code(Operand *right, Operand *left) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = Assign;
   code->u.assign.right = right;
   code->u.assign.left= left;
   return code;
}

InterCode *gen_binop_code(code_kind kind, Operand *result, Operand *op1 \
    , Operand *op2) {

   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = kind;
   code->u.binop.result = result;
   code->u.binop.op1 = op1;
   code->u.binop.op2 = op2;
   return code;
}

InterCode *gen_command_code(code_kind kind, Operand *op) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = kind;
   code->u.command.op = op;
   return code;
}

InterCode *gen_call_code(Operand *result, char *func_name) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = Call;
   code->u.call.result = result;
   strcpy(code->u.call.func_name, func_name);
   return code;
}

InterCode *gen_dec_code(Operand *addr, Operand *size) {
   InterCode *code = (InterCode*)malloc(sizeof(InterCode));
   code->kind = Dec;
   code->u.dec.addr = addr;
   code->u.dec.size = size;
   return code;
}

// construction functions for each operand
Operand *new_var_op(int var_no) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->kind = Variable;
    op->u.var_no = var_no;
    return op;
}

Operand *new_const_op(int value) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->kind = Constant;
    op->u.value = value;
    return op;
}

Operand *new_addr_op(int value) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->kind = Address;
    op->u.value = value;
    return op;
}

Operand *new_ref_op(int var_no) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->kind = Reference;
    op->u.var_no = var_no;
    return op;
}

Operand *new_lbl_op(int var_no) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->kind = Label;
    op->u.var_no = var_no;
    return op;
}

InterCodeList *link_inter_code(int n, ...) {
    if (n == 0)
        return NULL;

    va_list args;
    va_start(args, n);

    InterCodeList *result = va_arg(args, InterCodeList*), *tmp, *last;

    int i;
    for (i = 1; i < n; ++ i) {
       tmp = va_arg(args, InterCodeList*);
       if (result == NULL)
           result = tmp;
       else if (tmp) {
           result->prev->next = tmp;
           last = result->prev;
           result->prev = tmp->prev;
           tmp->prev->next = result;
           tmp->prev = last;
       }
    }

    va_end(args);

    return result;
}

// generate a new intercode list
InterCodeList *make_code_list(InterCode *code) {
    InterCodeList *new_list = (InterCodeList*)malloc(sizeof(InterCodeList));
    new_list->code = code;
    new_list->prev = new_list;
    new_list->next = new_list;
    return new_list;
}

void print_inter_code(FILE *file, InterCodeList *codes) {
    if (codes == NULL) return;
    InterCodeList *tmp = codes;
    do {
        InterCode *code = tmp->code;

        if (code->kind == FunCode)
            fprintf(file, "FUNCTION %s :\n", code->u.func.func_name);
        else if (code->kind == LabelDec)
            fprintf(file, "LABEL label%d :\n", code->u.label.dest->u.var_no);
        else if (code->kind == Assign) { // assign code
            if (code->u.assign.right->kind == Address)
                fprintf(file, "*");
            fprintf(file, "t%d := ", code->u.assign.right->u.var_no);
            if (code->u.assign.left->kind == Address)
                fprintf(file, "*t%d", code->u.assign.left->u.var_no);
            else if (code->u.assign.left->kind == Variable)
                fprintf(file, "t%d", code->u.assign.left->u.var_no);
            else if (code->u.assign.left->kind == Constant)
                fprintf(file, "#%d", code->u.assign.left->u.value);
            else if (code->u.assign.left->kind == Reference)
                fprintf(file, "&t%d", code->u.assign.left->u.var_no);
            fprintf(file, "\n");
        }
        else if (code->kind == Add || code->kind == Sub || code->kind  == Mul \
            || code->kind == Div) {
            /* left (result) operand */
            fprintf(file, "t%d := ", code->u.binop.result->u.var_no);
            /* right operand 1 */
            if (code->u.binop.op1->kind == Reference)
                fprintf(file, "&t%d", code->u.binop.op1->u.var_no);
            else if (code->u.binop.op1->kind == Variable)
                fprintf(file, "t%d", code->u.binop.op1->u.var_no);
            else if (code->u.binop.op1->kind == Constant)
                fprintf(file, "#%d", code->u.binop.op1->u.value);

            fprintf(file, " ");
            /* operator */
            if (code->kind == Add)
                fprintf(file, "+");
            else if (code->kind == Sub)
                fprintf(file, "-");
            else if (code->kind == Mul)
                fprintf(file, "*");
            else if (code->kind == Div)
                fprintf(file, "/");

            fprintf(file, " ");
            /* right operand 2 */
            if (code->u.binop.op2->kind == Reference)
                fprintf(file, "&t%d", code->u.binop.op2->u.var_no);
            else if (code->u.binop.op2->kind == Variable)
                fprintf(file, "t%d", code->u.binop.op2->u.var_no);
            else if (code->u.binop.op2->kind == Constant)
                fprintf(file, "#%d", code->u.binop.op2->u.value);

            fprintf(file, "\n");
        }
        else if (code->kind == Equal || code->kind == NotEqual          \
            || code->kind == More || code->kind == Less                 \
            || code->kind == MoreEqual || code->kind == LessEqual) {
            /* print conditional jump */
            fprintf(file, "IF ");
            /* condition operand 1 */
            if (code->u.binop.op1->kind == Variable)
                fprintf(file, "t%d", code->u.binop.op1->u.var_no);
            else if (code->u.binop.op1->kind == Constant)
                fprintf(file, "#%d", code->u.binop.op1->u.value);

            fprintf(file, " ");
            /* condition operator */
            if (code->kind == Equal)
                fprintf(file, "==");
            else if (code->kind == NotEqual)
                fprintf(file, "!=");
            else if (code->kind == More)
                fprintf(file, ">");
            else if (code->kind == Less)
                fprintf(file, "<");
            else if (code->kind == MoreEqual)
                fprintf(file, ">=");
            else if (code->kind == LessEqual)
                fprintf(file, "<=");

            fprintf(file, " ");
            /* condition operand 2 */
            if (code->u.binop.op2->kind == Variable)
                fprintf(file, "t%d", code->u.binop.op2->u.var_no);
            else if (code->u.binop.op2->kind == Constant)
                fprintf(file, "#%d", code->u.binop.op2->u.value);

            fprintf(file, " GOTO label%d\n", code->u.binop.result->u.var_no);

        }
        else if (code->kind == Return) {
            fprintf(file, "RETURN ");
            if (code->u.command.op->kind == Variable)
                fprintf(file, "t%d", code->u.command.op->u.var_no);
            else if (code->u.command.op->kind == Constant)
                fprintf(file, "#%d", code->u.command.op->u.value);
            fprintf(file, "\n");
        }
        else if (code->kind == Goto)
            fprintf(file, "GOTO label%d\n", code->u.command.op->u.var_no);
        else if (code->kind == Dec)
            fprintf(file, "DEC t%d %d\n", code->u.dec.addr->u.var_no    \
                , code->u.dec.size->u.value);
        else if (code->kind == Arg) {
            fprintf(file, "ARG ");

            if (code->u.command.op->kind == Reference)
                fprintf(file, "&t%d", code->u.command.op->u.var_no);
            else if (code->u.command.op->kind == Variable)
                fprintf(file, "t%d", code->u.command.op->u.var_no);
            else if (code->u.command.op->kind == Constant)
                fprintf(file, "#%d", code->u.command.op->u.value);

            fprintf(file, "\n");
        }
        else if (code->kind == Call)
            fprintf(file, "t%d := CALL %s\n", code->u.call.result->u.var_no \
                , code->u.call.func_name);
        else if (code->kind == Param)
            fprintf(file, "PARAM t%d\n", code->u.command.op->u.var_no);
        else if (code->kind == Read)
            fprintf(file, "READ t%d\n", code->u.command.op->u.var_no);
        else if (code->kind == Write)
            fprintf(file, "WRITE t%d\n", code->u.command.op->u.var_no);

        tmp = tmp->next;
    } while (tmp != codes);
}
// new temp variabel
Operand *new_temp() {
    return new_var_op(temp_now ++);
}
// new label
Operand *new_label() {
    return new_lbl_op(label_now ++);
}

void init_translate() {
    temp_now = label_now = 0;
}
