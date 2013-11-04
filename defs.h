#ifndef DEFS_H
#define DEFS_H

#include <assert.h>
/* definations for the aim of this program */

#define TRUE 1
#define FALSE 0
#define MAX_SYMBOL_NAME 32

typedef char* string;
typedef unsigned char bool;

/* useful functions */
void * ck_malloc(int len);
string String(const char * ps);
int full_atoi(const char * psnum);
#endif
