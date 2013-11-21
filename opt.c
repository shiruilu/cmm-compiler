#include "ir.h"
#include "opt.h"
#include <assert.h>
#include <malloc.h>
#include "defs.h"

CfgFunc * cfg_func_head = NULL;
InterCodeList * tail;

void gen_block(InterCodeList * codes)
{
    assert(codes);
    cfg_func_head = (CfgFunc *)ck_malloc(sizeof(CfgFunc));
    CfgFunc * cfg_func_now = cfg_func_head; //head is unused
    cfg_func_now->next = cfg_func_now->b_head = NULL;
    CfgBlock * cfg_block_now = (CfgBlock *)ck_malloc(sizeof(CfgBlock)); //head is un
    cfg_block_now->next = cfg_block_now->start = cfg_block_now->end = NULL;
    InterCodeList * t_codes = codes;
    /* break cycle */
    tail = t_codes->prev;
    tail->next = NULL;
    t_codes->prev = NULL;
    // prepare for switch use
    CfgFunc * new_func = NULL;
    CfgBlock * new_block = NULL;
    CfgBlock * new_blocklab = NULL;
    Operand * left = NULL;
    Operand * right = NULL;
    Operand * res = NULL;
    while (t_codes)
    {
        switch(t_codes->code->kind)
        {
            case FunCode:
                // new func
                new_func = (CfgFunc *)ck_malloc(sizeof(CfgFunc));
                new_func->next = NULL;
                cfg_func_now->next = new_func;
                cfg_func_now = cfg_func_now->next;
                //init first block of the func
                new_block = (CfgBlock *)ck_malloc(sizeof(CfgBlock));
                new_block->start = t_codes;
                new_block->end = NULL;
                new_block->next = NULL;
                if (t_codes->prev && !cfg_block_now->end)
                { //not first line && prev line not defined
                    cfg_block_now->end = t_codes->prev;
                }
                cfg_block_now->next = new_block;
                cfg_func_now->b_head = cfg_block_now; //assign new block to func
                cfg_block_now = cfg_block_now->next;
                break;
            case LabelDec:
                new_blocklab = (CfgBlock *)ck_malloc(sizeof(CfgBlock));
                new_blocklab->start = t_codes;
                new_blocklab->end = NULL;
                new_blocklab->next = NULL;
                if ( !cfg_block_now->end )
                { // prev line not defined
                    cfg_block_now->end = t_codes->prev;
                }

                cfg_block_now->next = new_blocklab;
                cfg_block_now = cfg_block_now->next;
                break;
            case Goto:
            case Call:
            case More:
            case Less:
            case MoreEqual:
            case LessEqual:
            case NotEqual:
            case Return:
                cfg_block_now->end = t_codes;
                break;
            case Add:
                left = t_codes->code->u.binop.op1;
                right = t_codes->code->u.binop.op2;
                res  = t_codes->code->u.binop.result;
                if (left->kind == Constant && left->u.value == 0)
                { // plus 0
                    t_codes->code->kind = Assign;
                    t_codes->code->u.assign.right = res;
                    t_codes->code->u.assign.left = right;
                }
                else if (right->kind == Constant && right->u.value == 0 )
                {
                    t_codes->code->kind = Assign;
                    t_codes->code->u.assign.right = res;
                    t_codes->code->u.assign.left = left;
                }
                break;
            default:
                break;
        }
        t_codes = t_codes->next;
    }
}

Regs *regs;

void copy_prop(InterCodeList * codes)
{
    regs =  (Regs *)ck_malloc(temp_now * sizeof(Regs));
    //InterCodeList * t_codes = codes;
    int cur_varno = -1; // for cur var in while analysis
    Regs * cur_reg = NULL; // for get_reg_content return
    CfgFunc * cur_func = cfg_func_head;
    while (cur_func = cur_func->next){
        CfgBlock * cur_blk = cur_func->b_head;
        while (cur_blk = cur_blk->next){
            /* clear in each block */
            int i=0;
            for (; i<temp_now; ++i){
                regs[i].stat = Unde;
            }

            InterCodeList * cur_code = cur_blk->start;
            while (cur_code != cur_blk->end){
                switch (cur_code->code->kind){
                    case Assign:
                        if (cur_code->code->u.assign.right->kind != Variable)
                            break;
                        if (cur_code->code->u.assign.left->kind == Constant){
                            cur_varno = cur_code->code->u.assign.right->u.var_no;
                            regs[cur_varno].stat = Cons;
                            regs[cur_varno].u.val = cur_code->code->u.assign.left->u.value;
                        }
                        /*else if (cur_code->code->u.assign.left->kind == Variable){
                            cur_reg = get_reg_content(cur_code->code->u.assign.left);
                            if (cur_reg->stat == Cons) {
                                // can be replaced by Const (many iter)
                                cur_code->code->u.assign.left->kind = Constant;
                                cur_code->code->u.assign.left->u.value = cur_reg->u.val;
                            }
                            else if (cur_reg->stat = Unde) {
                                // can be replaced by another reg (many iter)
                                // get_reg_content() ensure Unde var_no meaningful
                                cur_code->code->u.assign.left->u.var_no = cur_reg->u.var_no;
                            }
                        }
                        */
                        break;
                    case Add:
                    case Sub:
                    case Mul:
                    case Div:
                        if (cur_code->code->u.binop.result->kind != Variable)
                            break;
                        if (cur_code->code->u.binop.op1->kind == Variable \
                            && cur_code->code->u.binop.op2->kind == Constant)
                        {
                            Regs op1reg;
                            op1reg = get_reg_content(cur_code->code->u.binop.op1);
                            /*if ( op1reg.stat == Vari ){
                                cur_code->code->u.binop.op1->u.var_no = op1reg.u.var_no;
                                // update regs
                                regs[cur_code->code->u.binop.op1->u.var_no].stat = Vari;
                                regs[cur_code->code->u.binop.op1->u.var_no].u.val = op1reg.u.var_no;
                                }
                            */
                            if (op1reg.stat == Cons){
                                Operand * new_op = (Operand *)ck_malloc(sizeof(Operand));
                                new_op->kind = Constant;
                                new_op->u.value = op1reg.u.val;
                                cur_code->code->u.binop.op1 = new_op;
                                int regnum1 = cur_code->code->u.binop.op1->u.var_no;// save varno
                                elim_two_const(cur_code);
                                //update regs
                                //regs[regnum1].stat = Cons;
                                //regs[regnum1].u.val = cur_code->code->u.binop.op1->u.value;
                                /* have been replaced by elim() */
                                assert(cur_code->code->kind == Assign);
                                int regres = cur_code->code->u.assign.right->u.var_no;
                                regs[regres].stat = Cons;
                                regs[regres].u.val = cur_code->code->u.assign.left->u.value;
                            }
                        }
                        else if (cur_code->code->u.binop.op2->kind == Variable \
                            && cur_code->code->u.binop.op1->kind == Constant)
                        {
                            Regs op2reg;
                            op2reg = get_reg_content(cur_code->code->u.binop.op2);
                            if (op2reg.stat == Cons){
                                cur_code->code->u.binop.op2->kind = Constant;
                                cur_code->code->u.binop.op2->u.value = op2reg.u.val;
                                int regnum2 = cur_code->code->u.binop.op2->u.var_no;// save varno
                                elim_two_const(cur_code);
                                //update regs
                                /* have been replaced by elim() */
                                assert(cur_code->code->kind == Assign);
                                int regres = cur_code->code->u.assign.right->u.var_no;
                                regs[regres].stat = Cons;
                                regs[regres].u.val = cur_code->code->u.assign.left->u.value;
                            }
                        }
                        else if (cur_code->code->u.binop.op2->kind == Variable \
                            && cur_code->code->u.binop.op1->kind == Variable)
                        {
                            // reg1
                            Regs op1reg;
                            op1reg = get_reg_content(cur_code->code->u.binop.op1);

                            // reg2
                            Regs op2reg;
                            op2reg = get_reg_content(cur_code->code->u.binop.op2);

                            if (op1reg.stat == Cons && op2reg.stat == Cons){
                                cur_code->code->u.binop.op1->kind = Constant;
                                cur_code->code->u.binop.op1->u.value = op1reg.u.val;
                                int regnum1 = cur_code->code->u.binop.op1->u.var_no;// save varno

                                cur_code->code->u.binop.op2->kind = Constant;
                                cur_code->code->u.binop.op2->u.value = op2reg.u.val;
                                int regnum2 = cur_code->code->u.binop.op2->u.var_no;// save varno
                                elim_two_const(cur_code);
                                //update regs
                                /* have been replaced by elim() */
                                assert(cur_code->code->kind == Assign);
                                int regres = cur_code->code->u.assign.right->u.var_no;
                                regs[regres].stat = Cons;
                                regs[regres].u.val = cur_code->code->u.assign.left->u.value;
                            }
                        }
                        else if (cur_code->code->u.binop.op1->kind == Constant \
                            && cur_code->code->u.binop.op2->kind == Constant)
                        {
                            elim_two_const(cur_code);
                            //update regs
                            assert(cur_code->code->kind == Assign);
                            int regres = cur_code->code->u.assign.right->u.var_no;
                            regs[regres].stat = Cons;
                            regs[regres].u.val = cur_code->code->u.assign.left->u.value;
                        }
                        break;
                    default :
                        break;
                }
                cur_code = cur_code->next;
            }
            //cur_blk = cur_blk->next;
        }
    }
}
void elim_two_const(InterCodeList * cur_code)
{
    assert(cur_code->code->kind == Add || cur_code->code->kind == Sub   \
        ||cur_code->code->kind == Mul || cur_code->code->kind == Div);
    int res_con; // store the res of two Constant op
    switch(cur_code->code->kind)
    {
        case Add:
            res_con = cur_code->code->u.binop.op1->u.value + \
                cur_code->code->u.binop.op2->u.value;
            break;
        case Sub:
            res_con = cur_code->code->u.binop.op1->u.value - \
                cur_code->code->u.binop.op2->u.value;
            break;
        case Mul:
            res_con = cur_code->code->u.binop.op1->u.value * \
                cur_code->code->u.binop.op2->u.value;
            break;
        case Div:
            res_con = cur_code->code->u.binop.op1->u.value / \
                cur_code->code->u.binop.op2->u.value;
            break;
    }
    Operand * resu = cur_code->code->u.binop.result;
    cur_code->code->kind = Assign;
    cur_code->code->u.assign.right = resu;
    cur_code->code->u.assign.left->kind = Constant;
    cur_code->code->u.assign.left->u.value = res_con;
    //return res_con;
}

Regs get_reg_content(Operand * op){
    int curvar = op->u.var_no;
    //while (regs[curvar].stat != Unde){
        if (regs[curvar].stat == Cons) {
            return regs[curvar];
        }
        //  else {
            // Vari
        //  assert(regs[curvar].stat == Vari);
        //  curvar = regs[curvar].u.var_no; // next var
        //}
        //}
    // roll back to last
    Regs ret;// = regs[curvar];
    ret.stat = Unde;//Vari;
        //ret.u.var_no = curvar;
    return ret;
}

bool * gl_reg_useful;
void judge_reg_useful(InterCodeList * codes){
    gl_reg_useful = (bool *)ck_malloc( sizeof(bool) * temp_now );
    InterCodeList * tmpcodes = codes;
    while (tmpcodes){
        switch (tmpcodes->code->kind) {
            case Param:
            case Return:
            case Arg:
            case Read:
            case Write:
                gl_reg_useful[tmpcodes->code->u.command.op->u.var_no] = TRUE;
                break;
            case Dec:
                gl_reg_useful[tmpcodes->code->u.dec.addr->u.var_no] = TRUE;
                break;
            case Assign:
                if (tmpcodes->code->u.assign.left->kind == Variable \
                    || tmpcodes->code->u.assign.left->kind == Address \
                    || tmpcodes->code->u.assign.left->kind == Reference)
                {
                    gl_reg_useful[tmpcodes->code->u.assign.left->u.var_no] = TRUE;
                }
                if (tmpcodes->code->u.assign.right->kind == Address \
                    || tmpcodes->code->u.assign.right->kind == Reference)
                {
                    gl_reg_useful[tmpcodes->code->u.assign.right->u.var_no] = TRUE;
                }
                break;
            case Add:
            case Sub:
            case Mul:
            case Div:
            case Equal:
            case More:
            case Less:
            case MoreEqual:
            case LessEqual:
            case NotEqual:
                if (tmpcodes->code->u.binop.op1->kind == Variable   \
                    || tmpcodes->code->u.binop.op1->kind == Address     \
                    || tmpcodes->code->u.binop.op1->kind == Reference)
                {
                    gl_reg_useful[tmpcodes->code->u.binop.op1->u.var_no] = TRUE;
                }
                if (tmpcodes->code->u.binop.op2->kind == Variable   \
                    || tmpcodes->code->u.binop.op2->kind == Address    \
                    || tmpcodes->code->u.binop.op2->kind == Reference)
                {
                    gl_reg_useful[tmpcodes->code->u.binop.op2->u.var_no] = TRUE;
                }
                if (tmpcodes->code->u.binop.result->kind == Address \
                    || tmpcodes->code->u.binop.result->kind == Reference)
                {
                    gl_reg_useful[tmpcodes->code->u.binop.result->u.var_no] = TRUE;
                }
                break;
            default:
                break;
        }
        tmpcodes = tmpcodes->next;
    }
}

void remove_dead_assign(InterCodeList * codes)
{
    InterCodeList * tmpcodes = codes;
    while (tmpcodes) {
        switch (tmpcodes->code->kind) {
            case Assign:
                if ( (tmpcodes->code->u.assign.right->kind == Variable )
                    && tmpcodes->code->u.assign.left->kind != Reference
                    && tmpcodes->code->u.assign.left->kind != Address
                    //|| tmpcodes->code->u.assign.right->kind == Address \
                    //|| tmpcodes->code->u.assign.right->kind == Reference)
                    && !gl_reg_useful[tmpcodes->code->u.assign.right->u.var_no] )
                {
                    tmpcodes->prev->next = tmpcodes->next;
                    tmpcodes->next->prev = tmpcodes->prev;
                    free(tmpcodes);
                }
                break;
            case Add:
            case Sub:
            case Mul:
            case Div:
                if ( (tmpcodes->code->u.binop.result->kind == Variable)
                    && tmpcodes->code->u.binop.op1->kind != Reference
                    && tmpcodes->code->u.binop.op1->kind != Address
                    && tmpcodes->code->u.binop.op2->kind != Reference
                    && tmpcodes->code->u.binop.op2->kind != Address
                        //|| tmpcodes->code->u.binop.result->kind == Address \
                        //|| tmpcodes->code->u.binop.result->kind == Reference)
                    && !gl_reg_useful[tmpcodes->code->u.binop.result->u.var_no] )
                {
                    tmpcodes->prev->next = tmpcodes->next;
                    tmpcodes->next->prev = tmpcodes->prev;
                    free(tmpcodes);
                }
                break;
            default:
                break;
        }
        tmpcodes = tmpcodes->next;
    }
}
void opt(InterCodeList * codes)
{
    gen_block(codes);
    copy_prop(codes);
    judge_reg_useful(codes);
    remove_dead_assign(codes);
    // resume cycle
    codes->prev = tail;
    tail->next = codes;
}