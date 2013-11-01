#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "defs.h"
#define MAX_ERRINFO 40
/* ErrorCode starts at 1 */
typedef enum {LEXICAL_ERROR = 1, SYNTAX_ERROR, COMMENT_ERROR
              , UndefineVar_ERROR, UndefineFunc_ERROR, RedefineVar_ERROR, RedefineFunc_ERROR, UnmatchType_ERROR, RVal_ERROR, Operator_ERROR, Return_ERROR, Param_ERROR} ErrorCode;

//#ifdef PRINT_AST
extern bool gl_error_exist;
//#endif

void reportError(int errorcode, int lineno, int column, const char* msg);

#endif
