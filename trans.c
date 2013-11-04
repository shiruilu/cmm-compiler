#include "defs.h"
#include "trans.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 8

#define TRANSLATE_EXP_CASE_COND \
    Operand *label1 = new_label(), *label2 = new_label(); \
InterCodeList *code0 = make_code_list(gen_assign_code(place, new_const_op(0))); \
InterCodeList *code1 = translate_Cond(p_node, label1, label2); \
InterCodeList *code2 = link_inter_code(2, make_code_list(gen_label_code(label1)), (place == NULL) ? NULL : make_code_list(gen_assign_code(place, new_const_op(1)))); \
return link_inter_code(4, code0, code1, code2, make_code_list(gen_label_code(label2)));

#define TRANSLATE_EXP_CASE_ARIBINOP(operator) \
    Operand *t1 = new_temp(), *t2 = new_temp(); \
InterCodeList *code1 = translate_Exp(children[0], t1), *code2 = translate_Exp(children[2], t2); \
InterCodeList *code3 = (place == NULL) ? NULL : make_code_list(gen_binop_code(operator, place, t1, t2)); \
return link_inter_code(3, code1, code2, code3);

int get_size_of(Type *type) {
    if (type == NULL)
        return 0;
    if (type->kind == Basic)
        return 4;
    if (type->kind == Array) {
        return type->u.array.size * get_size_of(type->u.array.elem);
    }
    if (type->kind == Structure) {
        int sum = 0;
        FieldList *structure = type->u.structure;
        while (structure) {
            sum += get_size_of(structure->type);
            structure = structure->next;
        }
        return sum;
    }
}

typedef struct OperandList_ OperandList;

struct OperandList_ {
    Operand *op;
    OperandList *next;
};

InterCodeList *translate_Exp(ast_node *p_node, Operand *place);

InterCodeList *translate_Args(ast_node *p_node, OperandList **p_arg_list) {
    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    Operand *t1 = new_temp();
    InterCodeList *code1 = translate_Exp(children[0], t1);

    //arg_list = t1 + arg_list
    OperandList *new_node = (OperandList*)malloc(sizeof(OperandList));
    new_node->op = t1;
    new_node->next = *p_arg_list;
    *p_arg_list = new_node;

    if (child_num == 1 && children[0]->type == Exp_SYNTAX) {
        return code1;
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == COMMA_TOKEN && children[2]->type == Args_SYNTAX) {
        InterCodeList *code2 = translate_Args(children[2], p_arg_list);
        return link_inter_code(2, code1, code2);
    }
    return NULL;
}

InterCodeList *translate_Cond(ast_node *p_node,     \
    Operand *label_true, Operand *label_false)
{
    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    if (child_num == 3 && children[0]->type == Exp_SYNTAX               \
        && children[1]->type == RELOP_TOKEN && children[2]->type == Exp_SYNTAX) {
        Operand *t1 = new_temp(), *t2 = new_temp();
        InterCodeList *code1 = translate_Exp(children[0], t1);
        InterCodeList *code2 = translate_Exp(children[2], t2);
        code_kind kind;
        if (strcmp(children[1]->value.str_val, "==") == 0)
            kind = Equal;
        else if (strcmp(children[1]->value.str_val, "!=") == 0)
            kind = NotEqual;
        else if (strcmp(children[1]->value.str_val, ">") == 0)
            kind = More;
        else if (strcmp(children[1]->value.str_val, "<") == 0)
            kind = Less;
        else if (strcmp(children[1]->value.str_val, ">=") == 0)
            kind = MoreEqual;
        else if (strcmp(children[1]->value.str_val, "<=") == 0)
            kind = LessEqual;
        InterCodeList *code3 = make_code_list(gen_binop_code(kind, label_true, \
                t1, t2));
        return link_inter_code(4, code1, code2, code3,              \
            make_code_list(gen_command_code(Goto, label_false)));
    }
    else if (child_num == 2 && children[0]->type == NOT_TOKEN   \
        && children[1]->type == Exp_SYNTAX) {
        return translate_Cond(children[1], label_false, label_true);
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == AND_TOKEN && children[2]->type == Exp_SYNTAX) {
        Operand *label1 = new_label();
        InterCodeList *code1 = translate_Cond(children[0], label1, label_false);
        InterCodeList *code2 = translate_Cond(children[2], label_true, label_false);
        return link_inter_code(3, code1, make_code_list(gen_label_code(label1)), code2);
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == OR_TOKEN && children[2]->type == Exp_SYNTAX) {
        Operand *label1 = new_label();
        InterCodeList *code1 = translate_Cond(children[0], label_true, label1);
        InterCodeList *code2 = translate_Cond(children[2], label_true, label_false);
        return link_inter_code(3, code1, make_code_list(gen_label_code(label1)), code2);
    }
    else {
        Operand *t1 = new_temp();
        InterCodeList *code1 = translate_Exp(p_node, t1);
        InterCodeList *code2 = make_code_list(gen_binop_code(NotEqual, label_true, \
                t1, new_const_op(0)));
        return link_inter_code( 3, code1, code2,                    \
            make_code_list(gen_command_code(Goto, label_false)) );
    }
}

InterCodeList *translate_Exp(ast_node *p_node, Operand *place) {
    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    if (child_num == 3 && children[0]->type == Exp_SYNTAX               \
        && children[1]->type == ASSIGNOP_TOKEN && children[2]->type == Exp_SYNTAX)
    {
        Operand *t1 = (children[0]->lchild->next_sib == NULL) ? new_var_op(-1) : \
            new_addr_op(-1), *t2 = new_temp();
        InterCodeList *code1 = translate_Exp(children[0], t1),  \
            *code2 = translate_Exp(children[2], t2);
        InterCodeList *code3 = make_code_list(gen_assign_code(t1, t2));
        InterCodeList *code4 = (place == NULL) ? NULL : \
            make_code_list(gen_assign_code(place, t1));
        return link_inter_code(4, code1, code2, code3, code4);
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == AND_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_COND
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == OR_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_COND
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == RELOP_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_COND
    }
    else if (child_num == 2 && children[0]->type == NOT_TOKEN   \
        && children[1]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_COND
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == PLUS_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_ARIBINOP(Add)
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == MINUS_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_ARIBINOP(Sub)
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == STAR_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_ARIBINOP(Mul)
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == DIV_TOKEN && children[2]->type == Exp_SYNTAX) {
        TRANSLATE_EXP_CASE_ARIBINOP(Div)
    }
    else if (child_num == 3 && children[0]->type == LP_TOKEN            \
        && children[1]->type == Exp_SYNTAX && children[2]->type == RP_TOKEN) {
        return translate_Exp(children[1], place);
    }
    else if (child_num == 2 && children[0]->type == MINUS_TOKEN \
        && children[1]->type == Exp_SYNTAX)
    {
        Operand *t1 = new_temp();
        InterCodeList *code1 = translate_Exp(children[1], t1);
        InterCodeList *code2 = (place == NULL) ? NULL :                 \
            make_code_list(gen_binop_code(Sub, place, new_const_op(0), t1));
        return link_inter_code(2, code1, code2);
    }
    else if (child_num == 4 && children[0]->type == ID_TOKEN            \
        && children[1]->type == LP_TOKEN && children[2]->type == Args_SYNTAX \
        && children[3]->type == RP_TOKEN || child_num == 3              \
        && children[0]->type == ID_TOKEN && children[1]->type == LP_TOKEN \
        && children[2]->type == RP_TOKEN)
    {
        symbol_node *func_node = get_symbol(children[0]->value.str_val);
        Operand *ret = (place == NULL) ? new_temp() : place;
        if (child_num == 3) {
            if (strcmp(children[0]->value.str_val, "read") == 0)
                return make_code_list(gen_command_code(Read, ret));
            return make_code_list(gen_call_code(ret, children[0]->value.str_val));
        }
        else {
            OperandList *arg_list = NULL;
            InterCodeList *code1 = translate_Args(children[2], &arg_list);
            if (strcmp(children[0]->value.str_val, "write") == 0)
            {
                return link_inter_code(2, code1,                        \
                    make_code_list(gen_command_code(Write, arg_list->op)));
            }
            InterCodeList *code2 = NULL;
            while (arg_list) {
                code2 = link_inter_code(2, code2,                       \
                    make_code_list(gen_command_code(Arg, arg_list->op)));
                arg_list = arg_list->next;
            }
            return link_inter_code(3, code1, code2,                     \
                make_code_list(gen_call_code(ret, children[0]->value.str_val)));
        }
    }
    else if (child_num == 4 && children[0]->type == Exp_SYNTAX          \
        && children[1]->type == LB_TOKEN && children[2]->type == Exp_SYNTAX \
        && children[3]->type == RB_TOKEN)
    {
        Operand *t1 = new_var_op(-1), *t2 = new_temp(), \
            *t3 = new_temp(), *t4 = new_temp();

        InterCodeList *code1 = translate_Exp(children[0], t1);
        InterCodeList *code2 = translate_Exp(children[2], t2);
        InterCodeList *code3 = make_code_list(gen_binop_code(Mul, t3, t2, \
                new_const_op(get_size_of(p_node->attr.type))));
        InterCodeList *code4 = make_code_list(gen_binop_code(Add, t4, t1, t3));
        if (place == NULL)
            return link_inter_code(4, code1, code2, code3, code4);
        else if (place->u.var_no < 0) {
            place->u.var_no = t4->u.var_no;
            return link_inter_code(4, code1, code2, code3, code4);
        }
        else {
            return link_inter_code( 5, code1, code2, code3, code4,
                make_code_list(gen_assign_code(place, new_addr_op(t4->u.var_no))) );
        }
    }
    else if (child_num == 3 && children[0]->type == Exp_SYNTAX
        && children[1]->type == DOT_TOKEN && children[2]->type == ID_TOKEN)
    {
        Operand *t1 = new_var_op(-1), *t2 = new_temp();
        InterCodeList *code1 = translate_Exp(children[0], t1);

        int size_start = 0;
        FieldList *field = children[0]->attr.type->u.structure;
        while (field) {
            if (strcmp(field->id, children[2]->value.str_val) == 0)
                break;
            size_start += get_size_of(field->type);
            field = field->next;
        }

        InterCodeList *code2 = make_code_list(gen_binop_code(Add, t2, t1, \
                new_const_op(size_start)));

        if (place == NULL)
            return link_inter_code(2, code1, code2);
        else if (place->u.var_no < 0) {
            place->u.var_no = t2->u.var_no;
            return link_inter_code(2, code1, code2);
        }
        else {
            return link_inter_code( 3, code1, code2,                    \
                make_code_list(gen_assign_code(place, new_addr_op(t2->u.var_no))) );
        }
    }
    else if (child_num == 1 && children[0]->type == ID_TOKEN) {
        symbol_node *var_node = get_symbol(children[0]->value.str_val);
        InterCodeList *ret;
        if (place == NULL)
            ret = NULL;
        else if (place->u.var_no < 0) {
            ret = NULL;
            if (p_node->attr.type->kind == Basic)
                place->kind = Variable;
            else if (var_node->symbol.var_value.is_param)
                place->kind = Variable;
            else
                place->kind = Reference;
            place->u.var_no = var_node->symbol.var_value.var_op->u.var_no;
        }
        else {
            if (p_node->attr.type->kind == Basic)
                ret = make_code_list(gen_assign_code(place,     \
                        var_node->symbol.var_value.var_op));
            else
                ret = make_code_list(gen_assign_code(place,             \
                        new_ref_op(var_node->symbol.var_value.var_op->u.var_no)));
        }
        return ret;
    }
    else if (child_num == 1 && children[0]->type == INT_TOKEN) {
        int value = children[0]->value.int_val;
        return (place == NULL) ? NULL :                                 \
            make_code_list(gen_assign_code(place, new_const_op(value)));
    }
}

InterCodeList *translate_Stmt(ast_node *p_node) {
    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    if (child_num == 2 && children[0]->type == Exp_SYNTAX
        && children[1]->type == SEMI_TOKEN)
    {
        return translate_Exp(children[0], NULL);
    }
    else if (child_num == 1 && children[0]->type == CompSt_SYNTAX)
    {
        return translate(children[0]);
    }
    else if (child_num == 3 && children[0]->type == RETURN_TOKEN        \
        && children[1]->type == Exp_SYNTAX && children[2]->type == SEMI_TOKEN)
    {
        Operand *t1 = new_temp();
        InterCodeList *code1 = translate_Exp(children[1], t1);
        InterCodeList *code2 = make_code_list(gen_command_code(Return, t1));
        return link_inter_code(2, code1, code2);
    }
    else if (child_num == 5 && children[0]->type == IF_TOKEN            \
        && children[1]->type == LP_TOKEN && children[2]->type == Exp_SYNTAX \
        && children[3]->type == RP_TOKEN && children[4]->type == Stmt_SYNTAX)
    {
        Operand *label1 = new_label(), *label2 = new_label();
        InterCodeList *code1 = translate_Cond(children[2], label1, label2);
        InterCodeList *code2 = translate_Stmt(children[4]);
        return link_inter_code( 4, code1, make_code_list(gen_label_code(label1)),
            code2, make_code_list(gen_label_code(label2)) );
    }
    else if (child_num == 7 && children[0]->type == IF_TOKEN            \
        && children[1]->type == LP_TOKEN && children[2]->type == Exp_SYNTAX \
        && children[3]->type == RP_TOKEN && children[4]->type == Stmt_SYNTAX \
        && children[5]->type == ELSE_TOKEN && children[6]->type == Stmt_SYNTAX)
    {
        Operand *label1 = new_label(), *label2 = new_label(), *label3 = new_label();
        InterCodeList *code1 = translate_Cond(children[2], label1, label2);
        InterCodeList *code2 = translate_Stmt(children[4]);
        InterCodeList *code3 = translate_Stmt(children[6]);
        return link_inter_code( 7, code1, make_code_list(gen_label_code(label1)), \
            code2, make_code_list(gen_command_code(Goto, label3)),      \
            make_code_list(gen_label_code(label2)), code3,              \
            make_code_list(gen_label_code(label3)));
    }
    else if (child_num == 5 && children[0]->type == WHILE_TOKEN         \
        && children[1]->type == LP_TOKEN && children[2]->type == Exp_SYNTAX \
        && children[3]->type == RP_TOKEN && children[4]->type == Stmt_SYNTAX)
    {
        Operand *label1 = new_label(), *label2 = new_label(), *label3 = new_label();
        InterCodeList *code1 = translate_Cond(children[2], label2, label3);
        InterCodeList *code2 = translate_Stmt(children[4]);
        return link_inter_code( 6, make_code_list(gen_label_code(label1)), \
            code1, make_code_list(gen_label_code(label2)), code2,       \
            make_code_list(gen_command_code(Goto, label1)),             \
            make_code_list(gen_label_code(label3)) );
    }
    return NULL;
}

InterCodeList *translate_VarDec(ast_node *p_node) {
    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    if (child_num == 1 && children[0]->type == ID_TOKEN) {
        if (p_node->attr.is_in_struct) {
            return NULL;
        }
        symbol_node *new_symbol = (symbol_node*)malloc(sizeof(symbol_node));
        strcpy(new_symbol->key, children[0]->value.str_val);
        new_symbol->type = Var;
        new_symbol->symbol.var_value.type = p_node->attr.type;
        new_symbol->symbol.var_value.var_op = new_temp();
        new_symbol->symbol.var_value.is_param = FALSE;
        insert_symbol(new_symbol);
        if (p_node->attr.type->kind == Array) {
            return make_code_list(gen_dec_code(new_symbol->symbol.var_value.var_op,
                    new_const_op(get_size_of(p_node->attr.type))));
        }
        else {
            return NULL;
        }
    }
    else if (child_num == 4 && children[0]->type == VarDec_SYNTAX       \
        && children[1]->type == LB_TOKEN && children[2]->type == INT_TOKEN \
        && children[3]->type == RB_TOKEN) {
        return translate_VarDec(children[0]);
    }
}

InterCodeList *translate(ast_node *p_node) {
    if (p_node == NULL)
        return NULL;

    if (p_node->type == Stmt_SYNTAX) {
        return translate_Stmt(p_node);
    }
    if (p_node->type == VarDec_SYNTAX) {
        return translate_VarDec(p_node);
    }

    ast_node *children[MAX_CHILDREN];
    ast_node *child = p_node->lchild;
    int child_num = 0;
    while (child) {
        children[child_num ++] = child;
        child = child->next_sib;
    }

    if (p_node->type == ParamDec_SYNTAX) {
        translate_VarDec(children[1]);
        symbol_node *var_node = get_symbol(children[1]->attr.id);
        var_node->symbol.var_value.is_param = TRUE;
        return make_code_list(
            gen_command_code(Param, var_node->symbol.var_value.var_op)
                              );
    }

    if (p_node->type == ExtDef_SYNTAX && child_num == 3                 \
        && children[0]->type == Specifier_SYNTAX                        \
        && children[1]->type == FunDec_SYNTAX                           \
        && children[2]->type == CompSt_SYNTAX)
    {
        InterCodeList *code1 = translate(children[0]);
        enter_deeper_scope();
        InterCodeList *code2 = translate(children[1]),  \
            *code3 = translate(children[2]);
        exit_top_scope();
        return link_inter_code(3, code1, code2, code3);
    }
    if (p_node->type == CompSt_SYNTAX) {
        enter_deeper_scope();
        InterCodeList *code1 = translate(children[1])   \
            , *code2 = translate(children[2]);
        exit_top_scope();
        return link_inter_code(2, code1, code2);
    }
    if (p_node->type == FunDec_SYNTAX) {
        ast_node *args = (child_num == 3) ? NULL : children[2];
        return link_inter_code( 2,
            make_code_list(gen_func_code(children[0]->value.str_val)),
            translate(args) );
    }

    if (p_node->type == Dec_SYNTAX) {
        InterCodeList *code1 = translate_VarDec(children[0]);
        if (child_num == 3) { //Dec -> VarDec ASSIGNOP Exp
            Operand *op = get_symbol(children[0]->attr.id)->symbol.var_value.var_op;
            return link_inter_code(2, code1, translate_Exp(children[2], op));
        }
        else
            return code1;
    }

    InterCodeList *list = NULL;
    int i;
    for (i = 0; i < child_num; ++ i)
        list = link_inter_code(2, list, translate(children[i]));
    return list;

}

