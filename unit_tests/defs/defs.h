#ifndef DEFS_H
#define DEFS_H

#include <assert.h>

#define TRUE 1
#define FALSE 0
#define MAX_ERRINFO 40
/* ErrorCode starts at 1 */
typedef enum {LEXICAL_ERROR = 1, SYNTAX_ERROR, COMMENT_ERROR} ErrorCode;

/* useful functions */
void * ck_malloc(int len);
typedef char* string;
string String(char * ps);
#endif
