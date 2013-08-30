#ifndef DEFS_H
#define DEFS_H

#include <assert.h>

#define MAX_ERRINFO 40
/* ErrorCode starts at 1 */
typedef enum {LEXICAL_ERROR = 1, SYNTAX_ERROR, COMMENT_ERROR} ErrorCode;

#endif