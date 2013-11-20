#ifndef _GEN_CODE_H_
#define _GEN_CODE_H_

#include "ir.h"
#include <stdio.h>
#include "defs.h"

void gen_code(FILE *file, InterCodeList *codes);

#define NR_VAR_PER_STACK_FRAME 100

int offset_now, args_num;

#define CONST_TEMP_REG 1000000

typedef struct {
    int var_id; // -1 indicates free
    bool is_modified;
} reg_info;

#define NR_REGS 18

reg_info regs[NR_REGS];

#endif
